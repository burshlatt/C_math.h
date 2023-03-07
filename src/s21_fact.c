#include "s21_math.h"

long double s21_fact(double x) {
  long double fact = 1;
  for (int i = 1; i <= x; i++) {
    fact *= i;
  }
  return fact;
}
