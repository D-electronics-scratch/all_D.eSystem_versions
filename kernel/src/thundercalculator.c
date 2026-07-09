#include "thundercalculator.h"
#include "keyboard.h"
#include "calculator_input.h"
#include "video.h"
#include "main.h"
#include "main_ui.h"
#include "desktop_ui.h"

int sec_thunder;
int on_off;

void thunder_loop();
void thunder_ui();
void thunder_if_else();
void num_input();
void run_thunder_calc();



void num_input() {
    sec_thunder = calculator_read_int(450, 230);
}

void thunder_ui() {
    clear_screen(framebuffer,  0x00FF00);
    print_main_ui();
    draw_text(framebuffer, 430, 50, "-----------------------------------------------------------", 0x0000FF);
    draw_text(framebuffer, 430, 60, "|How many secconds are between the thunder and the flash ?|", 0x0000FF);
    draw_text(framebuffer, 430, 70, "-----------------------------------------------------------", 0x0000FF);
    draw_text(framebuffer, 430, 80, "|                    Type 99 to close                     |", 0x0000FF);
    draw_text(framebuffer, 430, 90, "-----------------------------------------------------------", 0x0000FF);
    
}

void run_thunder_calc() {
    on_off = 1;

    while (on_off == 1) {

        thunder_ui(); 

        sec_thunder = calculator_read_int(450, 230);

        if (sec_thunder == 99) {
            ui_desktop();
            on_off = 0;
            break;
        }

        
        int thunder_km = sec_thunder / 3;
        char buf[32];
        int_to_string(thunder_km, buf);


        clear_screen(framebuffer,  0x00FF00);
        //draw_text(framebuffer, 430, 50, "-----------------------------------------------------------", 0x0000FF);
        //draw_text(framebuffer, 430, 60, "|The thunderstorm is                   km away!!          |", 0x0000FF);
        draw_text(framebuffer, 430, 70, "-----------------------------------------------------------", 0x0000FF);
        draw_text(framebuffer, 430, 80, "| Type 1 to continue         | Type 2 to close            |", 0x0000FF);
        draw_text(framebuffer, 430, 90, "-----------------------------------------------------------", 0x0000FF);
        print_main_ui();
        draw_text(framebuffer, 430, 140, "Distance (km):", 0x0000FF);
        draw_text(framebuffer, 600, 140, buf, 0xFFFFFF);
        num_input();
        if (sec_thunder == 1) {


        } else if (sec_thunder == 2) {
            ui_desktop();
            return;
        }

        //sleep(1000);

    }


}