#include "video.h"
#include "main.h"
#include "keyboard.h"
#include "keyboard_input.h"
#include "util.h"
#include "clock.h"
#include <limine.h>
#include "main_ui.h"
#include "desktop_ui.h"
#include "calculator_input.h"
#include "sleep.h"


int hour = 0;
int min = 0;
int sec = 0;
int t_sec;
int t_sec2;
int clock_on_off;



void run_clock_d_elec();
void clock_ui();
void time_ui();
void timer(struct limine_framebuffer *fb);
void clock_icon_app();
void set_timer_ui();
void timer_running_ui();
void timer_finished_ui();
void hour_ui();
void minute_ui();
void seccond_ui();




void clock_ui(struct limine_framebuffer *fb) {
    timer(framebuffer);
    clock_icon_app(framebuffer);

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2) ;



    //clos icon

    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb,x + 15, y + 5, 5, 5, 0x0078D7);
    draw_rect(fb,x + 20, y + 10, 5, 5, 0x0078D7);
    draw_rect(fb,x + 25, y + 15, 5, 5, 0x0078D7);
    draw_rect(fb,x + 30, y + 20, 5, 5, 0x0078D7);
    draw_rect(fb,x + 35, y + 25, 5, 5, 0x0078D7);
    draw_rect(fb,x + 40, y + 30, 5, 5, 0x0078D7);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0x0078D7);
    draw_rect(fb,x + 50, y + 40, 5, 5, 0x0078D7);
    draw_rect(fb,x + 55, y + 45, 5, 5, 0x0078D7);
    draw_rect(fb,x + 60, y + 50, 5, 5, 0x0078D7);
    draw_rect(fb,x + 65, y + 55, 5, 5, 0x0078D7);
    draw_rect(fb,x + 70, y + 60, 5, 5, 0x0078D7);
    draw_rect(fb,x + 75, y + 65, 5, 5, 0x0078D7);

    draw_rect(fb,x + 75, y + 5, 5, 5, 0x0078D7);
    draw_rect(fb,x + 70, y + 10, 5, 5, 0x0078D7);
    draw_rect(fb,x + 65, y + 15, 5, 5, 0x0078D7);
    draw_rect(fb,x + 60, y + 20, 5, 5, 0x0078D7);
    draw_rect(fb,x + 55, y + 25 , 5, 5, 0x0078D7);
    draw_rect(fb,x + 50, y + 30, 5, 5, 0x0078D7);
    draw_rect(fb,x + 45, y + 35, 5, 5, 0x0078D7);
    draw_rect(fb,x + 40, y + 40, 5, 5, 0x0078D7);
    draw_rect(fb,x + 35, y + 45, 5, 5, 0x0078D7);
    draw_rect(fb,x + 30, y + 50 , 5, 5, 0x0078D7);
    draw_rect(fb,x + 25, y + 55, 5, 5, 0x0078D7);
    draw_rect(fb,x + 20, y + 60, 5, 5, 0x0078D7);
    draw_rect(fb,x + 15, y + 65, 5, 5, 0x0078D7);
    draw_text(fb,x + 8, y + 85, "Press [Esc]", 0x0078D7);

    








}

