/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessioMaroni0
*/

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

/*
 * REVERSE
 * Inverts all bits of x (Bitwise NOT)
 */
#define REVERSE(x) (~(x))




/*
 * BIT_SET
 * Sets the n-th bit of x to 1,
 * where x is the target value 
 * and n is the bit position to set.
 */
static inline uint8_t bit_set_8(uint8_t x, int n) {
    return (x | (1U << n));
}

static inline uint16_t bit_set_16(uint16_t x, int n) {
    return (x | (1U << n));
}

static inline uint32_t bit_set_32(uint32_t x, int n) {
    return (x | (1UL << n));
}

static inline uint64_t bit_set_64(uint64_t x, int n) {
    return (x | (1ULL << n));
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x' and the bit position as 'n'.
 * The macro automatically selects the correct type-specific function at compile time.
 * Example: my_val = BIT_SET(my_val, 3);
 */
#define BIT_SET(x, n) _Generic((x), \
    uint8_t:     bit_set_8((x), (n)),  \
    uint16_t:    bit_set_16((x), (n)), \
    uint32_t:    bit_set_32((x), (n)), \
    uint64_t:    bit_set_64((x), (n)), \
    signed char: bit_set_8((x), (n)),  \
    short:       bit_set_16((x), (n)), \
    int:         bit_set_32((x), (n)), \
    long long:   bit_set_64((x), (n)), \
    default:     bit_set_64((x), (n))   \
)



/*
 * BIT_CLEAR
 * Sets the n-th bit of x to 0,
 * where x is the target value 
 * and n is the bit position to set.
 */
static inline uint8_t bit_clear_8(uint8_t x, int n) {
    return (x & ~(1U << n));
}

static inline uint16_t bit_clear_16(uint16_t x, int n) {
    return (x & ~(1U << n));
}

static inline uint32_t bit_clear_32(uint32_t x, int n) {
    return (x & ~(1UL << n));
}

static inline uint64_t bit_clear_64(uint64_t x, int n) {
    return (x & ~(1ULL << n));
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x' and the bit position as 'n'.
 * The macro automatically selects the correct type-specific function at compile time.
 * Example: my_val = BIT_CLEAR(my_val, 6);
 */
#define BIT_CLEAR(x, n) _Generic((x), \
    uint8_t:        bit_clear_8((x), (n)),  \
    uint16_t:       bit_clear_16((x), (n)), \
    uint32_t:       bit_clear_32((x), (n)), \
    uint64_t:       bit_clear_64((x), (n)), \
    signed char:    bit_clear_8((x), (n)),  \
    short:          bit_clear_16((x), (n)), \
    int:            bit_clear_32((x), (n)), \
    long long:      bit_clear_64((x), (n)), \
    default:        bit_clear_64((x), (n))  \
)




/*
 * BIT_TOGGLE
 * Toggles (flips) the n-th bit of x,
 * where x is the target value 
 * and n is the bit position to toggle.
 */
static inline uint8_t bit_toggle_8(uint8_t x, int n) {
    return (x ^ (1U << n));
}

static inline uint16_t bit_toggle_16(uint16_t x, int n) {
    return (x ^ (1U << n));
}

static inline uint32_t bit_toggle_32(uint32_t x, int n) {
    return (x ^ (1UL << n));
}

static inline uint64_t bit_toggle_64(uint64_t x, int n) {
    return (x ^ (1ULL << n));
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x' and the bit position as 'n'.
 * The macro automatically selects the correct type-specific function at compile time.
 * Example: my_val = BIT_TOGGLE(my_val, 2);
 */
#define BIT_TOGGLE(x, n) _Generic((x), \
    uint8_t:        bit_toggle_8((x), (n)),  \
    uint16_t:       bit_toggle_16((x), (n)), \
    uint32_t:       bit_toggle_32((x), (n)), \
    uint64_t:       bit_toggle_64((x), (n)), \
    signed char:    bit_toggle_8((x), (n)),  \
    short:          bit_toggle_16((x), (n)), \
    int:            bit_toggle_32((x), (n)), \
    long long:      bit_toggle_64((x), (n)), \
    default:        bit_toggle_64((x), (n))  \
)




/*
 * SET_ALL_ONE
 * Sets all bits of x to 1.
 * Works safely for both signed and unsigned integer types.
 */
#define SET_ALL_ONE(x) do { (x) = -1; } while(0)

/*
 * SET_ALL_ZERO
 * Sets all bits of x to 0.
 * Works safely for all integer types.
 */
#define SET_ALL_ZERO(x) do { (x) = 0; } while(0)

/*
 * BIT_POPCOUNT
 * Counts the total number of bits set to 1.
 * Uses the compiler 64-bit builtin popcount for maximum efficiency.
 */
#define BIT_POPCOUNT(x) __builtin_popcountll((unsigned long long)(x))

