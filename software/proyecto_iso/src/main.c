#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "pio_control.h"
#include "processing.h"
#include "mem_offsets.h"


#define STATE_SETTING_MEM 0
#define STATE_SETTING_N 1
#define STATE_SETTING_D 2
#define STATE_GETTING_DIMENSIONS 3
#define STATE_DECRYPTING 4

void checkMem() {
	volatile unsigned int* ptr = (volatile unsigned int*)(SDRAM_BASE);

	for (uint32_t i = 0; i < SDRAM_SPAN; i++) {
		set_displays(ptr[i], 10);
		usleep(1000 * 1000 * 0.5);
	}
}

int main() {
	// checkMem();
	volatile unsigned int* mem_ptr = (volatile unsigned int*)(SDRAM_BASE);

	uint8_t state;
	uint32_t pixel_index = 0;
	while (1) {
		// state = IORD(SDRAM_BASE + STATE_OFFSET, 0);
		state = mem_ptr[STATE_OFFSET];

		set_displays(IORD_8DIRECT(SDRAM_BASE, STATE_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		set_displays(IORD_16DIRECT(SDRAM_BASE, PRIVATE_KEY_N_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		set_displays(IORD_16DIRECT(SDRAM_BASE, PRIVATE_KEY_D_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		set_displays(IORD_16DIRECT(SDRAM_BASE, IMAGE_WIDTH_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		set_displays(IORD_16DIRECT(SDRAM_BASE, IMAGE_HEIGHT_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		set_displays(IORD_32DIRECT(SDRAM_BASE, TOTAL_PIXELS_OFFSET), 16);
		usleep(1000 * 1000 * 2);

		// if (state == STATE_SETTING_N) {
		// 	if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
		// 		while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
		// 		IOWR(SDRAM_BASE + STATE_OFFSET, 0, STATE_SETTING_D);
		// 	}
		// 	else {
		// 		set_private_key_n();
		// 		set_displays(IORD(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0), 16);
		// 	}
		// }
		// else if (state == STATE_SETTING_D) {
		// 	if (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK) {
		// 		while (IORD(INPUTS_BASE, 0) & BUTTON_0_MSK);
		// 		IOWR(SDRAM_BASE + STATE_OFFSET, 0, STATE_GETTING_DIMENSIONS);
		// 	}
		// 	else {
		// 		set_private_key_d();
		// 		set_displays(IORD(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0), 16);
		// 	}
		// }
		// else if (state == STATE_GETTING_DIMENSIONS) {
		// 	uint16_t private_key_n = IORD(SDRAM_BASE + PRIVATE_KEY_N_OFFSET, 0);
		// 	uint16_t private_key_d = IORD(SDRAM_BASE + PRIVATE_KEY_D_OFFSET, 0);

		// 	uint16_t width = 0;
		// 	uint16_t height = 0;

		// 	if (width == 0 && pixel_index == 0) {
		// 		uint16_t encrypted_value = IORD(SDRAM_BASE + ENCRYPTED_IMAGE_OFFSET + 4 * pixel_index, 0);
		// 		width = binary_exponentiation(encrypted_value, private_key_d, private_key_n);
		// 		pixel_index++;
		// 	}

		// 	set_displays(width, 10);
		// 	usleep(1000 * 1000 * 1);

		// 	if (height == 0 && pixel_index == 1) {
		// 		uint16_t encrypted_value = IORD(SDRAM_BASE + ENCRYPTED_IMAGE_OFFSET + 4 * pixel_index, 0);
		// 		height = binary_exponentiation(encrypted_value, private_key_d, private_key_n);
		// 		pixel_index++;
		// 	}

		// 	set_displays(height, 10);
		// 	usleep(1000 * 1000 * 1);

		// 	if (width != 0 && height != 0) {
		// 		IOWR(SDRAM_BASE + IMAGE_WIDTH_OFFSET, 0, width);
		// 		IOWR(SDRAM_BASE + IMAGE_HEIGHT_OFFSET, 0, height);
		// 		IOWR(SDRAM_BASE + TOTAL_PIXELS_OFFSET, 0, width * height);

		// 		// IOWR(SDRAM_BASE + STATE_OFFSET, 0, STATE_DECRYPTING);
		// 		continue;
		// 	}

		// 	pixel_index = 0;
		// }
		// else if (state == STATE_DECRYPTING) {
		// 	// uint16_t encrypted_pixel = buffer[pixel_index];
		// 	// uint16_t decrypted_pixel = decrypt_pixel(encrypted_pixel, &private_key);

		// 	// if (decrypted_pixel != PIXEL_NOT_DECRYPTED) {
		// 	// 	set_displays(decrypted_pixel, 10);
		// 	// 	pixel_index = (pixel_index + 1) % 8;
		// 	// 	// pixel_index = (pixel_index + 1) % total_pixels;
		// 	// 	if (pixel_index == 0) {
		// 	// 		pixel_index = 2;
		// 	// 	}
		// 	// 	usleep(1000 * 1000 * 0.25);
		// 	// }
		// }
	}

	return 0;
}
