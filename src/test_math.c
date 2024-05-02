#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"

START_TEST(test_my_abs) {
  ck_assert_int_eq(my_abs(3), abs(3));
  ck_assert_int_eq(my_abs(-3), abs(-3));
  ck_assert_int_eq(my_abs(15), abs(15));
  ck_assert_int_eq(my_abs(-17), abs(-17));
  ck_assert_int_eq(my_abs(0), abs(0));
  ck_assert_int_eq(my_abs(9), abs(9));
  ck_assert_int_eq(my_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(my_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(my_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(test_my_fabs) {
  ck_assert_ldouble_eq(my_fabs(1.234), fabsl(1.234));
  ck_assert_ldouble_eq(my_fabs(-13.987), fabsl(-13.987));
  ck_assert_ldouble_eq(my_fabs(0.0), fabsl(0.0));
  ck_assert_ldouble_eq(my_fabs(INFINITY), fabsl(INFINITY));
  ck_assert_int_eq(my_fabs(NAN) == NAN, fabsl(NAN) == NAN);
  ck_assert_ldouble_eq(my_fabs(-INFINITY), fabsl(-INFINITY));
}
END_TEST

START_TEST(test_my_ceil) {
  ck_assert_ldouble_eq(my_ceil(1.2222), ceill(1.2222));
  ck_assert_ldouble_eq(my_ceil(-5.4444), ceill(-5.4444));
  ck_assert_ldouble_eq(my_ceil(12.7222), ceill(12.7222));
  ck_assert_ldouble_eq(my_ceil(0.0), ceill(0.0));
  ck_assert_double_eq(my_ceil(INFINITY), ceill(INFINITY));
  ck_assert_double_nan(my_ceil(NAN));
  ck_assert_double_eq(my_ceil(-INFINITY), ceill(-INFINITY));
}
END_TEST

START_TEST(test_my_floor) {
  ck_assert_ldouble_eq(my_floor(1.9999), floorl(1.9999));
  ck_assert_ldouble_eq(my_floor(-5.4444), floorl(-5.4444));
  ck_assert_ldouble_eq(my_floor(12.7226), floorl(12.7226));
  ck_assert_ldouble_eq(my_floor(0.0), floorl(0.0));
  ck_assert_double_eq(my_floor(INFINITY), floorl(INFINITY));
  ck_assert_double_nan(my_floor(NAN));
  ck_assert_double_eq(my_floor(-INFINITY), floorl(-INFINITY));
}
END_TEST

START_TEST(test_my_cos) {
  ck_assert_ldouble_eq_tol(my_cos(-0.99991), cosl(-0.99991), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-0.55321), cosl(-0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0.99991), cosl(0.99991), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0.55321), cosl(0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(5.12345), cosl(5.12345), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-1.12345), cosl(-1.12345), 1e-6);
  ck_assert_int_eq(my_cos(INFINITY) == NAN, cosl(INFINITY) == NAN);
  ck_assert_int_eq(my_cos(-INFINITY) == NAN, cosl(-INFINITY) == NAN);
  ck_assert_int_eq(my_cos(NAN) == NAN, cosl(NAN) == NAN);
}
END_TEST

START_TEST(test_my_sin) {
  ck_assert_ldouble_eq_tol(my_sin(-0.99991), sinl(-0.99991), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-0.55321), sinl(-0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0.99991), sinl(0.99991), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0.55321), sinl(0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(5.12345), sinl(5.12345), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-1.12345), sinl(-1.12345), 1e-6);
  ck_assert_int_eq(my_sin(INFINITY) == NAN, sinl(INFINITY) == NAN);
  ck_assert_int_eq(my_sin(-INFINITY) == NAN, sinl(-INFINITY) == NAN);
  ck_assert_int_eq(my_sin(NAN) == NAN, sinl(NAN) == NAN);
}
END_TEST

START_TEST(test_my_tan) {
  ck_assert_ldouble_eq_tol(my_tan(998.55321), tanl(998.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-0.55321), tanl(-0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-5.12345), tanl(-5.12345), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(0.55321), tanl(0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(5.12345), tanl(5.12345), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-1.12345), tanl(-1.12345), 1e-6);
  ck_assert_int_eq(my_tan(INFINITY) == NAN, tanl(INFINITY) == NAN);
  ck_assert_int_eq(my_tan(-INFINITY) == NAN, tanl(-INFINITY) == NAN);
  ck_assert_int_eq(my_tan(NAN) == NAN, tanl(NAN) == NAN);
}
END_TEST

START_TEST(test_my_log) {
  ck_assert_int_eq(my_log(0.0) == -INFINITY, logl(0.0) == -INFINITY);
  ck_assert_ldouble_eq_tol(my_log(866.55321), logl(866.55321), 1e-6);
  ck_assert_int_eq(my_log(-0.321) == NAN, logl(-0.321) == NAN);
  ck_assert_ldouble_eq_tol(my_log(1.546), logl(1.546), 1e-6);
  ck_assert_int_eq(my_log(INFINITY) == NAN, logl(INFINITY) == NAN);
  ck_assert_int_eq(my_log(-INFINITY) == NAN, logl(-INFINITY) == NAN);
  ck_assert_int_eq(my_log(NAN) == NAN, logl(NAN) == NAN);
  ;
}
END_TEST

