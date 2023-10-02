#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096

#define SDRAM_BASE 0xC0000000
#define SDRAM_SPAN 0x4000000

#define STATE_OFFSET 0x00000000
#define PROCESSING_PERCENTAGE_OFFSET 0x00000004
#define FINISHED_OFFSET 0x00000008
#define PRIVATE_KEY_N_OFFSET 0x0000000C
#define PRIVATE_KEY_D_OFFSET 0x00000010
#define IMAGE_WIDTH_OFFSET 0x000000014
#define IMAGE_HEIGHT_OFFSET 0x00000018
#define TOTAL_PIXELS_OFFSET 0x0000001C
#define ENCRYPTED_IMAGE_OFFSET 0x00000020

#define STATE_SETTING_MEM 0
#define STATE_SETTING_N 1
#define STATE_SETTING_D 2
#define STATE_GETTING_DIMENSIONS 3
#define STATE_DECRYPTING 4

const uint8_t encrypted_image_path[256] = "encrypted_image.txt";


uint8_t load_encrypted_image(volatile uint32_t* mem_ptr) {
	FILE* encrypted_image;

	encrypted_image = fopen(encrypted_image_path, "r");
	if (encrypted_image == NULL) {
		printf("Error opening file %s\n", encrypted_image_path);
		return 1;
	}

	uint8_t encrypted_pixel_digits = ceil(16 / log10(2));
	uint8_t pixel[encrypted_pixel_digits];
	uint8_t pixel_index = 0;

	uint8_t buffer[BUFFER_SIZE];
	while (fread(buffer, sizeof(char), BUFFER_SIZE, encrypted_image) > 0) {
		for (uint32_t i = 0; i < BUFFER_SIZE; i++) {
			const uint8_t character = buffer[i];

			if (character == '\n' || character == ' ') { continue; }

			if (character == ',' || character == '\0') {
				pixel[pixel_index + 1] = '\0';

				mem_ptr[ENCRYPTED_IMAGE_OFFSET + 4 * pixel_index] = atoi(pixel);

				memset(pixel, 0, encrypted_pixel_digits);
				pixel_index = 0;
				continue;
			}

			pixel[pixel_index] = character;
			pixel_index++;
		}

		memset(buffer, 0, BUFFER_SIZE);
	}

	fclose(encrypted_image);

	return 0;
}

int main() {
	uint8_t mem = open("/dev/mem", O_RDWR);
	if (mem < 0) {
		perror("open(\"/dev/mem\")");
		return 1;
	}

	uint32_t MEMORY_SIZE = sizeof(uint8_t) * SDRAM_SPAN;
	uint32_t* mapping = mmap
	(
		NULL,
		MEMORY_SIZE,
		PROT_READ | PROT_WRITE,
		MAP_SHARED,
		mem,
		SDRAM_BASE
	);
	if (mapping == MAP_FAILED) {
		perror("mmap()");
		return 1;
	}

	volatile uint8_t* mem_ptr = (void*)(mapping);

	// Sets memory to 0
	for (uint32_t i = 0; i < SDRAM_SPAN; i++) {
		mem_ptr[i] = (uint8_t)i;
	}

	// if (load_encrypted_image(mem_ptr)) { return 1; };

	// mem_ptr[PRIVATE_KEY_N_OFFSET] = 43423;
	// mem_ptr[PRIVATE_KEY_D_OFFSET] = 28667;

	// mem_ptr[STATE_OFFSET] = STATE_SETTING_N;

	uint32_t state;
	uint32_t private_key_n;
	uint32_t private_key_d;
	uint32_t image_width;
	uint32_t image_height;
	uint32_t total_pixels;
	while (1) {
		state = mem_ptr[STATE_OFFSET];
		private_key_n = mem_ptr[PRIVATE_KEY_N_OFFSET];
		private_key_d = mem_ptr[PRIVATE_KEY_D_OFFSET];
		image_width = mem_ptr[IMAGE_WIDTH_OFFSET];
		image_height = mem_ptr[IMAGE_HEIGHT_OFFSET];
		total_pixels = mem_ptr[TOTAL_PIXELS_OFFSET];

		printf("---------------------------------------------------------\n");
		printf("State = %d\n", state);

		printf("Private key n = %d\n", private_key_n);
		printf("Private key d = %d\n", private_key_d);

		printf("Image width = %d\n", image_width);
		printf("Image height = %d\n", image_height);
		printf("Total pixels = %d\n", total_pixels);
		printf("---------------------------------------------------------\n");

		sleep(2);
	}

	munmap(mapping, MEMORY_SIZE);
	close(mem);

	return 0;
}