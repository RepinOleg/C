#include "../s21_decimal.h"

int s21_raise_exp_decimal(int raise_to_exp, s21_decimal *result);
int s21_lower_exp_decimal(int lower_to_exp, s21_decimal *result);
int s21_div_by_ten(s21_decimal *result);
int s21_simple_round(s21_decimal *a);

// * 1) Возьмем число с меньшим порядком и увеличим его
// * порядок до большего, умножая b на 10
// * Таким образом число выровняется с другим
// * и множество операций с этими двумя станут в разы проще
// ---------------------------------------+
// ?    a = 123.456 b = 12345.6 <=> 0x1e240 * 10^-1
// ?           ^exp=3        ^exp=1
// ?    a = 123.456 b = 12345.600 <=> 0xbc6100 * 10^-3 = 0x1e240 * 10^-1
// ?           ^exp=3        ^exp=3
// ---------------------------------------+
// * 2) Существует случай переполнения:
// * Если умножать число d на 10, то оно точно переполнится
// ---------------------------------------+
// ?    c =   |79228162514264337593543950.335| <=> 0xfff....fff * 10^-3
// ?                                exp=3^
// ?    d = |7922816251426433759354395033.5|xx <=> 0xfff....fff * 10^-1
// ?                                exp=1^  ^^ нули сюда нельзя!
// ---------------------------------------+
// * 3) Поэтому вместо него будем делить число a на 10
// * Очевидно, что после этого будут теряться цифры в конце числа,
// * но c'est la vie (они бы в любом случае бы не вместились в decimal)
// ---------------------------------------+
// ?                                    :(  \/ - эти цифры отправились в небытие
// ?    c = |  79228162514264337593543950.3|35
// ?                                     ^exp=1
// ?    d = |7922816251426433759354395033.5|
// ?                                     ^exp=1
// ---------------------------------------+
// * 4) По сути в этот момент число округляется,
// * поэтому в некоторых случаях важно
// * учитывать отбрасываемые цифры для округления
// ---------------------------------------+
// ?    e = |79228162514264337593543950335| <-- повышать нельзя
// ?                                      ^exp=0
// ?    f = |0.6| =>  f = |0|.6 <=> 1
// ?          ^exp=1       ^exp=0
// ?    g = |0.53| =>  g = |0|.53 <=> 1
// ?
// !    h = |0.47| => h = |0.4|7 => h = |0.5| => h = |0|.5 <=> 1 - неверно!
// ---------------------------------------+
// * 5) Для исправления случая с h, стоит действительно *отбрасывать*
// * цифры до финального случая, когда это важно, а последнюю уже учитывать
// ---------------------------------------+
// ?    i = |0.48122131313213| => i = |0.4| <=> 0
// ?
// ?    j = |0.59123921312312| => j = |0.5| <=> 1
// ---------------------------------------+
int s21_normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int res = S21_OK;
  int exp_1 = s21_get_exp(*value_1), exp_2 = s21_get_exp(*value_2);
  // printf("Normalizing ");
  // s21_print_decimal(*value_1);
  // printf(" with ");
  // s21_print_decimal(*value_2);
  // printf("\n");
  // * Находим у какого из чисел большая степень
  if (exp_1 > exp_2) {
    // * Повышаем степень числа [2] с меньшей степени до
    // * степени числа [1] с большей степенью
    if (s21_raise_exp_decimal(exp_1, value_2)) {
      // * Если степень больше не получается повысить, берем
      // * меньшую степень [2] и теперь понижаем степень числа [1]
      // * с большей степенью
      exp_2 = s21_get_exp(*value_2);
      s21_lower_exp_decimal(exp_2, value_1);
    }
  } else {
    // * Повышаем степень числа [1] с меньшей степени до
    // * степени числа [2] с большей степенью
    if (s21_raise_exp_decimal(exp_2, value_1)) {
      // * Если степень больше не получается повысить, берем
      // * меньшую степень [1] и теперь понижаем степень числа [2]
      // * с большей степенью
      exp_1 = s21_get_exp(*value_1);
      s21_lower_exp_decimal(exp_1, value_2);
    }
  }
  // printf("Result of normalization: ");
  // s21_print_decimal(*value_1);
  // printf(" and ");
  // s21_print_decimal(*value_2);
  // putchar('\n');
  return res;
}

