// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated.h"
#include "Vtop__Dpi.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RST_N,0,0);
    VL_IN8(start_a,7,0);
    VL_IN8(start_b,7,0);
    VL_IN8(EN_start,0,0);
    VL_OUT8(RDY_start,0,0);
    VL_OUT8(RDY_get_result,0,0);
    VL_IN(start_c,31,0);
    VL_OUT(get_result,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ mkMACint32__DOT__CLK;
        CData/*0:0*/ mkMACint32__DOT__RST_N;
        CData/*7:0*/ mkMACint32__DOT__start_a;
        CData/*7:0*/ mkMACint32__DOT__start_b;
        CData/*0:0*/ mkMACint32__DOT__EN_start;
        CData/*0:0*/ mkMACint32__DOT__RDY_start;
        CData/*0:0*/ mkMACint32__DOT__RDY_get_result;
        CData/*0:0*/ mkMACint32__DOT__adder_ififo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__adder_ofifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__ans_EN;
        CData/*0:0*/ mkMACint32__DOT__inp_fifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__rg_out_valid;
        CData/*0:0*/ mkMACint32__DOT__rg_out_valid_D_IN;
        CData/*0:0*/ mkMACint32__DOT__rg_out_valid_EN;
        CData/*0:0*/ mkMACint32__DOT__stage1_fifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__stage2_fifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__stage3_fifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__stage4_fifo_rv_EN;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_fin;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage1;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage2;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage3;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage4;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage5;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage6;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_RL_rg_out_valid___05Fdreg_update;
        CData/*0:0*/ mkMACint32__DOT__CAN_FIRE_start;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_fin;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage1;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage2;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage3;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage4;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage5;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage6;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_RL_rg_out_valid___05Fdreg_update;
        CData/*0:0*/ mkMACint32__DOT__WILL_FIRE_start;
        CData/*6:0*/ mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_38_23_XOR_a_ETC___05F_d477;
        CData/*6:0*/ mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_79_91_XOR_s_ETC___05F_d549;
        CData/*6:0*/ mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_87_65_XOR_s_ETC___05F_d623;
        CData/*6:0*/ mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_95_38_XOR_s_ETC___05F_d696;
        CData/*4:0*/ mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_36_29_XOR_a_ETC___05F_d476;
        CData/*4:0*/ mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_77_97_XOR_s_ETC___05F_d548;
        CData/*4:0*/ mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_85_71_XOR_s_ETC___05F_d622;
        CData/*4:0*/ mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_93_44_XOR_s_ETC___05F_d695;
        CData/*2:0*/ mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_34_35_XOR_a_ETC___05F_d475;
        CData/*2:0*/ mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_75_03_XOR_s_ETC___05F_d547;
        CData/*2:0*/ mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_83_77_XOR_s_ETC___05F_d621;
        CData/*2:0*/ mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_91_50_XOR_s_ETC___05F_d694;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d312;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d314;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d316;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d318;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d320;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d322;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d324;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d326;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d328;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d330;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d332;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d334;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d336;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d338;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d340;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d342;
    };
    struct {
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d344;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d346;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d348;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d350;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d352;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d354;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d356;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d358;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d360;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d362;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d364;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d366;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d368;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d370;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d372;
        CData/*0:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d374;
        CData/*0:0*/ mkMACint32__DOT__sign___05F_1___05Fh29304;
        CData/*0:0*/ mkMACint32__DOT__v_overflow___05Fh24719;
        CData/*0:0*/ mkMACint32__DOT__v_sign___05Fh29231;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh12313;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh12596;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh12693;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh12878;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh12975;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13160;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13257;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13442;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13539;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13724;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh13821;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh14006;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh14103;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh16373;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh16696;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh16793;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh16978;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17075;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17260;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17357;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17542;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17639;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17824;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh17921;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh18106;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh18203;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh18388;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh18485;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh20775;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21098;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21195;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21380;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21477;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21662;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21759;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh21944;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22041;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22226;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22323;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22508;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22605;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22790;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh22887;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh25185;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh25508;
    };
    struct {
        CData/*0:0*/ mkMACint32__DOT__x___05Fh25605;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh25790;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh25887;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26072;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26169;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26354;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26451;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26636;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26733;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh26918;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh27015;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh27200;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh27297;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh3393;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4331;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4486;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4533;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4640;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4687;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4794;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4841;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4948;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh4995;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5102;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5149;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5256;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5303;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5410;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5457;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5564;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5611;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5718;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5765;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5872;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh5919;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6026;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6073;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6180;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6227;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6334;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6381;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6488;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6535;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6642;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6689;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6796;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6843;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6950;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh6997;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7104;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7151;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7258;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7305;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7412;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7459;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7566;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7613;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7720;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7767;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7874;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh7921;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8028;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8075;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8182;
    };
    struct {
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8229;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8336;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8383;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8490;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8537;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8644;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8691;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8798;
        CData/*0:0*/ mkMACint32__DOT__x___05Fh8845;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12314;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12411;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12597;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12694;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12879;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh12976;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13161;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13258;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13443;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13540;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13725;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh13822;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh14007;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh14104;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh16374;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh16511;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh16697;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh16794;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh16979;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17076;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17261;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17358;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17543;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17640;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17825;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh17922;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh18107;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh18204;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh18389;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh18486;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh20776;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh20913;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21099;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21196;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21381;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21478;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21663;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21760;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh21945;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22042;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22227;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22324;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22509;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22606;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22791;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh22888;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25186;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25323;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25509;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25606;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25791;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh25888;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26073;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26170;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26355;
    };
    struct {
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26452;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26637;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26734;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh26919;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh27016;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh27201;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh27298;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh3394;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4332;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4379;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4487;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4534;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4641;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4688;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4795;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4842;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4949;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh4996;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5103;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5150;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5257;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5304;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5411;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5458;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5565;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5612;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5719;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5766;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5873;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh5920;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6027;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6074;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6181;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6228;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6335;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6382;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6489;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6536;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6643;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6690;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6797;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6844;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6951;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh6998;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7105;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7152;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7259;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7306;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7413;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7460;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7567;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7614;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7721;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7768;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7875;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh7922;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8029;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8076;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8183;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8230;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8337;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8384;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8491;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8538;
    };
    struct {
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8645;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8692;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8799;
        CData/*0:0*/ mkMACint32__DOT__y___05Fh8846;
        SData/*8:0*/ mkMACint32__DOT__IF_adder_ififo_rv_BIT_32_AND_adder_ififo_rv_BI_ETC___05Fq6;
        SData/*8:0*/ mkMACint32__DOT__IF_stage2_fifo_rv_BIT_8_THEN_1_ELSE_0___05Fq7;
        SData/*8:0*/ mkMACint32__DOT__IF_stage3_fifo_rv_BIT_16_THEN_1_ELSE_0___05Fq8;
        SData/*8:0*/ mkMACint32__DOT__IF_stage4_fifo_rv_BIT_24_THEN_1_ELSE_0___05Fq9;
        SData/*8:0*/ mkMACint32__DOT__psum1___05Fh11405;
        SData/*8:0*/ mkMACint32__DOT__psum2___05Fh15743;
        SData/*8:0*/ mkMACint32__DOT__psum2___05Fh20145;
        IData/*31:0*/ mkMACint32__DOT__start_c;
        IData/*31:0*/ mkMACint32__DOT__get_result;
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[6];
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[6];
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[6];
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[6];
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[4];
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv_port1___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[4];
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv_port2___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[4];
        WData/*97:0*/ mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[4];
        WData/*97:0*/ mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[4];
        WData/*97:0*/ mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[4];
        WData/*97:0*/ mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[4];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv_port0___05Fwrite_1[3];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv_port1___05Fread[3];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[3];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv_port2___05Fread[3];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv[3];
        WData/*64:0*/ mkMACint32__DOT__adder_ififo_rv_D_IN[3];
        IData/*31:0*/ mkMACint32__DOT__ans;
        IData/*31:0*/ mkMACint32__DOT__ans_D_IN;
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv[4];
        WData/*97:0*/ mkMACint32__DOT__inp_fifo_rv_D_IN[4];
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv[6];
        WData/*161:0*/ mkMACint32__DOT__stage1_fifo_rv_D_IN[6];
        WData/*97:0*/ mkMACint32__DOT__stage2_fifo_rv[4];
        WData/*97:0*/ mkMACint32__DOT__stage2_fifo_rv_D_IN[4];
        WData/*97:0*/ mkMACint32__DOT__stage3_fifo_rv[4];
        WData/*97:0*/ mkMACint32__DOT__stage3_fifo_rv_D_IN[4];
        WData/*97:0*/ mkMACint32__DOT__stage4_fifo_rv[4];
        WData/*97:0*/ mkMACint32__DOT__stage4_fifo_rv_D_IN[4];
        IData/*31:0*/ mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27;
        IData/*31:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115;
        IData/*31:0*/ mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124;
        IData/*31:0*/ mkMACint32__DOT__a_ext___05F_1___05Fh29271;
        IData/*31:0*/ mkMACint32__DOT__a_ext___05Fh29142;
        IData/*31:0*/ mkMACint32__DOT__b___05Fh2034;
        IData/*31:0*/ mkMACint32__DOT__b___05Fh3472;
        IData/*31:0*/ mkMACint32__DOT__b___05Fh3501;
        IData/*31:0*/ mkMACint32__DOT__b___05Fh3530;
        IData/*31:0*/ mkMACint32__DOT__b_ext___05F_1___05Fh29303;
        IData/*31:0*/ mkMACint32__DOT__b_ext___05Fh29143;
        IData/*31:0*/ mkMACint32__DOT__cin093_AND_shift_a090___05Fq1;
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh2035;
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh2064;
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh2093;
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh3473;
    };
    struct {
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh3502;
        IData/*31:0*/ mkMACint32__DOT__cin___05Fh3531;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_carry___05Fh2038;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_carry___05Fh2067;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_carry___05Fh2096;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_sum___05Fh2037;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_sum___05Fh2066;
        IData/*31:0*/ mkMACint32__DOT__lsb_result_sum___05Fh2095;
        IData/*31:0*/ mkMACint32__DOT__product___05F_1___05Fh2527;
        IData/*31:0*/ mkMACint32__DOT__product___05Fh2314;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh2032;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh2061;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh2090;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh3470;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh3499;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh3528;
        IData/*31:0*/ mkMACint32__DOT__shift_a___05Fh3557;
        IData/*31:0*/ mkMACint32__DOT__stage_result_carry___05Fh3476;
        IData/*31:0*/ mkMACint32__DOT__stage_result_carry___05Fh3505;
        IData/*31:0*/ mkMACint32__DOT__stage_result_carry___05Fh3534;
        IData/*31:0*/ mkMACint32__DOT__stage_result_carry___05Fh3563;
        IData/*31:0*/ mkMACint32__DOT__stage_result_sum___05Fh3475;
        IData/*31:0*/ mkMACint32__DOT__stage_result_sum___05Fh3504;
        IData/*31:0*/ mkMACint32__DOT__stage_result_sum___05Fh3533;
        IData/*31:0*/ mkMACint32__DOT__stage_result_sum___05Fh3562;
        IData/*31:0*/ mkMACint32__DOT__v_sum___05Fh24720;
        IData/*31:0*/ mkMACint32__DOT__x165_OR_y166___05Fq10;
        IData/*31:0*/ mkMACint32__DOT__x285_OR_y286___05Fq11;
        IData/*31:0*/ mkMACint32__DOT__x605_OR_y606___05Fq4;
        IData/*31:0*/ mkMACint32__DOT__x625_OR_y626___05Fq3;
        IData/*31:0*/ mkMACint32__DOT__x645_OR_y646___05Fq2;
        IData/*31:0*/ mkMACint32__DOT__x736_OR_y737___05Fq5;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2147;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2165;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2167;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2271;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2285;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2287;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh2489;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh29227;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh29276;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3588;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3605;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3607;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3625;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3627;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3645;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3647;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3670;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3686;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3702;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3736;
        IData/*31:0*/ mkMACint32__DOT__x___05Fh3738;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh2166;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh2168;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh2286;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh2288;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3606;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3608;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3626;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3628;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3646;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3648;
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3737;
    };
    struct {
        IData/*31:0*/ mkMACint32__DOT__y___05Fh3739;
        IData/*24:0*/ mkMACint32__DOT__x___05Fh20355;
        IData/*16:0*/ mkMACint32__DOT__x___05Fh15953;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv_port0___05Fwrite_1;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv_port1___05Fread;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv_port1___05Fwrite_1;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv_port2___05Fread;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv;
        QData/*33:0*/ mkMACint32__DOT__adder_ofifo_rv_D_IN;
        QData/*63:0*/ mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_inp_f_ETC___05F_d54;
        QData/*63:0*/ mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_35_5_THEN_inp_f_ETC___05F_d55;
        QData/*63:0*/ mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_36_2_THEN_inp_f_ETC___05F_d56;
        QData/*32:0*/ mkMACint32__DOT__IF_IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6___05FETC___05Fq12;
        QData/*32:0*/ mkMACint32__DOT__v_sum___05Fh11585;
        QData/*32:0*/ mkMACint32__DOT__v_sum___05Fh15918;
        QData/*32:0*/ mkMACint32__DOT__v_sum___05Fh20320;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vm_traceActivity[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__5(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
