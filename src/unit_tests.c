#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abc_test) {
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(20), abs(20));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(0.2), acos(0.2), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(2)), 1);
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(S21_NAN)), 1);
  ck_assert_double_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), 1e-7);
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0), s21_asin(0), 1e-6);
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(-252.568));
  ck_assert_ldouble_nan(s21_asin(555));
  ck_assert_ldouble_nan(s21_asin(sqrt(-1)));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(atan(500.000), s21_atan(500.000), 1e-4);
  ck_assert_ldouble_eq_tol(atan(-1.0 / 0.0), s21_atan(-1.0 / 0.0), 1e-7);
  ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-7);
  ck_assert_ldouble_nan(s21_atan(0.0 / 0.0));
  ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-7);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), 1e-7);
  ck_assert_ldouble_eq_tol(atan(-2.78965), s21_atan(-2.78965), 1e-7);
  ck_assert_ldouble_eq_tol(atan(1), s21_atan(1), 1e-7);
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), 1e-7);
  for (double i = -565.324; i <= 789.532; i += 50.6235) {
    ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_ceil_test) {
  for (double i = -M_PI / 2; i <= M_PI / 2; i += 0.25) {
    ck_assert_double_eq(ceil(i), s21_ceil(i));
  }
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(INFINITY));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
  ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
  ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
  ck_assert_double_eq(ceil(S21_MAXFLOAT), s21_ceil(S21_MAXFLOAT));
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
  ck_assert_double_eq(ceil(7), s21_ceil(7));
  ck_assert_double_eq(ceil(0), s21_ceil(0));
  ck_assert_double_eq(ceil(-0.0), s21_ceil(-0.0));
}
END_TEST

START_TEST(s21_cos_test) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_M_PI; k > -2 * S21_M_PI; k -= S21_M_PI / 9) {
      ck_assert_ldouble_eq_tol(cos(k + R * S21_M_PI), s21_cos(k + R * S21_M_PI),
                               EPS);
    }
  }
  for (int R = 20; R >= -20; R -= 2) {
    for (double k = 2 * S21_M_PI; k > -2 * S21_M_PI; k -= S21_M_PI / 6) {
      ck_assert_ldouble_eq_tol(cos(k + R * S21_M_PI), s21_cos(k + R * S21_M_PI),
                               EPS);
    }
  }
  ck_assert_ldouble_eq_tol(cos(0.0), s21_cos(0.0), EPS);
  ck_assert_ldouble_eq_tol(cos(S21_M_PI), s21_cos(S21_M_PI), EPS);
  ck_assert_ldouble_eq_tol(cos(3 * S21_M_PI), s21_cos(3 * S21_M_PI), EPS);
  ck_assert_ldouble_eq_tol(cos(2 * S21_M_PI), s21_cos(2 * S21_M_PI), EPS);
  ck_assert_ldouble_eq_tol(cos(-2 * S21_M_PI), s21_cos(-2 * S21_M_PI), EPS);
  ck_assert_ldouble_eq_tol(cos(-S21_M_PI), s21_cos(-S21_M_PI), EPS);
  ck_assert_ldouble_eq_tol(cos(-0.0), s21_cos(-0.0), EPS);
  ck_assert_ldouble_eq_tol(cos(12415.12415), s21_cos(12415.12415), EPS);
  ck_assert_ldouble_eq_tol(cos(-124345.9999), s21_cos(-124345.9999), EPS);
  ck_assert_ldouble_eq_tol(cos(11.010101), s21_cos(11.010101), EPS);
  ck_assert_ldouble_nan(s21_cos(S21_HUGE_V));
  ck_assert_ldouble_nan(s21_cos(-S21_HUGE_V));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(s21_cos(-S21_HUGE_V));
  ck_assert_double_nan(s21_cos(S21_HUGE_V));
  ck_assert_double_nan(s21_cos(-0.0 / 0.0));
}
END_TEST

