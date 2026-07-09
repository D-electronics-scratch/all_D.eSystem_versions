#include "video.h"
#include "d_e_shell.h"
#include "keyboard.h"
#include "keyboard_input.h"
#include "calculator_input.h"
#include "util.h"
#include "calculator.h"
#include "clock.h"
#include "main.h"
#include "D_e_System_version.h"

char cmd[51];
int shell_open;

void d_eShell_run();
void d_e_shell_ui();
void shell_input();
void if_else_shell();
void d_e_shell_loop();

void d_e_shell_loop() {
    while(1) {
        if(shell_open == 1) {
            shell_input();

        } else if(shell_open == 2) {
            break;
        }
    } 
  
}

void shell_input() {
    keyboard_read_string(cmd, 51);
    if_else_shell();

}

void d_e_shell_ui() {

    clear_screen(framebuffer, 0x202020);
    print_main_ui();
    draw_text(framebuffer, 430, 50, "--------------------------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 430, 60, "|                         D.eShell                     |", 0xFFFFFF);
    draw_text(framebuffer, 430, 70, "--------------------------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 430, 80, "|  type cl to close      type help to show commands    |", 0xFFFFFF);
    draw_text(framebuffer, 430, 90, "--------------------------------------------------------", 0xFFFFFF);

}

void d_e_shell() {
    shell_open = 1;
    d_e_shell_ui();
    d_e_shell_loop();
    

    


    

}

void if_else_shell() {
    if (strcmp(cmd, "cl") == 0) {
        
        shell_open = 2;
        clear_screen(framebuffer, 0x0000FF);
        draw_text(framebuffer, 430, 50, "--------------------------------------------------------", 0xFF0000);
        draw_text(framebuffer, 430, 60, "|              Press anything to continue              |", 0xFF0000);
        draw_text(framebuffer, 430, 70, "--------------------------------------------------------", 0xFF0000);
        //ui_desktop();
        return;
        

    //} //else {
        //d_e_shell();

    } else if (strcmp(cmd, "help") == 0) {
        d_e_shell_ui();
        draw_text(framebuffer, 430, 100, "|You can type: calculator7open, clock7open, pc7shutdown|", 0xFFFFFF);
        draw_text(framebuffer, 430, 110, "|, de7version, shell7version, gui7version              |", 0xFFFFFF);
        draw_text(framebuffer, 430, 120, "--------------------------------------------------------", 0xFFFFFF);
        
        

    } else if(strcmp(cmd, "calculator7open") == 0) {
        shell_open = 2;
        
        app_calculator_run();
        return;

    } else if(strcmp(cmd, "clock7open") == 0) {
        shell_open = 2;
        run_clock_d_elec();
    } else if(strcmp(cmd, "pc7shutdown") == 0) {
        shutdown_computer();

    } else if(strcmp(cmd, "de7version") == 0) {
        D_e_Sys_v_run();

    } else if(strcmp(cmd, "shell7version") == 0) {
        d_e_shell_ui();
        draw_text(framebuffer, 430, 100, "|D.eShell version: D.eShell 1.0                        |", 0xFFFFFF);
        draw_text(framebuffer, 430, 120, "--------------------------------------------------------", 0xFFFFFF);

    } else if (strcmp(cmd, "gui7version") == 0) {
        d_e_shell_ui();
        draw_text(framebuffer, 430, 100, "| GUI version: D.UI 11                                 |", 0xFFFFFF);
        draw_text(framebuffer, 430, 120, "--------------------------------------------------------", 0xFFFFFF);


        

    } else {
        d_e_shell_ui();
    }
    
} 