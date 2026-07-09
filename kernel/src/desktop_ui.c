#include "video.h"
#include "ui_desktop.h"

void ui_desktop();

void rende_ui();

void render_desktop();




void ui_desktop() {
    clear_screen(framebuffer, 0x000000);  
    render_desktop();
    render_gui(); 

    render_ui();                          
}


void render_desktop() {
    draw_wallpaper_gradient(framebuffer);
}


void render_ui() {
    //draw_text(framebuffer, 500, 50, "--------------------------------", 0xFFFFFF);
    //draw_text(framebuffer, 500, 60, "| [Esc] Shutdown               |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 70, "| [2] calculator               |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 80, "| [3] clock                    |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 90, "| [4] info                     |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 100, "| [5] D.eShell                 |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 110, "| [6] thundercalculator        |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 120, "--------------------------------", 0xFFFFFF);

    print_main_ui();
}



