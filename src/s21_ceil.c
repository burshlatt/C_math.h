#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil = S21_NAN;
  if (x > 0 && x - (int)x != 0) {
    ceil = (int)x + 1;
  } else if (x < 0 || x - (int)x == 0) {
    ceil = (int)x;
  }
  if (x == S21_INF) {
    ceil = S21_INF;
  } else if (x == -S21_INF) {
    ceil = -S21_INF;
  }
  if (x == S21_MAXFLOAT) {
    ceil = S21_MAXFLOAT;
  }
  return ceil;
}