START_TEST(test_my_exp) {
  ck_assert_msg(fabsl(my_exp(0.55321) - expl(0.55321)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_exp(-2.12345) - expl(-2.12345)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_exp(10.55321) - expl(10.55321)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_exp(-10.12345) - expl(-10.12345)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_exp(0.0) - expl(0.0)) < 1e-6, "Values are not equal");
  ck_assert_double_eq(my_exp(INFINITY), expl(INFINITY));
  ck_assert_int_eq(my_exp(NAN) == NAN, expl(NAN) == NAN);
  ck_assert_double_eq(my_exp(-INFINITY), expl(-INFINITY));
}
END_TEST

START_TEST(test_my_fmod) {
  ck_assert_msg(fabsl(my_fmod(0.55321, 1.234) - fmodl(0.55321, 1.234)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_fmod(-2.12345, 1.234) - fmodl(-2.12345, 1.234)) < 1e-6,
                "Values are not equal");
  ck_assert_int_eq(my_fmod(INFINITY, 0) == NAN, fmodl(INFINITY, 0) == NAN);
  ck_assert_ldouble_eq(my_fmod(0.68, INFINITY), fmodl(0.68, INFINITY));
  ck_assert_int_eq(my_fmod(-INFINITY, 0) == NAN, fmodl(-INFINITY, 0) == NAN);
  ck_assert_ldouble_eq(my_fmod(0.68, -INFINITY), fmodl(0.68, -INFINITY));
  ck_assert_int_eq(my_fmod(INFINITY, 0) == NAN, fmodl(INFINITY, 0) == NAN);
  ck_assert_ldouble_eq(my_fmod(0, INFINITY), fmodl(0, INFINITY));
  ck_assert_int_eq(my_fmod(-INFINITY, 0) == NAN, fmodl(-INFINITY, 0) == NAN);
  ck_assert_ldouble_eq(my_fmod(0, -INFINITY), fmodl(0, -INFINITY));
  ck_assert_int_eq(my_fmod(0.68, NAN) == NAN, fmodl(0.68, NAN) == NAN);
  ck_assert_int_eq(my_fmod(NAN, 0.68) == NAN, fmodl(NAN, 0.68) == NAN);
  ck_assert_int_eq(my_fmod(-INFINITY, INFINITY) == NAN,
                   fmodl(-INFINITY, INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(INFINITY, -INFINITY) == NAN,
                   fmodl(INFINITY, -INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(INFINITY, INFINITY) == NAN,
                   fmodl(INFINITY, INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(-INFINITY, -INFINITY) == NAN,
                   fmodl(-INFINITY, -INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(INFINITY, NAN) == NAN, fmodl(INFINITY, NAN) == NAN);
  ck_assert_int_eq(my_fmod(NAN, INFINITY) == NAN, fmodl(NAN, INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(-INFINITY, NAN) == NAN,
                   fmodl(-INFINITY, NAN) == NAN);
  ck_assert_int_eq(my_fmod(NAN, -INFINITY) == NAN,
                   fmodl(NAN, -INFINITY) == NAN);
  ck_assert_int_eq(my_fmod(NAN, NAN) == NAN, fmodl(NAN, NAN) == NAN);
}
END_TEST

START_TEST(test_my_pow) {
  ck_assert_int_eq(my_pow(-20, 0.4) == NAN, pow(-20, 0.4) == NAN);
  ck_assert_double_eq_tol(my_pow(35.5, 2.4), pow(35.5, 2.4), 0.000001);
  ck_assert_double_eq_tol(my_pow(0, 0.4), pow(0, 0.4), 0.000001);
  ck_assert_double_eq_tol(my_pow(20, 0.4), pow(20, 0.4), 0.000001);
  ck_assert_double_eq_tol(my_pow(5, 0.4), pow(5, 0.4), 0.000001);
  ck_assert_int_eq(my_pow(-20, 0.4) == NAN, pow(-20, 0.4) == NAN);

  ck_assert_ldouble_eq(my_pow(INFINITY, 0), pow(INFINITY, 0));
  ck_assert_ldouble_eq(my_pow(0.68, INFINITY), pow(0.68, INFINITY));
  ck_assert_ldouble_eq(my_pow(-INFINITY, 0), pow(-INFINITY, 0));
  ck_assert_ldouble_eq(my_pow(0.68, -INFINITY), pow(0, -INFINITY));
  ck_assert_ldouble_eq(my_pow(INFINITY, 0), pow(INFINITY, 0));
  ck_assert_ldouble_eq(my_pow(0, INFINITY), pow(0, INFINITY));
  ck_assert_ldouble_eq(my_pow(-INFINITY, 0), pow(-INFINITY, 0));
  ck_assert_ldouble_eq(my_pow(0, -INFINITY), pow(0, -INFINITY));
  ck_assert_int_eq(my_pow(0.68, NAN) == NAN, pow(0.68, NAN) == NAN);
  ck_assert_int_eq(my_pow(NAN, 0.68) == NAN, pow(NAN, 0.68) == NAN);
  ck_assert_int_eq(my_pow(-INFINITY, INFINITY) == NAN,
                   pow(-INFINITY, INFINITY) == NAN);
  ck_assert_int_eq(my_pow(INFINITY, -INFINITY) == NAN,
                   pow(INFINITY, -INFINITY) == NAN);
  ck_assert_int_eq(my_pow(INFINITY, INFINITY) == NAN,
                   pow(INFINITY, INFINITY) == NAN);
  ck_assert_int_eq(my_pow(-INFINITY, -INFINITY) == NAN,
                   pow(-INFINITY, -INFINITY) == NAN);
  ck_assert_int_eq(my_pow(INFINITY, NAN) == NAN, pow(INFINITY, NAN) == NAN);
  ck_assert_int_eq(my_pow(NAN, INFINITY) == NAN, pow(NAN, INFINITY) == NAN);
  ck_assert_int_eq(my_pow(-INFINITY, NAN) == NAN, pow(-INFINITY, NAN) == NAN);
  ck_assert_int_eq(my_pow(NAN, -INFINITY) == NAN, pow(NAN, -INFINITY) == NAN);
  ck_assert_int_eq(my_pow(NAN, NAN) == NAN, pow(NAN, NAN) == NAN);
}
END_TEST

START_TEST(test_my_sqrt) {
  ck_assert_ldouble_eq_tol(my_sqrt(0.55321), sqrtl(0.55321), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(0.0), sqrtl(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(363.55321), sqrtl(363.55321), 1e-6);
  ck_assert_int_eq(my_sqrt(-2.12345) == NAN, sqrtl(-2.12345) == NAN);
  ck_assert_double_eq(my_sqrt(INFINITY), sqrtl(INFINITY));
  ck_assert_int_eq(my_sqrt(NAN) == NAN, sqrtl(NAN) == NAN);
  ck_assert_int_eq(my_sqrt(-INFINITY) == NAN, sqrtl(-INFINITY) == NAN);
}
END_TEST

START_TEST(test_my_acos) {
  ck_assert_msg(fabsl(my_acos(0.55) - acosl(0.55)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_acos(0.9876) - acosl(0.9876)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_acos(-0.241) - acosl(-0.241)) < 1e-6,
                "Values are not equal");
  ck_assert_int_eq(my_acos(1.5) == NAN, acosl(1.5) == NAN);
  ck_assert_int_eq(my_acos(NAN) == NAN, acosl(NAN) == NAN);
  ck_assert_int_eq(my_acos(-INFINITY) == NAN, acosl(-INFINITY) == NAN);
  ck_assert_int_eq(my_acos(INFINITY) == NAN, acosl(INFINITY) == NAN);
}
END_TEST

START_TEST(test_my_asin) {
  ck_assert_msg(fabsl(my_asin(0.55) - asinl(0.55)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_asin(0.9876) - asinl(0.9876)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_asin(-0.241) - asinl(-0.241)) < 1e-6,
                "Values are not equal");
  ck_assert_int_eq(my_asin(1.5) == NAN, asinl(1.5) == NAN);
  ck_assert_int_eq(my_asin(NAN) == NAN, asinl(NAN) == NAN);
  ck_assert_int_eq(my_asin(-INFINITY) == NAN, asinl(-INFINITY) == NAN);
  ck_assert_int_eq(my_asin(INFINITY) == NAN, asinl(INFINITY) == NAN);
}
END_TEST

START_TEST(test_my_atan) {
  ck_assert_msg(fabsl(my_atan(0.55321) - atanl(0.55321)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(-0.321) - atanl(-0.321)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(561.546) - atanl(561.546)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(-INFINITY) - atanl(-INFINITY)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(INFINITY) - atanl(INFINITY)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(-561.546) - atanl(-561.546)) < 1e-6,
                "Values are not equal");
  ck_assert_msg(fabsl(my_atan(0.0) - atanl(0.0)) < 1e-6,
                "Values are not equal");
  ck_assert_int_eq(my_atan(NAN) == NAN, atanl(NAN) == NAN);
}
END_TEST

int main(void) {
  Suite *s;
  TCase *tc;
  SRunner *sr;

  s = suite_create("MathFunctions");
  tc = tcase_create("MathTests");
  tcase_add_test(tc, test_my_abs);
  tcase_add_test(tc, test_my_fabs);
  tcase_add_test(tc, test_my_ceil);
  tcase_add_test(tc, test_my_floor);
  tcase_add_test(tc, test_my_cos);
  tcase_add_test(tc, test_my_sin);
  tcase_add_test(tc, test_my_tan);
  tcase_add_test(tc, test_my_log);
  tcase_add_test(tc, test_my_exp);
  tcase_add_test(tc, test_my_fmod);
  tcase_add_test(tc, test_my_pow);
  tcase_add_test(tc, test_my_sqrt);
  tcase_add_test(tc, test_my_acos);
  tcase_add_test(tc, test_my_asin);
  tcase_add_test(tc, test_my_atan);

  suite_add_tcase(s, tc);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}
