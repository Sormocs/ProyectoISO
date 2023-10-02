#include "altera_avalon_pio_regs.h"
#include "system.h"

#include "pio_control.h"
#include "mem_offsets.h"

/**
 * Sets the value of the PIOs used by the displays.
*/
void set_displays(uint32_t value, uint8_t base) {
  uint8_t displays[6] = { 0 };

  for (uint32_t i = 0; i < 6; i++) {
    displays[i] = value % base;
    value = value / base;
  }

  IOWR(DISPLAY_5_BASE, 0, displays[5]);
  IOWR(DISPLAY_4_BASE, 0, displays[4]);
  IOWR(DISPLAY_3_BASE, 0, displays[3]);
  IOWR(DISPLAY_2_BASE, 0, displays[2]);
  IOWR(DISPLAY_1_BASE, 0, displays[1]);
  IOWR(DISPLAY_0_BASE, 0, displays[0]);
}

void set_private_key_n() {
  uint16_t current_n = IORD(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0);

  if (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0, current_n + 1);
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0, current_n + 0xf);
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0, current_n + 0xff);
  }
}

void set_private_key_d() {
  uint16_t current_d = IORD(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0);

  if (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0, current_d + 1);
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0, current_d + 0xf);
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK);
    IOWR(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0, current_d + 0xff);
  }
}

uint16_t decrypt_pixel(uint16_t encrypted_pixel, private_key_t* private_key) {
  if (IORD(INPUTS_BASE, 0) & MODE_MSK) {
    return binary_exponentiation(encrypted_pixel, private_key->d, private_key->n);
  }

  if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
    return binary_exponentiation(encrypted_pixel, private_key->d, private_key->n);
  }

  return PIXEL_NOT_DECRYPTED;
}