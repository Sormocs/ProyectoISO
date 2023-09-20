#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 4096

const uint64_t n = 264930973;
const uint64_t d = 87162023;

const uint8_t encrypted_image_path[256] = "pixelesEncriptados.txt";
const uint8_t decrypted_image_path[256] = "decrypted_image.txt";

uint64_t binary_exponentiation(uint64_t base, uint64_t exp, uint64_t mod) {
  uint64_t result = 1;

  base = base % mod;
  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % mod;
    }

    base = (base * base) % mod;
    exp = exp >> 1;
  }

  return result;
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

  uint64_t encrypted_pixel_digits = ceil(32 / log10(2));

  uint8_t buffer[BUFFER_SIZE];

  uint8_t pixel[encrypted_pixel_digits];
  uint8_t pixel_index = 0;

  // printf("%ld\n", fread(buffer, sizeof(char), BUFFER_SIZE, encrypted_image));

  // memset(buffer, 0, BUFFER_SIZE);
  // printf("%ld\n", fread(buffer, sizeof(char), BUFFER_SIZE, encrypted_image));

  // for (size_t i = 0; i < BUFFER_SIZE; i++) {
  //   if (buffer[i] == '\0') { break; }
  //   printf("%c", buffer[i]);
  // }


  while (fread(buffer, sizeof(char), BUFFER_SIZE, encrypted_image) > 0) {
    for (uint64_t i = 0; i < BUFFER_SIZE; i++) {
      // usleep(100 * 500);

      const uint8_t character = buffer[i];

      // printf("Character: %c\n", character);
      if (character == '\n' || character == ' ') { continue; }

      if (character == '\0') {
        pixel[pixel_index + 1] = '\0';
        pixel_index = 0;

        uint64_t decrypted_pixel = binary_exponentiation(atoi(pixel), d, n);
        fprintf(decrypted_image, "%ld", decrypted_pixel);

        printf("Encrypted pixel: %ld\n", atoi(pixel));
        printf("Decrypted pixel: %ld\n", decrypted_pixel);
        printf("--------------------\n");
        break;
      }

      if (character != ',') {
        pixel[pixel_index] = character;
        pixel_index++;
        continue;
      }

      pixel[pixel_index + 1] = '\0';
      pixel_index = 0;

      uint64_t decrypted_pixel = binary_exponentiation(atoi(pixel), d, n);
      fprintf(decrypted_image, "%ld,", decrypted_pixel);

      printf("Encrypted pixel: %ld\n", atoi(pixel));
      printf("Decrypted pixel: %ld\n", decrypted_pixel);
      printf("--------------------\n");
    }

    memset(buffer, 0, BUFFER_SIZE);
  }

  fclose(encrypted_image);
  fclose(decrypted_image);

  return 0;
}