#ifndef MY_MATH_H
#define MY_MATH_H

#include <float.h>

#define my_NaN (0.0 / 0.0)
#define MY_POS_INF (5.0 / 0.0)
#define MY_NEG_INF (-5.0 / 0.0)
#define MY_EPS_9 1e-9
#define MY_EPS 1e-9
#define MY_EXP 2.71828182845904523536028747
#define MY_PI 3.14159265358979323846
#define MY_PI_2 1.570796326794896619231321691639751442
#define MY_PI_4 0.785398163397448309615660845819875721
#define MY_IS_NAN(x) (x != x)
#define MY_IS_INF(x) (x == MY_NEG_INF || x == MY_POS_INF)

int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);
long double my_factorial(double x);
int validDouble(double x);

#endif
