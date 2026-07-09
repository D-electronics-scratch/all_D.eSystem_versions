#include "video.h"
#include "calculator.h"
#include "keyboard.h"
#include "keyboard_input.h"
#include "calculator_input.h"
#include "util.h"
//includes

void calculator_ui();
void input_calculator();
void if_else_claculator();
void version_and_kernel_version_ui();
void ui_num_1();
void ui_num2();
void ui_sum();
void plus_icon();
void minus();
void multiply();
void divide_icon();
void close_icon();
//modules

int op;
int num1;
int num2;
int sum;
char key = 0;
//variables

void version_and_kernel_version_ui() {
    draw_text(framebuffer, 550, 10, "D.eSystem 6.0.3 alpha", 0xFFFFFF); //render D.Kernel version
    draw_text(framebuffer, 0, 10, "kernel version: D.Kernel 0.0.2", 0xFFFFFF); //render D.eSystem version

}







void app_calculator_run() {

    int num_cmd_calculator = 0;
    clear_screen(framebuffer, 0x1A7FFF);

    print_main_ui(); //render kernel version and D.eSystem version

    calculator_ui();
    input_calculator();
    //minus();


}


void calculator_ui() {

    //gui
    
    plus_icon(framebuffer);
    minus(framebuffer);
    multiply(framebuffer);
    divide_icon(framebuffer);
    close_icon(framebuffer);




}

void ui_num_1(struct limine_framebuffer *fb) {

    //gui

    uint32_t W = fb->width;
    uint32_t H = fb->height;
    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) -240;
    uint32_t x = (W / 2) - (icon_w / 2) - 70;


    draw_rect(fb, x, y, 300 , 50, 0x303030 );
    draw_text(fb, x + 50 , y + 20, "Type  your first number!!", 0xFFFFFF);
    
}

void ui_num2(struct limine_framebuffer *fb) {
    
    //gui

    uint32_t W = fb->width;
    uint32_t H = fb->height;
    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) -240;
    uint32_t x = (W / 2) - (icon_w / 2) - 70;

    
    draw_rect(fb, x, y, 300 , 50, 0x303030 );
    draw_text(fb, x + 48 , y + 20, "Type  your seccond number!!", 0xFFFFFF);

    
    
}

void ui_sum( struct limine_framebuffer *fb) {

    //gui


    uint32_t W = fb->width;
    uint32_t H = fb->height;
    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) -220;
    uint32_t x = (W / 2) - (icon_w / 2) - 85;

    draw_rect(fb, x, y, 320 , 70, 0x303030 );
    draw_rect(fb, x + 10, y + 31, 300 , 15, 0xFFFF99 );

    draw_text(fb, x + 12, y + 34, "sum:", 0x0000FF);
    draw_text(fb, x + 70, y + 55, "Press [1] to continue", 0xFFFFFF);
    





    //draw_text(framebuffer, 500, 135, "-----------------------------------------", 0xFFFFFF);
    //draw_text(framebuffer, 500, 145, "|            D.Calculator               |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 155, "-----------------------------------------", 0xFFFFFF);
    //draw_text(framebuffer, 500, 165, "| sum:                                  |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 175, "-----------------------------------------", 0xFFFFFF);
    //draw_text(framebuffer, 500, 185, "| [1] continue                          |", 0xFFFFFF);
    //draw_text(framebuffer, 500, 195, "-----------------------------------------", 0xFFFFFF);
    print_main_ui();

}


void input_calculator() {
 
    op = calculator_read_int(450, 230);
    if_else_claculator();


}


void if_else_claculator() {
    if (op == 1) {
        ;
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num_1(framebuffer);
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num2(framebuffer);
        num2 = calculator_read_int(450, 230);
        sum = num1 + num2;
        clear_screen(framebuffer, 0x1A7FFF);
        ui_sum(framebuffer);
        
        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 164, buf, 0x0000FF);
        
        

        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x1A7FFF);
            app_calculator_run();
        }

        

    } else if (op == 2) {
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num_1(framebuffer);
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num2(framebuffer);
        num2 = calculator_read_int(450, 230);
        sum = num1 - num2;
        clear_screen(framebuffer, 0x1A7FFF);
        ui_sum(framebuffer);

        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 164, buf, 0x0000FF);
        
        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x1A7FFF);
            app_calculator_run();


        }
        
    } else if (op == 3) {
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num_1(framebuffer);
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num2(framebuffer);
        num2 = calculator_read_int(450, 230);
        sum = num1 * num2;
        clear_screen(framebuffer, 0x1A7FFF);

        ui_sum(framebuffer);


        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 164, buf, 0x0000FF);
        
        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x1A7FFF);
            app_calculator_run();

        }



    } else if (op == 4) {


        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();
        ui_num_1(framebuffer);
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x1A7FFF);
        print_main_ui();

        ui_num2(framebuffer);
        num2 = calculator_read_int(450, 230);
        if (num2 == 0) {
            sum = 0;
            clear_screen(framebuffer, 0x1A7FFF);
            char buf[32];
            int_to_string(sum, buf);
            draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
            ui_sum(framebuffer);
            while (key == 0) {
                key = input_read_ascii();

            }

            if (key == '1') {
                key = 0;
                clear_screen(framebuffer, 0x1A7FFF);
                app_calculator_run();

            }
        }
        sum = num1 / num2;
        clear_screen(framebuffer, 0x1A7FFF);
        ui_sum(framebuffer);
        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 164, buf, 0x0000FF);
        
        while (key == 0) {
            key = input_read_ascii();

        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x1A7FFF);
            app_calculator_run();

        } 


    } else if (op == 5) {
        clear_screen(framebuffer, 0x1A7FFF);
        ui_desktop();
        return;
    } else {
        app_calculator_run();
    }
}









