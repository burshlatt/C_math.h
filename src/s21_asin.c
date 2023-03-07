#include "s21_math.h"

long double s21_asin(double x) {
  long double asin = x;
  if (x > -1 && x < 1) {
    asin = s21_atan(x / s21_sqrt(1 - x * x));
  } else if (x == 1) {
    asin = S21_M_PI / 2;
  } else if (x == -1) {
    asin = -1 * S21_M_PI / 2;
  } else {
    asin = S21_NAN;
  }
  return asin;
}