void time_ui() {
    draw_text(framebuffer, 500, 50, "----------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 60, "|Time:                                 |", 0xFFFFFF);
    draw_text(framebuffer, 500, 70, "----------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 80, "| Press [Esc]  to leave!!              |", 0xFFFFFF);
    draw_text(framebuffer, 500, 70, "----------------------------------------", 0xFFFFFF);

}


void run_clock_d_elec() {
   
    key = 0;
    clock_on_off = 0;

    

    clear_screen(framebuffer, 0x0078D7);
    print_main_ui();
   
    clock_ui(framebuffer);
    

    while (key == 0) {
        key = ps2_read_key();
    }

    if (key == 27) {
        clear_screen(framebuffer, 0x000000);
        ui_desktop();
        clock_on_off = 2;
        return;
        
    } else if (key == '1') {
        clear_screen(framebuffer, 0x0078D7);
        print_main_ui();

        set_timer_ui(framebuffer);


        t_sec = calculator_read_int(450, 230);
        t_sec2 = t_sec * 1000;
        clear_screen(framebuffer, 0x0078D7);
        print_main_ui();

        timer_running_ui(framebuffer);

       
        sleep (t_sec2); 
        clear_screen(framebuffer, 0x0078D7);
        print_main_ui();
        timer_finished_ui(framebuffer);
        

        
        char buf[32];
        itoa(t_sec, buf, 10);
        draw_text(framebuffer, 500, 200, buf, 0xFFFFFF);
        
        key = 0;
        while (key == 0) {
            key = ps2_read_key();
        }
        if (key == '1') {
            return;
        }

        
    } else if (key == '2') {
        key = 0;
        clear_screen(framebuffer, 0x0078D7);
        print_main_ui();
       

        hour_ui(framebuffer);


        hour = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x0078D7);print_main_ui();
       

        minute_ui(framebuffer);


        min = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x0078D7);print_main_ui();
        print_main_ui();
        seccond_ui(framebuffer);
       
        sec = calculator_read_int(450, 230);
        
        clear_screen(framebuffer, 0x0078D7);print_main_ui();
        
        print_main_ui();
        time_ui();

        clock_on_off = 1;

        while (key == 0) {
            key = ps2_read_key();
        }
        if (key == 27) {
            run_clock_d_elec();

        } 


    }
 
 
    

 while (1) {

    if (clock_on_off == 1) {

        sleep(1000);   
        sec++;

       
        if (sec >= 60) {
            sec = 0;
            min++;
        }

        if (min >= 60) {
            min = 0;
            hour++;
        }

        if (hour >= 24) {
            hour = 0;
        }

       
        clear_screen(framebuffer, 0x0078D7);
        print_main_ui();
        time_ui();

        
        char buf_sec[8];
        char buf_min[8];
        char buf_hour[8];

        itoa(sec, buf_sec, 10);
        itoa(min, buf_min, 10);
        itoa(hour, buf_hour, 10);

        draw_text(framebuffer, 590, 60, buf_sec, 0xffffff);
        draw_text(framebuffer, 573, 60, buf_min, 0xffffff);
        draw_text(framebuffer, 555, 60, buf_hour, 0xffffff);

        
        if (clock_on_off == 2) {
            break;
        }
    }
}

}





void timer(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2) + 130;
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 25, y + 10, 50, 5, 0x0078D7);
    draw_rect(fb, x + 25, y + 10, 5, 25, 0x0078D7 );
    draw_rect(fb, x + 70, y + 10, 5, 25, 0x0078D7 );
    draw_rect(fb, x + 25, y + 35, 50, 5, 0x0078D7);
    draw_rect(fb, x + 35, y + 40, 5, 15, 0x0078D7 );
    draw_rect(fb, x + 60, y + 40, 5, 15, 0x0078D7 );
    draw_rect(fb, x + 25, y + 55, 50, 5, 0x0078D7);
    draw_rect(fb, x + 25, y + 60, 5, 15, 0x0078D7 );
    draw_rect(fb, x + 70, y + 60, 5, 15, 0x0078D7 );
    draw_rect(fb, x + 25, y + 70, 50, 10, 0x0078D7);
    draw_text(fb, x + 15, y + 85, "Press [1]", 0x0078D7 );

    


}



void clock_icon_app(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 100;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2) - 130;
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);



    draw_rect(fb, x + 10, y + 10, 10, 60, 0x0078D7);
    draw_rect(fb, x + 80, y + 10, 10, 60, 0x0078D7);

    draw_rect(fb, x + 20, y + 10, 60, 10, 0x0078D7);
    draw_rect(fb, x + 20, y + 60, 60, 10, 0x0078D7);

  
    draw_rect(fb, x + 50, y + 37, 4, 17, 0x0078D7);
    draw_rect(fb, x + 50, y + 37, 20, 4, 0x0078D7);


    draw_text(fb, x + 15, y + 85, "Press [2]", 0x0078D7 );




}

void set_timer_ui(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 40, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 45, "How many secconds?", 0x00D4FF);

}



void timer_running_ui(struct limine_framebuffer *fb) {



    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 40, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 45, " Timer is runing! ", 0x00D4FF);



}




void timer_finished_ui(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 15, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 20, "     Finished!     ", 0x00D4FF);

    draw_rect(fb, x + 100, y + 65, 200, 20, 0x0078D7);

    draw_text(fb, x + 130, y + 70, "Press [1] to continue", 0x00D4FF);


    


}


void hour_ui(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 40, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 45, "      hour?      ", 0x00D4FF);

}




void minute_ui(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 40, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 45, "     minute?      ", 0x00D4FF);

}





void seccond_ui(struct limine_framebuffer *fb) {

    uint32_t W = fb->width;
    uint32_t H = fb->height;

    uint32_t icon_w = 400;
    uint32_t icon_h = 100;
    uint32_t x = (W / 2) - (icon_w / 2);
    uint32_t y = (H / 2) - (icon_h / 2);


    draw_rect(fb, x, y, icon_w, icon_h, 0x00D4FF);

    draw_rect(fb, x + 100, y + 40, 200, 20, 0x0078D7);
    draw_text(fb, x + 130, y + 45, "     seccond?      ", 0x00D4FF);

}



