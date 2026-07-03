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

#define REVERSE(x) (~(x))
#define BIT_SET(x, n) ((x) |= (1ULL << (n)))
#define BIT_CLEAR(x, n)  ((x) &= ~(1ULL << (n)))
#define BIT_TOGGLE(x, n) ((x) ^= (1ULL << (n)))
#define BIT_CHECK(x, n)  (((x) >> (n)) & 1ULL)
#define SET_ALL_ONE(x) ((x) = ~0)
#define SET_ALL_ZERO(x) ((x) = 0)
#define BIT_POPCOUNT(x) __builtin_popcount(x)
#define BIT_ROL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define BIT_ROR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

#define SWAP_ENDIAN32(x) ( \
    (((x) & 0x000000FFU) << 24) | \
    (((x) & 0x0000FF00U) << 8)  | \
    (((x) & 0x00FF0000U) >> 8)  | \
    (((x) & 0xFF000000U) >> 24)   \
)

#endif