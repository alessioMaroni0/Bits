#ifndef CHECKER_H
#define CHECKER_H

#include "../limits/limits.h"

#define OK_SUM_I32(x, y) \
    (!(((y) > 0 && (x) > I32_MAX - (y)) || ((y) < 0 && (x) < I32_MIN - (y))))

#define OK_SUM_U32(x, y) \
    (!((x) > U32_MAX - (y)))

#define OK_SUB_I32(x, y) \
    (!(((y) < 0 && (x) > I32_MAX + (y)) || ((y) > 0 && (x) < I32_MIN + (y))))

#define OK_SUB_U32(x, y) \
    ((x) >= (y))

#endif