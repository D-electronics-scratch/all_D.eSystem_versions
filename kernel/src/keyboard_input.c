#include "keyboard_input.h"
#include "keyboard.h"
#include <stdint.h>


char input_read_ascii() {
    //uint8_t sc = ps2_read_key();
    return ps2_read_key();
}

static char input_buffer[64];
static int input_len = 0;

void input_reset() {
    input_len = 0;
    input_buffer[0] = '\0';
}

void input_add_char(char c) {
    if (input_len < 63) {
        input_buffer[input_len++] = c;
        input_buffer[input_len] = '\0';
    }
}

char* input_get_string() {
    return input_buffer;
}

// Integer-Parser
int input_get_int() {
    int result = 0;
    int sign = 1;
    const char *s = input_buffer;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0');
        s++;
    }

    return result * sign;
}