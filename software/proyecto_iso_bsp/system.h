/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'platform'
 * SOPC Builder design path: ../../platform.sopcinfo
 *
 * Generated: Fri Sep 29 12:49:42 CST 2023
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x04000020
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 0
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x04000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x04000020
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 0
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x04000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/null"
#define ALT_STDERR_BASE 0x0
#define ALT_STDERR_DEV null
#define ALT_STDERR_TYPE ""
#define ALT_STDIN "/dev/null"
#define ALT_STDIN_BASE 0x0
#define ALT_STDIN_DEV null
#define ALT_STDIN_TYPE ""
#define ALT_STDOUT "/dev/null"
#define ALT_STDOUT_BASE 0x0
#define ALT_STDOUT_DEV null
#define ALT_STDOUT_TYPE ""
#define ALT_SYSTEM_NAME "platform"


/*
 * display_0 configuration
 *
 */

#define ALT_MODULE_CLASS_display_0 altera_avalon_pio
#define DISPLAY_0_BASE 0x4003060
#define DISPLAY_0_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_0_CAPTURE 0
#define DISPLAY_0_DATA_WIDTH 7
#define DISPLAY_0_DO_TEST_BENCH_WIRING 0
#define DISPLAY_0_DRIVEN_SIM_VALUE 0
#define DISPLAY_0_EDGE_TYPE "NONE"
#define DISPLAY_0_FREQ 50000000
#define DISPLAY_0_HAS_IN 0
#define DISPLAY_0_HAS_OUT 1
#define DISPLAY_0_HAS_TRI 0
#define DISPLAY_0_IRQ -1
#define DISPLAY_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_0_IRQ_TYPE "NONE"
#define DISPLAY_0_NAME "/dev/display_0"
#define DISPLAY_0_RESET_VALUE 0
#define DISPLAY_0_SPAN 16
#define DISPLAY_0_TYPE "altera_avalon_pio"


/*
 * display_1 configuration
 *
 */

#define ALT_MODULE_CLASS_display_1 altera_avalon_pio
#define DISPLAY_1_BASE 0x4003050
#define DISPLAY_1_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_1_CAPTURE 0
#define DISPLAY_1_DATA_WIDTH 7
#define DISPLAY_1_DO_TEST_BENCH_WIRING 0
#define DISPLAY_1_DRIVEN_SIM_VALUE 0
#define DISPLAY_1_EDGE_TYPE "NONE"
#define DISPLAY_1_FREQ 50000000
#define DISPLAY_1_HAS_IN 0
#define DISPLAY_1_HAS_OUT 1
#define DISPLAY_1_HAS_TRI 0
#define DISPLAY_1_IRQ -1
#define DISPLAY_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_1_IRQ_TYPE "NONE"
#define DISPLAY_1_NAME "/dev/display_1"
#define DISPLAY_1_RESET_VALUE 0
#define DISPLAY_1_SPAN 16
#define DISPLAY_1_TYPE "altera_avalon_pio"


/*
 * display_2 configuration
 *
 */

#define ALT_MODULE_CLASS_display_2 altera_avalon_pio
#define DISPLAY_2_BASE 0x4003040
#define DISPLAY_2_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_2_CAPTURE 0
#define DISPLAY_2_DATA_WIDTH 7
#define DISPLAY_2_DO_TEST_BENCH_WIRING 0
#define DISPLAY_2_DRIVEN_SIM_VALUE 0
#define DISPLAY_2_EDGE_TYPE "NONE"
#define DISPLAY_2_FREQ 50000000
#define DISPLAY_2_HAS_IN 0
#define DISPLAY_2_HAS_OUT 1
#define DISPLAY_2_HAS_TRI 0
#define DISPLAY_2_IRQ -1
#define DISPLAY_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_2_IRQ_TYPE "NONE"
#define DISPLAY_2_NAME "/dev/display_2"
#define DISPLAY_2_RESET_VALUE 0
#define DISPLAY_2_SPAN 16
#define DISPLAY_2_TYPE "altera_avalon_pio"


/*
 * display_3 configuration
 *
 */

