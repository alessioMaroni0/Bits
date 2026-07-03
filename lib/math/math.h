#ifndef CHECKER_H
#define CHECKER_H

#include "../limits/limits.h"

#define OK_SUM_I8(x, y) \
    (!(((y) > 0 && (x) > I8_MAX - (y)) || ((y) < 0 && (x) < I8_MIN - (y))))

#define OK_SUM_U8(x, y) \
    (!((x) > U8_MAX - (y)))

#define OK_SUM_I16(x, y) \
    (!(((y) > 0 && (x) > I16_MAX - (y)) || ((y) < 0 && (x) < I16_MIN - (y))))

#define OK_SUM_U16(x, y) \
    (!((x) > U16_MAX - (y)))

#define OK_SUM_I32(x, y) \
    (!(((y) > 0 && (x) > I32_MAX - (y)) || ((y) < 0 && (x) < I32_MIN - (y))))

#define OK_SUM_U32(x, y) \
    (!((x) > U32_MAX - (y)))

#define OK_SUM_I64(x, y) \
    (!(((y) > 0 && (x) > I64_MAX - (y)) || ((y) < 0 && (x) < I64_MIN - (y))))

#define OK_SUM_U64(x, y) \
    (!((x) > U64_MAX - (y)))

#define OK_SUB_I8(x, y) \
    (!(((y) < 0 && (x) > I8_MAX + (y)) || ((y) > 0 && (x) < I8_MIN + (y))))

#define OK_SUB_U8(x, y) \
    ((x) >= (y))

#define OK_SUB_I16(x, y) \
    (!(((y) < 0 && (x) > I16_MAX + (y)) || ((y) > 0 && (x) < I16_MIN + (y))))

#define OK_SUB_U16(x, y) \
    ((x) >= (y))

#define OK_SUB_I32(x, y) \
    (!(((y) < 0 && (x) > I32_MAX + (y)) || ((y) > 0 && (x) < I32_MIN + (y))))

#define OK_SUB_U32(x, y) \
    ((x) >= (y))

#define OK_SUB_I64(x, y) \
    (!(((y) < 0 && (x) > I64_MAX + (y)) || ((y) > 0 && (x) < I64_MIN + (y))))

#define OK_SUB_U64(x, y) \
    ((x) >= (y))

#define OK_MUL_I8(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I8_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I8_MAX / (y) : ( \
    (x) > 0 ? (y) >= I8_MIN / (x) : (x) >= I8_MIN / (y) \
    ))))

#define OK_MUL_U8(x, y) \
    ((y) == 0 || (x) <= U8_MAX / (y))

#define OK_MUL_I16(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I16_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I16_MAX / (y) : ( \
    (x) > 0 ? (y) >= I16_MIN / (x) : (x) >= I16_MIN / (y) \
    ))))

#define OK_MUL_U16(x, y) \
    ((y) == 0 || (x) <= U16_MAX / (y))

#define OK_MUL_I32(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I32_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I32_MAX / (y) : ( \
    (x) > 0 ? (y) >= I32_MIN / (x) : (x) >= I32_MIN / (y) \
    ))))

#define OK_MUL_U32(x, y) \
    ((y) == 0 || (x) <= U32_MAX / (y))

#define OK_MUL_I64(x, y) ( \
    (x) == 0 || (y) == 0 ? 1 : ( \
    (x) > 0 && (y) > 0 ? (x) <= I64_MAX / (y) : ( \
    (x) < 0 && (y) < 0 ? (x) >= I64_MAX / (y) : ( \
    (x) > 0 ? (y) >= I64_MIN / (x) : (x) >= I64_MIN / (y) \
    ))))

#define OK_MUL_U64(x, y) \
    ((y) == 0 || (x) <= U64_MAX / (y))

#define OK_DIV_I8(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I8_MIN && (y) == -1 ? 0 : 1 \
    ))

#define OK_DIV_U8(x, y) \
    ((y) != 0)

#define OK_DIV_I16(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I16_MIN && (y) == -1 ? 0 : 1 \
    ))

#define OK_DIV_U16(x, y) \
    ((y) != 0)

#define OK_DIV_I32(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I32_MIN && (y) == -1 ? 0 : 1 \
    ))

#define OK_DIV_U32(x, y) \
    ((y) != 0)

#define OK_DIV_I64(x, y) ( \
    (y) == 0 ? 0 : ( \
    (x) == I64_MIN && (y) == -1 ? 0 : 1 \
    ))

#define OK_DIV_U64(x, y) \
    ((y) != 0)

#endif