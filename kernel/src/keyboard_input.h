#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

void input_reset();
void input_add_char(char c);
char* input_get_string();
int input_get_int();

#endif