#include "lexem.h"

namespace s21 {
Lexeme::Lexeme(double value, int priority, LexemeType type)
    : value(value), priority(priority), type(type) {}
}  // namespace s21
