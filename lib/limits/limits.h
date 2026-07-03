#ifndef LIMITS_H
#define LIMITS_H

#include <stdint.h>

#define U8_MAX (uint8_t)(~0U)
#define I8_MAX (int8_t)(U8_MAX >> 1)
#define I8_MIN (-I8_MAX - 1)

#define U16_MAX (uint16_t)(~0U)
#define I16_MAX (int16_t)(U16_MAX >> 1)
#define I16_MIN (-I16_MAX - 1)

#define U32_MAX (uint32_t)(~0U)
#define I32_MAX (int32_t)(U32_MAX >> 1)
#define I32_MIN (-I32_MAX - 1)

#define U64_MAX (uint64_t)(~0U)
#define I64_MAX (int64_t)(U64_MAX >> 1)
#define I64_MIN (-I64_MAX - 1)

#endif