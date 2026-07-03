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

#define Ok_MUL_I32(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= INT32_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= INT32_MAX / (y) : ( \
    (x) > 0 ? (y) >= INT32_MIN / (x) : (x) >= INT32_MIN / (y) \
    ))))

#define Ok_MUL_U32(x, y) \
    ((x) > 0 && (y) > 0 && a > I32_MAX / y)

#define Ok_DIV_I32(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == INT32_MIN && (y) == -1 ? 0 : 1 \
    ))

#define Ok_DIV_U32(x, y) ((y) != 0)

#endif