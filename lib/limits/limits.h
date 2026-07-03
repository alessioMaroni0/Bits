/*
 * BITS Library
 * * This file is covered by the MIT License.
 * Copyright (c) 2026 alessiomaroni0
*/

#ifndef LIMITS_H
#define LIMITS_H

#include <stdint.h>

// 8-bit integer boundaries
#define U8_MAX (uint8_t)(~0U)        // Max unsigned 8-bit: invert 0 to set all bits to 1
#define I8_MAX (int8_t)(U8_MAX >> 1) // Max signed 8-bit: shift right to clear the sign bit (MSB)
#define I8_MIN (-I8_MAX - 1)         // Min signed 8-bit: asymmetric two's complement lower bound

// 16-bit integer boundaries
#define U16_MAX (uint16_t)(~0U)        // Max unsigned 16-bit: set all bits to 1
#define I16_MAX (int16_t)(U16_MAX >> 1) // Max signed 16-bit: clear the sign bit (MSB)
#define I16_MIN (-I16_MAX - 1)         // Min signed 16-bit: asymmetric two's complement lower bound

// 32-bit integer boundaries
#define U32_MAX (uint32_t)(~0U)        // Max unsigned 32-bit: set all bits to 1
#define I32_MAX (int32_t)(U32_MAX >> 1) // Max signed 32-bit: clear the sign bit (MSB)
#define I32_MIN (-I32_MAX - 1)         // Min signed 32-bit: asymmetric two's complement lower bound

// 64-bit integer boundaries
#define U64_MAX (uint64_t)(~0U)        // Max unsigned 64-bit: set all bits to 1
#define I64_MAX (int64_t)(U64_MAX >> 1) // Max signed 64-bit: clear the sign bit (MSB)
#define I64_MIN (-I64_MAX - 1)         // Min signed 64-bit: asymmetric two's complement lower bound

#endif