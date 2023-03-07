#include "s21_math.h"

long double intermediate_pow(double base, int exp) {
  long double int_pow = 1;
  if (base == 1 || exp == 0) {
    int_pow = 1;
  } else if (base == 0) {
    int_pow = 0;
  }
  if (exp > 0 && base != 1 && base != 0) {
    for (int i = 0; i < exp; i++) {
      int_pow = int_pow * base;
    }
  } else if (exp < 0 && base != 1 && base != 0) {
    for (int i = exp; i < 0; i++) {
      int_pow = int_pow / base;
    }
  }
  return int_pow;
}
