#ifndef BITUTILS_H
#define BITUTILS_H

#include <stdbool.h>
#include <stdint.h>

void set_bit(uint32_t *value, uint8_t bit);
void clear_bit(uint32_t *value, uint8_t bit);
void toggle_bit(uint32_t *value, uint8_t bit);
bool check_bit(uint32_t value, uint8_t bit);
void print_bit(uint32_t value, uint8_t bits);

#endif /* ifndef BITUTILS_H                                                                        \
#define BITUTILS_H */
