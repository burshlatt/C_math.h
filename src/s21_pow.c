#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double pow = 0;
  if (base == 1 || exp == 0) {
    pow = 1;
  } else if (base == 0) {
    pow = 0;
  } else if (base > 0) {
    pow = s21_exp(exp * s21_log(base));
  } else if (base < 0 && exp - (int)exp == 0) {
    base = -base;
    pow = s21_exp(exp * s21_log(base));
    if (s21_fmod(exp, 2) != 0) {
      pow = -pow;
    }
  }
  if (base < 0 && exp - (int)exp != 0) {
    pow = S21_NAN;
  }
  return pow;
}
