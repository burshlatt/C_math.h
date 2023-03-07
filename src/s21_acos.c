#include "s21_math.h"

long double s21_acos(double x) {
  long double acos = 0;
  if (x < -1 || x > 1) {
    acos = S21_NAN;
  } else if (x > 0 && x <= 1) {
    acos = s21_atan(s21_sqrt(1 - intermediate_pow(x, 2)) / x);
  } else if (x > -1 && x < 0) {
    acos = S21_M_PI + s21_atan(s21_sqrt(1 - intermediate_pow(x, 2)) / x);
  } else if (x == -1) {
    acos = S21_M_PI;
  } else if (x == 0) {
    acos = S21_M_PI / 2;
  } else if (x != x) {
    acos = S21_NAN;
  }
  return acos;
}
