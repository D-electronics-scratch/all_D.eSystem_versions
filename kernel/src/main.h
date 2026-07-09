#ifndef MAIN_H
#define MAIN_H

#include "video.h"
#include "calculator.h"
#include "clock.h"
#include "keyboard.h"
#include "keyboard_input.h"
#include "calculator_input.h"
#include "util.h"
#include <limine.h>

// globale variables
extern int op;
extern int num1;
extern int num2;
extern int sum;
extern char key;




//main fuctions 
void kmain(void);
void ASCII_desktop_home(struct limine_framebuffer *fb);
void shutdown_computer();
void app_calculator_run();

#endif