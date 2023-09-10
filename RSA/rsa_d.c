#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#define BUFFER_SIZE 4096

const uint8_t encrypted_image_path[256] = "imagen.txt";
const uint8_t decrypted_image_path[256] = "decrypted_image.txt";

uint8_t decrypt(uint8_t encrypted_pixel)
{
  uint8_t decrypted_pixel = 0;

  printf("Encrypted pixel: %d\n", encrypted_pixel);
}

int main()
{
  FILE* fp;

  fp = fopen(encrypted_image_path, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  uint8_t buffer[BUFFER_SIZE];

  uint8_t pixel[4] = { 0, 0, 0, '\0' };
  uint8_t pixel_index = 0;

  uint8_t pixel_value = 0;

  while (fread(buffer, sizeof(char), BUFFER_SIZE, fp) > 0) {
    for (uint64_t i = 0; i < BUFFER_SIZE; i++) {
      usleep(100 * 1000);

      const uint8_t character = buffer[i];

      if (character == '\n' || character == ' ') {
        continue;
      }

      if (character != ',') {
        pixel[pixel_index] = character;
        pixel_index++;
        continue;
      }

      pixel_index = 0;

      pixel_value = atoi(pixel);
      decrypt(pixel_value);
    }
  }

  fclose(fp);

  return 0;
}