/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessioMaroni0
*/

#ifndef CHECKER_H
#define CHECKER_H

#include "../limits/limits.h"


static inline int check_sum_i8(signed char x, signed char y) {
    return !(((y > 0) && (x > I8_MAX - y)) || ((y < 0) && (x < I8_MIN - y)));
}

static inline int check_sum_u8(unsigned char x, unsigned char y) {
    return !(x > U8_MAX - y);
}

static inline int check_sum_i16(short x, short y) {
    return !(((y > 0) && (x > I16_MAX - y)) || ((y < 0) && (x < I16_MIN - y)));
}

static inline int check_sum_u16(unsigned short x, unsigned short y) {
    return !(x > U16_MAX - y);
}

static inline int check_sum_i32(int x, int y) {
    return !(((y > 0) && (x > I32_MAX - y)) || ((y < 0) && (x < I32_MIN - y)));
}

static inline int check_sum_u32(unsigned int x, unsigned int y) {
    return !(x > U32_MAX - y);
}

static inline int check_sum_i64(long long x, long long y) {
    return !(((y > 0) && (x > I64_MAX - y)) || ((y < 0) && (x < I64_MIN - y)));
}

static inline int check_sum_u64(unsigned long long x, unsigned long long y) {
    return !(x > U64_MAX - y);
}

/*
 * CHECK_SUM
 * Returns 1 if the addition of x and y is safe (no overflow/underflow), 0 otherwise.
 * Dispatches automatically based on the type of x.
 */
#define CHECK_SUM(x, y) _Generic((x), \
    unsigned char:      check_sum_u8((x), (y)),  \
    unsigned short:     check_sum_u16((x), (y)), \
    unsigned int:       check_sum_u32((x), (y)), \
    unsigned long long: check_sum_u64((x), (y)), \
    signed char:        check_sum_i8((x), (y)),  \
    short:              check_sum_i16((x), (y)), \
    int:                check_sum_i32((x), (y)), \
    long long:          check_sum_i64((x), (y)), \
    default:            check_sum_i64((x), (y))  \
)




static inline int check_sub_i8(signed char x, signed char y) {
    return !(((y < 0) && (x > I8_MAX + y)) || ((y > 0) && (x < I8_MIN + y)));
}

static inline int check_sub_u8(unsigned char x, unsigned char y) {
    return (x >= y);
}

static inline int check_sub_i16(short x, short y) {
    return !(((y < 0) && (x > I16_MAX + y)) || ((y > 0) && (x < I16_MIN + y)));
}

static inline int check_sub_u16(unsigned short x, unsigned short y) {
    return (x >= y);
}

static inline int check_sub_i32(int x, int y) {
    return !(((y < 0) && (x > I32_MAX + y)) || ((y > 0) && (x < I32_MIN + y)));
}

static inline int check_sub_u32(unsigned int x, unsigned int y) {
    return (x >= y);
}

static inline int check_sub_i64(long long x, long long y) {
    return !(((y < 0) && (x > I64_MAX + y)) || ((y > 0) && (x < I64_MIN + y)));
}

static inline int check_sub_u64(unsigned long long x, unsigned long long y) {
    return (x >= y);
}

/*
 * CHECK_SUB
 * Returns 1 if the subtraction (x - y) is safe (no overflow/underflow), 0 otherwise.
 * Dispatches automatically based on the type of x.
 */
#define CHECK_SUB(x, y) _Generic((x), \
    unsigned char:      check_sub_u8((x), (y)),  \
    unsigned short:     check_sub_u16((x), (y)), \
    unsigned int:       check_sub_u32((x), (y)), \
    unsigned long long: check_sub_u64((x), (y)), \
    signed char:        check_sub_i8((x), (y)),  \
    short:              check_sub_i16((x), (y)), \
    int:                check_sub_i32((x), (y)), \
    long long:          check_sub_i64((x), (y)), \
    default:            check_sub_i64((x), (y))  \
)




static inline int check_mul_i8(signed char x, signed char y) {
    if (x == 0 || y == 0) return 1;
    if (x > 0 && y > 0)   return (x <= I8_MAX / y);
    if (x < 0 && y < 0)   return (x >= I8_MAX / y);
    return (x > 0) ? (y >= I8_MIN / x) : (x >= I8_MIN / y);
}

