#include "bitutils.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    uint32_t reg = 0b00000000;

    set_bit(&reg, 3);
    print_binary(reg, 8);

    toggle_bit(&reg, 4);
    print_binary(reg, 8);

    set_bit(&reg, 1);
    printf("The chosen bit is: %s\n", check_bit(reg, 1) ? "on" : "off");

    clear_bit(&reg, 1);
    print_binary(reg, 8);

    return 0;
}
