#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "pio_control.h"
#include "rsa.h"

#define STATE_SETTING_D 0
#define STATE_SETTING_N 1
#define STATE_DECRYPTING 2

#define MODE_MSK 0b10000
#define BUTTON_3_MSK 0b01000
#define BUTTON_2_MSK 0b00100
#define BUTTON_1_MSK 0b00010
#define BUTTON_0_MSK 0b00001

#define PIXEL_NOT_DECRYPTED 0xFFFF

void set_private_key_n(private_key_t* private_key) {
  if (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK);
    private_key->n += 1;
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK);
    private_key->n += 0xf;
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK);
    private_key->n += 0xff;
  }
}

void set_private_key_d(private_key_t* private_key) {
  if (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_1_MSK);
    private_key->d += 1;
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_2_MSK);
    private_key->d += 0xf;
  }
  else if (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_3_MSK);
    private_key->d += 0xff;
  }
}

uint16_t decrypt_pixel(uint16_t encrypted_pixel, private_key_t* private_key) {
  uint16_t decrypted_pixel = PIXEL_NOT_DECRYPTED;

  if (/* IORD(INPUTS_BASE, 0) & MODE_MSK || */ IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
    decrypted_pixel = binary_exponentiation(encrypted_pixel, private_key->d, private_key->n);
  }

  return decrypted_pixel;
}

int main() {
  uint8_t state = STATE_SETTING_N;

  private_key_t private_key = {
     .n = 43423, // A99F
     .d = 28667  // 6FFB
  };

  uint16_t buffer[8] = { 33766, 36577, 8525, 11202, 6856,  6201,  14881, 19556 };

  for (uint8_t i = 0; i < 8; i++) {
    set_displays(buffer[i]);
  }

  uint32_t pixel_index = 0;

  while (1) {
    if (state == STATE_SETTING_N) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_SETTING_D;
      }
      else {
        set_private_key_n(&private_key);
        set_displays(private_key.n);
      }
    }
    else if (state == STATE_SETTING_D) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_DECRYPTING;
      }
      else {
        set_private_key_d(&private_key);
        set_displays(private_key.d);
      }
    }
    else if (state == STATE_DECRYPTING) {
      uint16_t encrypted_pixel = buffer[pixel_index];
      uint16_t decrypted_pixel = decrypt_pixel(encrypted_pixel, &private_key);

      if (decrypted_pixel != PIXEL_NOT_DECRYPTED) {
        set_displays(decrypted_pixel);
        pixel_index = (pixel_index + 1) % 8;
      }
    }
  }

  return 0;
}