int s21_div_by_ten(s21_decimal *result) {
  long contain = 0, remainder = 0;
  unsigned int current = 0;
  for (int i = 2; i >= 0; --i) {
    current = (unsigned int)result->bits[i];
    contain = (remainder * 0x100000000) + (long)current;
    result->bits[i] = contain / 10;
    remainder = contain % 10;
  }
  return 0;
}

int s21_mod_by_ten(s21_decimal decimal, int *result) {
  // ? 2^32 % 10 = 6
  // ? 2^64 % 10 = [2^32 * 2^32] % 10 = [2^32 % 10 * 2^32 % 10] % 10 = 36%10 = 6
  // * Пусть A - decimal
  // ? A % 10 = [ a0 + a1 * 2^32 + a2 * 2^32 * 2^32 ] % 10 =
  // ?        = [a0 % 10 + 6*(a1 % 10) + 6*(a2 % 10)] % 10 =
  // ? | a0 % 10 = m0 |
  // ? | a1 % 10 = m1 |
  // ? | a2 % 10 = m2 |
  // *        = [m0 + 6*m1 + 6*m2] % 10 = *result
  int res = S21_OK;
  unsigned a0 = (unsigned)decimal.bits[0], a1 = (unsigned)decimal.bits[1],
           a2 = (unsigned)decimal.bits[2];
  int m0 = a0 % 10, m1 = a1 % 10, m2 = a2 % 10;
  *result = (m0 + 6 * m1 + 6 * 6 * m2) % 10;
  // printf("m0=%d m1=%d m2=%d\n", m0, m1, m2);
  // printf("Mod: {%d}\n", *result);
  return res;
}

int s21_raise_exp_decimal(int raise_to_exp, s21_decimal *result) {
  int res = S21_OK;
  // ? #1 - когда число повышает степень и переполянется, оно не возвращается
  // ? обратно в исходное состояние
  // * Чтобы это исправить, будем хранить прошлое состояние числа в backup
  // * и в случае переполнения вернем его
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal backup = *result;
  if (s21_is_correct_exp(raise_to_exp)) {
    for (int raise_from_exp = s21_get_exp(*result);
         raise_from_exp < raise_to_exp && !s21_mul(*result, ten, result);
         ++raise_from_exp) {
      s21_set_exp(result, raise_from_exp + 1);
      backup = *result;
    }
  }
  if (s21_get_exp(*result) != raise_to_exp) {
    res = 1;
    *result = backup;
  }
  return res;
}

int s21_lower_exp_decimal(int lower_to_exp, s21_decimal *result) {
  // ? #3 - пропадающая единица
  // * Почему-то забыл реализовать механизм из (5) пункта,
  // * и из-за этого после сброса всех цифр иногда теряется единичка
  // ? #7 - проблема с округлением при вычитании
  // ?   79228162514264337593543950335 - 7922816251426433759354395033.5 =
  // * Перевел обработку таких случаев в функцию simple_round
  // * Осталось регулировать эту обработку - когда нужно учесть знак, функция
  // * [сложения/вычитания]
  // * перед нормализацией его поставит, а после вернет назад
  int res = S21_CALC_ERR;
  if (s21_is_correct_exp(lower_to_exp)) {
    int lower_from_exp = s21_get_exp(*result);
    // * Спускаем степень таким же образом, но до lower_to_exp + 1,
    // * чтобы достать последнюю цифру
    for (; lower_from_exp > lower_to_exp + 1; --lower_from_exp) {
      // s21_print_decimal(*result);
      // printf(" -> ");
      s21_div_by_ten(result);
      s21_set_exp(result, lower_from_exp - 1);
    }
    res = s21_simple_round(result);
  }
  return res;
}

int s21_simple_round(s21_decimal *a) {
  // * Достаем последнюю цифру, и после деления проверяем, была ли она
  // * достаточно большой, чтобы она повлияла на число
  int last_num = 0, res = S21_OK;
  s21_decimal one = {{1, 0, 0, 0}};
  s21_mod_by_ten(*a, &last_num);
  s21_div_by_ten(a);
  if (last_num >= 5) {
    s21_set_exp(&one, s21_get_exp(*a));
    if (!s21_get_sign(*a)) {
      res = s21_add(*a, one, a);
    } else {
      res = s21_sub(*a, one, a);
    }
  }
  s21_set_exp(a, s21_get_exp(*a) - 1);
  return res;
}
