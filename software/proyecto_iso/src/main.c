#include <stdlib.h>
#include <stdint.h>

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
  // if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK) {
  //   while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_1_MSK);
  //   private_key->n += 1;
  // }
  // else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK) {
  //   while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_2_MSK);
  //   private_key->n += 0xf;
  // }
  // else if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK) {
  //   while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_3_MSK);
  //   private_key->n += 0xff;
  // }
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

// uint16_t decrypt_pixel(private_key_t* private_key, uint16_t* buffer, uint32_t pixel_index) {
//   uint16_t decrypted_pixel = PIXEL_NOT_DECRYPTED;

//   if (
//     // IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & MODE_MSK ||
//     IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK
//     ) {
//     while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK);

//     decrypted_pixel = binary_exponentiation(buffer[pixel_index], private_key->d, private_key->n);
//   }

//   return decrypted_pixel;
// }

int main() {
  uint8_t state = STATE_SETTING_N;

  private_key_t* private_key = (private_key_t*)malloc(sizeof(private_key_t));
  private_key->n = 43423; //A99F
  private_key->d = 28667; //6FFB

  // uint16_t buffer[16] = {
  //   33766, 36577, 8525, 8525,
  //   8525,  8525,  8525, 8525,
  //   8525,  8525,  6856, 8525,
  //   8525,  8525,  8525, 8525
  // };
  // uint16_t* buffer = (uint16_t*)malloc(16 * sizeof(uint16_t));
  // for (uint8_t i = 0; i < 16; i++) {
  //   buffer[i] = i + 1;
  // }

  uint32_t pixel_index = 0;

  while (1) {
    if (state == STATE_SETTING_N) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_SETTING_D;
      }
      else {
        set_private_key_n(private_key);
        set_displays(private_key->n);
      }
    }
    else if (state == STATE_SETTING_D) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_DECRYPTING;
      }
      else {
        set_private_key_d(private_key);
        set_displays(private_key->d);
      }
    }
    else if (state == STATE_DECRYPTING) {
      // if (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK) {
      //   while (IORD_ALTERA_AVALON_PIO_DATA(INPUTS_BASE) & BUTTON_0_MSK);
      //   set_displays(buffer[pixel_index]);
      //   pixel_index = (pixel_index + 1) % 16;
      // }
      // uint16_t decrypted_pixel = decrypt_pixel(private_key, buffer, pixel_index);
      // if (decrypted_pixel != PIXEL_NOT_DECRYPTED) {
      //   pixel_index = (pixel_index + 1) % 16;
      //   set_displays(decrypted_pixel);
      // }
    }
  }

  return 0;
}
