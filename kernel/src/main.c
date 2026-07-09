#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include "keyboard.h"
#include "limine.h"
#include "video.h"
#include "calculator.h"
#include "main.h"
#include "D_e_System_version.h"


struct limine_framebuffer *framebuffer;










// Set the base revision to 6, this is recommended as this is the latest
// base revision described by the Limine boot protocol specification.
// See specification for further info.

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent, _and_ they should be accessed at least
// once or marked as used with the "used" attribute as done here.

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

// Finally, define the start and end markers for the Limine requests.
// These can also be moved anywhere, to any .c file, as seen fit.

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] = LIMINE_REQUESTS_END_MARKER;

// Halt and catch fire function.
static void hcf(void) {
    for (;;) {
        asm ("hlt");
    }
}

// The following will be our kernel's entry point.
// If renaming kmain() to something else, make sure to change the
// linker script accordingly.










void ASCII_desktop_home(struct limine_framebuffer *framebuffer);
void shutdown_computer();
void app_calculator_run();







void kmain(void) {

    


    
    
    if (LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision) == false) {
        hcf();
    }

    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    framebuffer = framebuffer_request.response->framebuffers[0];
    volatile uint32_t *fb = framebuffer->address;

    while (1) {
        // render screen new
        for (size_t y = 0; y < framebuffer->height; y++) {
            for (size_t x = 0; x < framebuffer->width; x++) {
                fb[y * (framebuffer->pitch / 4) + x] = 0x202020;
            }
        }


        print_main_ui();
        ASCII_desktop_home(framebuffer);

        char key = 0;
        while (key == 0) {
            key = ps2_read_key();
        }

        if (key == 27) {
            shutdown_computer();
        } else if (key == '2') {
            app_calculator_run();   
        } else if (key == '3') {
            run_clock_d_elec();     
        } else if (key == '4') {
            D_e_Sys_v_run();

        }

    }
}


void ASCII_desktop_home(struct limine_framebuffer *framebuffer) {

    ui_desktop();

    char key = 0;

    //main menu input
    while(key == 0) {
        key = ps2_read_key();
    }

    if (key == '1') {
        draw_text(framebuffer, 500, 130, "Shutdown selected", 0xFFFFFF);
        shutdown_computer();

    } else if (key == '2') {
        app_calculator_run();
        
    } else if (key == '3') {

        run_clock_d_elec();

    } else if (key == '4') {
        D_e_Sys_v_run();
    } else if (key == '5') {
        d_e_shell();

    } else if (key == '6') {
        run_thunder_calc();
    }
    
}

void shutdown_computer() {
    acpi_shutdown();

}