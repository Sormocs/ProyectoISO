module main(
	input		clocks_ref_clk_clk,
	input		clocks_ref_reset_reset,
	output		clocks_sdram_clk_clk,
	input	logic[4:0] inputs,
	output logic[6:0]	display_5,
	output logic[6:0]	display_4,
	output logic[6:0]	display_3,
	output logic[6:0]	display_2,
	output logic[6:0]	display_1,
	output logic[6:0]	display_0,
	output	[12:0]	memory_mem_a,
	output	[2:0]	memory_mem_ba,
	output		memory_mem_ck,
	output		memory_mem_ck_n,
	output		memory_mem_cke,
	output		memory_mem_cs_n,
	output		memory_mem_ras_n,
	output		memory_mem_cas_n,
	output		memory_mem_we_n,
	output		memory_mem_reset_n,
	inout	[7:0]	memory_mem_dq,
	inout		memory_mem_dqs,
	inout		memory_mem_dqs_n,
	output		memory_mem_odt,
	output		memory_mem_dm,
	input		memory_oct_rzqin,
	output	[9:0]	leds_external_connection_export,
	output	[12:0]	sdram_0_wire_addr,
	output	[1:0]	sdram_0_wire_ba,
	output		sdram_0_wire_cas_n,
	output		sdram_0_wire_cke,
	output		sdram_0_wire_cs_n,
	inout	[15:0]	sdram_0_wire_dq,
	output	[1:0]	sdram_0_wire_dqm,
	output		sdram_0_wire_ras_n,
	output		sdram_0_wire_we_n
);
  logic[4:0] debounced_inputs;

  logic[3:0] display_5_driver_input;
  logic[3:0] display_4_driver_input;
  logic[3:0] display_3_driver_input;
  logic[3:0] display_2_driver_input;
  logic[3:0] display_1_driver_input;
  logic[3:0] display_0_driver_input;

  button_debouncer button_0_debouncer(
    .clk(clk),
    .button(!inputs[0]),
    .debounced_button(debounced_inputs[0])
  );

  button_debouncer button_1_debouncer(
    .clk(clk),
    .button(!inputs[1]),
    .debounced_button(debounced_inputs[1])
  );

  button_debouncer button_2_debouncer(
    .clk(clk),
    .button(!inputs[2]),
    .debounced_button(debounced_inputs[2])
  );

  button_debouncer button_3_debouncer(
    .clk(clk),
    .button(!inputs[3]),
    .debounced_button(debounced_inputs[3])
  );

  assign debounced_inputs[4] = inputs[4];

  platform cpu(
	 .clocks_ref_clk_clk(clocks_ref_clk_clk),
	 .clocks_ref_reset_reset(!clocks_ref_reset_reset),   
	 .clocks_sdram_clk_clk(clocks_sdram_clk_clk),                 
    .inputs_external_connection_export(debounced_inputs),
    .display_5_external_connection_export(display_5_driver_input),
    .display_4_external_connection_export(display_4_driver_input),
    .display_3_external_connection_export(display_3_driver_input),
    .display_2_external_connection_export(display_2_driver_input),
    .display_1_external_connection_export(display_1_driver_input),
    .display_0_external_connection_export(display_0_driver_input),
	 .memory_mem_a                         (memory_mem_a),                         //                        memory.mem_a
	 .memory_mem_ba                        (memory_mem_ba),                        //                              .mem_ba
	 .memory_mem_ck                        (memory_mem_ck),                        //                              .mem_ck
	 .memory_mem_ck_n                      (memory_mem_ck_n),                      //                              .mem_ck_n
	 .memory_mem_cke                       (memory_mem_cke),                       //                              .mem_cke
	 .memory_mem_cs_n                      (memory_mem_cs_n),                      //                              .mem_cs_n
	 .memory_mem_ras_n                     (memory_mem_ras_n),                     //                              .mem_ras_n
	 .memory_mem_cas_n                     (memory_mem_cas_n),                     //                              .mem_cas_n
	 .memory_mem_we_n                      (memory_mem_we_n),                      //                              .mem_we_n
	 .memory_mem_reset_n                   (memory_mem_reset_n),
	 .memory_mem_dq                        (memory_mem_dq),                        //                              .mem_dq
	 .memory_mem_dqs                       (memory_mem_dqs),                       //                              .mem_dqs
	 .memory_mem_dqs_n                     (memory_mem_dqs_n),                     //                              .mem_dqs_n
	 .memory_mem_odt                       (memory_mem_odt),                       //                              .mem_odt
	 .memory_mem_dm                        (memory_mem_dm),                        //                              .mem_dm
	 .memory_oct_rzqin                     (memory_oct_rzqin),                     //                              .oct_rzqin                        //                         reset.reset_n
	 .leds_external_connection_export      (leds_external_connection_export),      //      leds_external_connection.export
	 .sdram_0_wire_addr                    (sdram_0_wire_addr),                    //                  sdram_0_wire.addr
	 .sdram_0_wire_ba                      (sdram_0_wire_ba),                      //                              .ba
	 .sdram_0_wire_cas_n                   (sdram_0_wire_cas_n),                   //                              .cas_n
	 .sdram_0_wire_cke                     (sdram_0_wire_cke),                     //                              .cke
	 .sdram_0_wire_cs_n                    (sdram_0_wire_cs_n),                    //                              .cs_n
	 .sdram_0_wire_dq                      (sdram_0_wire_dq),                      //                              .dq
	 .sdram_0_wire_dqm                     (sdram_0_wire_dqm),                     //                              .dqm
	 .sdram_0_wire_ras_n                   (sdram_0_wire_ras_n),                   //                              .ras_n
	 .sdram_0_wire_we_n                    (sdram_0_wire_we_n)                     //                              .we_n

  );

  display_driver display_5_driver(
    .input_data(display_5_driver_input),
    .output_data(display_5)
  );

  display_driver display_4_driver(
    .input_data(display_4_driver_input),
    .output_data(display_4)
  );

  display_driver display_3_driver(
    .input_data(display_3_driver_input),
    .output_data(display_3)
  );

  display_driver display_2_driver(
    .input_data(display_2_driver_input),
    .output_data(display_2)
  );

  display_driver display_1_driver(
    .input_data(display_1_driver_input),
    .output_data(display_1)
  );

  display_driver display_0_driver(
    .input_data(display_0_driver_input),
    .output_data(display_0)
  );
endmodule