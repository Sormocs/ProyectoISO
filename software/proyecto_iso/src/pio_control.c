#include "altera_avalon_pio_regs.h"
#include "system.h"

#include "pio_control.h"

#define DISPLAYS_BASE 16

/**
 * Sets the value of the PIOs used by the displays.
*/
void set_displays(uint32_t value) {
  uint8_t displays[6] = { 0 };

  for (uint32_t i = 0; i < 6; i++) {
    displays[i] = value % DISPLAYS_BASE;
    value = value / DISPLAYS_BASE;
  }

  IOWR(DISPLAY_5_BASE, 0, displays[5]);
  IOWR(DISPLAY_4_BASE, 0, displays[4]);
  IOWR(DISPLAY_3_BASE, 0, displays[3]);
  IOWR(DISPLAY_2_BASE, 0, displays[2]);
  IOWR(DISPLAY_1_BASE, 0, displays[1]);
  IOWR(DISPLAY_0_BASE, 0, displays[0]);
}