#include "s21_math.h"

int8_t s21_is_zero(double x) { return s21_fabs(x) < S21_EPS * S21_EPS; }

double decrease_in_the_number(double x) {
  return (x > 2 * S21_2PI || x < -2 * S21_2PI) ? s21_fmod(x, 2 * S21_2PI) : x;
}

long double s21_factorial(int x) {
  long double result = 0.0;
  if (x < 0) {
    result = 0.;
  } else if (x == 0 || x == 1) {
    result = 1.;
  } else {
    result = x * s21_factorial(x - 1);
  }
  return result;
}

long double s21_acos(double x) {
  double res = (S21_MATH_PI / 2) - s21_asin(x);
  return res;
}

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_sin(double x) {
  long double result = 0, y = 1;
  if (x == S21_INFINITY || x == -S21_INFINITY) {
    result = S21_NAN;
  } else if (x != x) {
    result = S21_NAN;
  } else {
    x = decrease_in_the_number(x);
    result = x;
    for (int i = 1; s21_fabs(y) > S21_EPS; i++) {
      y = s21_pow(-1, i) * s21_pow(x, 1 + 2 * i) / s21_factorial(1 + 2 * i);
      result += y;
    }
  }
  return result;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_cos(double x) {
  long double res = 1, y = 1;
  if (x == S21_INFINITY || x == -S21_INFINITY) {
    res = S21_NAN;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    x = decrease_in_the_number(x);
    for (int i = 1; s21_fabs(y) > S21_EPS; i++) {
      y = s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factorial(2 * i);
      res += y;
    }
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (x != x || y != y || x == S21_INFINITY || x == -S21_INFINITY) {
    res = S21_NAN;
  } else if (y == S21_INFINITY || x == -S21_INFINITY) {
    res = x;
  } else {
    res = x;
    y = s21_fabs(y);
    if (x > 0) {
      while (res >= y) {
        res -= y;
      }
    } else {
      while (res <= -y) {
        res += y;
      }
    }
  }
  return res;
}

long double s21_fabs(double x) {
  long double res = 0;
  if (x != x) {
    res = S21_NAN;
  } else {
    res = (x < 0) ? -x : x;
  }
  return res;
}
long double s21_asin(double x) {
  long double res = x;
  if (x > 1 || x < -1) {
    res = S21_NAN;
  } else if (x == 1) {
    res = S21_MATH_PI / 2;
  } else if (x == -1) {
    res = -(S21_MATH_PI / 2);
  } else {
    long int n = 1;
    long double term = x;
    while (!(s21_is_zero(term))) {
      term *= ((x * x) * (2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1));
      res += term;
      n++;
    }
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 1;
  double new_root = S21_DBL_MAX;
  do {
    new_root = (res + x / res) / 2;
    if (s21_fabs(res - new_root) < S21_EPS)
      break;
    else
      res = new_root;
  } while (!(s21_fabs(res - new_root) > S21_EPS));

  return res;
}

long double s21_atan(double x) {
  int8_t sign = 1;
  if (x <= S21_EPS) {
    x *= -1;
    sign = -1;
  }
  long double atan = 0.0;

  if (s21_fabs(x) > 1e-4) {
    atan = s21_acos(1 / s21_sqrt(1 + x * x));
  } else if (s21_fabs(x) <= 1e-4)
    atan = x;
  atan *= (double)sign;

  return atan;
}

long double s21_ceil(double x) {
  int res = x;
  if (x - res && x > 0.) return (long double)(res + 1);
  return (long double)res;
}

long double s21_floor(double x) {
  int res = x;
  if (x - res && x < 0.) return (long double)(res - 1);
  return (long double)res;
}

long double s21_exp(double x) {
  int flag = 0;
  if (x < 0) {
    x = -x;
    flag = 1;
  }
  long double res = 1.0;
  int n = 1;
  long double el = x;

  while (el > S21_EPS) {
    if (el == S21_INFINITY) break;
    res += el;
    el *= (x / ++n);
  }

  res = (double)res;

  return (flag) ? 1 / (long double)res : (long double)res;
}

long double s21_log(double x) {
  long double ans = 0.0;

  if (x < 0) {
    ans = S21_NAN;
  } else if (x < 1) {
    long double alpha = (x - 1) / (x + 1);
    ans = alpha;
    long double save = ans * alpha * alpha;

    for (int i = 2; i <= INT16_MAX; i++) {
      ans += (1.0 / (2 * i - 1)) * save;
      save = save * alpha * alpha;
    }

    ans = (double)ans;

    ans = (x > 0) ? (long double)(2.0 * ans) : S21_INFINITY;
  } else {
    int cnt = 0;
    while (x > S21_MATH_E) {
      x /= S21_MATH_E;
      cnt++;
    }

    long double prev = x - 1.0;
    ans = prev;

    do {
      prev = ans;
      long double exp_val = s21_exp(prev);
      ans = prev + 2 * ((x - exp_val) / (x + exp_val));
    } while (prev - ans > S21_EPS);

    ans = (double)ans;

    ans = (long double)ans + cnt;
  }

  return ans;
}

long double s21_pow(double base, double exp) {
  long double ans = 0.0;
  if (exp == (int)exp) {
    if (exp < 0) {
      base = 1 / base;
      exp = -exp;
    }
    ans = 1;
    for (float i = 0; i < exp; i++) {
      ans *= base;
    }
  } else if (base < 0) {
    ans = S21_NAN;
  } else if (base == 0) {
    if (exp < 0) {
      ans = S21_INFINITY;
    } else if (exp > 0) {
      ans = 0;
    } else {
      ans = 1;
    }
  } else {
    ans = s21_exp(exp * s21_log(base));
  }

  ans = (double)ans;

  return (long double)ans;
}