START_TEST(s21_exp_test) {
  double number = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = -0.0;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = 1.0;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = 1.1111;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = -1.1111;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = 10;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = -10;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = -1.9999999;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = 1.9999999;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = -0.9999999;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  number = 0.9999999;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_double_nan(exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(S21_HUGE_V));
  ck_assert_double_infinite(exp(S21_HUGE_V));
  ck_assert_ldouble_eq(s21_exp(-S21_HUGE_V), 0.0);
  ck_assert_ldouble_eq(exp(-S21_HUGE_V), 0.0);
  number = 5.5;
  ck_assert_ldouble_eq_tol(s21_exp(number), (long double)exp(number), EPS);
  ck_assert_double_eq_tol(s21_exp(3.3333), s21_exp(3.3333), EPS);
  ck_assert_double_eq_tol(s21_exp(-5.5), s21_exp(-5.5), EPS);
  ck_assert_double_eq(s21_exp(4566.7899), s21_exp(4566.7899));
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_double_eq_tol(exp(0.4564), s21_exp(0.4564), EPS);
  ck_assert_double_eq(exp(0), s21_exp(0));
  ck_assert_double_eq_tol(exp(-45.11), s21_exp(-45.11), EPS);
  ck_assert_double_eq_tol(exp(-1), s21_exp(-1), EPS);
  ck_assert_double_eq_tol(exp(-0.000001), s21_exp(-0.000001), EPS);
}
END_TEST

START_TEST(s21_fabs_test) {
  double number = 0.0;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -1.0;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = 1.0;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = 33.43543;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -33.345345;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = S21_MAXFLOAT;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -S21_MAXFLOAT;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -55.55;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -0.0;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = 0.0000000000001;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  number = -0.000000000001;
  ck_assert_ldouble_eq(s21_fabs(number), (long double)fabs(number));
  ck_assert_ldouble_nan(fabs(sqrt(-1)));
  ck_assert_ldouble_nan(s21_fabs(sqrt(-1)));
  ck_assert_ldouble_infinite(fabs(S21_HUGE_V));
  ck_assert_ldouble_infinite(s21_fabs(S21_HUGE_V));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-S21_HUGE_V));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
  ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
  ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
  ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(S21_HUGE_V));
  ck_assert_double_eq(fabs(0.000213), s21_fabs(0.000213));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_double_eq(floor(INFINITY), s21_floor(S21_HUGE_V));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(-S21_HUGE_V));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_int_eq(floor(-7.0), s21_floor(-7.0));
  ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
  ck_assert_double_eq(floor(123.02), s21_floor(123.02));
  ck_assert_double_eq(floor(S21_MAXFLOAT), s21_floor(S21_MAXFLOAT));
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
  ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
  ck_assert_double_eq(floor(7), s21_floor(7));
  ck_assert_double_eq(floor(0), s21_floor(0));
  ck_assert_double_eq(floor(0.0), s21_floor(0.0));
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_ldouble_eq_tol(fmod(12345, 12.234), s21_fmod(12345, 12.234), EPS);
  ck_assert_ldouble_eq_tol(fmod(12345, 12.234), s21_fmod(12345, 12.234), EPS);
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
  ck_assert_ldouble_eq_tol(fmod(-2834.242, 11.2), s21_fmod(-2834.242, 11.2),
                           EPS);
  ck_assert_ldouble_eq_tol(fmod(4, 2), s21_fmod(4, 2), EPS);
  ck_assert_ldouble_nan(s21_fmod(-10, 0));
  ck_assert_ldouble_eq_tol(fmod(121, 11.0001), s21_fmod(121, 11.0001), EPS);
  ck_assert_ldouble_eq_tol(fmod(1244.12414, 1244), s21_fmod(1244.12414, 1244),
                           EPS);
  ck_assert_ldouble_eq_tol(fmod(1.21, -0.99999), s21_fmod(1.21, -0.99999), EPS);
  ck_assert_ldouble_eq_tol(fmod(1.21, 124214141), s21_fmod(1.21, 124214141),
                           EPS);
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_nan(fmod(S21_HUGE_V, -1));
  ck_assert_double_nan(s21_fmod(S21_HUGE_V, -1));
  ck_assert_double_eq(fmod(0, S21_HUGE_V), s21_fmod(0, S21_HUGE_V));
  ck_assert_double_nan(s21_fmod(0, S21_NAN));
  ck_assert_double_nan(fmod(0, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_HUGE_V));
  ck_assert_double_nan(s21_fmod(S21_HUGE_V, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, -S21_HUGE_V));
  ck_assert_double_nan(s21_fmod(-S21_HUGE_V, S21_NAN));
  ck_assert_double_nan(fmod(S21_NAN, S21_HUGE_V));
  ck_assert_double_nan(fmod(S21_HUGE_V, S21_NAN));
  ck_assert_double_nan(fmod(S21_NAN, -S21_HUGE_V));
  ck_assert_double_nan(fmod(-S21_HUGE_V, S21_NAN));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_double_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_double_eq_tol(s21_log(10), log(10), 1e-6);
  ck_assert_double_eq_tol(s21_log(100), log(100), 1e-6);
  ck_assert_double_eq_tol(s21_log(0x14BD), log(0x14BD), 1e-6);
  ck_assert_int_eq(isinf(s21_log(0)), 1);
  ck_assert_double_eq_tol(s21_log(12), log(12), 1e-6);
  ck_assert_int_eq(isnan(s21_log(-1)), 1);
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_double_eq_tol(s21_pow(1, 2), pow(1, 2), 1e-6);
  ck_assert_double_eq_tol(s21_pow(0, 2), pow(0, 2), 1e-6);
  ck_assert_double_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_double_eq_tol(s21_pow(12, 0), pow(12, 0), 1e-6);
  ck_assert_double_eq_tol(s21_pow(-1, 2), pow(-1, 2), 1e-6);
  ck_assert_double_eq_tol(s21_pow(-15, 3), pow(-15, 3), 1e-6);
  ck_assert_double_eq_tol(s21_pow(-15, -3), pow(-15, -3), 1e-6);
  ck_assert_double_eq_tol(s21_pow(15, -3), pow(15, -3), 1e-6);
  ck_assert_double_eq_tol(s21_pow(15, -3.45), pow(15, -3.45), 1e-6);
  ck_assert_int_eq(isnan(s21_pow(-15, 3.45)), 1);
  ck_assert_int_eq(isnan(s21_pow(-15, -3.45)), 1);
  ck_assert_double_eq_tol(s21_pow(23, 10), pow(23, 10), 1e+0);
}
END_TEST

