#ifndef BITS_H
#define BITS_H

#define UINT_MAX (~0U)
#define INT_MAX (int)(UINT_MAX >> 1)
#define INT_MIN (-INT_MAX - 1)

#define OK_SUM_I32(x, y) \
    (!(((y) > 0 && (x) > INT_MAX - (y)) || ((y) < 0 && (x) < INT_MIN - (y))))

#define OK_SUM_U32(x, y) \
    (!((x) > UINT_MAX - (y)))

#define OK_SUB_I32(x, y) \
    (!(((y) < 0 && (x) > INT_MAX + (y)) || ((y) > 0 && (x) < INT_MIN + (y))))

#define OK_SUB_U32(x, y) \
    ((x) >= (y))

#endif