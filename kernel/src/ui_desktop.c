#include "ui_desktop.h"
#include "video.h"

void render_gui();
void clock_icon();
void shutdown_icon();
void calculator_icon();
void info_icon();
void d_e_shell_icon();
void d_menu_icon();

void render_gui() {

    clock_icon(framebuffer);
    shutdown_icon(framebuffer);
    calculator_icon(framebuffer);
    info_icon(framebuffer);
    d_e_shell_icon(framebuffer);


}

void clock_icon(struct limine_framebuffer *fb) {
    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2) + 330;

    draw_rect(fb, x, y, 100, 100, 0x404040);

    draw_rect(fb, x + 10, y + 10, 10, 60, 0xEEEEEE);
    draw_rect(fb, x + 80, y + 10, 10, 60, 0xEEEEEE);

    draw_rect(fb, x + 20, y + 10, 60, 10, 0xEEEEEE);
    draw_rect(fb, x + 20, y + 60, 60, 10, 0xEEEEEE);

  
    draw_rect(fb, x + 50, y + 37, 4, 17, 0x00FFFF);
    draw_rect(fb, x + 50, y + 37, 20, 4, 0x00FFFF);

    draw_text(fb, x + 15, y + 85, "Press [3]", 0xFF0000);
}



void shutdown_icon(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t x = (W / 2) - (icon_w / 2) - 130;
    uint32_t y = (H / 2) - (icon_h / 2) + 330;

    draw_rect(fb, x, y, icon_w, icon_h, 0xFF0000);
    draw_rect(fb, x + 20, y + 10, 10, 60, 0xEEEEEE);
    draw_rect(fb, x + 70, y + 10, 10, 60, 0xEEEEEE);
    draw_rect(fb, x + 20, y + 60, 60, 10, 0xEEEEEE);
    draw_rect(fb, x + 45, y + 10, 10, 30, 0xEEEEEE);
    draw_text(fb, x + 5, y + 85, "Press [Esc]", 0xFFFFFF);
}



void calculator_icon(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t x = (W / 2) - (icon_w / 2) + 130;
    uint32_t y = (H / 2) - (icon_h / 2) + 330;



    draw_rect(fb, x, y, icon_w, icon_h, 0x99FF99);

    draw_rect(fb, x + 15, y + 9, 5, 20, 0xFF9999);
    draw_rect(fb, x + 8, y + 16 , 20, 5, 0xFF9999);
    //draw_rect(fb, 730, 690, 5, 20, 0xFF99FF);

    draw_rect(fb,x + 60, y + 15, 20, 5, 0x9999FF);

    draw_rect(fb, x + 10, y + 50, 20, 5, 0xFF99FF);
    draw_rect(fb, x + 10, y + 60, 20, 5, 0xFF99FF);

    draw_rect(fb, x + 70, y + 50, 5, 5, 0x202020);
    draw_rect(fb, x + 70, y + 60, 5, 5, 0x202020);
    draw_text(fb, x + 15, y + 85, "Press [2]", 0xFF0000);
    



    


}

void info_icon(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t x = (W / 2) - (icon_w / 2) - 260;
    uint32_t y = (H / 2) - (icon_h / 2) + 330;

    
    draw_rect(fb, x, y, icon_w, icon_h, 0x0000FF);


    draw_rect(fb, x + 45, y + 10, 10, 10, 0xFFFF00);   // Punkt
    draw_rect(fb, x + 45, y + 30, 10, 40, 0xFFFF00);   // Strich

    
    draw_text(fb, x + 15, y + 85, "Press [4]", 0xFF0000);
}


void d_e_shell_icon(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t x = (W / 2) + 220;
    uint32_t y = (H / 2) + 280;

    draw_rect(fb, x, y, icon_w, icon_h, 0x202020);

    
    draw_rect(fb, x + 10, y + 60, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 15, y + 55, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 20, y + 50, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 25, y + 45, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 30, y + 40, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 25, y + 35, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 20, y + 30, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 15, y + 25, 5, 5, 0xFFFFFF);
    draw_rect(fb, x + 10, y + 20, 5, 5, 0xFFFFFF);

    draw_rect(fb, x + 35, y + 60, 55, 5, 0xFFFFFF);
    draw_text(fb, x + 15, y + 85, "Press [5]", 0xFF0000);
}

void d_menu_icon() {
    draw_rect(framebuffer, 10, 680, 100, 100, 0xCCCCCC);
    draw_rect(framebuffer, 20, 700, 5, 65, 0xFFFFFF);

    draw_rect(framebuffer, 25, 705, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 30, 710, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 35, 715, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 40, 720, 5, 5, 0xFFFFFF);

    draw_rect(framebuffer, 25, 755, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 30, 750, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 35, 745, 5, 5, 0xFFFFFF);
    draw_rect(framebuffer, 40, 740, 5, 5, 0xFFFFFF);

    draw_rect(framebuffer, 40, 720, 5, 20, 0xFFFFFF);

    draw_rect(framebuffer, 60, 760, 5, 5, 0xFFFFFF);
    

}