/*
 * IS_POWER_OF2
 * Returns 1 (true) if x is a power of 2, and 0 (false) otherwise.
 * Works safely for all signed and unsigned integer types.
 */
#define IS_POWER_OF2(x) (((x) > 0) && (((x) & ((x) - 1)) == 0))

/*
 * BIT_ROL
 * Rotates the bits of x to the left by n positions (Circular Shift).
 * Safe for any value of n (including 0).
 */
static inline uint8_t bit_rol_8(uint8_t x, int n) {
    return (uint8_t)(((x) << (n & 7)) | ((x) >> ((8 - n) & 7)));
}

static inline uint16_t bit_rol_16(uint16_t x, int n) {
    return (uint16_t)(((x) << (n & 15)) | ((x) >> ((16 - n) & 15)));
}

static inline uint32_t bit_rol_32(uint32_t x, int n) {
    return (uint32_t)(((x) << (n & 31)) | ((x) >> ((32 - n) & 31)));
}

static inline uint64_t bit_rol_64(uint64_t x, int n) {
    return (uint64_t)(((x) << (n & 63)) | ((x) >> ((64 - n) & 63)));
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x' and the rotation count as 'n'.
 * The macro automatically selects the correct type-specific function at compile time.
 * Example: my_val = BIT_ROL(my_val, 4);
 */
#define BIT_ROL(x, n) _Generic((x), \
    uint8_t:        bit_rol_8((x), (n)),  \
    uint16_t:       bit_rol_16((x), (n)), \
    uint32_t:       bit_rol_32((x), (n)), \
    uint64_t:       bit_rol_64((x), (n)), \
    signed char:    bit_rol_8((x), (n)),  \
    short:          bit_rol_16((x), (n)), \
    int:            bit_rol_32((x), (n)), \
    long long:      bit_rol_64((x), (n)), \
    default:        bit_rol_64((x), (n))  \
)




/*
 * BIT_ROR
 * Rotates the bits of x to the right by n positions (Circular Shift).
 * Safe for any value of n (including 0).
 */
static inline uint8_t bit_ror_8(uint8_t x, int n) {
    return (uint8_t)(((x) >> (n & 7)) | ((x) << ((8 - n) & 7)));
}

static inline uint16_t bit_ror_16(uint16_t x, int n) {
    return (uint16_t)(((x) >> (n & 15)) | ((x) << ((16 - n) & 15)));
}

static inline uint32_t bit_ror_32(uint32_t x, int n) {
    return (uint32_t)(((x) >> (n & 31)) | ((x) << ((32 - n) & 31)));
}

static inline uint64_t bit_ror_64(uint64_t x, int n) {
    return (uint64_t)(((x) >> (n & 63)) | ((x) << ((64 - n) & 63)));
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x' and the rotation count as 'n'.
 * The macro automatically selects the correct type-specific function at compile time.
 * Example: my_val = BIT_ROR(my_val, 4);
 */
#define BIT_ROR(x, n) _Generic((x), \
    uint8_t:        bit_ror_8((x), (n)),  \
    uint16_t:       bit_ror_16((x), (n)), \
    uint32_t:       bit_ror_32((x), (n)), \
    uint64_t:       bit_ror_64((x), (n)), \
    signed char:    bit_ror_8((x), (n)),  \
    short:          bit_ror_16((x), (n)), \
    int:            bit_ror_32((x), (n)), \
    long long:      bit_ror_64((x), (n)), \
    default:        bit_ror_64((x), (n))  \
)

/*
 * BIT_SWAP_ENDIAN
 * Reverses the byte order of an integer value (Endianness conversion).
 * Uses compiler builtins for hardware-accelerated byte swapping.
 */
static inline uint8_t bit_swap_endian_8(uint8_t x) {
    return x; // Un singolo byte non ha ordine da invertire
}

static inline uint16_t bit_swap_endian_16(uint16_t x) {
    return __builtin_bswap16(x);
}

static inline uint32_t bit_swap_endian_32(uint32_t x) {
    return __builtin_bswap32(x);
}

static inline uint64_t bit_swap_endian_64(uint64_t x) {
    return __builtin_bswap64(x);
}

/*
 * Usage:
 * Pass any integer variable (from uint8_t to uint64_t) as 'x'.
 * The macro automatically selects the correct byte-swap operation at compile time.
 * Example: my_val = BIT_SWAP_ENDIAN(my_val);
 */
#define BIT_SWAP_ENDIAN(x) _Generic((x), \
    uint8_t:        bit_swap_endian_8(x),  \
    uint16_t:       bit_swap_endian_16(x), \
    uint32_t:       bit_swap_endian_32(x), \
    uint64_t:       bit_swap_endian_64(x), \
    signed char:    bit_swap_endian_8(x),  \
    short:          bit_swap_endian_16(x), \
    int:            bit_swap_endian_32(x), \
    long long:      bit_swap_endian_64(x), \
    default:        bit_swap_endian_64(x)  \
)

#endif