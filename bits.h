#ifndef BITS_H
#define BITS_H

#define UINT_MAX (~0U)
#define INT_MAX (int)(UINT_MAX >> 1)
#define INT_MIN (-INT_MAX - 1)

#define OK_SUM32(x,y)\
    (!(((y) > 0 && (x) > INT_MAX - (y)) || ((y) < 0 && (x) < INT_MIN - (y))))


#endif