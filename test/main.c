/*
 * BITS Library - Comprehensive Test Suite
 * Test file to verify bitwise operations and overflow checkers.
 */

#include <stdio.h>
#include <stdint.h>
#include "../lib/bits.h"

#define TEST_EQUAL(msg, val, expected) \
    printf("[%s] %s: %s (Valore: %lld, Atteso: %lld)\n", \
           ((val) == (expected)) ? "OK" : "FAIL", (msg), \
           ((val) == (expected)) ? "PASSATO" : "FALLITO", \
           (long long)(val), (long long)(expected))

#define TEST_CHECKER(msg, cond, expected) \
    printf("[%s] %s: %s (Risultato: %s)\n", \
           ((cond) == (expected)) ? "OK" : "FAIL", (msg), \
           ((cond) == (expected)) ? "PASSATO" : "FALLITO", \
           (cond) ? "SICURO" : "OVERFLOW")

int main(void) {


    uint8_t reg8 = 0;
    reg8 = BIT_SET(reg8, 3);
    TEST_EQUAL("BIT_SET (uint8_t) bit 3", reg8, 8);

    reg8 = BIT_TOGGLE(reg8, 3);
    TEST_EQUAL("BIT_TOGGLE (uint8_t) bit 3 (spegne)", reg8, 0);

    uint32_t reg32 = 0;
    reg32 = BIT_SET(reg32, 16);
    TEST_EQUAL("BIT_SET (uint32_t) bit 16", reg32, 65536);

    reg32 = BIT_CLEAR(reg32, 16);
    TEST_EQUAL("BIT_CLEAR (uint32_t) bit 16", reg32, 0);

    // Test POPCOUNT e REVERSE
    uint16_t pop_test = 0b10110011; // 5 bit a 1
    TEST_EQUAL("BIT_POPCOUNT (uint16_t)", BIT_POPCOUNT(pop_test), 5);
    
    uint8_t rev_test = 0x0F;
    TEST_EQUAL("REVERSE (uint8_t)", (uint8_t)REVERSE(rev_test), 0xF0);

    uint32_t all_one_test = 0;
    SET_ALL_ONE(all_one_test);
    TEST_EQUAL("SET_ALL_ONE (uint32_t)", all_one_test, 0xFFFFFFFFU);

    SET_ALL_ZERO(all_one_test);
    TEST_EQUAL("SET_ALL_ZERO (uint32_t)", all_one_test, 0);

    TEST_EQUAL("IS_POWER_OF2 (1024)", IS_POWER_OF2(1024), 1);
    TEST_EQUAL("IS_POWER_OF2 (1023)", IS_POWER_OF2(1023), 0);

    printf("\n");

    uint32_t rol_test = 0x80000001U;
    TEST_EQUAL("BIT_ROL (uint32_t) di 1 pos", BIT_ROL(rol_test, 1), 0x00000003U);

    uint16_t ror_test = 0x0001U;
    TEST_EQUAL("BIT_ROR (uint16_t) di 1 pos", BIT_ROR(ror_test, 1), 0x8000U);

    uint32_t endian_test = 0x11223344U;
    TEST_EQUAL("BIT_SWAP_ENDIAN (uint32_t)", BIT_SWAP_ENDIAN(endian_test), 0x44332211U);

    uint8_t endian_byte = 0xAA;
    TEST_EQUAL("BIT_SWAP_ENDIAN (uint8_t - invariato)", BIT_SWAP_ENDIAN(endian_byte), 0xAA);

    printf("\n");

    int32_t s_max = I32_MAX;
    TEST_CHECKER("CHECK_SUM (int) sicuro", CHECK_SUM(s_max - 10, 5), 1);
    TEST_CHECKER("CHECK_SUM (int) con overflow", CHECK_SUM(s_max, 1), 0);

    uint8_t u_max = U8_MAX;
    TEST_CHECKER("CHECK_SUM (uint8_t) sicuro", CHECK_SUM((uint8_t)200, (uint8_t)55), 1);
    TEST_CHECKER("CHECK_SUM (uint8_t) con wrapping", CHECK_SUM(u_max, (uint8_t)1), 0);

    int16_t s16_min = I16_MIN;
    TEST_CHECKER("CHECK_SUB (int16_t) sicuro", CHECK_SUB((short)0, (short)100), 1);
    TEST_CHECKER("CHECK_SUB (int16_t) con underflow", CHECK_SUB(s16_min, (short)1), 0);

    uint32_t u32_val = 10;
    TEST_CHECKER("CHECK_SUB (uint32_t) sotto lo zero", CHECK_SUB(u32_val, 11U), 0);

    int32_t mul_val = 2000000000;
    TEST_CHECKER("CHECK_MUL (int) sicuro", CHECK_MUL(mul_val, 1), 1);
    TEST_CHECKER("CHECK_MUL (int) con overflow", CHECK_MUL(mul_val, 2), 0);

    int8_t div_min = I8_MIN;
    TEST_CHECKER("CHECK_DIV divisione per zero", CHECK_DIV((signed char)10, (signed char)0), 0);
    TEST_CHECKER("CHECK_DIV sicuro", CHECK_DIV((signed char)10, (signed char)2), 1);
    TEST_CHECKER("CHECK_DIV TMin / -1 (overflow)", CHECK_DIV(div_min, (signed char)-1), 0);


    return 0;
}