#ifndef UTILS_H
#define UTILS_H

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