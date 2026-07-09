#include "sleep.h"
#include <stdint.h>

uint64_t tick = 3000000;


static inline uint64_t rdtsc(void) {
    uint32_t lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

void sleep(int ms) {
    if (ms <= 0) return;

    uint64_t start = rdtsc();
    uint64_t target = start + (uint64_t)ms * tick;

    while (rdtsc() < target) {
        
    }
}