#define ALT_MODULE_CLASS_display_3 altera_avalon_pio
#define DISPLAY_3_BASE 0x4003030
#define DISPLAY_3_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_3_CAPTURE 0
#define DISPLAY_3_DATA_WIDTH 7
#define DISPLAY_3_DO_TEST_BENCH_WIRING 0
#define DISPLAY_3_DRIVEN_SIM_VALUE 0
#define DISPLAY_3_EDGE_TYPE "NONE"
#define DISPLAY_3_FREQ 50000000
#define DISPLAY_3_HAS_IN 0
#define DISPLAY_3_HAS_OUT 1
#define DISPLAY_3_HAS_TRI 0
#define DISPLAY_3_IRQ -1
#define DISPLAY_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_3_IRQ_TYPE "NONE"
#define DISPLAY_3_NAME "/dev/display_3"
#define DISPLAY_3_RESET_VALUE 0
#define DISPLAY_3_SPAN 16
#define DISPLAY_3_TYPE "altera_avalon_pio"


/*
 * display_4 configuration
 *
 */

#define ALT_MODULE_CLASS_display_4 altera_avalon_pio
#define DISPLAY_4_BASE 0x4003020
#define DISPLAY_4_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_4_CAPTURE 0
#define DISPLAY_4_DATA_WIDTH 7
#define DISPLAY_4_DO_TEST_BENCH_WIRING 0
#define DISPLAY_4_DRIVEN_SIM_VALUE 0
#define DISPLAY_4_EDGE_TYPE "NONE"
#define DISPLAY_4_FREQ 50000000
#define DISPLAY_4_HAS_IN 0
#define DISPLAY_4_HAS_OUT 1
#define DISPLAY_4_HAS_TRI 0
#define DISPLAY_4_IRQ -1
#define DISPLAY_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_4_IRQ_TYPE "NONE"
#define DISPLAY_4_NAME "/dev/display_4"
#define DISPLAY_4_RESET_VALUE 0
#define DISPLAY_4_SPAN 16
#define DISPLAY_4_TYPE "altera_avalon_pio"


/*
 * display_5 configuration
 *
 */

#define ALT_MODULE_CLASS_display_5 altera_avalon_pio
#define DISPLAY_5_BASE 0x4003010
#define DISPLAY_5_BIT_CLEARING_EDGE_REGISTER 0
#define DISPLAY_5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DISPLAY_5_CAPTURE 0
#define DISPLAY_5_DATA_WIDTH 7
#define DISPLAY_5_DO_TEST_BENCH_WIRING 0
#define DISPLAY_5_DRIVEN_SIM_VALUE 0
#define DISPLAY_5_EDGE_TYPE "NONE"
#define DISPLAY_5_FREQ 50000000
#define DISPLAY_5_HAS_IN 0
#define DISPLAY_5_HAS_OUT 1
#define DISPLAY_5_HAS_TRI 0
#define DISPLAY_5_IRQ -1
#define DISPLAY_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DISPLAY_5_IRQ_TYPE "NONE"
#define DISPLAY_5_NAME "/dev/display_5"
#define DISPLAY_5_RESET_VALUE 0
#define DISPLAY_5_SPAN 16
#define DISPLAY_5_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * inputs configuration
 *
 */

#define ALT_MODULE_CLASS_inputs altera_avalon_pio
#define INPUTS_BASE 0x4003070
#define INPUTS_BIT_CLEARING_EDGE_REGISTER 0
#define INPUTS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUTS_CAPTURE 0
#define INPUTS_DATA_WIDTH 5
#define INPUTS_DO_TEST_BENCH_WIRING 0
#define INPUTS_DRIVEN_SIM_VALUE 0
#define INPUTS_EDGE_TYPE "NONE"
#define INPUTS_FREQ 50000000
#define INPUTS_HAS_IN 1
#define INPUTS_HAS_OUT 0
#define INPUTS_HAS_TRI 0
#define INPUTS_IRQ -1
#define INPUTS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUTS_IRQ_TYPE "NONE"
#define INPUTS_NAME "/dev/inputs"
#define INPUTS_RESET_VALUE 0
#define INPUTS_SPAN 16
#define INPUTS_TYPE "altera_avalon_pio"


