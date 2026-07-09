#pragma once
#include <stdint.h>

struct RSDPDescriptor {
    char signature[8];
    uint8_t checksum;
    char oemid[6];
    uint8_t revision;
    uint32_t rsdt_address;
} __attribute__((packed));

struct ACPISDTHeader {
    char signature[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oemid[6];
    char oemtableid[8];
    uint32_t oemrevision;
    uint32_t creatorid;
    uint32_t creatorrevision;
} __attribute__((packed));

struct FADT {
    struct ACPISDTHeader h;
    uint32_t firmware_ctrl;
    uint32_t dsdt;

    uint8_t reserved;

    uint8_t preferred_pm_profile;
    uint16_t sci_int;
    uint32_t smi_cmd;
    uint8_t acpi_enable;
    uint8_t acpi_disable;
    uint8_t s4bios_req;
    uint8_t pstate_cnt;

    uint32_t pm1a_evt_blk;
    uint32_t pm1b_evt_blk;
    uint32_t pm1a_cnt_blk;
    uint32_t pm1b_cnt_blk;

    // … wir brauchen nicht mehr für Shutdown
} __attribute__((packed));

uint64_t acpi_find_rsdp();
struct FADT* acpi_find_fadt();
void acpi_shutdown();