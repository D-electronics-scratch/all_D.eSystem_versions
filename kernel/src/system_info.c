#include <stdint.h>
#include "system_info.h"
#include <limine.h>
#include "system_info.h"

// ---------- CPUID ----------
void cpuid(int code, uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d) {
    asm volatile("cpuid"
                 : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
                 : "a"(code));
}

// ---------- CPU BRAND ----------
void get_cpu_brand(char *brand) {
    uint32_t a, b, c, d;
    uint32_t *ptr = (uint32_t*)brand;

    for (int i = 0; i < 3; i++) {
        cpuid(0x80000002 + i, &a, &b, &c, &d);
        ptr[i*4 + 0] = a;
        ptr[i*4 + 1] = b;
        ptr[i*4 + 2] = c;
        ptr[i*4 + 3] = d;
    }

    brand[48] = 0;
}

// ---------- RAM INFO ----------
__attribute__((used, section(".limine_requests")))
static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST_ID,
    .revision = 0
};

uint64_t get_total_ram() {
    uint64_t total = 0;

    struct limine_memmap_response *resp = memmap_request.response;

    for (uint64_t i = 0; i < resp->entry_count; i++) {
        struct limine_memmap_entry *entry = resp->entries[i];

        if (entry->type == LIMINE_MEMMAP_USABLE) {
            total += entry->length;
        }
    }

    return total;
}