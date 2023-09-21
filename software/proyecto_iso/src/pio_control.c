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

  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_5_BASE, displays[5]);
  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_4_BASE, displays[4]);
  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_3_BASE, displays[3]);
  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_2_BASE, displays[2]);
  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_1_BASE, displays[1]);
  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_0_BASE, displays[0]);
}