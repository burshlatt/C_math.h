#include "s21_math.h"

long double s21_floor(double x) {
  long double floor = x;
  if (x > 0 || (x < 0 && floor - (int)floor == 0)) {
    floor = (int)x;
  } else if (x < 0 && floor - (int)floor != 0) {
    floor = (int)x - 1;
  }
  if (x == S21_INF) {
    floor = S21_INF;
  } else if (x == -S21_INF) {
    floor = -S21_INF;
  } else if (x == S21_MAXFLOAT) {
    floor = S21_MAXFLOAT;
  }
  return floor;
}