START_TEST(s21_sin_test) {
  ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_double_eq_tol(s21_sin(10), sin(10), 1e-6);
  ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_double_eq_tol(s21_sin(0x14BD), sin(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_sin(145), sin(145), 1e-6);
  ck_assert_double_eq_tol(s21_sin(16), sin(16), 1e-6);
  ck_assert_double_eq_tol(s21_sin(5), sin(5), 1e-6);
  ck_assert_double_eq_tol(s21_sin(7), sin(7), 1e-6);
  ck_assert_double_eq_tol(s21_sin(-16), sin(-16), 1e-6);
  ck_assert_double_eq_tol(s21_sin(145986), sin(145986), 1e-6);
  ck_assert_int_eq(isnan(s21_sin(S21_NAN)), 1);
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_double_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(10), sqrt(10), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(178), sqrt(178), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(12), sqrt(12), 1e-6);
  ck_assert_int_eq(isnan(s21_sqrt(-1)), 1);
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_double_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_double_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_double_eq_tol(s21_tan(10), tan(10), 1e-6);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_double_eq_tol(s21_tan(0x14BD), tan(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_tan(145), tan(145), 1e-6);
  ck_assert_double_eq_tol(s21_tan(16), tan(16), 1e-6);
  ck_assert_double_eq_tol(s21_tan(-16), tan(-16), 1e-6);
  ck_assert_int_eq(isnan(s21_tan(S21_NAN)), 1);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *runner = srunner_create(s1);

  int failed = 0;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_abc_test);
  tcase_add_test(tc1_1, s21_acos_test);
  tcase_add_test(tc1_1, s21_asin_test);
  tcase_add_test(tc1_1, s21_atan_test);
  tcase_add_test(tc1_1, s21_ceil_test);
  tcase_add_test(tc1_1, s21_cos_test);
  tcase_add_test(tc1_1, s21_exp_test);
  tcase_add_test(tc1_1, s21_fabs_test);
  tcase_add_test(tc1_1, s21_floor_test);
  tcase_add_test(tc1_1, s21_fmod_test);
  tcase_add_test(tc1_1, s21_log_test);
  tcase_add_test(tc1_1, s21_pow_test);
  tcase_add_test(tc1_1, s21_sin_test);
  tcase_add_test(tc1_1, s21_sqrt_test);
  tcase_add_test(tc1_1, s21_tan_test);

  srunner_run_all(runner, CK_ENV);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed == 0 ? 0 : 1;
}
