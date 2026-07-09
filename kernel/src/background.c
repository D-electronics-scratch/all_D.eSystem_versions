#include "video.h"
#include "background.h"

static uint32_t lerp_color(uint32_t a, uint32_t b, uint32_t t, uint32_t max) {
    uint8_t ar = (a >> 16) & 0xFF;
    uint8_t ag = (a >> 8) & 0xFF;
    uint8_t ab = a & 0xFF;

    uint8_t br = (b >> 16) & 0xFF;
    uint8_t bg = (b >> 8) & 0xFF;
    uint8_t bb = b & 0xFF;

    uint8_t r = ar + ((br - ar) * t) / max;
    uint8_t g = ag + ((bg - ag) * t) / max;
    uint8_t b2 = ab + ((bb - ab) * t) / max;

    return (r << 16) | (g << 8) | b2;
}

void draw_wallpaper_gradient(struct limine_framebuffer *fb) {
    uint32_t top = 0xFF00FF;     // Pink
    uint32_t bottom = 0x00FFFF;  // Cyan

    for (uint32_t y = 0; y < fb->height; y++) {
        uint32_t color = lerp_color(top, bottom, y, fb->height);

        for (uint32_t x = 0; x < fb->width; x++) {
            putpixel(fb, x, y, color);
        }
    }
}
