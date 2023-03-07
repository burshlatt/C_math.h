#include "s21_math.h"

long double s21_sin(double x) {
  long double sin = 0;
  x = s21_fmod(x, S21_M_PI * 2);
  for (int i = 0; i < 1000; i++) {
    sin += intermediate_pow(-1, i) *
           (intermediate_pow(x, 2 * i + 1) / s21_fact(2 * i + 1));
  }
  return sin;
}
