#include "s21_math.h"

long double s21_cos(double x) {
  long double cos = 0;
  int prefix = 1;
  x = s21_fmod(x, S21_M_PI * 2);
  for (int i = 0; i < 1000; i += 2) {
    cos += prefix * (intermediate_pow(x, i) / s21_fact(i));
    prefix = -prefix;
  }
  return cos;
}
