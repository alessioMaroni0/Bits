#ifndef CHECKER_H
#define CHECKER_H

#define OK_SUM_I32(x, y) \
    (!(((y) > 0 && (x) > INT_MAX - (y)) || ((y) < 0 && (x) < INT_MIN - (y))))

#define OK_SUM_U32(x, y) \
    (!((x) > UINT_MAX - (y)))

#define OK_SUB_I32(x, y) \
    (!(((y) < 0 && (x) > INT_MAX + (y)) || ((y) > 0 && (x) < INT_MIN + (y))))

#define OK_SUB_U32(x, y) \
    ((x) >= (y))

#endif