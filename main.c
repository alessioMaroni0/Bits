#include <stdio.h>
#include "lib/bits.h"

int main() {
    int a = I32_MAX;
    int b = I32_MIN;
    unsigned int c = U32_MAX;
    
    printf("--- 1. Limiti dei Tipi a 32 Bit ---\n");
    printf("Il valore INT_MAX (a) è: %d\n", a);
    printf("Il valore INT_MIN (b) è: %d\n", b);
    printf("Il valore UINT_MAX (c) è: %u\n\n", c);

    printf("--- 2. Controlli Overflow/Underflow ---\n");
    
    int x_sum = I32_MAX;
    int y_sum = 1;
    if (OK_SUM_I32(x_sum, y_sum)) {
        printf("Somma con segno sicura: %d\n", x_sum + y_sum);
    } else {
        printf("[ATTENZIONE] Overflow rilevato! Non posso sommare %d + %d\n", x_sum, y_sum);
    }

    unsigned int ux_sum = U32_MAX;
    unsigned int uy_sum = 1;
    if (OK_SUM_U32(ux_sum, uy_sum)) {
        printf("Somma unsigned sicura: %u\n", ux_sum + uy_sum);
    } else {
        printf("[ATTENZIONE] Overflow unsigned rilevato!\n");
    }

    int x_sub = I32_MIN;
    int y_sub = 1;
    if (OK_SUB_I32(x_sub, y_sub)) {
        printf("Sottrazione sicura: %d\n", x_sub - y_sub);
    } else {
        printf("[ATTENZIONE] Underflow rilevato! Non posso sottrarre %d - %d\n", x_sub, y_sub);
    }
    printf("\n");

    printf("--- 3. Manipolazione Bit Singoli ---\n");
    unsigned int registro = 0;
    
    BIT_SET(registro, 3);
    BIT_SET(registro, 5);
    printf("Registro dopo SET dei bit 3 e 5: %u\n", registro);
    
    printf("Verifica bit 3: %s\n", BIT_CHECK(registro, 3) ? "ACCESO" : "SPENTO");
    printf("Verifica bit 4: %s\n", BIT_CHECK(registro, 4) ? "ACCESO" : "SPENTO");
    
    BIT_TOGGLE(registro, 5);
    BIT_CLEAR(registro, 3);
    printf("Registro dopo CLEAR(3) e TOGGLE(5): %u\n\n", registro);

    printf("--- 4. Stato Globale e Popcount ---\n");
    unsigned int maschera;
    
    SET_ALL_ONE(maschera);
    printf("Dopo SET_ALL_ONE la maschera vale: %u\n", maschera);
    printf("Numero di bit a 1 (Popcount): %d\n", BIT_POPCOUNT(maschera));
    
    SET_ALL_ZERO(maschera);
    printf("Dopo SET_ALL_ZERO la maschera vale: %u\n", maschera);
    
    unsigned int valore = 5;
    printf("Il REVERSE (NOT) di 5 è: %u\n\n", REVERSE(valore));

    printf("--- 5. Rotazione Circolare dei Bit ---\n");
    unsigned int bit_test = 0x80000001U;
    
    unsigned int ruotato_sx = BIT_ROL32(bit_test, 1);
    unsigned int ruotato_dx = BIT_ROR32(bit_test, 1);
    
    printf("Valore iniziale: 0x%X\n", bit_test);
    printf("Ruotato a Sinistra di 1: 0x%X\n", ruotato_sx);
    printf("Ruotato a Destra di 1:   0x%X\n\n", ruotato_dx);

    printf("--- 6. Inversione Endianness ---\n");
    unsigned int dati_network = 0x12345678U;
    unsigned int dati_swappati = SWAP_ENDIAN32(dati_network);
    
    printf("Dato originale: 0x%08X\n", dati_network);
    printf("Dato invertito: 0x%08X\n", dati_swappati);

    return 0;
}