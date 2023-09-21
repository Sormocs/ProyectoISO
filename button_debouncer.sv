module button_debouncer #(
  parameter DOWN_CYCLES = 32'd5000000,
  parameter UP_CYLES = 32'd10000)(
  input logic clk,
  input logic button,
  output logic debounced_button
);
  logic[31:0] counter = 0;
  logic[31:0] counter_max = DOWN_CYCLES;

  always_ff @(posedge clk) begin
    if(button || debounced_button) begin
      if (counter == counter_max) begin
        counter <= 32'd0;
        counter_max <= debounced_button ? DOWN_CYCLES : UP_CYLES;
        debounced_button <= ~debounced_button;
      end
      else begin 
        counter <= counter + 1;
      end
    end
    else begin
      counter <= 32'd0;
      debounced_button <= 1'b0;
    end  
  end
endmodule