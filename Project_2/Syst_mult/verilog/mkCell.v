//
// Generated by Bluespec Compiler, version 2021.12.1 (build fd501401)
//
// On Sun Nov 24 11:22:13 IST 2024
//
//
// Ports:
// Name                         I/O  size props
// RDY_putA                       O     1 const
// RDY_putB                       O     1 const
// RDY_putC                       O     1 const
// RDY_putS                       O     1 const
// getC                           O    32 reg
// RDY_getC                       O     1
// getA                           O    16 reg
// RDY_getA                       O     1
// getB                           O    16 reg
// RDY_getB                       O     1
// getS                           O     1 reg
// RDY_getS                       O     1
// ans_ready                      O     1 reg
// RDY_ans_ready                  O     1
// CLK                            I     1 clock
// RST_N                          I     1 reset
// putA_a                         I    16 reg
// putB_b                         I    16 reg
// putC_c                         I    32 reg
// putS_s                         I     1 reg
// EN_putA                        I     1
// EN_putB                        I     1
// EN_putC                        I     1
// EN_putS                        I     1
//
// No combinational paths from inputs to outputs
//
//

`ifdef BSV_ASSIGNMENT_DELAY
`else
  `define BSV_ASSIGNMENT_DELAY
`endif

`ifdef BSV_POSITIVE_RESET
  `define BSV_RESET_VALUE 1'b1
  `define BSV_RESET_EDGE posedge
`else
  `define BSV_RESET_VALUE 1'b0
  `define BSV_RESET_EDGE negedge
