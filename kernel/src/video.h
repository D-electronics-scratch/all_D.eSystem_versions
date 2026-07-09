#pragma once
#include <stdint.h>
#include <limine.h>

extern struct limine_framebuffer *framebuffer;

void putpixel(struct limine_framebuffer *fb, uint32_t x, uint32_t y, uint32_t color);
void draw_char(struct limine_framebuffer *fb, uint32_t x, uint32_t y, char c, uint32_t color);
void draw_text(struct limine_framebuffer *fb, uint32_t x, uint32_t y, const char *text, uint32_t color);
void draw_rect(struct limine_framebuffer *fb, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
void fill_screen_gray(struct limine_framebuffer *fb);
void clear_screen(struct limine_framebuffer *fb, uint32_t color);