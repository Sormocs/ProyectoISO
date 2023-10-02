#pragma once

#include <stdint.h>

#include "processing.h"

#define MODE_MSK 0b10000
#define BUTTON_3_MSK 0b01000
#define BUTTON_2_MSK 0b00100
#define BUTTON_1_MSK 0b00010
#define BUTTON_0_MSK 0b00001

void set_displays(uint32_t value, uint8_t base);

void set_private_key_n(private_key_t* private_key);

void set_private_key_d(private_key_t* private_key);

uint16_t decrypt_pixel(uint16_t encrypted_pixel, private_key_t* private_key);