`endif

module mkCell(CLK,
	      RST_N,

	      putA_a,
	      EN_putA,
	      RDY_putA,

	      putB_b,
	      EN_putB,
	      RDY_putB,

	      putC_c,
	      EN_putC,
	      RDY_putC,

	      putS_s,
	      EN_putS,
	      RDY_putS,

	      getC,
	      RDY_getC,

	      getA,
	      RDY_getA,

	      getB,
	      RDY_getB,

	      getS,
	      RDY_getS,

	      ans_ready,
	      RDY_ans_ready);
  input  CLK;
  input  RST_N;

  // action method putA
  input  [15 : 0] putA_a;
  input  EN_putA;
  output RDY_putA;

  // action method putB
  input  [15 : 0] putB_b;
  input  EN_putB;
  output RDY_putB;

  // action method putC
  input  [31 : 0] putC_c;
  input  EN_putC;
  output RDY_putC;

  // action method putS
  input  putS_s;
  input  EN_putS;
  output RDY_putS;

  // value method getC
  output [31 : 0] getC;
  output RDY_getC;

  // value method getA
  output [15 : 0] getA;
  output RDY_getA;

  // value method getB
  output [15 : 0] getB;
  output RDY_getB;

  // value method getS
  output getS;
  output RDY_getS;

  // value method ans_ready
  output ans_ready;
  output RDY_ans_ready;

  // signals for module outputs
  wire [31 : 0] getC;
  wire [15 : 0] getA, getB;
  wire RDY_ans_ready,
       RDY_getA,
       RDY_getB,
       RDY_getC,
       RDY_getS,
       RDY_putA,
       RDY_putB,
       RDY_putC,
       RDY_putS,
       ans_ready,
       getS;

  // register regA
  reg [15 : 0] regA;
  wire [15 : 0] regA_D_IN;
  wire regA_EN;

  // register regB
  reg [15 : 0] regB;
  wire [15 : 0] regB_D_IN;
  wire regB_EN;

  // register regC
  reg [31 : 0] regC;
  wire [31 : 0] regC_D_IN;
  wire regC_EN;

  // register regResult
  reg [31 : 0] regResult;
  wire [31 : 0] regResult_D_IN;
  wire regResult_EN;

  // register regS
  reg regS;
  wire regS_D_IN, regS_EN;

  // ports of submodule mac
  wire [31 : 0] mac_get_result, mac_start_c;
  wire [15 : 0] mac_start_a, mac_start_b;
  wire mac_EN_start,
       mac_RDY_get_result,
       mac_RDY_get_result_ready,
       mac_get_result_ready,
       mac_start_s;

  // rule scheduling signals
  wire CAN_FIRE_RL_fetchMACResult,
       CAN_FIRE_RL_passInputsToMAC,
       CAN_FIRE_putA,
       CAN_FIRE_putB,
       CAN_FIRE_putC,
       CAN_FIRE_putS,
       WILL_FIRE_RL_fetchMACResult,
       WILL_FIRE_RL_passInputsToMAC,
       WILL_FIRE_putA,
       WILL_FIRE_putB,
       WILL_FIRE_putC,
       WILL_FIRE_putS;

  // action method putA
  assign RDY_putA = 1'd1 ;
  assign CAN_FIRE_putA = 1'd1 ;
  assign WILL_FIRE_putA = EN_putA ;

  // action method putB
  assign RDY_putB = 1'd1 ;
  assign CAN_FIRE_putB = 1'd1 ;
  assign WILL_FIRE_putB = EN_putB ;

  // action method putC
  assign RDY_putC = 1'd1 ;
  assign CAN_FIRE_putC = 1'd1 ;
  assign WILL_FIRE_putC = EN_putC ;

  // action method putS
  assign RDY_putS = 1'd1 ;
  assign CAN_FIRE_putS = 1'd1 ;
  assign WILL_FIRE_putS = EN_putS ;

  // value method getC
  assign getC = regResult ;
  assign RDY_getC = RDY_ans_ready ;

  // value method getA
  assign getA = regA ;
  assign RDY_getA = RDY_ans_ready ;

  // value method getB
  assign getB = regB ;
  assign RDY_getB = RDY_ans_ready ;

  // value method getS
  assign getS = regS ;
  assign RDY_getS = RDY_ans_ready ;

  // value method ans_ready
  assign ans_ready = mac_get_result_ready ;
  assign RDY_ans_ready = mac_RDY_get_result_ready && mac_get_result_ready ;

  // submodule mac
  mkTopMAC mac(.CLK(CLK),
	       .RST_N(RST_N),
	       .start_a(mac_start_a),
	       .start_b(mac_start_b),
	       .start_c(mac_start_c),
	       .start_s(mac_start_s),
	       .EN_start(mac_EN_start),
	       .RDY_start(),
	       .get_result(mac_get_result),
	       .RDY_get_result(mac_RDY_get_result),
	       .get_result_ready(mac_get_result_ready),
	       .RDY_get_result_ready(mac_RDY_get_result_ready));

  // rule RL_fetchMACResult
  assign CAN_FIRE_RL_fetchMACResult =
	     mac_RDY_get_result && mac_RDY_get_result_ready &&
	     mac_get_result_ready ;
  assign WILL_FIRE_RL_fetchMACResult = CAN_FIRE_RL_fetchMACResult ;

  // rule RL_passInputsToMAC
  assign CAN_FIRE_RL_passInputsToMAC = 1'd1 ;
  assign WILL_FIRE_RL_passInputsToMAC = 1'd1 ;

  // register regA
  assign regA_D_IN = putA_a ;
  assign regA_EN = EN_putA ;

  // register regB
  assign regB_D_IN = putB_b ;
  assign regB_EN = EN_putB ;

  // register regC
  assign regC_D_IN = putC_c ;
  assign regC_EN = EN_putC ;

  // register regResult
  assign regResult_D_IN = mac_get_result ;
  assign regResult_EN = CAN_FIRE_RL_fetchMACResult ;

  // register regS
  assign regS_D_IN = putS_s ;
  assign regS_EN = EN_putS ;

  // submodule mac
  assign mac_start_a = regA ;
  assign mac_start_b = regB ;
  assign mac_start_c = regC ;
  assign mac_start_s = regS ;
  assign mac_EN_start = 1'd1 ;

  // handling of inlined registers

  always@(posedge CLK)
  begin
    if (RST_N == `BSV_RESET_VALUE)
      begin
        regA <= `BSV_ASSIGNMENT_DELAY 16'd0;
	regB <= `BSV_ASSIGNMENT_DELAY 16'd0;
	regC <= `BSV_ASSIGNMENT_DELAY 32'd0;
	regResult <= `BSV_ASSIGNMENT_DELAY 32'd0;
	regS <= `BSV_ASSIGNMENT_DELAY 1'd0;
      end
    else
      begin
        if (regA_EN) regA <= `BSV_ASSIGNMENT_DELAY regA_D_IN;
	if (regB_EN) regB <= `BSV_ASSIGNMENT_DELAY regB_D_IN;
	if (regC_EN) regC <= `BSV_ASSIGNMENT_DELAY regC_D_IN;
	if (regResult_EN) regResult <= `BSV_ASSIGNMENT_DELAY regResult_D_IN;
	if (regS_EN) regS <= `BSV_ASSIGNMENT_DELAY regS_D_IN;
      end
  end

  // synopsys translate_off
  `ifdef BSV_NO_INITIAL_BLOCKS
  `else // not BSV_NO_INITIAL_BLOCKS
  initial
  begin
    regA = 16'hAAAA;
    regB = 16'hAAAA;
    regC = 32'hAAAAAAAA;
    regResult = 32'hAAAAAAAA;
    regS = 1'h0;
  end
  `endif // BSV_NO_INITIAL_BLOCKS
  // synopsys translate_on
endmodule  // mkCell
