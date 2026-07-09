#include "video.h"
#include "main_ui.h"

void print_main_ui();

void print_main_ui() {
    draw_text(framebuffer, 550, 10, "D.eSystem 6.0.2 beta", 0xFF00FF); //render D.Kernel version
    draw_text(framebuffer, 10, 10, "kernel version: D.Kernel 0.0.4", 0xFF0000); //render D.eSystem version
}