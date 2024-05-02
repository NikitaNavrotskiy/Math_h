#include "my_math.h"

int my_abs(int x) {
  int res = x < 0 ? -x : x;
  return res;
}

long double my_fabs(double x) {
  long double res = x < 0.0 ? (long double)(-x) : (long double)x;
  return res;
}

long double my_ceil(double x) {
  long double res;
  if (MY_IS_INF(x) && x > 0)
    res = MY_POS_INF;
  else if (MY_IS_INF(x) && x <= 0)
    res = MY_NEG_INF;
  else if (MY_IS_NAN(x))
    res = my_NaN;
  else if (x >= 0.0)
    res = (long double)(long long)(x + 0.999999);
  else
    res = (long double)(long long)(x);

  return res;
}

long double my_floor(double x) {
  long double res = (long int)x;
  if (MY_IS_INF(x) && x > 0)
    res = MY_POS_INF;
  else if (MY_IS_INF(x) && x <= 0)
    res = MY_NEG_INF;
  else if (MY_IS_NAN(x))
    res = my_NaN;
  else if (x - (int)x < 0)
    res = (long int)x - 1;
  return res;
}

long double my_cos(double x) {
  if (validDouble(x) == 1) {
    return my_NaN;
  }
  return (my_sin(x + MY_PI_2));
}

int validDouble(double x) {
  if (MY_IS_NAN(x))
    return 1;
  else if (MY_IS_INF(x))
    return 1;
  return 0;
}
long double my_sin(double x) {
  if (validDouble(x) == 1) {
    return my_NaN;
  }
  // Корректируем угол x, чтобы он был в интервале [-π, π]
  while (my_fabs(x) - 2 * MY_PI > MY_EPS) {
    x += (2 * MY_PI * x / my_fabs(x)) * -1;
  }

  long double res = 0;
  for (int i = 0; i < 100; i++) {
    res += my_pow(-1, i) * my_pow(x, 1 + 2 * i) / my_factorial(1 + 2 * i);
  }
  return res;
}

long double my_tan(double x) { return my_sin(x) / my_cos(x); }

long double my_log(double x) {
  long double res = 0;

  if (x == 0.0)
    return MY_NEG_INF;
  else if (MY_IS_INF(x) && x > 0)
    return MY_POS_INF;
  else if (MY_IS_INF(x) && x <= 0)
    return my_NaN;
  else if (MY_IS_NAN(x) || x <= 0)
    return my_NaN;
  else {
    for (int i = 0; i < 100; i++) {
      res = res + 2 * (x - my_exp(res)) / (x + my_exp(res));
    }
  }

  return res;
}

long double my_exp(double x) {
  long double tmp = 1;
  long double res = 1;
  if (MY_IS_NAN(x))
    return my_NaN;
  else if (x == MY_POS_INF || x > 710)
    return MY_POS_INF;
  else if (x == MY_NEG_INF)
    return (long double)0;
  else if (x < 0)
    return (long double)(1 / my_exp(-x));
  else {
    for (long int i = 1; tmp > 1e-17; i++) {
      tmp = tmp * x / i;
      res = res + tmp;
    }
  }
  return res;
}

long double my_fmod(double x, double y) {
  long double res;
  if ((MY_IS_INF(x) && MY_IS_INF(y)) || MY_IS_INF(x))
    res = my_NaN;
  else if (MY_IS_INF(y))
    res = x;
  else if (MY_IS_NAN(x) || MY_IS_NAN(y))
    res = my_NaN;
  else
    res = (long double)x - ((long long int)(x / y) * (long double)y);
  return res;
}

long double my_pow(double base, double degree) {
  long double res = 0;
  if (!base && !degree)
    res = 1;
  else if (MY_IS_INF(base) && degree == 0) {
    return (long double)1.0;
  } else if (base == MY_NEG_INF && degree == MY_POS_INF)
    res = MY_POS_INF;
  else if (base == MY_NEG_INF && degree == MY_NEG_INF)
    res = 0;
  else if (base < 0 && degree - (int)degree)
    res = -my_NaN;
  else {
    res = my_exp(degree * my_log(my_fabs(base)));
    if (base < 0 && (int)degree % 2) {
      res *= -1;
    }
  }
  return res;
}

long double my_sqrt(double x) {
  long double result = 0;
  if (x < 0)
    result = my_NaN;
  else
    result = my_pow(x, 0.5);
  return result;
}

long double my_acos(double x) {
  long double res = 0;
  if (x == my_NaN || x == MY_POS_INF || x == MY_NEG_INF || x < -1.0 ||
      x > 1.0) {
    return my_NaN;
  } else if (x == 1.0) {
    return (long double)0;
  } else if (!x) {
    return MY_PI_2;
  }
  if (x > 0) {
    res = my_atan(my_sqrt(1 - x * x) / x);
  } else {
    res = my_atan(my_sqrt(1 - x * x) / x) + MY_PI;
  }

  return res;
}

long double my_asin(double x) {
  if (x == my_NaN || x == MY_POS_INF || x == MY_NEG_INF || x < -1.0 ||
      x > 1.0) {
    return my_NaN;
  } else if (x == 0.0) {
    return (long double)x;
  }

  long double res = (long double)x;

  res = my_atan(x / (my_sqrt(1 - x * x)));
  return res;
}

long double my_atan(double x) {
  long double res = 0;
  if (x == MY_POS_INF) {
    return MY_PI_2;
  } else if (x == MY_NEG_INF) {
    return -MY_PI_2;
  } else if (MY_IS_NAN(x))
    res = my_NaN;
  else if (my_fabs(x) == 1) {
    res = MY_PI_4 * x;
  } else if (my_fabs(x) < 1) {
    for (int i = 0; i < 4999; i++) {
      res += (my_pow(-1, i) * my_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else if (my_fabs(x) > 1) {
    for (int i = 0; i < 4999; i++)
      res += (my_pow(-1, i) * my_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    res = ((MY_PI * my_sqrt(x * x)) / (2 * x)) - res;
  }
  return res;
}

long double my_factorial(double x) {
  long double res = 0;
  if (res < 0)
    res = MY_POS_INF;
  else
    res = (x < 2) ? 1 : x * my_factorial(x - 1);
  return res;
}
