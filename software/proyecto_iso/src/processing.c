#include "processing.h"

uint16_t binary_exponentiation(uint16_t base, uint16_t exp, uint16_t mod) {
  uint32_t result = 1;

  base = base % mod;
  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % mod;
    }

    base = (base * base) % mod;
    exp = exp >> 1;
  }

  return (uint16_t)result;
}
