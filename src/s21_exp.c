#include "s21_math.h"

long double s21_exp(double x) {
  long double exp = 1;
  if (x > 0) {
    for (int i = 1; i < 100; i++) {
      exp += intermediate_pow(x, i) / s21_fact(i);
    }
  } else if (x < 0) {
    x = -x;
    for (int i = 1; i < 100; i++) {
      exp += intermediate_pow(x, i) / s21_fact(i);
    }
    exp = 1 / exp;
  }
  if (x != x) {
    exp = S21_NAN;
  }
  return exp;
}
