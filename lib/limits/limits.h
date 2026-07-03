#ifndef LIMITS_H
#define LIMITS_H

#include <stdint.h>

#define U32_MAX (~0U)
#define I32_MAX (uint32_t)(U32_MAX >> 1)
#define I32_MIN (-I32_MAX - 1)

#endif