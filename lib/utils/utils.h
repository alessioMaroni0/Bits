/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessioMaroni0
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
#define SET_ALL_ONE(x) do { (x) = (typeof(x))~0ULL; } while(0)

// Sets all bits of x to 0
#define SET_ALL_ZERO(x) do { (x) = 0; } while(0)

// Counts the total number of bits set to 1 using compiler builtin
#define BIT_POPCOUNT(x) __builtin_popcount((unsigned long long)(x))

// Return 1 if is power of 2
#define IS_POWER_OF2(x) (((x) > 0) && (((x) & ((x) - 1)) == 0))

// Performs a bits circular left shift (Rotate Left) by n positions
#define BIT_ROL8(x, n) (((x) << (n)) | ((x) >> (8 - (n))))
#define BIT_ROL16(x, n) (((x) << (n)) | ((x) >> (16 - (n))))
#define BIT_ROL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define BIT_ROL64(x, n) (((x) << (n)) | ((x) >> (64 - (n))))

// Performs a bits circular right shift (Rotate Right) by n positions
#define BIT_ROR8(x, n) (((x) >> (n)) | ((x) << (8 - (n))))
#define BIT_ROR16(x, n) (((x) >> (n)) | ((x) << (16 - (n))))
#define BIT_ROR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define BIT_ROR64(x, n) (((x) >> (n)) | ((x) << (64 - (n))))

// Reverses the byte order of a bits value (Endianness conversion)
#define SWAP_ENDIAN8(x) ((uint8_t)(x))

#define SWAP_ENDIAN16(x) ((uint16_t)( \
    (((uint16_t)(x) & 0x00FFU) << 8) | \
    (((uint16_t)(x) & 0xFF00U) >> 8)   \
))

#define SWAP_ENDIAN32(x) ((uint32_t)( \
    (((uint32_t)(x) & 0x000000FFU) << 24) | \
    (((uint32_t)(x) & 0x0000FF00U) << 8)  | \
    (((uint32_t)(x) & 0x00FF0000U) >> 8)  | \
    (((uint32_t)(x) & 0xFF000000U) >> 24)   \
))

#define SWAP_ENDIAN64(x) ((uint64_t)( \
    (((uint64_t)(x) & 0x00000000000000FFULL) << 56) | \
    (((uint64_t)(x) & 0x000000000000FF00ULL) << 40) | \
    (((uint64_t)(x) & 0x0000000000FF0000ULL) << 24) | \
    (((uint64_t)(x) & 0x00000000FF000000ULL) << 8)  | \
    (((uint64_t)(x) & 0x000000FF00000000ULL) >> 8)  | \
    (((uint64_t)(x) & 0x0000FF0000000000ULL) >> 24) | \
    (((uint64_t)(x) & 0x00FF000000000000ULL) >> 40) | \
    (((uint64_t)(x) & 0xFF00000000000000ULL) >> 56)   \
))

#endif