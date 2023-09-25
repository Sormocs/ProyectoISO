/** Converts a 4-bit number to its representation in a 7-segment display */
module display_driver(
  input logic [3:0] input_data,
  output logic [6:0] output_data
);
  always_comb begin
    case (input_data) 
      0: output_data = 7'b1000000;
      1: output_data = 7'b1111001;
      2: output_data = 7'b0100100;
      3: output_data = 7'b0110000;
      4: output_data = 7'b0011001;
      5: output_data = 7'b0010010;
      6: output_data = 7'b0000010;
      7: output_data = 7'b1111000;
      8: output_data = 7'b0000000;
      9: output_data = 7'b0010000;
      10: output_data = 7'b0001000;
      11: output_data = 7'b0000011;
      12: output_data = 7'b1000110;
      13: output_data = 7'b0100001;
      14: output_data = 7'b0000110;
      15: output_data = 7'b0001110;
      default: output_data = 7'b1111111;
    endcase
  end
endmodule