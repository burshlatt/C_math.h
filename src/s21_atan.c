#include "s21_math.h"

long double s21_atan(double x) {
  long double atan = 0;
  if (x > -1 && x < 1) {
    for (int i = 1; i < 1000; i++) {
      atan += (intermediate_pow(-1, i - 1) * intermediate_pow(x, 2 * i - 1)) /
              (2 * i - 1);
    }
  } else if (s21_fabs(x) > 1) {
    for (int i = 0; i < 1000; i++) {
      atan += intermediate_pow(-1, i) * intermediate_pow(x, -1 - (2 * i)) /
              (1 + (2 * i));
    }
    atan = S21_M_PI * s21_sqrt(x * x) / (2 * x) - atan;
  } else if (x == 1) {
    atan = S21_M_PI / 4;
  } else if (x == -1) {
    atan = -1 * S21_M_PI / 4;
  } else if (x != x) {
    atan = S21_NAN;
  }
  if (x == S21_INF) {
    atan = S21_M_PI / 2;
  } else if (x == -S21_INF) {
    atan = -S21_M_PI / 2;
  }
  return atan;
}
