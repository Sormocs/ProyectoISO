#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "altera_avalon_timer_regs.h"

static void timer_isr(void *context)
{
	(void) context;

	if (IORD(LED_BASE,0) == 0){
		IOWR(LED_BASE,1,1);
	} else {
		IOWR(LED_BASE,1,0);
	}

	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE,0);
}

int main() {
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ,
			timer_isr,
			NULL,
			NULL);

	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE,
			ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
					| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);

	while(1);
	return(0);
}