// GUI

void plus_icon(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2) - 310;



    draw_rect(fb,x, y, 100, 100, 0x99FF99); // square

    draw_rect(fb,x + 50 , y + 30, 5, 40, 0xFF99FF);
    draw_rect(fb,x + 32, y + 47, 40, 5, 0xFF9999);
    draw_text(fb, x + 25, y + 85, "Type 1", 0xFF0000);
    //minus();

    

}


void minus(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) - 180;
    uint32_t x = (W / 2) - (icon_w / 2);



    draw_rect(fb,x , y, 100, 100, 0x99FF99); // square

    draw_rect(fb, x + 32, y + 47 , 40, 5, 0xFF9999);

    draw_text(fb, x + 25, y + 85, "Type 2", 0xFF0000);
    
   


}


void multiply(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) - 50;
    uint32_t x = (W / 2) - (icon_w / 2);




    draw_rect(fb,x, y, 100, 100, 0x99FF99);

    draw_rect(fb,x + 15, y + 5, 5, 5, 0xFF9999);
    draw_rect(fb,x + 20, y + 10, 5, 5, 0xFF9999);
    draw_rect(fb,x + 25, y + 15, 5, 5, 0xFF9999);
    draw_rect(fb,x + 30, y + 20, 5, 5, 0xFF9999);
    draw_rect(fb,x + 35, y + 25, 5, 5, 0xFF9999);
    draw_rect(fb,x + 40, y + 30, 5, 5, 0xFF9999);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0xFF9999);
    draw_rect(fb,x + 50, y + 40, 5, 5, 0xFF9999);
    draw_rect(fb,x + 55, y + 45, 5, 5, 0xFF9999);
    draw_rect(fb,x + 60, y + 50, 5, 5, 0xFF9999);
    draw_rect(fb,x + 65, y + 55, 5, 5, 0xFF9999);
    draw_rect(fb,x + 70, y + 60, 5, 5, 0xFF9999);
    draw_rect(fb,x + 75, y + 65, 5, 5, 0xFF9999);
    


    draw_rect(fb,x + 75, y + 5, 5, 5, 0xFF9999);
    draw_rect(fb,x + 70, y + 10, 5, 5, 0xFF9999);
    draw_rect(fb,x + 65, y + 15, 5, 5, 0xFF9999);
    draw_rect(fb,x + 60, y + 20, 5, 5, 0xFF9999);
    draw_rect(fb,x + 55, y + 25 , 5, 5, 0xFF9999);
    draw_rect(fb,x + 50, y + 30, 5, 5, 0xFF9999);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0xFF9999);
    draw_rect(fb,x + 40, y + 40, 5, 5, 0xFF9999);
    draw_rect(fb,x + 35, y + 45, 5, 5, 0xFF9999);
    draw_rect(fb,x + 30, y + 50 , 5, 5, 0xFF9999);
    draw_rect(fb,x + 25, y + 55, 5, 5, 0xFF9999);
    draw_rect(fb,x + 20, y + 60, 5, 5, 0xFF9999);
    draw_rect(fb,x + 15, y + 65, 5, 5, 0xFF9999);
    draw_text(fb,x + 25, y + 85, "Type 3", 0xFF0000);



    

    

}


void divide_icon(struct limine_framebuffer *fb) {

    uint32_t H = fb->height;
    uint32_t W = fb->width;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) + 80;
    uint32_t x = (W / 2) - (icon_w / 2);


    draw_rect(fb, x, y, 100, 100, 0x99FF99);

    draw_rect(fb,x + 43, y + 25 , 15, 15, 0xFF9999);

    draw_rect(fb, x + 32, y + 47 , 40, 5, 0xFF9999);


    draw_rect(fb,x + 43, y + 60, 15, 15, 0xFF9999);

    draw_text(fb , x + 25, y + 85, "Type 4", 0xFF0000);

}


void close_icon(struct limine_framebuffer *fb) {
    uint32_t H = fb->height;
    uint32_t W = fb->width;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;

    uint32_t y = (H / 2) - (icon_h / 2) + 210;
    uint32_t x = (W / 2) - (icon_w / 2);

    draw_rect(fb, x, y, 100, 100, 0xFF0000);



    draw_rect(fb,x + 15, y + 5, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 20, y + 10, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 25, y + 15, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 30, y + 20, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 35, y + 25, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 40, y + 30, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 50, y + 40, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 55, y + 45, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 60, y + 50, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 65, y + 55, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 70, y + 60, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 75, y + 65, 5, 5, 0xFFFFFF);

    draw_rect(fb,x + 75, y + 5, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 70, y + 10, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 65, y + 15, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 60, y + 20, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 55, y + 25 , 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 50, y + 30, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 40, y + 40, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 35, y + 45, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 30, y + 50 , 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 25, y + 55, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 20, y + 60, 5, 5, 0xFFFFFF);
    draw_rect(fb,x + 15, y + 65, 5, 5, 0xFFFFFF);
    draw_text(fb,x + 25, y + 85, "Type 5", 0xFFFFFF);



    
}