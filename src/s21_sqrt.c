#include "s21_math.h"

long double s21_sqrt(double x) {
  long double sqrt = 0;
  if (x > 0) {
    sqrt = x;
    for (int i = 0; i < 100; i++) {
      sqrt = (sqrt + x / sqrt) / 2;
    }
  } else if (x < 0) {
    sqrt = S21_NAN;
  }
  return sqrt;
}
