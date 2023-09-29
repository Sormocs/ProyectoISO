#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "pio_control.h"
#include "rsa.h"

#define STATE_SETTING_D 0
#define STATE_SETTING_N 1
#define STATE_GET_DIMENSIONS 2
#define STATE_DECRYPTING 3

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
  if (IORD(INPUTS_BASE, 0) & MODE_MSK) {
    return binary_exponentiation(encrypted_pixel, private_key->d, private_key->n);
  }

  if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
    while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
    return binary_exponentiation(encrypted_pixel, private_key->d, private_key->n);
  }

  return PIXEL_NOT_DECRYPTED;
}

void checkMem(){

	volatile unsigned int *ptr = (volatile unsigned int*)SDRAM_0_BASE;

	if(ptr[0] != 0){
		IOWR(LEDS_BASE,1,0xb0000000001);
	}
	if(ptr[1] != 0){
		IOWR(LEDS_BASE,1,0xb0000000011);
	}
	if(ptr[2] != 0){
		IOWR(LEDS_BASE,1,0xb0000000111);
	}
	if(ptr[3] != 0){
		IOWR(LEDS_BASE,1,0xb0000001111);
	}
	if(ptr[4] != 0){
		IOWR(LEDS_BASE,1,0xb0000011111);
	}
	if(ptr[5] != 0){
		IOWR(LEDS_BASE,1,0xb0001111111);
	}
	if(ptr[6] != 0){
		IOWR(LEDS_BASE,1,0xb0011111111);
	}
	if(ptr[7] != 0){
		IOWR(LEDS_BASE,1,0xb0111111111);
	}
	if(ptr[8] != 0){
		IOWR(LEDS_BASE,1,0xb1111111111);
	}
	if(ptr[9] != 0){
		IOWR(LEDS_BASE,1,0xb1000100001);
	}

}

int main() {

  checkMem();

  uint8_t state = STATE_SETTING_N;

  private_key_t private_key = {
    .n = 43423, // A99F
    .d = 28667  // 6FFB
  };

  uint16_t buffer[8] = { 33766, 36577, 8525, 11202, 6856,  6201,  14881, 19556 };

  uint16_t width = 0;
  uint16_t height = 0;
  uint32_t total_pixels = 0;

  uint32_t pixel_index = 0;

  while (1) {
    if (state == STATE_SETTING_N) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_SETTING_D;
      }
      else {
        set_private_key_n(&private_key);
        set_displays(private_key.n, 16);
      }
    }
    else if (state == STATE_SETTING_D) {
      if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
        while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
        state = STATE_GET_DIMENSIONS;
      }
      else {
        set_private_key_d(&private_key);
        set_displays(private_key.d, 16);
      }
    }
    else if (state == STATE_GET_DIMENSIONS) {
      if (width == 0 && pixel_index == 0) {
        width = binary_exponentiation(buffer[pixel_index], private_key.d, private_key.n);
        pixel_index++;
      }

      set_displays(width, 10);
      usleep(1000 * 1000 * 1);

      if (height == 0 && pixel_index == 1) {
        height = binary_exponentiation(buffer[pixel_index], private_key.d, private_key.n);
        pixel_index++;
      }

      set_displays(height, 10);
      usleep(1000 * 1000 * 1);

      if (width != 0 && height != 0) {
        total_pixels = width * height;
        state = STATE_DECRYPTING;
        continue;
      }

      pixel_index = 0;
    }
    else if (state == STATE_DECRYPTING) {
      uint16_t encrypted_pixel = buffer[pixel_index];
      uint16_t decrypted_pixel = decrypt_pixel(encrypted_pixel, &private_key);

      if (decrypted_pixel != PIXEL_NOT_DECRYPTED) {
        set_displays(decrypted_pixel, 10);
        pixel_index = (pixel_index + 1) % 8;
        // pixel_index = (pixel_index + 1) % total_pixels;
        if (pixel_index == 0) {
          pixel_index = 2;
        }
        usleep(1000 * 1000 * 0.25);
      }
    }
  }

  return 0;
}
