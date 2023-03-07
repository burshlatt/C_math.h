#include "s21_math.h"

long double s21_log(double x) {
  long double log = 0;
  int count_of_power = 0;
  if (x == 0) {
    log = -S21_INF;
  } else if (x < 0) {
    log = S21_NAN;
  } else if (x > 0) {
    while (x >= S21_E) {
      x = x / S21_E;
      count_of_power++;
    }
    for (int i = 0; i < 100; i++) {
      log = log + 2 * (x - s21_exp(log)) / (x + s21_exp(log));
    }
    log = log + count_of_power;
  }
  return log;
}
