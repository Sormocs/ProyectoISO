#include <stdlib.h>
#include <stdint.h>

#include "altera_avalon_pio_regs.h"
#include "system.h"

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

void set_private_key_d(private_key_t* private_key) {
  if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK);
    private_key->d += 1;
  }
  else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK);
    private_key->d += 0xf;
  }
  else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK);
    private_key->d += 0xff;
  }
}

void set_private_key_n(private_key_t* private_key) {
  if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK);
    private_key->n += 1;
  }
  else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK);
    private_key->n += 0xf;
  }
  else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK) {
    while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK);
    private_key->n += 0xff;
  }
}

void decrypt_pixel(private_key_t* private_key) {
  // if ((state & MODE_MSK) || (state & BUTTON_0_MSK)) {
    //   uint16_t decrypted_pixel = binary_exponentiation(buffer[pixel_index], private_key->d, private_key->n);
    //   pixel_index = (pixel_index + 1) % 16;

    //   set_displays(decrypted_pixel);
    // }
}

int main() {
  uint8_t state = STATE_SETTING_D;

  private_key_t* private_key = (private_key_t*)malloc(sizeof(private_key_t));
  private_key->d = 0;
  private_key->n = 0;

  // uint32_t pixel_index = 0;
  // uint16_t buffer[16] = {
  //   33766, 36577, 8525, 8525,
  //   8525,  8525,  8525, 8525,
  //   8525,  8525,  6856, 8525,
  //   8525,  8525,  8525, 8525
  // };

  while (1) {
    if (state == STATE_SETTING_D) {
      if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK) {
        while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK);
        state = STATE_SETTING_N;
      }
      else {
        set_private_key_d(private_key);
        set_displays(private_key->d);
      }
    }
    else if (state == STATE_SETTING_N) {
      if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK) {
        while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK);
        state = STATE_DECRYPTING;
      }
      else {
        set_private_key_n(private_key);
        set_displays(private_key->n);
      }
    }
    else if (state == STATE_DECRYPTING) {
      if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK) {
        while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK);
        state = STATE_SETTING_D;
      }
      else {
        decrypt_pixel(private_key);
        set_displays(0xFAFAFA);
      }
    }
  }

  return 0;
}
