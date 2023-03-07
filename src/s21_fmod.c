#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double fmod = S21_NAN;
  long double x_copy = x;
  long double y_copy = y;
  if (x < 0 || y < 0) {
    x_copy = s21_fabs(x_copy);
    y_copy = s21_fabs(y_copy);
  }
  if (y != 0) {
    fmod = x_copy - s21_floor(x_copy / y_copy) * y_copy;
  }
  if (x < 0) {
    fmod = -fmod;
  }
  if (y < 0) {
    fmod = s21_fabs(fmod);
  }
  if (y == S21_INF || y == -S21_INF) {
    fmod = 0;
  }
  if (x != x && (y == S21_HUGE_V || y == -S21_HUGE_V)) {
    fmod = S21_NAN;
  }
  return fmod;
}
