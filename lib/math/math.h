/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessiomaroni0
*/

#ifndef CHECKER_H
#define CHECKER_H

#include "../limits/limits.h"

// ADDITION OVERFLOW CHECKS

// Checks signed 8-bit addition for positive overflow or negative underflow
#define OK_SUM_I8(x, y) \
    (!(((y) > 0 && (x) > I8_MAX - (y)) || ((y) < 0 && (x) < I8_MIN - (y))))

// Checks unsigned 8-bit addition for wrapping overflow
#define OK_SUM_U8(x, y) \
    (!((x) > U8_MAX - (y)))

// Checks signed 16-bit addition for positive overflow or negative underflow
#define OK_SUM_I16(x, y) \
    (!(((y) > 0 && (x) > I16_MAX - (y)) || ((y) < 0 && (x) < I16_MIN - (y))))

// Checks unsigned 16-bit addition for wrapping overflow
#define OK_SUM_U16(x, y) \
    (!((x) > U16_MAX - (y)))

// Checks signed 32-bit addition for positive overflow or negative underflow
#define OK_SUM_I32(x, y) \
    (!(((y) > 0 && (x) > I32_MAX - (y)) || ((y) < 0 && (x) < I32_MIN - (y))))

// Checks unsigned 32-bit addition for wrapping overflow
#define OK_SUM_U32(x, y) \
    (!((x) > U32_MAX - (y)))

// Checks signed 64-bit addition for positive overflow or negative underflow
#define OK_SUM_I64(x, y) \
    (!(((y) > 0 && (x) > I64_MAX - (y)) || ((y) < 0 && (x) < I64_MIN - (y))))

// Checks unsigned 64-bit addition for wrapping overflow
#define OK_SUM_U64(x, y) \
    (!((x) > U64_MAX - (y)))



// SUBTRACTION OVERFLOW CHECKS

    
// Checks signed 8-bit subtraction for positive overflow or negative underflow
#define OK_SUB_I8(x, y) \
    (!(((y) < 0 && (x) > I8_MAX + (y)) || ((y) > 0 && (x) < I8_MIN + (y))))

// Checks unsigned 8-bit subtraction to prevent wrapping below zero
#define OK_SUB_U8(x, y) \
    ((x) >= (y))

// Checks signed 16-bit subtraction for positive overflow or negative underflow
#define OK_SUB_I16(x, y) \
    (!(((y) < 0 && (x) > I16_MAX + (y)) || ((y) > 0 && (x) < I16_MIN + (y))))

// Checks unsigned 16-bit subtraction to prevent wrapping below zero
#define OK_SUB_U16(x, y) \
    ((x) >= (y))

// Checks signed 32-bit subtraction for positive overflow or negative underflow
#define OK_SUB_I32(x, y) \
    (!(((y) < 0 && (x) > I32_MAX + (y)) || ((y) > 0 && (x) < I32_MIN + (y))))

// Checks unsigned 32-bit subtraction to prevent wrapping below zero
#define OK_SUB_U32(x, y) \
    ((x) >= (y))

// Checks signed 64-bit subtraction for positive overflow or negative underflow
#define OK_SUB_I64(x, y) \
    (!(((y) < 0 && (x) > I64_MAX + (y)) || ((y) > 0 && (x) < I64_MIN + (y))))

// Checks unsigned 64-bit subtraction to prevent wrapping below zero
#define OK_SUB_U64(x, y) \
    ((x) >= (y))


// MULTIPLICATION OVERFLOW CHECKS

// Checks signed 8-bit multiplication using inverse division boundaries
#define OK_MUL_I8(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I8_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I8_MAX / (y) : ( \
    (x) > 0 ? (y) >= I8_MIN / (x) : (x) >= I8_MIN / (y) \
    ))))

// Checks unsigned 8-bit multiplication for bounds overflow
#define OK_MUL_U8(x, y) \
    ((y) == 0 || (x) <= U8_MAX / (y))

// Checks signed 16-bit multiplication using inverse division boundaries
#define OK_MUL_I16(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I16_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I16_MAX / (y) : ( \
    (x) > 0 ? (y) >= I16_MIN / (x) : (x) >= I16_MIN / (y) \
    ))))

// Checks unsigned 16-bit multiplication for bounds overflow
#define OK_MUL_U16(x, y) \
    ((y) == 0 || (x) <= U16_MAX / (y))

// Checks signed 32-bit multiplication using inverse division boundaries
#define OK_MUL_I32(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I32_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I32_MAX / (y) : ( \
    (x) > 0 ? (y) >= I16_MIN / (x) : (x) >= I32_MIN / (y) \
    ))))

// Checks unsigned 32-bit multiplication for bounds overflow
#define OK_MUL_U32(x, y) \
    ((y) == 0 || (x) <= U32_MAX / (y))

// Checks signed 64-bit multiplication using inverse division boundaries
#define OK_MUL_I64(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I64_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I64_MAX / (y) : ( \
    (x) > 0 ? (y) >= I64_MIN / (x) : (x) >= I64_MIN / (y) \
    ))))

// Checks unsigned 64-bit multiplication for bounds overflow
#define OK_MUL_U64(x, y) \
    ((y) == 0 || (x) <= U64_MAX / (y))


// DIVISION OVERFLOW & ZERO CHECKS

// Checks signed 8-bit division for division-by-zero and TMin / -1 overflow
#define OK_DIV_I8(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I8_MIN && (y) == -1 ? 0 : 1 \
    ))

// Checks unsigned 8-bit division for division-by-zero
#define OK_DIV_U8(x, y) \
    ((y) != 0)

// Checks signed 16-bit division for division-by-zero and TMin / -1 overflow
#define OK_DIV_I16(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I16_MIN && (y) == -1 ? 0 : 1 \
    ))

// Checks unsigned 16-bit division for division-by-zero
#define OK_DIV_U16(x, y) \
    ((y) != 0)

// Checks signed 32-bit division for division-by-zero and TMin / -1 overflow
#define OK_DIV_I32(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I32_MIN && (y) == -1 ? 0 : 1 \
    ))

// Checks unsigned 32-bit division for division-by-zero
#define OK_DIV_U32(x, y) \
    ((y) != 0)

// Checks signed 64-bit division for division-by-zero and TMin / -1 overflow
#define OK_DIV_I64(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I64_MIN && (y) == -1 ? 0 : 1 \
    ))

// Checks unsigned 64-bit division for division-by-zero
#define OK_DIV_U64(x, y) \
    ((y) != 0)

#endif