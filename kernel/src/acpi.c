#include "acpi.h"
#include "string.h"

uint64_t acpi_find_rsdp() {
    for (uint64_t addr = 0x000E0000; addr < 0x00100000; addr += 16) {
        if (memcmp((void*)addr, "RSD PTR ", 8) == 0) {
            return addr;
        }
    }
    return 0;
}

struct FADT* acpi_find_fadt() {
    uint64_t rsdp_addr = acpi_find_rsdp();
    if (!rsdp_addr) return NULL;

    struct RSDPDescriptor* rsdp = (void*)rsdp_addr;
    struct ACPISDTHeader* rsdt = (void*)(uint64_t)rsdp->rsdt_address;

    int entries = (rsdt->length - sizeof(struct ACPISDTHeader)) / 4;
    uint32_t* table_ptr = (uint32_t*)((uint64_t)rsdt + sizeof(struct ACPISDTHeader));

    for (int i = 0; i < entries; i++) {
        struct ACPISDTHeader* hdr = (struct ACPISDTHeader*)(uint64_t)table_ptr[i];

        if (memcmp(hdr->signature, "FACP", 4) == 0) {
            return (struct FADT*)hdr;
        }
    }

    return NULL;
}


extern void outw(uint16_t port, uint16_t value);

void acpi_shutdown() {
    struct FADT* fadt = acpi_find_fadt();
    if (!fadt) return;

    uint16_t pm1a = fadt->pm1a_cnt_blk;

    // S5 = 0x5 (QEMU + viele echte PCs)
    uint16_t SLP_TYP_S5 = 0x5;

    uint16_t value = (SLP_TYP_S5 << 10) | (1 << 13); // SLP_EN
    outw(pm1a, value);

    for (;;) asm("hlt");
}

