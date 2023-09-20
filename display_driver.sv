/** Converts a 4-bit number to its representation in a 7-segment display */
module display_driver(
  input logic [3:0] data,
  output logic [6:0] segment
);

  always_comb begin
    case (data) 
      0: segment = 7'b1000000;
      1: segment = 7'b1111001;
      2: segment = 7'b0100100;
      3: segment = 7'b0110000;
      4: segment = 7'b0011001;
      5: segment = 7'b0010010;
      6: segment = 7'b0000010;
      7: segment = 7'b1111000;
      8: segment = 7'b0000000;
      9: segment = 7'b0010000;
      default: segment = 7'b1111111;
    endcase
  end
endmodule