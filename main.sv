module main(
  input logic clk,
  input logic reset,
	input	logic[4:0] inputs,
	output logic[6:0]	display_5,
	output logic[6:0]	display_4,
	output logic[6:0]	display_3,
	output logic[6:0]	display_2,
	output logic[6:0]	display_1,
	output logic[6:0]	display_0
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
    .clk_clk(clk),
    .reset_reset_n(!reset),
    .inputs_external_connection_export(debounced_inputs),
    .display_5_external_connection_export(display_5_driver_input),
    .display_4_external_connection_export(display_4_driver_input),
    .display_3_external_connection_export(display_3_driver_input),
    .display_2_external_connection_export(display_2_driver_input),
    .display_1_external_connection_export(display_1_driver_input),
    .display_0_external_connection_export(display_0_driver_input)
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