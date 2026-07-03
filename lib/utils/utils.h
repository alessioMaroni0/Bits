/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessiomaroni0
*/

#ifndef UTILS_H
#define UTILS_H

// Inverts all bits of x (Bitwise NOT)
#define REVERSE(x) (~(x))

// Sets the n-th bit of x to 1
#define BIT_SET(x, n) ((x) |= (1ULL << (n)))

// Clears the n-th bit of x to 0
#define BIT_CLEAR(x, n)  ((x) &= ~(1ULL << (n)))

// Toggles (flips) the n-th bit of x
#define BIT_TOGGLE(x, n) ((x) ^= (1ULL << (n)))

// Extracts the value of the n-th bit of x (returns 0 or 1)
#define BIT_CHECK(x, n)  (((x) >> (n)) & 1ULL)

// Sets all bits of x to 1
#define SET_ALL_ONE(x) ((x) = ~0)

// Sets all bits of x to 0
#define SET_ALL_ZERO(x) ((x) = 0)

// Counts the total number of bits set to 1 using compiler builtin
#define BIT_POPCOUNT(x) __builtin_popcount(x)

// Performs a 32-bit circular left shift (Rotate Left) by n positions
#define BIT_ROL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Performs a 32-bit circular right shift (Rotate Right) by n positions
#define BIT_ROR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

// Reverses the byte order of a 32-bit value (Endianness conversion)
#define SWAP_ENDIAN32(x) ( \
    (((x) & 0x000000FFU) << 24) | \
    (((x) & 0x0000FF00U) << 8)  | \
    (((x) & 0x00FF0000U) >> 8)  | \
    (((x) & 0xFF000000U) >> 24)   \
)

#endif