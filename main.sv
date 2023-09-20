module main(
  input logic clk,
  input logic reset
);

  platform cpu(
    .clk_clk(clk),
    .reset_reset_n(reset)
  );

endmodule