/*
 * leds configuration
 *
 */

#define ALT_MODULE_CLASS_leds altera_avalon_pio
#define LEDS_BASE 0x4003000
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 10
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE "NONE"
#define LEDS_FREQ 50000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ -1
#define LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_IRQ_TYPE "NONE"
#define LEDS_NAME "/dev/leds"
#define LEDS_RESET_VALUE 0
#define LEDS_SPAN 16
#define LEDS_TYPE "altera_avalon_pio"


/*
 * ram configuration
 *
 */

#define ALT_MODULE_CLASS_ram altera_avalon_onchip_memory2
#define RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_BASE 0x4002000
#define RAM_CONTENTS_INFO ""
#define RAM_DUAL_PORT 0
#define RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_INIT_CONTENTS_FILE "platform_ram"
#define RAM_INIT_MEM_CONTENT 1
#define RAM_INSTANCE_ID "NONE"
#define RAM_IRQ -1
#define RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_NAME "/dev/ram"
#define RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define RAM_RAM_BLOCK_TYPE "AUTO"
#define RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_SINGLE_CLOCK_OP 0
#define RAM_SIZE_MULTIPLE 1
#define RAM_SIZE_VALUE 4096
#define RAM_SPAN 4096
#define RAM_TYPE "altera_avalon_onchip_memory2"
#define RAM_WRITABLE 1


/*
 * rom configuration
 *
 */

#define ALT_MODULE_CLASS_rom altera_avalon_onchip_memory2
#define ROM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ROM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ROM_BASE 0x4000000
#define ROM_CONTENTS_INFO ""
#define ROM_DUAL_PORT 0
#define ROM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ROM_INIT_CONTENTS_FILE "platform_rom"
#define ROM_INIT_MEM_CONTENT 1
#define ROM_INSTANCE_ID "NONE"
#define ROM_IRQ -1
#define ROM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ROM_NAME "/dev/rom"
#define ROM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ROM_RAM_BLOCK_TYPE "AUTO"
#define ROM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ROM_SINGLE_CLOCK_OP 0
#define ROM_SIZE_MULTIPLE 1
#define ROM_SIZE_VALUE 8192
#define ROM_SPAN 8192
#define ROM_TYPE "altera_avalon_onchip_memory2"
#define ROM_WRITABLE 0


/*
 * sdram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sdram_0 altera_avalon_new_sdram_controller
#define SDRAM_0_BASE 0x0
#define SDRAM_0_CAS_LATENCY 3
#define SDRAM_0_CONTENTS_INFO
#define SDRAM_0_INIT_NOP_DELAY 0.0
#define SDRAM_0_INIT_REFRESH_COMMANDS 2
#define SDRAM_0_IRQ -1
#define SDRAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_0_IS_INITIALIZED 1
#define SDRAM_0_NAME "/dev/sdram_0"
#define SDRAM_0_POWERUP_DELAY 100.0
#define SDRAM_0_REFRESH_PERIOD 7.8125
#define SDRAM_0_REGISTER_DATA_IN 1
#define SDRAM_0_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_0_SDRAM_BANK_WIDTH 2
#define SDRAM_0_SDRAM_COL_WIDTH 10
#define SDRAM_0_SDRAM_DATA_WIDTH 16
#define SDRAM_0_SDRAM_NUM_BANKS 4
#define SDRAM_0_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_0_SDRAM_ROW_WIDTH 13
#define SDRAM_0_SHARED_DATA 0
#define SDRAM_0_SIM_MODEL_BASE 0
#define SDRAM_0_SPAN 67108864
#define SDRAM_0_STARVATION_INDICATOR 0
#define SDRAM_0_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_0_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_0_T_AC 5.4
#define SDRAM_0_T_MRD 3
#define SDRAM_0_T_RCD 15.0
#define SDRAM_0_T_RFC 70.0
#define SDRAM_0_T_RP 15.0
#define SDRAM_0_T_WR 14.0

#endif /* __SYSTEM_H_ */
