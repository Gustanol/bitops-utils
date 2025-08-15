#include "bitutils.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void set_bit(uint32_t *value, uint8_t bit) {
    /*
     * must include the pointer of value variable because it will be modified
     *
     * bit argument referes to the position that will "turn on"
     *
     * the operation '(1U << bit)' creates a mask that will be compared with the
     * original variable with OR operation
     */
    *value |= (1U << bit);
}

void clear_bit(uint32_t *value, uint8_t bit) {
    /*
     * the diference between this function and the first one is that here a
     * inverted mask of shifting is created and compared with the original
     * variable using AND operation
     *
     * must be that way because we have to guaranted that no other bit shift to 0
     *
     * and if we used OR operation, the bit would keep 1
     */
    *value &= ~(1U << bit);
}

void toggle_bit(uint32_t *value, uint8_t bit) {
    /*
     * in here, we use XOR operation (exclusive OR) just to toggle the bit
     */
    *value ^= (1U << bit);
}

bool check_bit(uint32_t value, uint8_t bit) {
    /*
     * it just creates a mask and compare with the value variable
     */
    return (value & (1U << bit)) != 0;
}

void print_binary(uint32_t value, uint8_t bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}
