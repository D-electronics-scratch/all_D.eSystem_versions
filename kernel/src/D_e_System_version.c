#include "D_e_System_version.h"
#include "video.h"
#include "keyboard.h"
#include "desktop_ui.h"
#include "main_ui.h"
#include "keyboard_input.h"
#include "system_info.h"



void D_e_Sys_v_run();


void D_e_Sys_v_run() {
    int key = 0;

    char cpu_name[64];
    clear_screen(framebuffer, 0x0000FF);

    get_cpu_brand(cpu_name);
    draw_text(framebuffer, 300, 210, cpu_name, 0xFFFFFF);

    uint64_t ram = get_total_ram();
    char ram_text[32];
    itoa(ram / (1024 * 1024), ram_text, 10);
    draw_text(framebuffer, 350, 230, ram_text, 0xFFFFFF);



    print_main_ui();

    draw_text(framebuffer, 250, 50, "------------------------------------------------------------------------------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 250, 60, "| [Esc] close                                 D.eSystem version                                            |", 0xFFFFFF);
    draw_text(framebuffer, 250, 70, "------------------------------------------------------------------------------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 250, 80, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 90, "| Kernel version: D.Kernel 0.4                                                                             |", 0xFFFFFF);
    draw_text(framebuffer, 250, 100, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 110, "| D.eSystem version: D.eSystem 6.0.2 beta                                                                 |", 0xFFFFFF);
    draw_text(framebuffer, 250, 120, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 130, "| UI version: D.UI 11                                                                                      |", 0xFFFFFF);
    draw_text(framebuffer, 250, 140, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 150, "| UX version: Color UX D.eSystem beta edition                                                                   |", 0xFFFFFF);
    draw_text(framebuffer, 250, 160, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 170, "| Brand: D.electronics                                                                                     |", 0xFFFFFF);
    draw_text(framebuffer, 250, 180, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 190, "| Codename: Hardmount                                                                                      |", 0xFFFFFF);
    draw_text(framebuffer, 250, 200, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 210, "| CPU:                                                                                                     |", 0xFFFFFF);
    draw_text(framebuffer, 250, 220, "|                                                                                                          |", 0xFFFFFF);
    draw_text(framebuffer, 250, 230, "| RAM (MB):                                                                                                |", 0xFFFFFF);
    draw_text(framebuffer, 250, 240, "------------------------------------------------------------------------------------------------------------", 0xFFFFFF);


    while(key == 0) {
        key = ps2_read_key();
    }
    if (key == 27) {
        ui_desktop();
        return;
    }
    



}