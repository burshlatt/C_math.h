#include "s21_math.h"

long double s21_tan(double x) {
  long double tan = 0;
  x = s21_fmod(x, S21_M_PI);
  tan = s21_sin(x) / s21_cos(x);
  return tan;
}
