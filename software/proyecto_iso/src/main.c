#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "pio_control.h"
#include "processing.h"

#define STATE_SETTING_D 0
#define STATE_SETTING_N 1
#define STATE_GETTING_DIMENSIONS 2
#define STATE_DECRYPTING 3

void checkMem() {
	volatile unsigned int* ptr = (volatile unsigned int*)SDRAM_BASE;

	for (uint8_t i = 0; i < 10; i++) {
		if (ptr[i] > 9) {
			set_displays(0xFFFF, 16);
		}
		else {
			set_displays(ptr[i], 16);
		}

		usleep(1000 * 1000 * 1);
	}
}

int main() {
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

	checkMem();
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
				state = STATE_GETTING_DIMENSIONS;
			}
			else {
				set_private_key_d(&private_key);
				set_displays(private_key.d, 16);
			}
		}
		else if (state == STATE_GETTING_DIMENSIONS) {
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
