#include "keyboard.h"
#include "keyboard_input.h"
#include "video.h"

int calculator_read_int(int x, int y) {
    input_reset();

    int prompt_y = y + 500;   // <<< Prompt verschoben
    draw_text(framebuffer, x, prompt_y, "         Input> ", 0xFFFFFF);

    int cursor_x = x + 120;
    int cursor_y = prompt_y;  // <<< Input auf gleiche Höhe

    while (1) {
        char c = input_read_ascii();
        if (c == 0) continue;

        if (c == '\n') break;

        char str[2] = {c, 0};
        draw_text(framebuffer, cursor_x, cursor_y, str, 0xFF0000);

        cursor_x += 8;
        input_add_char(c);
    }

    return input_get_int();
}




void keyboard_read_string(char* buffer, int max_len) {
    int index = 0;

    int x = 450;      
    int y = 230;
    int cursor_x = x + 120;

    draw_text(framebuffer, x, y, "         Input> ", 0xFFFFFF);

    while (1) {
        char c = input_read_ascii();
        if (c == 0) continue;

        
        if (c == '\n') {
            buffer[index] = 0;
            return;
        }

     
        if (c == '\b' && index > 0) {
            index--;
            buffer[index] = 0;

        
            draw_text(framebuffer, cursor_x - 8, y, " ", 0x0000FF); // 
            cursor_x -= 8;

            continue;
        }

       
        if (index < max_len - 1) {
            buffer[index++] = c;
            buffer[index] = 0;

            
            char str[2] = {c, 0};
            draw_text(framebuffer, cursor_x, y, str, 0xFFFFFF);
            cursor_x += 8;
        }
    }
}