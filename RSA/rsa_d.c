#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 4096

const uint16_t n = 43423;
const uint16_t d = 28667;

const uint8_t encrypted_image_path[256] = "encrypted_image.txt";
const uint8_t decrypted_image_path[256] = "decrypted_image.txt";

uint8_t binary_exponentiation(uint16_t base, uint16_t exp, uint16_t mod) {
  uint32_t result = 1;

  base = base % mod;
  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % mod;
    }

    base = (base * base) % mod;
    exp = exp >> 1;
  }

  return (uint8_t)result;
}

int main()
{
  FILE* encrypted_image;

  encrypted_image = fopen(encrypted_image_path, "r");
  if (encrypted_image == NULL) {
    printf("Error opening file %s\n", encrypted_image_path);
    return 1;
  }

  FILE* decrypted_image = fopen(decrypted_image_path, "w");
  if (decrypted_image == NULL) {
    printf("Error opening file %s\n", decrypted_image_path);
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
        pixel_index = 0;

        uint8_t decrypted_pixel = binary_exponentiation(atoi(pixel), d, n);

        if (character == '\0') {
          fprintf(decrypted_image, "%hhu", decrypted_pixel);
          memset(pixel, 0, encrypted_pixel_digits);
          break;
        }

        fprintf(decrypted_image, "%hhu,", decrypted_pixel);
        memset(pixel, 0, encrypted_pixel_digits);
        continue;
      }

      pixel[pixel_index] = character;
      pixel_index++;
    }

    memset(buffer, 0, BUFFER_SIZE);
  }

  fclose(encrypted_image);
  fclose(decrypted_image);

  return 0;
}