static inline int check_mul_u8(unsigned char x, unsigned char y) {
    return (y == 0 || x <= U8_MAX / y);
}

static inline int check_mul_i16(short x, short y) {
    if (x == 0 || y == 0) return 1;
    if (x > 0 && y > 0)   return (x <= I16_MAX / y);
    if (x < 0 && y < 0)   return (x >= I16_MAX / y);
    return (x > 0) ? (y >= I16_MIN / x) : (x >= I16_MIN / y);
}

static inline int check_mul_u16(unsigned short x, unsigned short y) {
    return (y == 0 || x <= U16_MAX / y);
}

static inline int check_mul_i32(int x, int y) {
    if (x == 0 || y == 0) return 1;
    if (x > 0 && y > 0)   return (x <= I32_MAX / y);
    if (x < 0 && y < 0)   return (x >= I32_MAX / y);
    return (x > 0) ? (y >= I32_MIN / x) : (x >= I32_MIN / y); // Bug Fix: I16_MIN -> I32_MIN
}

static inline int check_mul_u32(unsigned int x, unsigned int y) {
    return (y == 0 || x <= U32_MAX / y);
}

static inline int check_mul_i64(long long x, long long y) {
    if (x == 0 || y == 0) return 1;
    if (x > 0 && y > 0)   return (x <= I64_MAX / y);
    if (x < 0 && y < 0)   return (x >= I64_MAX / y);
    return (x > 0) ? (y >= I64_MIN / x) : (x >= I64_MIN / y);
}

static inline int check_mul_u64(unsigned long long x, unsigned long long y) {
    return (y == 0 || x <= U64_MAX / y);
}

/*
 * CHECK_MUL
 * Returns 1 if the multiplication of x and y is safe (no overflow), 0 otherwise.
 * Dispatches automatically based on the type of x.
 */
#define CHECK_MUL(x, y) _Generic((x), \
    unsigned char:      check_mul_u8((x), (y)),  \
    unsigned short:     check_mul_u16((x), (y)), \
    unsigned int:       check_mul_u32((x), (y)), \
    unsigned long long: check_mul_u64((x), (y)), \
    signed char:        check_mul_i8((x), (y)),  \
    short:              check_mul_i16((x), (y)), \
    int:                check_mul_i32((x), (y)), \
    long long:          check_mul_i64((x), (y)), \
    default:            check_mul_i64((x), (y))  \
)




static inline int check_div_i8(signed char x, signed char y) {
    if (y == 0) return 0;
    if (x == I8_MIN && y == -1) return 0;
    return 1;
}

static inline int check_div_u8(unsigned char x, unsigned char y) {
    (void)x;
    return (y != 0);
}

static inline int check_div_i16(short x, short y) {
    if (y == 0) return 0;
    if (x == I16_MIN && y == -1) return 0;
    return 1;
}

static inline int check_div_u16(unsigned short x, unsigned short y) {
    (void)x;
    return (y != 0);
}

static inline int check_div_i32(int x, int y) {
    if (y == 0) return 0;
    if (x == I32_MIN && y == -1) return 0;
    return 1;
}

static inline int check_div_u32(unsigned int x, unsigned int y) {
    (void)x;
    return (y != 0);
}

static inline int check_div_i64(long long x, long long y) {
    if (y == 0) return 0;
    if (x == I64_MIN && y == -1) return 0;
    return 1;
}

static inline int check_div_u64(unsigned long long x, unsigned long long y) {
    (void)x;
    return (y != 0);
}

/*
 * CHECK_DIV
 * Returns 1 if the division (x / y) is safe (no division-by-zero and no TMin/-1 overflow), 0 otherwise.
 * Dispatches automatically based on the type of x.
 */
#define CHECK_DIV(x, y) _Generic((x), \
    unsigned char:      check_div_u8((x), (y)),  \
    unsigned short:     check_div_u16((x), (y)), \
    unsigned int:       check_div_u32((x), (y)), \
    unsigned long long: check_div_u64((x), (y)), \
    signed char:        check_div_i8((x), (y)),  \
    short:              check_div_i16((x), (y)), \
    int:                check_div_i32((x), (y)), \
    long long:          check_div_i64((x), (y)), \
    default:            check_div_i64((x), (y))  \
)

#endif