#pragma once

#include <stdint.h>

typedef struct {
  uint16_t d;
  uint16_t n;
} private_key_t;

uint16_t binary_exponentiation(uint16_t base, uint16_t exp, uint16_t mod);
