#pragma once
#include <stdint.h>

void cpuid(int code, uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d);
void get_cpu_brand(char *brand);
uint64_t get_total_ram();