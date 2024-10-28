// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/mkTopMAC.v", 37, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/mkTopMAC.v", 37, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mkTopMAC__DOT__CLK = vlTOPp->CLK;
    vlTOPp->mkTopMAC__DOT__RST_N = vlTOPp->RST_N;
    vlTOPp->mkTopMAC__DOT__start_a = vlTOPp->start_a;
    vlTOPp->mkTopMAC__DOT__start_b = vlTOPp->start_b;
    vlTOPp->mkTopMAC__DOT__start_c = vlTOPp->start_c;
    vlTOPp->mkTopMAC__DOT__start_s = vlTOPp->start_s;
    vlTOPp->mkTopMAC__DOT__EN_start = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__WILL_FIRE_start = vlTOPp->EN_start;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_s_EN) {
            vlTOPp->mkTopMAC__DOT__rg_s = vlTOPp->mkTopMAC__DOT__rg_s_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_s = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_out_valid_EN) {
            vlTOPp->mkTopMAC__DOT__rg_out_valid = vlTOPp->mkTopMAC__DOT__rg_out_valid_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_out_valid = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_out_EN) {
            vlTOPp->mkTopMAC__DOT__rg_out = vlTOPp->mkTopMAC__DOT__rg_out_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_inp_valid_EN) {
            vlTOPp->mkTopMAC__DOT__rg_inp_valid = vlTOPp->mkTopMAC__DOT__rg_inp_valid_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_inp_valid = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_c_EN) {
            vlTOPp->mkTopMAC__DOT__rg_c = vlTOPp->mkTopMAC__DOT__rg_c_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_c = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_b_EN) {
            vlTOPp->mkTopMAC__DOT__rg_b = vlTOPp->mkTopMAC__DOT__rg_b_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_b = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkTopMAC__DOT__rg_a_EN) {
            vlTOPp->mkTopMAC__DOT__rg_a = vlTOPp->mkTopMAC__DOT__rg_a_D_IN;
        }
    } else {
        vlTOPp->mkTopMAC__DOT__rg_a = 0U;
    }
    vlTOPp->mkTopMAC__DOT__RDY_get_result = vlTOPp->mkTopMAC__DOT__rg_out_valid;
    vlTOPp->mkTopMAC__DOT__get_result = vlTOPp->mkTopMAC__DOT__rg_out;
    vlTOPp->mkTopMAC__DOT__CAN_FIRE_RL_r1_mac = vlTOPp->mkTopMAC__DOT__rg_inp_valid;
    vlTOPp->mkTopMAC__DOT__WILL_FIRE_RL_r1_mac = vlTOPp->mkTopMAC__DOT__rg_inp_valid;
    vlTOPp->mkTopMAC__DOT__rg_out_EN = vlTOPp->mkTopMAC__DOT__rg_inp_valid;
    vlTOPp->mkTopMAC__DOT__rg_out_valid_D_IN = vlTOPp->mkTopMAC__DOT__rg_inp_valid;
    vlTOPp->mkTopMAC__DOT__exp_b___05Fh18605 = (0xffU 
                                                & (vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__mant_b___05Fh18607 = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->mkTopMAC__DOT__rg_c));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14 
        = (0xffU & (~ (vlTOPp->mkTopMAC__DOT__rg_c 
                       >> 0x17U)));
    vlTOPp->mkTopMAC__DOT__rg_b_BITS_7_TO_0___05Fq1 
        = (0xffU & (IData)(vlTOPp->mkTopMAC__DOT__rg_b));
    vlTOPp->mkTopMAC__DOT__sign_a___05Fh18600 = (1U 
                                                 & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                     ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                    >> 0xfU));
    vlTOPp->mkTopMAC__DOT__rg_a_BITS_7_TO_0___05Fq34 
        = (0xffU & (IData)(vlTOPp->mkTopMAC__DOT__rg_a));
    vlTOPp->mkTopMAC__DOT__y___05Fh22095 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh21899 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh21945 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh21749 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh21795 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh21599 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh21645 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh21449 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh21495 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh21299 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh21345 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh21148 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh46158 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 7U));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_7_AND_rg_b_BIT_7_THEN_2_ELSE_0___05Fq3 
        = ((0x80U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                     & (IData)(vlTOPp->mkTopMAC__DOT__rg_b)))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh21194 = (1U & (((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__rg_b)) 
                                                  >> 8U));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29023 
        = (0x4000U | (0x3f80U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                 << 7U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29105 
        = (0x2000U | (0x1fc0U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                 << 6U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29169 
        = (0x1000U | (0xfe0U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                                << 5U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29233 
        = (0x800U | (0x7f0U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                               << 4U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29297 
        = (0x400U | (0x3f8U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                               << 3U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29361 
        = (0x200U | (0x1fcU & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                               << 2U)));
    vlTOPp->mkTopMAC__DOT__partial_product___05Fh29425 
        = (0x100U | (0xfeU & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a) 
                              << 1U)));
    vlTOPp->mkTopMAC__DOT__product___05Fh29492 = (0x80U 
                                                  | (0x7fU 
                                                     & (IData)(vlTOPp->mkTopMAC__DOT__rg_a)));
    vlTOPp->RDY_get_result = vlTOPp->mkTopMAC__DOT__RDY_get_result;
    vlTOPp->get_result = vlTOPp->mkTopMAC__DOT__get_result;
    vlTOPp->mkTopMAC__DOT__b___05Fh1501 = ((0xffffff00U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlTOPp->mkTopMAC__DOT__rg_b_BITS_7_TO_0___05Fq1) 
                                                              >> 7U)))) 
                                               << 8U)) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__rg_b_BITS_7_TO_0___05Fq1));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_4___05FETC___05F_d16 
        = ((IData)(vlTOPp->mkTopMAC__DOT__sign_a___05Fh18600) 
           == (1U & (vlTOPp->mkTopMAC__DOT__rg_c >> 0x1fU)));
    vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080 
        = ((0xffffff00U & ((- (IData)((1U & ((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BITS_7_TO_0___05Fq34) 
                                             >> 7U)))) 
                           << 8U)) | (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BITS_7_TO_0___05Fq34));
    vlTOPp->mkTopMAC__DOT__x___05Fh46306 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21194) 
                                                  ^ (IData)(
                                                            (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_7_AND_rg_b_BIT_7_THEN_2_ELSE_0___05Fq3 
                                                             >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh21149 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_7_AND_rg_b_BIT_7_THEN_2_ELSE_0___05Fq3 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21194));
    vlTOPp->mkTopMAC__DOT__cin___05Fh29431 = ((1U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
                                               ? vlTOPp->mkTopMAC__DOT__product___05Fh29492
                                               : 0U);
    vlTOPp->mkTopMAC__DOT__b___05F_1___05Fh1562 = ((IData)(1U) 
                                                   + 
                                                   (~ vlTOPp->mkTopMAC__DOT__b___05Fh1501));
    vlTOPp->mkTopMAC__DOT__sign___05F_1___05Fh1563 
        = (1U & (~ (vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080 
                    >> 7U)));
    vlTOPp->mkTopMAC__DOT__a___05F_1___05Fh1615 = ((IData)(1U) 
                                                   + 
                                                   (~ vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080));
    vlTOPp->mkTopMAC__DOT__x___05Fh21344 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21148) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21149));
    vlTOPp->mkTopMAC__DOT__product___05Fh29428 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29425 
                                                  ^ vlTOPp->mkTopMAC__DOT__cin___05Fh29431);
    vlTOPp->mkTopMAC__DOT__cin9431_AND_partial_product9425___05Fq2 
        = (vlTOPp->mkTopMAC__DOT__cin___05Fh29431 & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29425);
    vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086 
        = ((0x80U & vlTOPp->mkTopMAC__DOT__b___05Fh1501)
            ? vlTOPp->mkTopMAC__DOT__b___05F_1___05Fh1562
            : vlTOPp->mkTopMAC__DOT__b___05Fh1501);
    vlTOPp->mkTopMAC__DOT__product___05Fh3080 = ((0x80U 
                                                  & vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080)
                                                  ? vlTOPp->mkTopMAC__DOT__a___05F_1___05Fh1615
                                                  : vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080);
    vlTOPp->mkTopMAC__DOT__x___05Fh46459 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21345) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21344));
    vlTOPp->mkTopMAC__DOT__y___05Fh21300 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21344) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21345));
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_1_4_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d85 
        = ((2U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__product___05Fh29428
            : vlTOPp->mkTopMAC__DOT__cin___05Fh29431);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29429 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__cin9431_AND_partial_product9425___05Fq2 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2629 = (0xffffff80U 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 7U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2693 = (0xffffffc0U 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 6U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2757 = (0xffffffe0U 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 5U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2821 = (0xfffffff0U 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 4U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2885 = (0xfffffff8U 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 3U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh2949 = (0xfffffffcU 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 2U));
    vlTOPp->mkTopMAC__DOT__shift_a___05Fh3013 = (0xfffffffeU 
                                                 & (vlTOPp->mkTopMAC__DOT__product___05Fh3080 
                                                    << 1U));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2110 
        = ((1U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh3080
            : 0U);
    vlTOPp->mkTopMAC__DOT__x___05Fh21494 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21299) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21300));
    vlTOPp->mkTopMAC__DOT__y___05Fh29387 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_1_4_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d85 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29361);
    vlTOPp->mkTopMAC__DOT__b___05Fh29366 = ((2U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
                                             ? vlTOPp->mkTopMAC__DOT__carry___05Fh29429
                                             : 0U);
    vlTOPp->mkTopMAC__DOT__product___05Fh3016 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh3013 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2110);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05Fq35 
        = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2110 
           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh3013);
    vlTOPp->mkTopMAC__DOT__x___05Fh46611 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21495) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21494));
    vlTOPp->mkTopMAC__DOT__y___05Fh21450 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21494) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21495));
    vlTOPp->mkTopMAC__DOT__x___05Fh29568 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29361 
                                            ^ vlTOPp->mkTopMAC__DOT__b___05Fh29366);
    vlTOPp->mkTopMAC__DOT__x___05Fh29388 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29361 
                                            & vlTOPp->mkTopMAC__DOT__b___05Fh29366);
    vlTOPp->mkTopMAC__DOT__y___05Fh29389 = (vlTOPp->mkTopMAC__DOT__b___05Fh29366 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_1_4_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d85);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2119 
        = ((2U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh3016
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2110);
    vlTOPp->mkTopMAC__DOT__carry___05Fh3017 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05Fq35 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT__x___05Fh21644 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21449) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21450));
    vlTOPp->mkTopMAC__DOT__product___05Fh29364 = (vlTOPp->mkTopMAC__DOT__x___05Fh29568 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_1_4_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d85);
    vlTOPp->mkTopMAC__DOT__x___05Fh29386 = (vlTOPp->mkTopMAC__DOT__x___05Fh29388 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29389);
    vlTOPp->mkTopMAC__DOT__y___05Fh2975 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2119 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2949);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2116 
        = ((2U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh3017
            : 0U);
    vlTOPp->mkTopMAC__DOT__y___05Fh21600 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21644) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21645));
    vlTOPp->mkTopMAC__DOT__x___05Fh46763 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21645) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21644));
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d96 
        = ((4U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__product___05Fh29364
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_1_4_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d85);
    vlTOPp->mkTopMAC__DOT__x9386_OR_y9387___05Fq4 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh29386 | vlTOPp->mkTopMAC__DOT__y___05Fh29387);
    vlTOPp->mkTopMAC__DOT__x___05Fh3155 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2949 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2116);
    vlTOPp->mkTopMAC__DOT__x___05Fh2976 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2949 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2116);
    vlTOPp->mkTopMAC__DOT__y___05Fh2977 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2116 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2119);
    vlTOPp->mkTopMAC__DOT__x___05Fh21794 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21599) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21600));
    vlTOPp->mkTopMAC__DOT__y___05Fh29323 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d96 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29297);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29365 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__x9386_OR_y9387___05Fq4 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh2952 = (vlTOPp->mkTopMAC__DOT__x___05Fh3155 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2119);
    vlTOPp->mkTopMAC__DOT__x___05Fh2974 = (vlTOPp->mkTopMAC__DOT__x___05Fh2976 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh2977);
    vlTOPp->mkTopMAC__DOT__y___05Fh21750 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21794) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21795));
    vlTOPp->mkTopMAC__DOT__x___05Fh46915 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21795) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21794));
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d92 
        = ((4U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh29365
            : vlTOPp->mkTopMAC__DOT__b___05Fh29366);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2130 
        = ((4U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2952
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2119);
    vlTOPp->mkTopMAC__DOT__x974_OR_y975___05Fq36 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh2974 | vlTOPp->mkTopMAC__DOT__y___05Fh2975);
    vlTOPp->mkTopMAC__DOT__x___05Fh21944 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21749) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21750));
    vlTOPp->mkTopMAC__DOT__x___05Fh29584 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29297 
                                            ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d92);
    vlTOPp->mkTopMAC__DOT__x___05Fh29324 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29297 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d92);
    vlTOPp->mkTopMAC__DOT__y___05Fh29325 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d92 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d96);
    vlTOPp->mkTopMAC__DOT__y___05Fh2911 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2130 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2885);
    vlTOPp->mkTopMAC__DOT__carry___05Fh2953 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x974_OR_y975___05Fq36 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh21900 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21944) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21945));
    vlTOPp->mkTopMAC__DOT__x___05Fh47067 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21945) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21944));
    vlTOPp->mkTopMAC__DOT__product___05Fh29300 = (vlTOPp->mkTopMAC__DOT__x___05Fh29584 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d96);
    vlTOPp->mkTopMAC__DOT__x___05Fh29322 = (vlTOPp->mkTopMAC__DOT__x___05Fh29324 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29325);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2126 
        = ((4U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2953
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2116);
    vlTOPp->mkTopMAC__DOT__x___05Fh22094 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh21899) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh21900));
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d107 
        = ((8U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__product___05Fh29300
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d96);
    vlTOPp->mkTopMAC__DOT__x9322_OR_y9323___05Fq5 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh29322 | vlTOPp->mkTopMAC__DOT__y___05Fh29323);
    vlTOPp->mkTopMAC__DOT__x___05Fh3171 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2885 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2126);
    vlTOPp->mkTopMAC__DOT__x___05Fh2912 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2885 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2126);
    vlTOPp->mkTopMAC__DOT__y___05Fh2913 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2126 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2130);
    vlTOPp->mkTopMAC__DOT__x___05Fh47219 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh22095) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh22094));
    vlTOPp->mkTopMAC__DOT__y___05Fh29259 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d107 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29233);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29301 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__x9322_OR_y9323___05Fq5 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh2888 = (vlTOPp->mkTopMAC__DOT__x___05Fh3171 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2130);
    vlTOPp->mkTopMAC__DOT__x___05Fh2910 = (vlTOPp->mkTopMAC__DOT__x___05Fh2912 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh2913);
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d103 
        = ((8U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh29301
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_2_2_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d92);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2141 
        = ((8U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2888
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2130);
    vlTOPp->mkTopMAC__DOT__x910_OR_y911___05Fq37 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh2910 | vlTOPp->mkTopMAC__DOT__y___05Fh2911);
    vlTOPp->mkTopMAC__DOT__x___05Fh29600 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29233 
                                            ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d103);
    vlTOPp->mkTopMAC__DOT__x___05Fh29260 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29233 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d103);
    vlTOPp->mkTopMAC__DOT__y___05Fh29261 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d103 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d107);
    vlTOPp->mkTopMAC__DOT__y___05Fh2847 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2141 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2821);
    vlTOPp->mkTopMAC__DOT__carry___05Fh2889 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x910_OR_y911___05Fq37 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh29236 = (vlTOPp->mkTopMAC__DOT__x___05Fh29600 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d107);
    vlTOPp->mkTopMAC__DOT__x___05Fh29258 = (vlTOPp->mkTopMAC__DOT__x___05Fh29260 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29261);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2137 
        = ((8U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2889
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2126);
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d118 
        = ((0x10U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__product___05Fh29236
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d107);
    vlTOPp->mkTopMAC__DOT__x9258_OR_y9259___05Fq6 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh29258 | vlTOPp->mkTopMAC__DOT__y___05Fh29259);
    vlTOPp->mkTopMAC__DOT__x___05Fh3187 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2821 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2137);
    vlTOPp->mkTopMAC__DOT__x___05Fh2848 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2821 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2137);
    vlTOPp->mkTopMAC__DOT__y___05Fh2849 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2137 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2141);
    vlTOPp->mkTopMAC__DOT__y___05Fh29195 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d118 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29169);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29237 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__x9258_OR_y9259___05Fq6 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh2824 = (vlTOPp->mkTopMAC__DOT__x___05Fh3187 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2141);
    vlTOPp->mkTopMAC__DOT__x___05Fh2846 = (vlTOPp->mkTopMAC__DOT__x___05Fh2848 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh2849);
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d114 
        = ((0x10U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh29237
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_3_0_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d103);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2152 
        = ((0x10U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2824
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2141);
    vlTOPp->mkTopMAC__DOT__x846_OR_y847___05Fq38 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh2846 | vlTOPp->mkTopMAC__DOT__y___05Fh2847);
    vlTOPp->mkTopMAC__DOT__x___05Fh29616 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29169 
                                            ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d114);
    vlTOPp->mkTopMAC__DOT__x___05Fh29196 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29169 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d114);
    vlTOPp->mkTopMAC__DOT__y___05Fh29197 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d114 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d118);
    vlTOPp->mkTopMAC__DOT__y___05Fh2783 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2152 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2757);
    vlTOPp->mkTopMAC__DOT__carry___05Fh2825 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x846_OR_y847___05Fq38 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh29172 = (vlTOPp->mkTopMAC__DOT__x___05Fh29616 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d118);
    vlTOPp->mkTopMAC__DOT__x___05Fh29194 = (vlTOPp->mkTopMAC__DOT__x___05Fh29196 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29197);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2148 
        = ((0x10U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2825
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2137);
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d129 
        = ((0x20U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__product___05Fh29172
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d118);
    vlTOPp->mkTopMAC__DOT__x9194_OR_y9195___05Fq7 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh29194 | vlTOPp->mkTopMAC__DOT__y___05Fh29195);
    vlTOPp->mkTopMAC__DOT__x___05Fh3203 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2757 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2148);
    vlTOPp->mkTopMAC__DOT__x___05Fh2784 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2757 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2148);
    vlTOPp->mkTopMAC__DOT__y___05Fh2785 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2148 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2152);
    vlTOPp->mkTopMAC__DOT__y___05Fh29131 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d129 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29105);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29173 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__x9194_OR_y9195___05Fq7 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh2760 = (vlTOPp->mkTopMAC__DOT__x___05Fh3203 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2152);
    vlTOPp->mkTopMAC__DOT__x___05Fh2782 = (vlTOPp->mkTopMAC__DOT__x___05Fh2784 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh2785);
    vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d125 
        = ((0x20U & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh29173
            : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_4_8_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d114);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2163 
        = ((0x20U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2760
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2152);
    vlTOPp->mkTopMAC__DOT__x782_OR_y783___05Fq39 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh2782 | vlTOPp->mkTopMAC__DOT__y___05Fh2783);
    vlTOPp->mkTopMAC__DOT__x___05Fh29632 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29105 
                                            ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d125);
    vlTOPp->mkTopMAC__DOT__x___05Fh29132 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29105 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d125);
    vlTOPp->mkTopMAC__DOT__y___05Fh29133 = (vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d125 
                                            & vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d129);
    vlTOPp->mkTopMAC__DOT__y___05Fh2719 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2163 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2693);
    vlTOPp->mkTopMAC__DOT__carry___05Fh2761 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x782_OR_y783___05Fq39 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh29108 = (vlTOPp->mkTopMAC__DOT__x___05Fh29632 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d129);
    vlTOPp->mkTopMAC__DOT__x___05Fh29130 = (vlTOPp->mkTopMAC__DOT__x___05Fh29132 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29133);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2159 
        = ((0x20U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2761
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2148);
    vlTOPp->mkTopMAC__DOT__cin___05Fh29029 = ((0x40U 
                                               & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
                                               ? vlTOPp->mkTopMAC__DOT__product___05Fh29108
                                               : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d129);
    vlTOPp->mkTopMAC__DOT__x9130_OR_y9131___05Fq8 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh29130 | vlTOPp->mkTopMAC__DOT__y___05Fh29131);
    vlTOPp->mkTopMAC__DOT__x___05Fh3219 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2693 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2159);
    vlTOPp->mkTopMAC__DOT__x___05Fh2720 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2693 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2159);
    vlTOPp->mkTopMAC__DOT__y___05Fh2721 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2159 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2163);
    vlTOPp->mkTopMAC__DOT__y___05Fh29666 = (vlTOPp->mkTopMAC__DOT__cin___05Fh29029 
                                            & vlTOPp->mkTopMAC__DOT__partial_product___05Fh29023);
    vlTOPp->mkTopMAC__DOT__carry___05Fh29109 = (0xfffffffeU 
                                                & (vlTOPp->mkTopMAC__DOT__x9130_OR_y9131___05Fq8 
                                                   << 1U));
    vlTOPp->mkTopMAC__DOT__product___05Fh2696 = (vlTOPp->mkTopMAC__DOT__x___05Fh3219 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2163);
    vlTOPp->mkTopMAC__DOT__x___05Fh2718 = (vlTOPp->mkTopMAC__DOT__x___05Fh2720 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh2721);
    vlTOPp->mkTopMAC__DOT__b___05Fh29028 = ((0x40U 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_b))
                                             ? vlTOPp->mkTopMAC__DOT__carry___05Fh29109
                                             : vlTOPp->mkTopMAC__DOT__IF_rg_b_1_BIT_5_6_THEN_1_CONCAT_rg_a_BITS_6_TO_ETC___05F_d125);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2174 
        = ((0x40U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2696
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2163);
    vlTOPp->mkTopMAC__DOT__x718_OR_y719___05Fq40 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh2718 | vlTOPp->mkTopMAC__DOT__y___05Fh2719);
    vlTOPp->mkTopMAC__DOT__x___05Fh29049 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29023 
                                            ^ vlTOPp->mkTopMAC__DOT__b___05Fh29028);
    vlTOPp->mkTopMAC__DOT__x___05Fh29667 = (vlTOPp->mkTopMAC__DOT__partial_product___05Fh29023 
                                            & vlTOPp->mkTopMAC__DOT__b___05Fh29028);
    vlTOPp->mkTopMAC__DOT__y___05Fh29668 = (vlTOPp->mkTopMAC__DOT__b___05Fh29028 
                                            & vlTOPp->mkTopMAC__DOT__cin___05Fh29029);
    vlTOPp->mkTopMAC__DOT__y___05Fh3253 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2174 
                                           & vlTOPp->mkTopMAC__DOT__shift_a___05Fh2629);
    vlTOPp->mkTopMAC__DOT__carry___05Fh2697 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x718_OR_y719___05Fq40 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
        = (vlTOPp->mkTopMAC__DOT__x___05Fh29049 ^ vlTOPp->mkTopMAC__DOT__cin___05Fh29029);
    vlTOPp->mkTopMAC__DOT__x___05Fh29665 = (vlTOPp->mkTopMAC__DOT__x___05Fh29667 
                                            | vlTOPp->mkTopMAC__DOT__y___05Fh29668);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2170 
        = ((0x40U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2697
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2159);
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
        = (vlTOPp->mkTopMAC__DOT__x___05Fh29665 | vlTOPp->mkTopMAC__DOT__y___05Fh29666);
    vlTOPp->mkTopMAC__DOT__x___05Fh2655 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2629 
                                           ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2170);
    vlTOPp->mkTopMAC__DOT__x___05Fh3254 = (vlTOPp->mkTopMAC__DOT__shift_a___05Fh2629 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2170);
    vlTOPp->mkTopMAC__DOT__y___05Fh3255 = (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2170 
                                           & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2174);
    vlTOPp->mkTopMAC__DOT__y___05Fh32428 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xfU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 0xeU)));
    vlTOPp->mkTopMAC__DOT__x___05Fh32229 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xeU) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 0xdU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh32276 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xeU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 0xdU)));
    vlTOPp->mkTopMAC__DOT__x___05Fh32077 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xdU) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 0xcU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh32124 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xdU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 0xcU)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31925 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xcU) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 0xbU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31972 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xcU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 0xbU)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31773 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xbU) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 0xaU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31820 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xbU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 0xaU)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31621 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xaU) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 9U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31668 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 0xaU) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 9U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31469 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 9U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 8U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31516 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 9U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 8U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31317 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 8U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 7U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31364 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 8U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 7U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31165 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 7U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 6U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31212 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 7U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 6U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh31013 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 6U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 5U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh31060 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 6U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 5U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh30861 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 5U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 4U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh30908 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 5U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 4U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh30709 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 4U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 3U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh30756 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 4U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 3U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh30557 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 3U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 2U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh30604 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 3U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 2U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh30404 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 2U) 
                                                  & (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                     >> 1U)));
    vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05Fq9 
        = ((1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                   >> 1U) & vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147))
            ? 4ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh30451 = (1U & ((vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141 
                                                   >> 2U) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                                   >> 1U)));
    vlTOPp->mkTopMAC__DOT__product___05Fh2632 = (vlTOPp->mkTopMAC__DOT__x___05Fh2655 
                                                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2174);
    vlTOPp->mkTopMAC__DOT__x___05Fh3252 = (vlTOPp->mkTopMAC__DOT__x___05Fh3254 
                                           | vlTOPp->mkTopMAC__DOT__y___05Fh3255);
    vlTOPp->mkTopMAC__DOT__y___05Fh30405 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05Fq9 
                                                     >> 2U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30451));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
        = ((0x80U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__product___05Fh2632
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2174);
    vlTOPp->mkTopMAC__DOT__x252_OR_y253___05Fq41 = 
        (vlTOPp->mkTopMAC__DOT__x___05Fh3252 | vlTOPp->mkTopMAC__DOT__y___05Fh3253);
    vlTOPp->mkTopMAC__DOT__x___05Fh30603 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30404) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30405));
    vlTOPp->mkTopMAC__DOT__carry___05Fh2633 = (0xfffffffeU 
                                               & (vlTOPp->mkTopMAC__DOT__x252_OR_y253___05Fq41 
                                                  << 1U));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d243 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30604) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30603)) 
            << 3U) | ((4U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30451) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05Fq9 
                                         >> 2U))) << 2U)) 
                      | ((2U & ((0xfffffffeU & vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141) 
                                ^ (vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_AND_IF___05FETC___05F_d147 
                                   << 1U))) | (1U & vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d141))));
    vlTOPp->mkTopMAC__DOT__y___05Fh30558 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30603) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30604));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185 
        = ((0x80U & vlTOPp->mkTopMAC__DOT__IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_078_T_ETC___05F_d2086)
            ? vlTOPp->mkTopMAC__DOT__carry___05Fh2633
            : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2170);
    vlTOPp->mkTopMAC__DOT__x___05Fh30755 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30557) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30558));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2435 
        = (1U & (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                 ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185));
    vlTOPp->mkTopMAC__DOT__x___05Fh2487 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1fU));
    vlTOPp->mkTopMAC__DOT__x___05Fh8314 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__y___05Fh8362 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh8160 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__y___05Fh8208 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__x___05Fh8006 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__y___05Fh8054 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh7852 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh7900 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__x___05Fh7698 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__y___05Fh7746 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh7544 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh7592 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x19U));
    vlTOPp->mkTopMAC__DOT__x___05Fh7390 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x18U));
    vlTOPp->mkTopMAC__DOT__y___05Fh7438 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh7236 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh7284 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x17U));
    vlTOPp->mkTopMAC__DOT__x___05Fh7082 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x16U));
    vlTOPp->mkTopMAC__DOT__y___05Fh7130 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6928 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x15U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6976 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6774 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x14U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6822 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6620 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6668 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6466 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x12U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6514 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6312 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6360 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6158 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh6206 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh6004 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh6052 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5850 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xeU));
    vlTOPp->mkTopMAC__DOT__y___05Fh5898 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5696 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh5744 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5542 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh5590 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5388 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh5436 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5234 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh5282 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh5080 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh5128 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4926 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 8U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4974 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4772 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4820 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4618 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4666 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4464 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4512 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4310 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4358 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4156 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4204 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh4002 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh4050 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh3847 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 1U));
    vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq42 
        = ((1U & (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                  & vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh3895 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2176 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2185) 
                                                 >> 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh30710 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30755) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30756));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2433 
        = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh3895) 
                 ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq42 
                            >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh3848 = ((IData)(
                                                   (vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq42 
                                                    >> 1U)) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh3895));
    vlTOPp->mkTopMAC__DOT__x___05Fh30907 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30709) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30710));
    vlTOPp->mkTopMAC__DOT__x___05Fh4049 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh3847) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh3848));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d244 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30908) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30907)) 
            << 5U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30756) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30755)) 
                       << 4U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d243)));
    vlTOPp->mkTopMAC__DOT__y___05Fh30862 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30907) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30908));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2431 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4050) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4049));
    vlTOPp->mkTopMAC__DOT__y___05Fh4003 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4049) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4050));
    vlTOPp->mkTopMAC__DOT__x___05Fh31059 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh30861) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh30862));
    vlTOPp->mkTopMAC__DOT__x___05Fh4203 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4002) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4003));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31060) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31059));
    vlTOPp->mkTopMAC__DOT__y___05Fh31014 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31059) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31060));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2429 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4204) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4203));
    vlTOPp->mkTopMAC__DOT__y___05Fh4157 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4203) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4204));
    vlTOPp->mkTopMAC__DOT__x___05Fh31211 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31013) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31014));
    vlTOPp->mkTopMAC__DOT__x___05Fh4357 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4156) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4157));
    vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31212) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31211));
    vlTOPp->mkTopMAC__DOT__y___05Fh31166 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31211) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31212));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2427 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4358) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4357));
    vlTOPp->mkTopMAC__DOT__y___05Fh4311 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4357) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4358));
    vlTOPp->mkTopMAC__DOT__y___05Fh63037 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628)));
    vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_5628_THEN_2_ELSE_0___05Fq10 
        = ((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628)
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh31363 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31165) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31166));
    vlTOPp->mkTopMAC__DOT__x___05Fh4511 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4310) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4311));
    vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31364) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31363));
    vlTOPp->mkTopMAC__DOT__y___05Fh31318 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31363) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31364));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2425 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4512) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4511));
    vlTOPp->mkTopMAC__DOT__y___05Fh4465 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4511) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4512));
    vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_1608_THEN_2_ELSE_0___05Fq11 
        = ((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608)
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh63036 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608) 
                                                  ^ (IData)(
                                                            (vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_5628_THEN_2_ELSE_0___05Fq10 
                                                             >> 1U))));
    vlTOPp->mkTopMAC__DOT__x___05Fh39068 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_5628_THEN_2_ELSE_0___05Fq10 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608));
    vlTOPp->mkTopMAC__DOT__x___05Fh31515 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31317) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31318));
    vlTOPp->mkTopMAC__DOT__x___05Fh4665 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4464) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4465));
    vlTOPp->mkTopMAC__DOT__IF_x3036_AND_y3037_THEN_2_ELSE_0___05Fq12 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63036) 
            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63037))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh54901 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31516) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31515));
    vlTOPp->mkTopMAC__DOT__y___05Fh31470 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31515) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31516));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2423 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4666) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4665));
    vlTOPp->mkTopMAC__DOT__y___05Fh4619 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4665) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4666));
    vlTOPp->mkTopMAC__DOT__x___05Fh55051 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_1608_THEN_2_ELSE_0___05Fq11 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901));
    vlTOPp->mkTopMAC__DOT__y___05Fh63226 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39068));
    vlTOPp->mkTopMAC__DOT__x___05Fh39218 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39068) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901));
    vlTOPp->mkTopMAC__DOT__x___05Fh31667 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31469) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31470));
    vlTOPp->mkTopMAC__DOT__x___05Fh4819 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4618) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4619));
    vlTOPp->mkTopMAC__DOT__x___05Fh63376 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_x3036_AND_y3037_THEN_2_ELSE_0___05Fq12 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63226));
    vlTOPp->mkTopMAC__DOT__y___05Fh55052 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31668) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31667));
    vlTOPp->mkTopMAC__DOT__y___05Fh31622 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31667) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31668));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2421 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4820) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4819));
    vlTOPp->mkTopMAC__DOT__y___05Fh4773 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4819) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4820));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d348 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55051)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_x_BIT_0___05FBIT_0_1608_THEN_2_ELSE_0___05Fq11 
                                         >> 1U))) << 1U)) 
                      | (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh55201 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55051) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052));
    vlTOPp->mkTopMAC__DOT__y___05Fh63377 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39218));
    vlTOPp->mkTopMAC__DOT__x___05Fh39368 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39218) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052));
    vlTOPp->mkTopMAC__DOT__x___05Fh31819 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31621) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31622));
    vlTOPp->mkTopMAC__DOT__x___05Fh4973 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4772) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4773));
    vlTOPp->mkTopMAC__DOT__x___05Fh63526 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63376) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63377));
    vlTOPp->mkTopMAC__DOT__y___05Fh55202 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31820) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31819));
    vlTOPp->mkTopMAC__DOT__y___05Fh31774 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31819) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31820));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2419 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4974) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4973));
    vlTOPp->mkTopMAC__DOT__y___05Fh4927 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4973) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4974));
    vlTOPp->mkTopMAC__DOT__x___05Fh55351 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55201) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202));
    vlTOPp->mkTopMAC__DOT__y___05Fh63527 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39368));
    vlTOPp->mkTopMAC__DOT__x___05Fh39518 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39368) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202));
    vlTOPp->mkTopMAC__DOT__x___05Fh31971 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31773) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31774));
    vlTOPp->mkTopMAC__DOT__x___05Fh5127 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh4926) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh4927));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d385 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63527) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63526)) 
            << 3U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63377) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63376)) 
                       << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63226) 
                                         ^ (IData)(
                                                   (vlTOPp->mkTopMAC__DOT__IF_x3036_AND_y3037_THEN_2_ELSE_0___05Fq12 
                                                    >> 1U))) 
                                        << 1U)) | ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63036) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63037)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh63676 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63526) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63527));
    vlTOPp->mkTopMAC__DOT__y___05Fh55352 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31972) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31971));
    vlTOPp->mkTopMAC__DOT__y___05Fh31926 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31971) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31972));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2417 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5128) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5127));
    vlTOPp->mkTopMAC__DOT__y___05Fh5081 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5127) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5128));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d349 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55351)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55201)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d348)));
    vlTOPp->mkTopMAC__DOT__x___05Fh55501 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55351) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352));
    vlTOPp->mkTopMAC__DOT__y___05Fh63677 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39518));
    vlTOPp->mkTopMAC__DOT__x___05Fh39668 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39518) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352));
    vlTOPp->mkTopMAC__DOT__x___05Fh32123 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh31925) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh31926));
    vlTOPp->mkTopMAC__DOT__x___05Fh5281 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5080) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5081));
    vlTOPp->mkTopMAC__DOT__x___05Fh63826 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63676) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63677));
    vlTOPp->mkTopMAC__DOT__y___05Fh55502 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32124) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32123));
    vlTOPp->mkTopMAC__DOT__y___05Fh32078 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32123) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32124));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2415 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5282) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5281));
    vlTOPp->mkTopMAC__DOT__y___05Fh5235 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5281) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5282));
    vlTOPp->mkTopMAC__DOT__x___05Fh55651 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55501) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502));
    vlTOPp->mkTopMAC__DOT__y___05Fh63827 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39668));
    vlTOPp->mkTopMAC__DOT__x___05Fh39818 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39668) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502));
    vlTOPp->mkTopMAC__DOT__x___05Fh32275 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32077) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32078));
    vlTOPp->mkTopMAC__DOT__x___05Fh5435 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5234) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5235));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d386 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63827) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63826)) 
            << 5U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63677) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63676)) 
                       << 4U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d385)));
    vlTOPp->mkTopMAC__DOT__x___05Fh63976 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63826) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63827));
    vlTOPp->mkTopMAC__DOT__y___05Fh55652 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32276) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32275));
    vlTOPp->mkTopMAC__DOT__y___05Fh32230 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32275) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32276));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2413 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5436) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5435));
    vlTOPp->mkTopMAC__DOT__y___05Fh5389 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5435) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5436));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d350 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55651)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55501)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d349)));
    vlTOPp->mkTopMAC__DOT__x___05Fh54231 = (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652) 
                                             << 6U) 
                                            | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502) 
                                                << 5U) 
                                               | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352) 
                                                   << 4U) 
                                                  | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202) 
                                                      << 3U) 
                                                     | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052) 
                                                         << 2U) 
                                                        | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901) 
                                                            << 1U) 
                                                           | (IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608)))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh38248 = (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652) 
                                             << 7U) 
                                            | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55502) 
                                                << 6U) 
                                               | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55352) 
                                                   << 5U) 
                                                  | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55202) 
                                                      << 4U) 
                                                     | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55052) 
                                                         << 3U) 
                                                        | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh54901) 
                                                            << 2U) 
                                                           | (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608) 
                                                               << 1U) 
                                                              | (IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628))))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh63977 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39818));
    vlTOPp->mkTopMAC__DOT__y___05Fh64127 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh39818) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652));
    vlTOPp->mkTopMAC__DOT__x___05Fh32427 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32229) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32230));
    vlTOPp->mkTopMAC__DOT__x___05Fh5589 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5388) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5389));
    vlTOPp->mkTopMAC__DOT__fraction___05F_2___05Fh53292 
        = vlTOPp->mkTopMAC__DOT__x___05Fh54231;
    vlTOPp->mkTopMAC__DOT__fraction___05F_3___05Fh37279 
        = vlTOPp->mkTopMAC__DOT__x___05Fh38248;
    vlTOPp->mkTopMAC__DOT__x___05Fh64126 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63976) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63977));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d233 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh32428) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh32427));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2411 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5590) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5589));
    vlTOPp->mkTopMAC__DOT__y___05Fh5543 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5589) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5590));
    vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d356 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628) 
            & (0x80U != (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h61608) 
                          << 8U) | (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628) 
                                     << 7U) | (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234) 
                                                << 6U) 
                                               | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d244))))))
            ? ((((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh55651) 
                 & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh55652)) 
                << 7U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d350))
            : vlTOPp->mkTopMAC__DOT__fraction___05F_2___05Fh53292);
    vlTOPp->mkTopMAC__DOT__x___05Fh64276 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh64126) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh64127));
    vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d387 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh64127) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh64126)) 
            << 7U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63977) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63976)) 
                       << 6U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d386)));
    vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
        = (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d233) 
            | (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234) 
                & (0x40U != (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628) 
                              << 7U) | (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234) 
                                         << 6U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d244))))) 
               & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh64127)))
            ? 0xffffff81U : 0xffffff80U);
    vlTOPp->mkTopMAC__DOT__x___05Fh5743 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5542) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5543));
    vlTOPp->mkTopMAC__DOT__IF_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_X_ETC___05F_d392 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh64127)
            ? (IData)(vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d387)
            : (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63977) 
                << 7U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63827) 
                           << 6U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63677) 
                                      << 5U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63527) 
                                                 << 4U) 
                                                | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63377) 
                                                    << 3U) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63226) 
                                                       << 2U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh63036) 
                                                          << 1U) 
                                                         | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh63037)))))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh47264 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47219) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 7U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh47065 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47067) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh47112 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47067) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 6U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46913 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46915) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh46960 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46915) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 5U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46761 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46763) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh46808 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46763) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 4U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46609 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46611) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh46656 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46611) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 3U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46457 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46459) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh46504 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46459) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 2U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46304 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46306) 
                                            & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                               >> 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh46351 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46306) 
                                                  ^ 
                                                  (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267 
                                                   >> 1U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46156 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46158) 
                                            & vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267);
    vlTOPp->mkTopMAC__DOT__y___05Fh46157 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46158) 
                                                  ^ vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d267));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2409 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5744) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5743));
    vlTOPp->mkTopMAC__DOT__y___05Fh5697 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5743) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5744));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37335 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh64127) 
             & (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh64276)) 
            << 8U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_X_ETC___05F_d392));
    vlTOPp->mkTopMAC__DOT__x___05Fh71583 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x17U) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46157));
    vlTOPp->mkTopMAC__DOT__y___05Fh71584 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x17U) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46157)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105496 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46157)));
    vlTOPp->mkTopMAC__DOT__IF_x6156_OR_y6157_THEN_3_ELSE_1___05Fq13 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46156) 
            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46157))
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh5897 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5696) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5697));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37281 
        = (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234) 
            & (0x40U != (((IData)(vlTOPp->mkTopMAC__DOT__x_BIT_0___05FBIT_0___05F_h45628) 
                          << 7U) | (((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d234) 
                                     << 6U) | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d244)))))
            ? vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37335
            : vlTOPp->mkTopMAC__DOT__fraction___05F_3___05Fh37279);
    vlTOPp->mkTopMAC__DOT__IF_INV_y1584_THEN_3_ELSE_1___05Fq16 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584)
            ? 1ULL : 3ULL);
    vlTOPp->mkTopMAC__DOT__IF_x1583_OR_y1584_THEN_3_ELSE_1___05Fq15 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh71583) 
            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584))
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh105494 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105496) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14));
    vlTOPp->mkTopMAC__DOT__y___05Fh105495 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105496) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105642 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46351) 
                                                   ^ (IData)(
                                                             (vlTOPp->mkTopMAC__DOT__IF_x6156_OR_y6157_THEN_3_ELSE_1___05Fq13 
                                                              >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh46305 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_x6156_OR_y6157_THEN_3_ELSE_1___05Fq13 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46351));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2407 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5898) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5897));
    vlTOPp->mkTopMAC__DOT__y___05Fh5851 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5897) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5898));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37277 
        = ((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d233)
            ? 0U : vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37281);
    vlTOPp->mkTopMAC__DOT__IF_INV_y05495_THEN_3_ELSE_1___05Fq18 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495)
            ? 1ULL : 3ULL);
    vlTOPp->mkTopMAC__DOT__IF_x05494_OR_y05495_THEN_3_ELSE_1___05Fq17 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105494) 
            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495))
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh105640 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105642) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh105686 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105642) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 1U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh71732 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105642)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46503 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46304) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46305));
    vlTOPp->mkTopMAC__DOT__x___05Fh6051 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh5850) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh5851));
    vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05Fq20 
        = ((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR_IF___05FETC___05F_d233)
            ? vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05F_d356
            : vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh37277);
    vlTOPp->mkTopMAC__DOT__x___05Fh114986 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105686) 
                                                   ^ (IData)(
                                                             (vlTOPp->mkTopMAC__DOT__IF_x05494_OR_y05495_THEN_3_ELSE_1___05Fq17 
                                                              >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh105641 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_x05494_OR_y05495_THEN_3_ELSE_1___05Fq17 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105686));
    vlTOPp->mkTopMAC__DOT__x___05Fh71729 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x18U) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71732));
    vlTOPp->mkTopMAC__DOT__y___05Fh71775 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x18U) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71732)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105793 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46504) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46503));
    vlTOPp->mkTopMAC__DOT__y___05Fh46458 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46503) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46504));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2405 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6052) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6051));
    vlTOPp->mkTopMAC__DOT__y___05Fh6005 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6051) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6052));
    vlTOPp->mkTopMAC__DOT__prod_mant___05Fh18654 = 
        (0x7f0000U & (vlTOPp->mkTopMAC__DOT__IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_0_3_XOR___05FETC___05Fq20 
                      << 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh115032 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh114986)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105836 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105640) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105641));
    vlTOPp->mkTopMAC__DOT__x___05Fh81020 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71775) 
                                                  ^ (IData)(
                                                            (vlTOPp->mkTopMAC__DOT__IF_x1583_OR_y1584_THEN_3_ELSE_1___05Fq15 
                                                             >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh71730 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_x1583_OR_y1584_THEN_3_ELSE_1___05Fq15 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71775));
    vlTOPp->mkTopMAC__DOT__x___05Fh105791 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105793) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh105837 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105793) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 2U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh71883 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105793)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46655 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46457) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46458));
    vlTOPp->mkTopMAC__DOT__x___05Fh6205 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6004) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6005));
    vlTOPp->mkTopMAC__DOT__mant_a___05Fh18603 = (0x800000U 
                                                 | vlTOPp->mkTopMAC__DOT__prod_mant___05Fh18654);
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_8_5_XOR_rg_b_1_BIT_8_6_3_XOR_IF_r_ETC___05F_d1005 
        = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115032) 
                 ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_INV_y05495_THEN_3_ELSE_1___05Fq18 
                            >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh114987 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_INV_y05495_THEN_3_ELSE_1___05Fq18 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115032));
    vlTOPp->mkTopMAC__DOT__y___05Fh81066 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81020)));
    vlTOPp->mkTopMAC__DOT__x___05Fh71925 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh71729) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71730));
    vlTOPp->mkTopMAC__DOT__x___05Fh115138 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105837) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105836));
    vlTOPp->mkTopMAC__DOT__y___05Fh105792 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105836) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105837));
    vlTOPp->mkTopMAC__DOT__x___05Fh71880 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x19U) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71883));
    vlTOPp->mkTopMAC__DOT__y___05Fh71926 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x19U) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71883)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105943 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46656) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46655));
    vlTOPp->mkTopMAC__DOT__y___05Fh46610 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46655) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46656));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2403 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6206) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6205));
    vlTOPp->mkTopMAC__DOT__y___05Fh6159 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6205) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6206));
    vlTOPp->mkTopMAC__DOT__x___05Fh115183 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh114986) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh114987));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_24_14_XOR_INV_rg_a_BIT_8_5_XOR___05FETC___05F_d564 
        = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81066) 
                 ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_INV_y1584_THEN_3_ELSE_1___05Fq16 
                            >> 1U))));
    vlTOPp->mkTopMAC__DOT__y___05Fh81021 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_INV_y1584_THEN_3_ELSE_1___05Fq16 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81066));
    vlTOPp->mkTopMAC__DOT__y___05Fh115184 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115138)));
    vlTOPp->mkTopMAC__DOT__x___05Fh105986 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105791) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105792));
    vlTOPp->mkTopMAC__DOT__x___05Fh81172 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71926) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh71925));
    vlTOPp->mkTopMAC__DOT__y___05Fh71881 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh71925) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71926));
    vlTOPp->mkTopMAC__DOT__x___05Fh105941 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105943) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh105987 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105943) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 3U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh72033 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105943)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46807 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46609) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46610));
    vlTOPp->mkTopMAC__DOT__x___05Fh6359 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6158) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6159));
    vlTOPp->mkTopMAC__DOT__x___05Fh81217 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81020) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81021));
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_9_2_XOR_rg_b_1_BIT_9_3_6_XOR_rg_a_ETC___05F_d1004 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115184) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115183));
    vlTOPp->mkTopMAC__DOT__y___05Fh115139 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115183) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115184));
    vlTOPp->mkTopMAC__DOT__y___05Fh81218 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81172)));
    vlTOPp->mkTopMAC__DOT__x___05Fh72075 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh71880) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71881));
    vlTOPp->mkTopMAC__DOT__x___05Fh115289 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105987) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105986));
    vlTOPp->mkTopMAC__DOT__y___05Fh105942 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105986) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105987));
    vlTOPp->mkTopMAC__DOT__x___05Fh72030 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x1aU) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72033));
    vlTOPp->mkTopMAC__DOT__y___05Fh72076 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x1aU) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72033)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106093 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46808) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46807));
    vlTOPp->mkTopMAC__DOT__y___05Fh46762 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46807) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46808));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2401 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6360) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6359));
    vlTOPp->mkTopMAC__DOT__y___05Fh6313 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6359) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6360));
    vlTOPp->mkTopMAC__DOT__x___05Fh115334 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115138) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115139));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_25_11_XOR_INV_rg_a_BIT_9_2_XOR___05FETC___05F_d563 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81218) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81217));
    vlTOPp->mkTopMAC__DOT__y___05Fh81173 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81217) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81218));
    vlTOPp->mkTopMAC__DOT__y___05Fh115335 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115289)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106136 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105941) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105942));
    vlTOPp->mkTopMAC__DOT__x___05Fh81323 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72076) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72075));
    vlTOPp->mkTopMAC__DOT__y___05Fh72031 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72075) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72076));
    vlTOPp->mkTopMAC__DOT__x___05Fh106091 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106093) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh106137 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106093) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 4U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh72183 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106093)));
    vlTOPp->mkTopMAC__DOT__x___05Fh46959 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46761) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46762));
    vlTOPp->mkTopMAC__DOT__x___05Fh6513 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6312) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6313));
    vlTOPp->mkTopMAC__DOT__x___05Fh81368 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81172) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81173));
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_10_9_XOR_rg_b_1_BIT_10_0_9_XOR_rg_ETC___05F_d1003 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115335) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115334));
    vlTOPp->mkTopMAC__DOT__y___05Fh115290 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115334) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115335));
    vlTOPp->mkTopMAC__DOT__y___05Fh81369 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81323)));
    vlTOPp->mkTopMAC__DOT__x___05Fh72225 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72030) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72031));
    vlTOPp->mkTopMAC__DOT__x___05Fh115440 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106137) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106136));
    vlTOPp->mkTopMAC__DOT__y___05Fh106092 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106136) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106137));
    vlTOPp->mkTopMAC__DOT__x___05Fh72180 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x1bU) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72183));
    vlTOPp->mkTopMAC__DOT__y___05Fh72226 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x1bU) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72183)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106243 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46960) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46959));
    vlTOPp->mkTopMAC__DOT__y___05Fh46914 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46959) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46960));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2399 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6514) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6513));
    vlTOPp->mkTopMAC__DOT__y___05Fh6467 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6513) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6514));
    vlTOPp->mkTopMAC__DOT__x___05Fh115485 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115289) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115290));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_26_08_XOR_INV_rg_a_BIT_10_9_XOR_ETC___05F_d562 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81369) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81368));
    vlTOPp->mkTopMAC__DOT__y___05Fh81324 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81368) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81369));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_BIT_rg_a_BI_ETC___05F_d882 
        = (1U & (vlTOPp->mkTopMAC__DOT__mant_b___05Fh18607 
                 >> (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115440) 
                      << 4U) | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115289) 
                                 << 3U) | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115138) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh114986) 
                                               << 1U) 
                                              | (1U 
                                                 & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495)))))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh115486 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115440)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106286 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106091) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106092));
    vlTOPp->mkTopMAC__DOT__x___05Fh81474 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72226) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72225));
    vlTOPp->mkTopMAC__DOT__y___05Fh72181 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72225) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72226));
    vlTOPp->mkTopMAC__DOT__x___05Fh106241 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106243) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh106287 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106243) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 5U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh72333 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106243)));
    vlTOPp->mkTopMAC__DOT__x___05Fh47111 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh46913) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh46914));
    vlTOPp->mkTopMAC__DOT__x___05Fh6667 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6466) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6467));
    vlTOPp->mkTopMAC__DOT__x___05Fh81519 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81323) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81324));
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_11_6_XOR_rg_b_1_BIT_11_7_2_XOR_rg_ETC___05F_d1002 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115486) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115485));
    vlTOPp->mkTopMAC__DOT__y___05Fh115441 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115485) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115486));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d439 
        = (1U & (vlTOPp->mkTopMAC__DOT__mant_a___05Fh18603 
                 >> (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81474) 
                      << 4U) | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81323) 
                                 << 3U) | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81172) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81020) 
                                               << 1U) 
                                              | (1U 
                                                 & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584)))))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh81520 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81474)));
    vlTOPp->mkTopMAC__DOT__x___05Fh72375 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72180) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72181));
    vlTOPp->mkTopMAC__DOT__x___05Fh115591 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106287) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106286));
    vlTOPp->mkTopMAC__DOT__y___05Fh106242 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106286) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106287));
    vlTOPp->mkTopMAC__DOT__x___05Fh72330 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x1cU) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72333));
    vlTOPp->mkTopMAC__DOT__y___05Fh72376 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x1cU) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72333)));
    vlTOPp->mkTopMAC__DOT__y___05Fh47066 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47111) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh47112));
    vlTOPp->mkTopMAC__DOT__x___05Fh106393 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh47112) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47111));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2397 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6668) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6667));
    vlTOPp->mkTopMAC__DOT__y___05Fh6621 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6667) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6668));
    vlTOPp->mkTopMAC__DOT__y___05Fh130985 = (1U & (vlTOPp->mkTopMAC__DOT__mant_b___05Fh18607 
                                                   >> 
                                                   (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_11_6_XOR_rg_b_1_BIT_11_7_2_XOR_rg_ETC___05F_d1002) 
                                                     << 4U) 
                                                    | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_10_9_XOR_rg_b_1_BIT_10_0_9_XOR_rg_ETC___05F_d1003) 
                                                        << 3U) 
                                                       | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_9_2_XOR_rg_b_1_BIT_9_3_6_XOR_rg_a_ETC___05F_d1004) 
                                                           << 2U) 
                                                          | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_8_5_XOR_rg_b_1_BIT_8_6_3_XOR_IF_r_ETC___05F_d1005) 
                                                              << 1U) 
                                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495)))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh115636 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115440) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115441));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_27_05_XOR_INV_rg_a_BIT_11_6_XOR_ETC___05F_d561 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81520) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81519));
    vlTOPp->mkTopMAC__DOT__y___05Fh81475 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81519) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81520));
    vlTOPp->mkTopMAC__DOT__y___05Fh115637 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115591)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106436 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106241) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106242));
    vlTOPp->mkTopMAC__DOT__x___05Fh81625 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72376) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72375));
    vlTOPp->mkTopMAC__DOT__y___05Fh72331 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72375) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72376));
    vlTOPp->mkTopMAC__DOT__x___05Fh47263 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47065) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh47066));
    vlTOPp->mkTopMAC__DOT__x___05Fh106391 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106393) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh106437 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106393) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 6U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh72483 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106393)));
    vlTOPp->mkTopMAC__DOT__x___05Fh6821 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6620) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6621));
    vlTOPp->mkTopMAC__DOT__y___05Fh97019 = (1U & (vlTOPp->mkTopMAC__DOT__mant_a___05Fh18603 
                                                  >> 
                                                  (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_27_05_XOR_INV_rg_a_BIT_11_6_XOR_ETC___05F_d561) 
                                                    << 4U) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_26_08_XOR_INV_rg_a_BIT_10_9_XOR_ETC___05F_d562) 
                                                       << 3U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_25_11_XOR_INV_rg_a_BIT_9_2_XOR___05FETC___05F_d563) 
                                                          << 2U) 
                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_24_14_XOR_INV_rg_a_BIT_8_5_XOR___05FETC___05F_d564) 
                                                             << 1U) 
                                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584)))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh81670 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81474) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81475));
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_12_3_XOR_rg_b_1_BIT_12_4_5_XOR_rg_ETC___05F_d1008 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115637) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115636)) 
            << 5U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_11_6_XOR_rg_b_1_BIT_11_7_2_XOR_rg_ETC___05F_d1002) 
                       << 4U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_10_9_XOR_rg_b_1_BIT_10_0_9_XOR_rg_ETC___05F_d1003) 
                                  << 3U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_9_2_XOR_rg_b_1_BIT_9_3_6_XOR_rg_a_ETC___05F_d1004) 
                                             << 2U) 
                                            | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_8_5_XOR_rg_b_1_BIT_8_6_3_XOR_IF_r_ETC___05F_d1005) 
                                                << 1U) 
                                               | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh115592 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115636) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115637));
    vlTOPp->mkTopMAC__DOT__y___05Fh81671 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81625)));
    vlTOPp->mkTopMAC__DOT__x___05Fh72525 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72330) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72331));
    vlTOPp->mkTopMAC__DOT__x___05Fh106543 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh47264) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh47263));
    vlTOPp->mkTopMAC__DOT__x___05Fh115742 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106437) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106436));
    vlTOPp->mkTopMAC__DOT__y___05Fh106392 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106436) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106437));
    vlTOPp->mkTopMAC__DOT__x___05Fh72480 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x1dU) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72483));
    vlTOPp->mkTopMAC__DOT__y___05Fh72526 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x1dU) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72483)));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2395 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6822) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6821));
    vlTOPp->mkTopMAC__DOT__y___05Fh6775 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6821) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6822));
    vlTOPp->mkTopMAC__DOT__x___05Fh115787 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115591) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115592));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_28_46_XOR_INV_rg_a_BIT_12_3_XOR_ETC___05F_d567 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81671) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81670)) 
            << 5U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_27_05_XOR_INV_rg_a_BIT_11_6_XOR_ETC___05F_d561) 
                       << 4U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_26_08_XOR_INV_rg_a_BIT_10_9_XOR_ETC___05F_d562) 
                                  << 3U) | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_25_11_XOR_INV_rg_a_BIT_9_2_XOR___05FETC___05F_d563) 
                                             << 2U) 
                                            | (((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_24_14_XOR_INV_rg_a_BIT_8_5_XOR___05FETC___05F_d564) 
                                                << 1U) 
                                               | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584))))));
    vlTOPp->mkTopMAC__DOT__y___05Fh81626 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81670) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81671));
    vlTOPp->mkTopMAC__DOT__prod_exp___05Fh18658 = (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106543) 
                                                    << 7U) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106393) 
                                                       << 6U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106243) 
                                                          << 5U) 
                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106093) 
                                                             << 4U) 
                                                            | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105943) 
                                                                << 3U) 
                                                               | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105793) 
                                                                   << 2U) 
                                                                  | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105642) 
                                                                      << 1U) 
                                                                     | (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh105496))))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh106541 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106543) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh106587 = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106543) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_BITS_30_TO_23___05Fq14) 
                                                    >> 7U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh72633 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106543)));
    vlTOPp->mkTopMAC__DOT__y___05Fh115788 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115742)));
    vlTOPp->mkTopMAC__DOT__x___05Fh106586 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106391) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106392));
    vlTOPp->mkTopMAC__DOT__x___05Fh81776 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72526) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72525));
    vlTOPp->mkTopMAC__DOT__y___05Fh72481 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72525) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72526));
    vlTOPp->mkTopMAC__DOT__x___05Fh6975 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6774) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6775));
    vlTOPp->mkTopMAC__DOT__x___05Fh81821 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81625) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81626));
    vlTOPp->mkTopMAC__DOT__exp_a___05Fh18601 = vlTOPp->mkTopMAC__DOT__prod_exp___05Fh18658;
    vlTOPp->mkTopMAC__DOT__x___05Fh72630 = ((vlTOPp->mkTopMAC__DOT__rg_c 
                                             >> 0x1eU) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72633));
    vlTOPp->mkTopMAC__DOT__y___05Fh72676 = (1U & ((vlTOPp->mkTopMAC__DOT__rg_c 
                                                   >> 0x1eU) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72633)));
    vlTOPp->mkTopMAC__DOT__y___05Fh115743 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115787) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115788));
    vlTOPp->mkTopMAC__DOT__y___05Fh106542 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106586) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106587));
    vlTOPp->mkTopMAC__DOT__x___05Fh115893 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106587) 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106586));
    vlTOPp->mkTopMAC__DOT__y___05Fh81822 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81776)));
    vlTOPp->mkTopMAC__DOT__x___05Fh72675 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72480) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72481));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2393 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6976) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6975));
    vlTOPp->mkTopMAC__DOT__y___05Fh6929 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6975) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6976));
    vlTOPp->mkTopMAC__DOT___0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_X_ETC___05F_d328 
        = (vlTOPp->mkTopMAC__DOT__exp_a___05Fh18601 
           <= vlTOPp->mkTopMAC__DOT__exp_b___05Fh18605);
    vlTOPp->mkTopMAC__DOT__x___05Fh115938 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115742) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115743));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901 
        = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh106541) 
           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh106542));
    vlTOPp->mkTopMAC__DOT__y___05Fh115939 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115893)));
    vlTOPp->mkTopMAC__DOT__y___05Fh81777 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81821) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81822));
    vlTOPp->mkTopMAC__DOT__y___05Fh72631 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72675) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72676));
    vlTOPp->mkTopMAC__DOT__x___05Fh81927 = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72676) 
                                            ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72675));
    vlTOPp->mkTopMAC__DOT__x___05Fh7129 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh6928) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh6929));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012 
        = (0xffU & ((IData)(vlTOPp->mkTopMAC__DOT___0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_X_ETC___05F_d328)
                     ? (vlTOPp->mkTopMAC__DOT__rg_c 
                        >> 0x17U) : (IData)(vlTOPp->mkTopMAC__DOT__prod_exp___05Fh18658)));
    vlTOPp->mkTopMAC__DOT__x___05Fh119366 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901)));
    vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_ETC___05F_d1009 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115939) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115938)) 
            << 7U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115788) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115787)) 
                       << 6U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_12_3_XOR_rg_b_1_BIT_12_4_5_XOR_rg_ETC___05F_d1008)));
    vlTOPp->mkTopMAC__DOT__y___05Fh115894 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115938) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115939));
    vlTOPp->mkTopMAC__DOT__x___05Fh81972 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81776) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81777));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460 
        = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh72630) 
           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh72631));
    vlTOPp->mkTopMAC__DOT__y___05Fh81973 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81927)));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2391 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7130) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7129));
    vlTOPp->mkTopMAC__DOT__y___05Fh7083 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7129) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7130));
    vlTOPp->mkTopMAC__DOT__sum_exp___05Fh18612 = vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012;
    if ((1U & (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012))) {
        vlTOPp->mkTopMAC__DOT__IF_INV_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BI_ETC___05Fq31 = 0ULL;
        vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05Fq30 = 2ULL;
    } else {
        vlTOPp->mkTopMAC__DOT__IF_INV_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BI_ETC___05Fq31 = 2ULL;
        vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05Fq30 = 0ULL;
    }
    vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70154 = (
                                                   (0xffffff00U 
                                                    & ((- (IData)((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366))) 
                                                       << 8U)) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115893) 
                                                       << 7U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115742) 
                                                          << 6U) 
                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115591) 
                                                             << 5U) 
                                                            | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115440) 
                                                                << 4U) 
                                                               | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115289) 
                                                                   << 3U) 
                                                                  | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115138) 
                                                                      << 2U) 
                                                                     | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh114986) 
                                                                         << 1U) 
                                                                        | (1U 
                                                                           & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh105495)))))))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh116089 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh115893) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh115894));
    vlTOPp->mkTopMAC__DOT__x___05Fh85400 = (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460)));
    vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_30_40_XOR_INV_rg_a_BIT_14_7_XOR_ETC___05F_d568 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81973) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81972)) 
            << 7U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81822) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81821)) 
                       << 6U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_28_46_XOR_INV_rg_a_BIT_12_3_XOR_ETC___05F_d567)));
    vlTOPp->mkTopMAC__DOT__y___05Fh81928 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81972) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81973));
    vlTOPp->mkTopMAC__DOT__x___05Fh7283 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7082) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7083));
    vlTOPp->mkTopMAC__DOT__y___05Fh182125 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 1U) 
                                                   ^ (IData)(
                                                             (vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05Fq30 
                                                              >> 1U))));
    vlTOPp->mkTopMAC__DOT__x___05Fh174863 = (1U & ((IData)(
                                                           (vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05Fq30 
                                                            >> 1U)) 
                                                   & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                      >> 1U)));
    vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
        = ((0x1fU >= vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70154)
            ? (vlTOPp->mkTopMAC__DOT__mant_b___05Fh18607 
               >> vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70154)
            : 0U);
    vlTOPp->mkTopMAC__DOT__y___05Fh116045 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116089) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70217 = (
                                                   (0xffffff00U 
                                                    & ((- (IData)((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400))) 
                                                       << 8U)) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81927) 
                                                       << 7U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81776) 
                                                          << 6U) 
                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81625) 
                                                             << 5U) 
                                                            | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81474) 
                                                                << 4U) 
                                                               | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81323) 
                                                                   << 3U) 
                                                                  | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81172) 
                                                                      << 2U) 
                                                                     | (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81020) 
                                                                         << 1U) 
                                                                        | (1U 
                                                                           & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh71584)))))))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh82123 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh81927) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh81928));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2389 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7284) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7283));
    vlTOPp->mkTopMAC__DOT__y___05Fh7237 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7283) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7284));
    vlTOPp->mkTopMAC__DOT__x___05Fh182275 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_INV_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BI_ETC___05Fq31 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182125));
    vlTOPp->mkTopMAC__DOT__y___05Fh182276 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 2U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh174863)));
    vlTOPp->mkTopMAC__DOT__x___05Fh175013 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh174863) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 2U));
    vlTOPp->mkTopMAC__DOT__IF_mant_b_adj29572_BIT_0_AND_y30985_THEN_2_ELSE_0___05Fq22 
        = ((vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh130985))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh116240 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116045));
    vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 = 
        ((0x1fU >= vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70217)
          ? (vlTOPp->mkTopMAC__DOT__mant_a___05Fh18603 
             >> vlTOPp->mkTopMAC__DOT__exp_diff___05Fh70217)
          : 0U);
    vlTOPp->mkTopMAC__DOT__y___05Fh82079 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82123) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh7437 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7236) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7237));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2056 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182276) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182275)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182125) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_INV_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BI_ETC___05Fq31 
                                         >> 1U))) << 1U)) 
                      | (1U & (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012))));
    vlTOPp->mkTopMAC__DOT__x___05Fh182425 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182275) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182276));
    vlTOPp->mkTopMAC__DOT__y___05Fh182426 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 3U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175013)));
    vlTOPp->mkTopMAC__DOT__x___05Fh175163 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175013) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh131329 = (1U & ((IData)(
                                                           (vlTOPp->mkTopMAC__DOT__IF_mant_b_adj29572_BIT_0_AND_y30985_THEN_2_ELSE_0___05Fq22 
                                                            >> 1U)) 
                                                   & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                      >> 1U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh116196 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116240) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__IF_mant_a_adj5606_BIT_0_AND_y7019_THEN_2_ELSE_0___05Fq21 
        = ((vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh97019))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh82274 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82079));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2387 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7438) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7437));
    vlTOPp->mkTopMAC__DOT__y___05Fh7391 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7437) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7438));
    vlTOPp->mkTopMAC__DOT__x___05Fh182575 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182425) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182426));
    vlTOPp->mkTopMAC__DOT__y___05Fh182576 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 4U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175163)));
    vlTOPp->mkTopMAC__DOT__x___05Fh175313 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175163) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh131481 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131329) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh116391 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116196));
    vlTOPp->mkTopMAC__DOT__x___05Fh97363 = (1U & ((IData)(
                                                          (vlTOPp->mkTopMAC__DOT__IF_mant_a_adj5606_BIT_0_AND_y7019_THEN_2_ELSE_0___05Fq21 
                                                           >> 1U)) 
                                                  & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                     >> 1U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh82230 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82274) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh7591 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7390) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7391));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2057 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182576) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182575)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182426) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182425)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2056)));
    vlTOPp->mkTopMAC__DOT__x___05Fh182725 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182575) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182576));
    vlTOPp->mkTopMAC__DOT__y___05Fh182726 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 5U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175313)));
    vlTOPp->mkTopMAC__DOT__x___05Fh175463 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175313) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 5U));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1273 
        = ((8U & ((0xfffffff8U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                  ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131481) 
                     << 3U))) | ((4U & ((0xfffffffcU 
                                         & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                        ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131329) 
                                           << 2U))) 
                                 | ((2U & ((0xfffffffeU 
                                            & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                           ^ ((IData)(
                                                      (vlTOPp->mkTopMAC__DOT__IF_mant_b_adj29572_BIT_0_AND_y30985_THEN_2_ELSE_0___05Fq22 
                                                       >> 1U)) 
                                              << 1U))) 
                                    | (1U & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh130985))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh131633 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131481) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh116347 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116391) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh97515 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97363) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh82425 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82230));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2385 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7592) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7591));
    vlTOPp->mkTopMAC__DOT__y___05Fh7545 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7591) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7592));
    vlTOPp->mkTopMAC__DOT__x___05Fh182875 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182725) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182726));
    vlTOPp->mkTopMAC__DOT__y___05Fh182876 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 6U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175463)));
    vlTOPp->mkTopMAC__DOT__x___05Fh175613 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175463) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh131785 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131633) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh116542 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116347));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d832 
        = ((8U & ((0xfffffff8U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                  ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97515) 
                     << 3U))) | ((4U & ((0xfffffffcU 
                                         & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                        ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97363) 
                                           << 2U))) 
                                 | ((2U & ((0xfffffffeU 
                                            & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                           ^ ((IData)(
                                                      (vlTOPp->mkTopMAC__DOT__IF_mant_a_adj5606_BIT_0_AND_y7019_THEN_2_ELSE_0___05Fq21 
                                                       >> 1U)) 
                                              << 1U))) 
                                    | (1U & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh97019))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh97667 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97515) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh82381 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82425) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh7745 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7544) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7545));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2058 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182876) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182875)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182726) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182725)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2057)));
    vlTOPp->mkTopMAC__DOT__x___05Fh183025 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh182875) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182876));
    vlTOPp->mkTopMAC__DOT__y___05Fh183176 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175613) 
                                             & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh183026 = (1U & (
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012) 
                                                    >> 7U) 
                                                   ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh175613)));
    vlTOPp->mkTopMAC__DOT__x___05Fh131937 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131785) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 5U));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1011 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116542)) 
            << 0xbU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116391)) 
                         << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116240)) 
                                      << 9U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116089)) 
                                                 << 8U) 
                                                | (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_ETC___05F_d1009)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh116498 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116542) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh97819 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97667) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh82576 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82381));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2383 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7746) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7745));
    vlTOPp->mkTopMAC__DOT__y___05Fh7699 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7745) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7746));
    vlTOPp->mkTopMAC__DOT__x___05Fh183175 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh183025) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183026));
    vlTOPp->mkTopMAC__DOT__x___05Fh132089 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131937) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh116693 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116498));
    vlTOPp->mkTopMAC__DOT__x___05Fh97971 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97819) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 5U));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d570 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82576)) 
            << 0xbU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82425)) 
                         << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82274)) 
                                      << 9U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                                  ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82123)) 
                                                 << 8U) 
                                                | (IData)(vlTOPp->mkTopMAC__DOT__INV_rg_c_4_BIT_30_40_XOR_INV_rg_a_BIT_14_7_XOR_ETC___05F_d568)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh82532 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82576) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh7899 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7698) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7699));
    vlTOPp->mkTopMAC__DOT__x___05Fh183325 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh183175) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183176));
    vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05F_d2059 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183176) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh183175)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183026) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh183025)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2058)));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1275 
        = ((0x80U & ((0xffffff80U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                     ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132089) 
                        << 7U))) | ((0x40U & ((0xffffffc0U 
                                               & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                              ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131937) 
                                                 << 6U))) 
                                    | ((0x20U & ((0xffffffe0U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131785) 
                                                  << 5U))) 
                                       | ((0x10U & 
                                           ((0xfffffff0U 
                                             & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                            ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh131633) 
                                               << 4U))) 
                                          | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1273)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh132241 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132089) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh116649 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116693) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh98123 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97971) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh82727 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82532));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2381 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7900) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7899));
    vlTOPp->mkTopMAC__DOT__y___05Fh7853 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7899) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7900));
    vlTOPp->mkTopMAC__DOT__x___05Fh132393 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132241) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh116844 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116649));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d834 
        = ((0x80U & ((0xffffff80U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                     ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98123) 
                        << 7U))) | ((0x40U & ((0xffffffc0U 
                                               & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                              ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97971) 
                                                 << 6U))) 
                                    | ((0x20U & ((0xffffffe0U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97819) 
                                                  << 5U))) 
                                       | ((0x10U & 
                                           ((0xfffffff0U 
                                             & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                            ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh97667) 
                                               << 4U))) 
                                          | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d832)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh98275 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98123) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh82683 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82727) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh8053 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh7852) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh7853));
    vlTOPp->mkTopMAC__DOT__x___05Fh132545 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132393) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh116800 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116844) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh98427 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98275) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh82878 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82683));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2379 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8054) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8053));
    vlTOPp->mkTopMAC__DOT__y___05Fh8007 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8053) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8054));
    vlTOPp->mkTopMAC__DOT__x___05Fh132697 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132545) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh116995 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116800));
    vlTOPp->mkTopMAC__DOT__x___05Fh98579 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98427) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh82834 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82878) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh8207 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8006) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8007));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1277 
        = ((0x800U & ((0xfffff800U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                      ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132697) 
                         << 0xbU))) | ((0x400U & ((0xfffffc00U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132545) 
                                                   << 0xaU))) 
                                       | ((0x200U & 
                                           ((0xfffffe00U 
                                             & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                            ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132393) 
                                               << 9U))) 
                                          | ((0x100U 
                                              & ((0xffffff00U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132241) 
                                                  << 8U))) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1275)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh132849 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132697) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh116951 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116995) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh98731 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98579) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh83029 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82834));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2377 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8208) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8207));
    vlTOPp->mkTopMAC__DOT__y___05Fh8161 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8207) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8208));
    vlTOPp->mkTopMAC__DOT__x___05Fh133001 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132849) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh117146 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh116951));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d836 
        = ((0x800U & ((0xfffff800U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                      ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98731) 
                         << 0xbU))) | ((0x400U & ((0xfffffc00U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98579) 
                                                   << 0xaU))) 
                                       | ((0x200U & 
                                           ((0xfffffe00U 
                                             & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                            ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98427) 
                                               << 9U))) 
                                          | ((0x100U 
                                              & ((0xffffff00U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98275) 
                                                  << 8U))) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d834)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh98883 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98731) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh82985 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83029) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh8361 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8160) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8161));
    vlTOPp->mkTopMAC__DOT__x___05Fh133153 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133001) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xdU));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1013 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117146)) 
            << 0xfU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116995)) 
                         << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116844)) 
                                      << 0xdU) | ((
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                                    ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh116693)) 
                                                   << 0xcU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1011)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh117102 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117146) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh99035 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98883) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh83180 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh82985));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2375 
        = ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8362) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8361));
    vlTOPp->mkTopMAC__DOT__y___05Fh8315 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8361) 
                                           & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8362));
    vlTOPp->mkTopMAC__DOT__x___05Fh133305 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133153) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh117297 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117102));
    vlTOPp->mkTopMAC__DOT__x___05Fh99187 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99035) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xdU));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d572 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83180)) 
            << 0xfU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83029)) 
                         << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82878)) 
                                      << 0xdU) | ((
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                                    ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh82727)) 
                                                   << 0xcU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d570)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh83136 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83180) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__y___05Fh2488 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh8314) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh8315));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1279 
        = ((0x8000U & ((0xffff8000U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                       ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133305) 
                          << 0xfU))) | ((0x4000U & 
                                         ((0xffffc000U 
                                           & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                          ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133153) 
                                             << 0xeU))) 
                                        | ((0x2000U 
                                            & ((0xffffe000U 
                                                & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                               ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133001) 
                                                  << 0xdU))) 
                                           | ((0x1000U 
                                               & ((0xfffff000U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh132849) 
                                                   << 0xcU))) 
                                              | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1277)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh133457 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133305) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh117253 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117297) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh99339 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99187) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh83331 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83136));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2373 
        = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh2487) 
           ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh2488));
    vlTOPp->mkTopMAC__DOT__x___05Fh133609 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133457) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh117448 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117253));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d838 
        = ((0x8000U & ((0xffff8000U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                       ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99339) 
                          << 0xfU))) | ((0x4000U & 
                                         ((0xffffc000U 
                                           & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                          ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99187) 
                                             << 0xeU))) 
                                        | ((0x2000U 
                                            & ((0xffffe000U 
                                                & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                               ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99035) 
                                                  << 0xdU))) 
                                           | ((0x1000U 
                                               & ((0xfffff000U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh98883) 
                                                   << 0xcU))) 
                                              | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d836)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh99491 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99339) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh83287 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83331) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__product___05F_1___05Fh1619 
        = ((IData)(1U) + ((0x80000000U & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2373)) 
                                          << 0x1fU)) 
                          | ((0x40000000U & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2375)) 
                                             << 0x1eU)) 
                             | ((0x20000000U & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2377)) 
                                                << 0x1dU)) 
                                | ((0x10000000U & (
                                                   (~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2379)) 
                                                   << 0x1cU)) 
                                   | ((0x8000000U & 
                                       ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2381)) 
                                        << 0x1bU)) 
                                      | ((0x4000000U 
                                          & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2383)) 
                                             << 0x1aU)) 
                                         | ((0x2000000U 
                                             & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2385)) 
                                                << 0x19U)) 
                                            | ((0x1000000U 
                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2387)) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2389)) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2391)) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2393)) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2395)) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2397)) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2399)) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2401)) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2403)) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2405)) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2407)) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2409)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2411)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2413)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2415)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2417)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2419)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2421)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2423)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2425)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2427)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2429)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2431)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2433)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2435)))))))))))))))))))))))))))))))))));
    vlTOPp->mkTopMAC__DOT__product___05Fh1510 = (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2373) 
                                                  << 0x1fU) 
                                                 | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2375) 
                                                     << 0x1eU) 
                                                    | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2377) 
                                                        << 0x1dU) 
                                                       | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2379) 
                                                           << 0x1cU) 
                                                          | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2381) 
                                                              << 0x1bU) 
                                                             | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2383) 
                                                                 << 0x1aU) 
                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2385) 
                                                                    << 0x19U) 
                                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2387) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2389) 
                                                                          << 0x17U) 
                                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2391) 
                                                                             << 0x16U) 
                                                                            | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2393) 
                                                                                << 0x15U) 
                                                                               | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2395) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2397) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2399) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2401) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2403) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2405) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2407) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2409) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2411) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2413) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2415) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2417) 
                                                                                << 9U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2419) 
                                                                                << 8U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2421) 
                                                                                << 7U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2423) 
                                                                                << 6U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2425) 
                                                                                << 5U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2427) 
                                                                                << 4U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2429) 
                                                                                << 3U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2431) 
                                                                                << 2U) 
                                                                                | (((IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2433) 
                                                                                << 1U) 
                                                                                | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2435))))))))))))))))))))))))))))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh133761 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133609) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh117404 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117448) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh99643 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99491) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh83482 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83287));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
        = ((1U & ((0x80U & vlTOPp->mkTopMAC__DOT__b___05Fh1501)
                   ? (IData)(vlTOPp->mkTopMAC__DOT__sign___05F_1___05Fh1563)
                   : (vlTOPp->mkTopMAC__DOT__SEXT_rg_a_BITS_7_TO_0_079___05F_d2080 
                      >> 7U))) ? vlTOPp->mkTopMAC__DOT__product___05F_1___05Fh1619
            : vlTOPp->mkTopMAC__DOT__product___05Fh1510);
    vlTOPp->mkTopMAC__DOT__x___05Fh133913 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133761) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh117599 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117404));
    vlTOPp->mkTopMAC__DOT__x___05Fh99795 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99643) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh83438 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83482) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh1475 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                  ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                 >> 0x1fU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15983 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__y___05Fh16031 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15829 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__y___05Fh15877 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15675 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__y___05Fh15723 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15521 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh15569 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15367 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__y___05Fh15415 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh15213 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh15261 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x19U));
    vlTOPp->mkTopMAC__DOT__x___05Fh15059 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x18U));
    vlTOPp->mkTopMAC__DOT__y___05Fh15107 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14905 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14953 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x17U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14751 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x16U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14799 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14597 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x15U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14645 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14443 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x14U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14491 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14289 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14337 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh14135 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x12U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14183 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh13981 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh14029 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh13827 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh13875 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh13673 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh13721 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh13519 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xeU));
    vlTOPp->mkTopMAC__DOT__y___05Fh13567 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh13365 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh13413 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh13211 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh13259 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh13057 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh13105 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh12903 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh12951 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh12749 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12797 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh12595 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 8U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12643 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh12441 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12489 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh12287 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12335 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh12133 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12181 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh11979 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh12027 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh11825 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh11873 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh11671 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh11719 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh11516 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   & vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 1U));
    vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq43 
        = ((1U & (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                  & vlTOPp->mkTopMAC__DOT__rg_c)) ? 2ULL
            : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh11564 = (1U & ((vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                   ^ vlTOPp->mkTopMAC__DOT__rg_c) 
                                                  >> 1U));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1281 
        = ((0x80000U & ((0xfff80000U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                        ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133913) 
                           << 0x13U))) | ((0x40000U 
                                           & ((0xfffc0000U 
                                               & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                              ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133761) 
                                                 << 0x12U))) 
                                          | ((0x20000U 
                                              & ((0xfffe0000U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133609) 
                                                  << 0x11U))) 
                                             | ((0x10000U 
                                                 & ((0xffff0000U 
                                                     & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                    ^ 
                                                    ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133457) 
                                                     << 0x10U))) 
                                                | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1279)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh134065 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh133913) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh117555 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117599) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh99947 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99795) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh83633 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83438));
    vlTOPp->mkTopMAC__DOT__y___05Fh11517 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq43 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11564));
    vlTOPp->mkTopMAC__DOT__x___05Fh134217 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134065) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh117750 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117555));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d840 
        = ((0x80000U & ((0xfff80000U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                        ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99947) 
                           << 0x13U))) | ((0x40000U 
                                           & ((0xfffc0000U 
                                               & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                              ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99795) 
                                                 << 0x12U))) 
                                          | ((0x20000U 
                                              & ((0xfffe0000U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99643) 
                                                  << 0x11U))) 
                                             | ((0x10000U 
                                                 & ((0xffff0000U 
                                                     & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                    ^ 
                                                    ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99491) 
                                                     << 0x10U))) 
                                                | (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d838)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh100099 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh99947) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh83589 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83633) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh11718 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11516) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11517));
    vlTOPp->mkTopMAC__DOT__x___05Fh134369 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134217) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x15U));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1015 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117750)) 
            << 0x13U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117599)) 
                          << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117448)) 
                                        << 0x11U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117297)) 
                                         << 0x10U) 
                                        | (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1013)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh117706 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117750) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh100251 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100099) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh83784 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83589));
    vlTOPp->mkTopMAC__DOT__y___05Fh11672 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11718) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11719));
    vlTOPp->mkTopMAC__DOT__x___05Fh134521 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134369) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh117901 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117706));
    vlTOPp->mkTopMAC__DOT__x___05Fh100403 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100251) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x15U));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d574 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83784)) 
            << 0x13U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83633)) 
                          << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83482)) 
                                        << 0x11U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83331)) 
                                         << 0x10U) 
                                        | (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d572)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh83740 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83784) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh11872 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11671) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11672));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1283 
        = ((0x800000U & ((0xff800000U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                         ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134521) 
                            << 0x17U))) | ((0x400000U 
                                            & ((0xffc00000U 
                                                & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                               ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134369) 
                                                  << 0x16U))) 
                                           | ((0x200000U 
                                               & ((0xffe00000U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134217) 
                                                   << 0x15U))) 
                                              | ((0x100000U 
                                                  & ((0xfff00000U 
                                                      & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                     ^ 
                                                     ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134065) 
                                                      << 0x14U))) 
                                                 | vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1281))));
    vlTOPp->mkTopMAC__DOT__x___05Fh134673 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134521) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh117857 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117901) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh100555 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100403) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh83935 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83740));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2683 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11873) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11872)) 
            << 3U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11719) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11718)) 
                       << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11564) 
                                         ^ (IData)(
                                                   (vlTOPp->mkTopMAC__DOT__IF_IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_ETC___05Fq43 
                                                    >> 1U))) 
                                        << 1U)) | (1U 
                                                   & (vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2470 
                                                      ^ vlTOPp->mkTopMAC__DOT__rg_c)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh11826 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11872) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11873));
    vlTOPp->mkTopMAC__DOT__x___05Fh134825 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134673) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh118052 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh117857));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d842 
        = ((0x800000U & ((0xff800000U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                         ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100555) 
                            << 0x17U))) | ((0x400000U 
                                            & ((0xffc00000U 
                                                & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                               ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100403) 
                                                  << 0x16U))) 
                                           | ((0x200000U 
                                               & ((0xffe00000U 
                                                   & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                  ^ 
                                                  ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100251) 
                                                   << 0x15U))) 
                                              | ((0x100000U 
                                                  & ((0xfff00000U 
                                                      & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                     ^ 
                                                     ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100099) 
                                                      << 0x14U))) 
                                                 | vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d840))));
    vlTOPp->mkTopMAC__DOT__x___05Fh100707 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100555) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh83891 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83935) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12026 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11825) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11826));
    vlTOPp->mkTopMAC__DOT__x___05Fh134977 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134825) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh118008 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118052) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh100859 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100707) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh84086 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh83891));
    vlTOPp->mkTopMAC__DOT__y___05Fh11980 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12026) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12027));
    vlTOPp->mkTopMAC__DOT__x___05Fh135129 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134977) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh118203 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118008));
    vlTOPp->mkTopMAC__DOT__x___05Fh101011 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100859) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh84042 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84086) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12180 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh11979) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh11980));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1285 
        = ((0x8000000U & ((0xf8000000U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                          ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135129) 
                             << 0x1bU))) | ((0x4000000U 
                                             & ((0xfc000000U 
                                                 & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134977) 
                                                   << 0x1aU))) 
                                            | ((0x2000000U 
                                                & ((0xfe000000U 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134825) 
                                                    << 0x19U))) 
                                               | ((0x1000000U 
                                                   & ((0xff000000U 
                                                       & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                      ^ 
                                                      ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh134673) 
                                                       << 0x18U))) 
                                                  | vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1283))));
    vlTOPp->mkTopMAC__DOT__x___05Fh135281 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135129) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh118159 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118203) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh101163 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101011) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh84237 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84042));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2684 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12181) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12180)) 
            << 5U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12027) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12026)) 
                       << 4U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2683)));
    vlTOPp->mkTopMAC__DOT__y___05Fh12134 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12180) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12181));
    vlTOPp->mkTopMAC__DOT__x___05Fh135433 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135281) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh118354 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118159));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d844 
        = ((0x8000000U & ((0xf8000000U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                          ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101163) 
                             << 0x1bU))) | ((0x4000000U 
                                             & ((0xfc000000U 
                                                 & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101011) 
                                                   << 0x1aU))) 
                                            | ((0x2000000U 
                                                & ((0xfe000000U 
                                                    & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100859) 
                                                    << 0x19U))) 
                                               | ((0x1000000U 
                                                   & ((0xff000000U 
                                                       & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                      ^ 
                                                      ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh100707) 
                                                       << 0x18U))) 
                                                  | vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d842))));
    vlTOPp->mkTopMAC__DOT__x___05Fh101315 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101163) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh84193 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84237) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12334 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12133) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12134));
    vlTOPp->mkTopMAC__DOT__x___05Fh135585 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135433) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1017 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118354)) 
            << 0x17U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118203)) 
                          << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118052)) 
                                        << 0x15U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh117901)) 
                                         << 0x14U) 
                                        | vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1015))));
    vlTOPp->mkTopMAC__DOT__y___05Fh118310 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118354) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh101467 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101315) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh84388 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84193));
    vlTOPp->mkTopMAC__DOT__y___05Fh12288 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12334) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12335));
    vlTOPp->mkTopMAC__DOT__y___05Fh130464 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135585) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572 
                                                >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh118505 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118310));
    vlTOPp->mkTopMAC__DOT__x___05Fh101619 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101467) 
                                             & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                                >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d576 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84388)) 
            << 0x17U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84237)) 
                          << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84086)) 
                                        << 0x15U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh83935)) 
                                         << 0x14U) 
                                        | vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d574))));
    vlTOPp->mkTopMAC__DOT__y___05Fh84344 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84388) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12488 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12287) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12288));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1287 
        = ((0x80000000U & ((0x80000000U & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                           ^ ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh130464) 
                              << 0x1fU))) | ((0x40000000U 
                                              & ((0xc0000000U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135585) 
                                                  << 0x1eU))) 
                                             | ((0x20000000U 
                                                 & ((0xe0000000U 
                                                     & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                    ^ 
                                                    ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135433) 
                                                     << 0x1dU))) 
                                                | ((0x10000000U 
                                                    & ((0xf0000000U 
                                                        & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572) 
                                                       ^ 
                                                       ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh135281) 
                                                        << 0x1cU))) 
                                                   | vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1285))));
    vlTOPp->mkTopMAC__DOT__y___05Fh118461 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118505) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__y___05Fh96498 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101619) 
                                            & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606 
                                               >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh84539 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84344));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2685 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12489) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12488)) 
            << 7U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12335) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12334)) 
                       << 6U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2684)));
    vlTOPp->mkTopMAC__DOT__y___05Fh12442 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12488) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12489));
    vlTOPp->mkTopMAC__DOT__x___05Fh118656 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118461));
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d846 
        = ((0x80000000U & ((0x80000000U & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                           ^ ((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh96498) 
                              << 0x1fU))) | ((0x40000000U 
                                              & ((0xc0000000U 
                                                  & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                 ^ 
                                                 ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101619) 
                                                  << 0x1eU))) 
                                             | ((0x20000000U 
                                                 & ((0xe0000000U 
                                                     & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                    ^ 
                                                    ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101467) 
                                                     << 0x1dU))) 
                                                | ((0x10000000U 
                                                    & ((0xf0000000U 
                                                        & vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606) 
                                                       ^ 
                                                       ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh101315) 
                                                        << 0x1cU))) 
                                                   | vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d844))));
    vlTOPp->mkTopMAC__DOT__y___05Fh84495 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84539) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12642 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12441) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12442));
    vlTOPp->mkTopMAC__DOT__y___05Fh118612 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118656) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh84690 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84495));
    vlTOPp->mkTopMAC__DOT__y___05Fh12596 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12642) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12643));
    vlTOPp->mkTopMAC__DOT__x___05Fh118807 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118612));
    vlTOPp->mkTopMAC__DOT__y___05Fh84646 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84690) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12796 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12595) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12596));
    vlTOPp->mkTopMAC__DOT__y___05Fh118763 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118807) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh84841 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84646));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2686 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12797) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12796)) 
            << 9U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12643) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12642)) 
                       << 8U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2685)));
    vlTOPp->mkTopMAC__DOT__y___05Fh12750 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12796) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12797));
    vlTOPp->mkTopMAC__DOT__x___05Fh118958 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118763));
    vlTOPp->mkTopMAC__DOT__y___05Fh84797 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84841) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh12950 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12749) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12750));
    vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1019 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118958)) 
            << 0x1bU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118807)) 
                          << 0x1aU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118656)) 
                                        << 0x19U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118505)) 
                                         << 0x18U) 
                                        | vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1017))));
    vlTOPp->mkTopMAC__DOT__y___05Fh118914 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh118958) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh84992 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84797));
    vlTOPp->mkTopMAC__DOT__y___05Fh12904 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12950) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12951));
    vlTOPp->mkTopMAC__DOT__x___05Fh119109 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh118914));
    vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d578 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84992)) 
            << 0x1bU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84841)) 
                          << 0x1aU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84690)) 
                                        << 0x19U) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84539)) 
                                         << 0x18U) 
                                        | vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d576))));
    vlTOPp->mkTopMAC__DOT__y___05Fh84948 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh84992) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh13104 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12903) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12904));
    vlTOPp->mkTopMAC__DOT__y___05Fh119065 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119109) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh85143 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh84948));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2687 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13105) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13104)) 
            << 0xbU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh12951) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh12950)) 
                         << 0xaU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2686)));
    vlTOPp->mkTopMAC__DOT__y___05Fh13058 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13104) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13105));
    vlTOPp->mkTopMAC__DOT__x___05Fh119260 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh119065));
    vlTOPp->mkTopMAC__DOT__y___05Fh85099 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85143) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh13258 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13057) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13058));
    vlTOPp->mkTopMAC__DOT__y___05Fh119216 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119260) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh85294 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh85099));
    vlTOPp->mkTopMAC__DOT__y___05Fh13212 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13258) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13259));
    vlTOPp->mkTopMAC__DOT__x___05Fh119411 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh119216));
    vlTOPp->mkTopMAC__DOT__y___05Fh85250 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85294) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh13412 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13211) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13212));
    vlTOPp->mkTopMAC__DOT__y___05Fh119367 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119411) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901));
    vlTOPp->mkTopMAC__DOT__x___05Fh85445 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh85250));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2688 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13413) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13412)) 
            << 0xdU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13259) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13258)) 
                         << 0xcU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2687)));
    vlTOPp->mkTopMAC__DOT__y___05Fh13366 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13412) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13413));
    vlTOPp->mkTopMAC__DOT__y___05Fh114359 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh119367));
    vlTOPp->mkTopMAC__DOT__y___05Fh85401 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85445) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460));
    vlTOPp->mkTopMAC__DOT__x___05Fh13566 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13365) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13366));
    vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70156 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh114359)) 
            << 0x1fU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119411)) 
                          << 0x1eU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119260)) 
                                        << 0x1dU) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d901) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh119109)) 
                                         << 0x1cU) 
                                        | vlTOPp->mkTopMAC__DOT__rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_rg_a_B_ETC___05F_d1019))));
    vlTOPp->mkTopMAC__DOT__y___05Fh80393 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85400) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh85401));
    vlTOPp->mkTopMAC__DOT__y___05Fh13520 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13566) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13567));
    vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
        = ((0x1fU >= vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70156)
            ? ((IData)(1U) << vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70156)
            : 0U);
    vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70219 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh80393)) 
            << 0x1fU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85445)) 
                          << 0x1eU) | ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                         ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85294)) 
                                        << 0x1dU) | 
                                       ((((IData)(vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d460) 
                                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh85143)) 
                                         << 0x1cU) 
                                        | vlTOPp->mkTopMAC__DOT__rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7_XOR_rg___05FETC___05F_d578))));
    vlTOPp->mkTopMAC__DOT__x___05Fh13720 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13519) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13520));
    vlTOPp->mkTopMAC__DOT__y___05Fh125955 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x17U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125802 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x16U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125649 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x15U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125496 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x14U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125343 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x13U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125190 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x12U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh125037 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x11U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124884 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x10U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124731 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xfU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124578 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xeU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124425 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xdU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124272 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xcU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124119 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xbU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123966 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xaU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123813 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 9U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123660 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 8U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123507 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 7U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123354 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 6U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123201 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 5U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123048 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 4U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh122895 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 3U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh122742 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 2U)));
    vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9___05FETC___05Fq23 
        = ((1U & vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022)
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh122588 = (1U & (~ 
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 1U)));
    vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
        = ((0x1fU >= vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70219)
            ? ((IData)(1U) << vlTOPp->mkTopMAC__DOT__exp_diff_sub___05Fh70219)
            : 0U);
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2689 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13721) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13720)) 
            << 0xfU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13567) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13566)) 
                         << 0xeU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2688)));
    vlTOPp->mkTopMAC__DOT__y___05Fh13674 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13720) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13721));
    vlTOPp->mkTopMAC__DOT__y___05Fh122542 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9___05FETC___05Fq23 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122588));
    vlTOPp->mkTopMAC__DOT__y___05Fh91989 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x17U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91836 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x16U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91683 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x15U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91530 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x14U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91377 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x13U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91224 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x12U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91071 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x11U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90918 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x10U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90765 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xfU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90612 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xeU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90459 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xdU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90306 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xcU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90153 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xbU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90000 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xaU)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89847 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 9U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89694 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 8U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89541 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 7U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89388 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 6U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89235 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 5U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89082 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 4U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh88929 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 3U)));
    vlTOPp->mkTopMAC__DOT__y___05Fh88776 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 2U)));
    vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_ETC___05Fq19 
        = ((1U & vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581)
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh88622 = (1U & (~ 
                                                  (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 1U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh13874 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13673) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13674));
    vlTOPp->mkTopMAC__DOT__x___05Fh122741 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 1U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122542)));
    vlTOPp->mkTopMAC__DOT__y___05Fh88576 = ((IData)(
                                                    (vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_ETC___05Fq19 
                                                     >> 1U)) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88622));
    vlTOPp->mkTopMAC__DOT__y___05Fh13828 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13874) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13875));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1140 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122742) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh122741)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122588) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9___05FETC___05Fq23 
                                         >> 1U))) << 1U)) 
                      | (1U & (~ vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022))));
    vlTOPp->mkTopMAC__DOT__y___05Fh122696 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh122741) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122742));
    vlTOPp->mkTopMAC__DOT__x___05Fh88775 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 1U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88576)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14028 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13827) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13828));
    vlTOPp->mkTopMAC__DOT__x___05Fh122894 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 2U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122696)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d699 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88776) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh88775)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88622) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_ETC___05Fq19 
                                         >> 1U))) << 1U)) 
                      | (1U & (~ vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581))));
    vlTOPp->mkTopMAC__DOT__y___05Fh88730 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh88775) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88776));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2690 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14029) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14028)) 
            << 0x11U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13875) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13874)) 
                          << 0x10U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2689)));
    vlTOPp->mkTopMAC__DOT__y___05Fh13982 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14028) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14029));
    vlTOPp->mkTopMAC__DOT__y___05Fh122849 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh122894) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122895));
    vlTOPp->mkTopMAC__DOT__x___05Fh88928 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 2U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88730)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14182 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh13981) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh13982));
    vlTOPp->mkTopMAC__DOT__x___05Fh123047 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 3U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122849)));
    vlTOPp->mkTopMAC__DOT__y___05Fh88883 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh88928) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88929));
    vlTOPp->mkTopMAC__DOT__y___05Fh14136 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14182) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14183));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1141 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123048) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123047)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh122895) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh122894)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1140)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123002 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123047) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123048));
    vlTOPp->mkTopMAC__DOT__x___05Fh89081 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 3U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88883)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14336 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14135) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14136));
    vlTOPp->mkTopMAC__DOT__x___05Fh123200 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 4U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123002)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d700 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89082) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89081)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh88929) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh88928)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d699)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89036 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89081) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89082));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2691 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14337) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14336)) 
            << 0x13U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14183) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14182)) 
                          << 0x12U) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2690));
    vlTOPp->mkTopMAC__DOT__y___05Fh14290 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14336) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14337));
    vlTOPp->mkTopMAC__DOT__y___05Fh123155 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123200) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123201));
    vlTOPp->mkTopMAC__DOT__x___05Fh89234 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 4U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89036)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14490 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14289) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14290));
    vlTOPp->mkTopMAC__DOT__x___05Fh123353 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 5U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123155)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89189 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89234) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89235));
    vlTOPp->mkTopMAC__DOT__y___05Fh14444 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14490) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14491));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1142 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123354) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123353)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123201) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123200)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1141)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123308 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123353) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123354));
    vlTOPp->mkTopMAC__DOT__x___05Fh89387 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 5U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89189)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14644 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14443) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14444));
    vlTOPp->mkTopMAC__DOT__x___05Fh123506 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 6U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123308)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d701 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89388) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89387)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89235) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89234)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d700)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89342 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89387) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89388));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2692 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14645) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14644)) 
            << 0x15U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14491) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14490)) 
                          << 0x14U) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2691));
    vlTOPp->mkTopMAC__DOT__y___05Fh14598 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14644) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14645));
    vlTOPp->mkTopMAC__DOT__y___05Fh123461 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123506) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123507));
    vlTOPp->mkTopMAC__DOT__x___05Fh89540 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 6U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89342)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14798 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14597) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14598));
    vlTOPp->mkTopMAC__DOT__x___05Fh123659 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 7U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123461)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89495 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89540) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89541));
    vlTOPp->mkTopMAC__DOT__y___05Fh14752 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14798) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14799));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1143 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123660) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123659)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123507) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123506)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1142)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123614 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123659) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123660));
    vlTOPp->mkTopMAC__DOT__x___05Fh89693 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 7U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89495)));
    vlTOPp->mkTopMAC__DOT__x___05Fh14952 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14751) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14752));
    vlTOPp->mkTopMAC__DOT__x___05Fh123812 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 8U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123614)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d702 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89694) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89693)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89541) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89540)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d701)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89648 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89693) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89694));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2693 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14953) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14952)) 
            << 0x17U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14799) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14798)) 
                          << 0x16U) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2692));
    vlTOPp->mkTopMAC__DOT__y___05Fh14906 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14952) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14953));
    vlTOPp->mkTopMAC__DOT__y___05Fh123767 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123812) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123813));
    vlTOPp->mkTopMAC__DOT__x___05Fh89846 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 8U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89648)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15106 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh14905) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh14906));
    vlTOPp->mkTopMAC__DOT__x___05Fh123965 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 9U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123767)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89801 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89846) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89847));
    vlTOPp->mkTopMAC__DOT__y___05Fh15060 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15106) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15107));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1144 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123966) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123965)) 
            << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123813) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123812)) 
                         << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1143)));
    vlTOPp->mkTopMAC__DOT__y___05Fh123920 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh123965) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123966));
    vlTOPp->mkTopMAC__DOT__x___05Fh89999 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 9U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89801)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15260 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15059) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15060));
    vlTOPp->mkTopMAC__DOT__x___05Fh124118 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xaU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh123920)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d703 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90000) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89999)) 
            << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89847) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89846)) 
                         << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d702)));
    vlTOPp->mkTopMAC__DOT__y___05Fh89954 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh89999) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90000));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2694 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15261) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15260)) 
            << 0x19U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15107) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15106)) 
                          << 0x18U) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2693));
    vlTOPp->mkTopMAC__DOT__y___05Fh15214 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15260) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15261));
    vlTOPp->mkTopMAC__DOT__y___05Fh124073 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124118) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124119));
    vlTOPp->mkTopMAC__DOT__x___05Fh90152 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xaU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh89954)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15414 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15213) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15214));
    vlTOPp->mkTopMAC__DOT__x___05Fh124271 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xbU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124073)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90107 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90152) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90153));
    vlTOPp->mkTopMAC__DOT__y___05Fh15368 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15414) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15415));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1145 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124272) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124271)) 
            << 0xcU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124119) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124118)) 
                         << 0xbU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1144)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124226 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124271) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124272));
    vlTOPp->mkTopMAC__DOT__x___05Fh90305 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xbU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90107)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15568 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15367) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15368));
    vlTOPp->mkTopMAC__DOT__x___05Fh124424 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xcU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124226)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d704 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90306) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90305)) 
            << 0xcU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90153) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90152)) 
                         << 0xbU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d703)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90260 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90305) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90306));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2695 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15569) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15568)) 
            << 0x1bU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15415) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15414)) 
                          << 0x1aU) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2694));
    vlTOPp->mkTopMAC__DOT__y___05Fh15522 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15568) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15569));
    vlTOPp->mkTopMAC__DOT__y___05Fh124379 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124424) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124425));
    vlTOPp->mkTopMAC__DOT__x___05Fh90458 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xcU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90260)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15722 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15521) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15522));
    vlTOPp->mkTopMAC__DOT__x___05Fh124577 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xdU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124379)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90413 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90458) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90459));
    vlTOPp->mkTopMAC__DOT__y___05Fh15676 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15722) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15723));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1146 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124578) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124577)) 
            << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124425) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124424)) 
                         << 0xdU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1145)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124532 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124577) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124578));
    vlTOPp->mkTopMAC__DOT__x___05Fh90611 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xdU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90413)));
    vlTOPp->mkTopMAC__DOT__x___05Fh15876 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15675) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15676));
    vlTOPp->mkTopMAC__DOT__x___05Fh124730 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xeU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124532)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d705 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90612) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90611)) 
            << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90459) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90458)) 
                         << 0xdU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d704)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90566 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90611) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90612));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2696 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15877) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15876)) 
            << 0x1dU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15723) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15722)) 
                          << 0x1cU) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2695));
    vlTOPp->mkTopMAC__DOT__y___05Fh15830 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15876) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15877));
    vlTOPp->mkTopMAC__DOT__y___05Fh124685 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124730) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124731));
    vlTOPp->mkTopMAC__DOT__x___05Fh90764 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xeU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90566)));
    vlTOPp->mkTopMAC__DOT__x___05Fh16030 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15829) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15830));
    vlTOPp->mkTopMAC__DOT__x___05Fh124883 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0xfU) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124685)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90719 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90764) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90765));
    vlTOPp->mkTopMAC__DOT__y___05Fh15984 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh16030) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh16031));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1147 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124884) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124883)) 
            << 0x10U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124731) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124730)) 
                          << 0xfU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1146)));
    vlTOPp->mkTopMAC__DOT__y___05Fh124838 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh124883) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124884));
    vlTOPp->mkTopMAC__DOT__x___05Fh90917 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0xfU) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90719)));
    vlTOPp->mkTopMAC__DOT__y___05Fh1476 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh15983) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh15984));
    vlTOPp->mkTopMAC__DOT__x___05Fh125036 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x10U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124838)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d706 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90918) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90917)) 
            << 0x10U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90765) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90764)) 
                          << 0xfU) | (IData)(vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d705)));
    vlTOPp->mkTopMAC__DOT__y___05Fh90872 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh90917) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90918));
    vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2697 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh1475) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh1476)) 
            << 0x1fU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh16031) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh16030)) 
                          << 0x1eU) | vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2696));
    vlTOPp->mkTopMAC__DOT__y___05Fh124991 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125036) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125037));
    vlTOPp->mkTopMAC__DOT__x___05Fh91070 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x10U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh90872)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125189 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x11U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh124991)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91025 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91070) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91071));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1148 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125190) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125189)) 
            << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125037) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125036)) 
                          << 0x11U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1147));
    vlTOPp->mkTopMAC__DOT__y___05Fh125144 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125189) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125190));
    vlTOPp->mkTopMAC__DOT__x___05Fh91223 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x11U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91025)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125342 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x12U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125144)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d707 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91224) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91223)) 
            << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91071) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91070)) 
                          << 0x11U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d706));
    vlTOPp->mkTopMAC__DOT__y___05Fh91178 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91223) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91224));
    vlTOPp->mkTopMAC__DOT__y___05Fh125297 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125342) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125343));
    vlTOPp->mkTopMAC__DOT__x___05Fh91376 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x12U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91178)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125495 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x13U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125297)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91331 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91376) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91377));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1149 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125496) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125495)) 
            << 0x14U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125343) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125342)) 
                          << 0x13U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1148));
    vlTOPp->mkTopMAC__DOT__y___05Fh125450 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125495) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125496));
    vlTOPp->mkTopMAC__DOT__x___05Fh91529 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x13U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91331)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125648 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x14U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125450)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d708 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91530) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91529)) 
            << 0x14U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91377) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91376)) 
                          << 0x13U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d707));
    vlTOPp->mkTopMAC__DOT__y___05Fh91484 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91529) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91530));
    vlTOPp->mkTopMAC__DOT__y___05Fh125603 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125648) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125649));
    vlTOPp->mkTopMAC__DOT__x___05Fh91682 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x14U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91484)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125801 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x15U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125603)));
    vlTOPp->mkTopMAC__DOT__y___05Fh91637 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91682) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91683));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1150 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125802) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125801)) 
            << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125649) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125648)) 
                          << 0x15U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1149));
    vlTOPp->mkTopMAC__DOT__y___05Fh125756 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125801) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125802));
    vlTOPp->mkTopMAC__DOT__x___05Fh91835 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x15U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91637)));
    vlTOPp->mkTopMAC__DOT__x___05Fh125954 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT___0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_XOR_ETC___05F_d1022 
                                                    >> 0x16U) 
                                                   | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125756)));
    vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d709 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91836) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91835)) 
            << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91683) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91682)) 
                          << 0x15U) | vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d708));
    vlTOPp->mkTopMAC__DOT__y___05Fh91790 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91835) 
                                            & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91836));
    vlTOPp->mkTopMAC__DOT__NOT_1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_BIT_rg___05FETC___05F_d1154 
        = ((~ (IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_BIT_rg_a_BI_ETC___05F_d882)) 
           & (0U == ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh125955) 
                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh125954)) 
                      << 0x17U) | (vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_ETC___05F_d1150 
                                   & vlTOPp->mkTopMAC__DOT__rg_c))));
    vlTOPp->mkTopMAC__DOT__x___05Fh91988 = (1U & ((vlTOPp->mkTopMAC__DOT___0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_14_7___05FETC___05F_d581 
                                                   >> 0x16U) 
                                                  | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91790)));
    vlTOPp->mkTopMAC__DOT___theResult___05F_snd_snd_fst___05Fh104134 
        = ((IData)(vlTOPp->mkTopMAC__DOT__NOT_1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_BIT_rg___05FETC___05F_d1154)
            ? vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh129572
            : vlTOPp->mkTopMAC__DOT___1_CONCAT_rg_c_4_BITS_22_TO_0_49_50_SRL_INV_rg___05FETC___05F_d1287);
    vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d713 
        = ((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d439) 
           & (0U == ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh91989) 
                       ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh91988)) 
                      << 0x17U) | (vlTOPp->mkTopMAC__DOT__INV_0b1_SL_rg_c_4_BIT_30_40_AND_INV_rg_a_BIT_1_ETC___05F_d709 
                                   & vlTOPp->mkTopMAC__DOT__prod_mant___05Fh18654))));
    vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 = 
        ((IData)(vlTOPp->mkTopMAC__DOT___0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_X_ETC___05F_d328)
          ? vlTOPp->mkTopMAC__DOT__mant_b___05Fh18607
          : vlTOPp->mkTopMAC__DOT___theResult___05F_snd_snd_fst___05Fh104134);
    vlTOPp->mkTopMAC__DOT___theResult___05F_snd_fst___05Fh70223 
        = ((IData)(vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d713)
            ? vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh95606
            : vlTOPp->mkTopMAC__DOT___1_CONCAT_IF_1_CONCAT_rg_a_BITS_6_TO_0_2_CONCAT_ETC___05F_d846);
    vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24 
        = (~ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611);
    vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 = 
        ((IData)(vlTOPp->mkTopMAC__DOT___0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8_9_X_ETC___05F_d328)
          ? vlTOPp->mkTopMAC__DOT___theResult___05F_snd_fst___05Fh70223
          : vlTOPp->mkTopMAC__DOT__mant_a___05Fh18603);
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1290 
        = (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
           < vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611);
    vlTOPp->mkTopMAC__DOT__x___05Fh144268 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh152826 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh143962 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__x___05Fh152520 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__y___05Fh144010 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__y___05Fh152568 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__x___05Fh143808 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh152366 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__y___05Fh143856 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__y___05Fh152414 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh143654 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__x___05Fh152212 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh143702 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh152260 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__x___05Fh143500 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh152058 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__y___05Fh143548 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__y___05Fh152106 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh143346 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151904 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh143394 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151952 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__x___05Fh143192 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151750 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__y___05Fh143240 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151798 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh143038 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151596 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh143086 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151644 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142884 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151442 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142932 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151490 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142730 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151288 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142778 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151336 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142576 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh151134 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142624 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151182 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142422 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh150980 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142470 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh151028 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142268 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh150826 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142316 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__y___05Fh150874 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh142114 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh150672 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142162 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh150720 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh141960 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh150518 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh142008 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh150566 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh141806 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh150364 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141854 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh150412 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh141652 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh150210 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141700 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__y___05Fh150258 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh141498 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh150056 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141546 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh150104 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh141344 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh149902 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141392 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh149950 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh141190 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh149748 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141238 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh149796 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh141036 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh149594 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh141084 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh149642 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh140882 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh149440 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140930 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh149488 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh140728 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh149286 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140776 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__y___05Fh149334 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh140574 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh149132 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140622 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh149180 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh140420 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148978 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140468 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh149026 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh140266 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148824 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140314 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh148872 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh140112 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148670 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140160 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh148718 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh139958 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148516 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh140006 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh148564 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh139804 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148362 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh139852 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh148410 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh139649 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148207 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__IF_mant_a_adj8609_BIT_0_AND_mant_b_adj8611_BIT_ETC___05Fq26 
        = ((1U & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                  & vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__y___05Fh139697 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh148255 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__x___05Fh148057 = (1U & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                   & vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24));
    vlTOPp->mkTopMAC__DOT__y___05Fh148058 = (1U & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                                                   ^ vlTOPp->mkTopMAC__DOT__INV_mant_b_adj8611___05Fq24));
    vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25 
        = (~ vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609);
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_3_snd___05Fh70092 
        = (1U & ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1290)
                  ? (vlTOPp->mkTopMAC__DOT__rg_c >> 0x1fU)
                  : (IData)(vlTOPp->mkTopMAC__DOT__sign_a___05Fh18600)));
    vlTOPp->mkTopMAC__DOT__y___05Fh139650 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_mant_a_adj8609_BIT_0_AND_mant_b_adj8611_BIT_ETC___05Fq26 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139697));
    vlTOPp->mkTopMAC__DOT__IF_x48057_OR_y48058_THEN_3_ELSE_1___05Fq27 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148057) 
            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148058))
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh161385 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1eU));
    vlTOPp->mkTopMAC__DOT__x___05Fh161079 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__y___05Fh161127 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1dU));
    vlTOPp->mkTopMAC__DOT__x___05Fh160925 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__y___05Fh160973 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1cU));
    vlTOPp->mkTopMAC__DOT__x___05Fh160771 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__y___05Fh160819 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1bU));
    vlTOPp->mkTopMAC__DOT__x___05Fh160617 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__y___05Fh160665 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x1aU));
    vlTOPp->mkTopMAC__DOT__x___05Fh160463 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__y___05Fh160511 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x19U));
    vlTOPp->mkTopMAC__DOT__x___05Fh160309 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__y___05Fh160357 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x18U));
    vlTOPp->mkTopMAC__DOT__x___05Fh160155 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__y___05Fh160203 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x17U));
    vlTOPp->mkTopMAC__DOT__x___05Fh160001 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__y___05Fh160049 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x16U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159847 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159895 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159693 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159741 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x14U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159539 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159587 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159385 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159433 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159231 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159279 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh159077 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__y___05Fh159125 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0x10U));
    vlTOPp->mkTopMAC__DOT__x___05Fh158923 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158971 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh158769 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158817 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh158615 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158663 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh158461 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158509 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xcU));
    vlTOPp->mkTopMAC__DOT__x___05Fh158307 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158355 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh158153 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__y___05Fh158201 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh157999 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__y___05Fh158047 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157845 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157893 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 8U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157691 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157739 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157537 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157585 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157383 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157431 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157229 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157277 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 4U));
    vlTOPp->mkTopMAC__DOT__x___05Fh157075 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__y___05Fh157123 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh156921 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__y___05Fh156969 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 2U));
    vlTOPp->mkTopMAC__DOT__x___05Fh156766 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__y___05Fh156814 = (1U & (
                                                   (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                    ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25) 
                                                   >> 1U));
    vlTOPp->mkTopMAC__DOT__x___05Fh156616 = (1U & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                   & vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25));
    vlTOPp->mkTopMAC__DOT__y___05Fh156617 = (1U & (vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611 
                                                   ^ vlTOPp->mkTopMAC__DOT__INV_mant_a_adj8609___05Fq25));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_3_snd___05Fh70087 
        = ((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_4___05FETC___05F_d16)
            ? (IData)(vlTOPp->mkTopMAC__DOT__sign_a___05Fh18600)
            : (IData)(vlTOPp->mkTopMAC__DOT___theResult___05F___05F_3_snd___05Fh70092));
    vlTOPp->mkTopMAC__DOT__x___05Fh139851 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh139649) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139650));
    vlTOPp->mkTopMAC__DOT__y___05Fh148208 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_x48057_OR_y48058_THEN_3_ELSE_1___05Fq27 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148255));
    vlTOPp->mkTopMAC__DOT__IF_x56616_OR_y56617_THEN_3_ELSE_1___05Fq28 
        = (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh156616) 
            | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156617))
            ? 3ULL : 1ULL);
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1506 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139852) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh139851)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139697) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_mant_a_adj8609_BIT_0_AND_mant_b_adj8611_BIT_ETC___05Fq26 
                                         >> 1U))) << 1U)) 
                      | (1U & (vlTOPp->mkTopMAC__DOT__mant_a_adj___05Fh18609 
                               ^ vlTOPp->mkTopMAC__DOT__mant_b_adj___05Fh18611))));
    vlTOPp->mkTopMAC__DOT__y___05Fh139805 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh139851) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139852));
    vlTOPp->mkTopMAC__DOT__x___05Fh148409 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148207) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148208));
    vlTOPp->mkTopMAC__DOT__y___05Fh156767 = ((IData)(
                                                     (vlTOPp->mkTopMAC__DOT__IF_x56616_OR_y56617_THEN_3_ELSE_1___05Fq28 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156814));
    vlTOPp->mkTopMAC__DOT__x___05Fh140005 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh139804) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139805));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1906 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148410) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148409)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148255) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_x48057_OR_y48058_THEN_3_ELSE_1___05Fq27 
                                         >> 1U))) << 1U)) 
                      | (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148058)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh148363 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148409) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148410));
    vlTOPp->mkTopMAC__DOT__x___05Fh156968 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh156766) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156767));
    vlTOPp->mkTopMAC__DOT__y___05Fh139959 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140005) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140006));
    vlTOPp->mkTopMAC__DOT__x___05Fh148563 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148362) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148363));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1706 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156969) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh156968)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156814) 
                              ^ (IData)((vlTOPp->mkTopMAC__DOT__IF_x56616_OR_y56617_THEN_3_ELSE_1___05Fq28 
                                         >> 1U))) << 1U)) 
                      | (1U & (~ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156617)))));
    vlTOPp->mkTopMAC__DOT__y___05Fh156922 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh156968) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156969));
    vlTOPp->mkTopMAC__DOT__x___05Fh140159 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh139958) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh139959));
    vlTOPp->mkTopMAC__DOT__y___05Fh148517 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148563) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148564));
    vlTOPp->mkTopMAC__DOT__x___05Fh157122 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh156921) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh156922));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1507 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140160) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140159)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140006) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140005)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1506)));
    vlTOPp->mkTopMAC__DOT__y___05Fh140113 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140159) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140160));
    vlTOPp->mkTopMAC__DOT__x___05Fh148717 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148516) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148517));
    vlTOPp->mkTopMAC__DOT__y___05Fh157076 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157122) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157123));
    vlTOPp->mkTopMAC__DOT__x___05Fh140313 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140112) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140113));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1907 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148718) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148717)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148564) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148563)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1906)));
    vlTOPp->mkTopMAC__DOT__y___05Fh148671 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148717) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148718));
    vlTOPp->mkTopMAC__DOT__x___05Fh157276 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157075) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157076));
    vlTOPp->mkTopMAC__DOT__y___05Fh140267 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140313) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140314));
    vlTOPp->mkTopMAC__DOT__x___05Fh148871 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148670) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148671));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1707 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157277) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157276)) 
            << 4U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157123) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157122)) 
                       << 3U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1706)));
    vlTOPp->mkTopMAC__DOT__y___05Fh157230 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157276) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157277));
    vlTOPp->mkTopMAC__DOT__x___05Fh140467 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140266) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140267));
    vlTOPp->mkTopMAC__DOT__y___05Fh148825 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148871) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148872));
    vlTOPp->mkTopMAC__DOT__x___05Fh157430 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157229) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157230));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1508 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140468) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140467)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140314) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140313)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1507)));
    vlTOPp->mkTopMAC__DOT__y___05Fh140421 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140467) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140468));
    vlTOPp->mkTopMAC__DOT__x___05Fh149025 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148824) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148825));
    vlTOPp->mkTopMAC__DOT__y___05Fh157384 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157430) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157431));
    vlTOPp->mkTopMAC__DOT__x___05Fh140621 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140420) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140421));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1908 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149026) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149025)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148872) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148871)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1907)));
    vlTOPp->mkTopMAC__DOT__y___05Fh148979 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149025) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149026));
    vlTOPp->mkTopMAC__DOT__x___05Fh157584 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157383) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157384));
    vlTOPp->mkTopMAC__DOT__y___05Fh140575 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140621) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140622));
    vlTOPp->mkTopMAC__DOT__x___05Fh149179 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh148978) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh148979));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1708 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157585) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157584)) 
            << 6U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157431) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157430)) 
                       << 5U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1707)));
    vlTOPp->mkTopMAC__DOT__y___05Fh157538 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157584) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157585));
    vlTOPp->mkTopMAC__DOT__x___05Fh140775 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140574) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140575));
    vlTOPp->mkTopMAC__DOT__y___05Fh149133 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149179) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149180));
    vlTOPp->mkTopMAC__DOT__x___05Fh157738 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157537) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157538));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1509 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140776) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140775)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140622) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140621)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1508)));
    vlTOPp->mkTopMAC__DOT__y___05Fh140729 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140775) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140776));
    vlTOPp->mkTopMAC__DOT__x___05Fh149333 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149132) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149133));
    vlTOPp->mkTopMAC__DOT__y___05Fh157692 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157738) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157739));
    vlTOPp->mkTopMAC__DOT__x___05Fh140929 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140728) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140729));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1909 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149334) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149333)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149180) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149179)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1908)));
    vlTOPp->mkTopMAC__DOT__y___05Fh149287 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149333) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149334));
    vlTOPp->mkTopMAC__DOT__x___05Fh157892 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157691) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157692));
    vlTOPp->mkTopMAC__DOT__y___05Fh140883 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140929) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140930));
    vlTOPp->mkTopMAC__DOT__x___05Fh149487 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149286) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149287));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1709 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157893) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157892)) 
            << 8U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157739) 
                        ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157738)) 
                       << 7U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1708)));
    vlTOPp->mkTopMAC__DOT__y___05Fh157846 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157892) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157893));
    vlTOPp->mkTopMAC__DOT__x___05Fh141083 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140882) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140883));
    vlTOPp->mkTopMAC__DOT__y___05Fh149441 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149487) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149488));
    vlTOPp->mkTopMAC__DOT__x___05Fh158046 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157845) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh157846));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1510 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141084) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141083)) 
            << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh140930) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh140929)) 
                         << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1509)));
    vlTOPp->mkTopMAC__DOT__y___05Fh141037 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141083) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141084));
    vlTOPp->mkTopMAC__DOT__x___05Fh149641 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149440) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149441));
    vlTOPp->mkTopMAC__DOT__y___05Fh158000 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158046) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158047));
    vlTOPp->mkTopMAC__DOT__x___05Fh141237 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141036) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141037));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1910 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149642) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149641)) 
            << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149488) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149487)) 
                         << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1909)));
    vlTOPp->mkTopMAC__DOT__y___05Fh149595 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149641) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149642));
    vlTOPp->mkTopMAC__DOT__x___05Fh158200 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh157999) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158000));
    vlTOPp->mkTopMAC__DOT__y___05Fh141191 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141237) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141238));
    vlTOPp->mkTopMAC__DOT__x___05Fh149795 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149594) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149595));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1710 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158201) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158200)) 
            << 0xaU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158047) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158046)) 
                         << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1709)));
    vlTOPp->mkTopMAC__DOT__y___05Fh158154 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158200) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158201));
    vlTOPp->mkTopMAC__DOT__x___05Fh141391 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141190) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141191));
    vlTOPp->mkTopMAC__DOT__y___05Fh149749 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149795) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149796));
    vlTOPp->mkTopMAC__DOT__x___05Fh158354 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158153) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158154));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1511 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141392) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141391)) 
            << 0xcU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141238) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141237)) 
                         << 0xbU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1510)));
    vlTOPp->mkTopMAC__DOT__y___05Fh141345 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141391) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141392));
    vlTOPp->mkTopMAC__DOT__x___05Fh149949 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149748) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149749));
    vlTOPp->mkTopMAC__DOT__y___05Fh158308 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158354) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158355));
    vlTOPp->mkTopMAC__DOT__x___05Fh141545 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141344) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141345));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1911 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149950) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149949)) 
            << 0xcU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149796) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149795)) 
                         << 0xbU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1910)));
    vlTOPp->mkTopMAC__DOT__y___05Fh149903 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149949) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149950));
    vlTOPp->mkTopMAC__DOT__x___05Fh158508 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158307) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158308));
    vlTOPp->mkTopMAC__DOT__y___05Fh141499 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141545) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141546));
    vlTOPp->mkTopMAC__DOT__x___05Fh150103 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh149902) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh149903));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1711 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158509) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158508)) 
            << 0xcU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158355) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158354)) 
                         << 0xbU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1710)));
    vlTOPp->mkTopMAC__DOT__y___05Fh158462 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158508) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158509));
    vlTOPp->mkTopMAC__DOT__x___05Fh141699 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141498) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141499));
    vlTOPp->mkTopMAC__DOT__y___05Fh150057 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150103) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150104));
    vlTOPp->mkTopMAC__DOT__x___05Fh158662 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158461) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158462));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1512 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141700) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141699)) 
            << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141546) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141545)) 
                         << 0xdU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1511)));
    vlTOPp->mkTopMAC__DOT__y___05Fh141653 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141699) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141700));
    vlTOPp->mkTopMAC__DOT__x___05Fh150257 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150056) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150057));
    vlTOPp->mkTopMAC__DOT__y___05Fh158616 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158662) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158663));
    vlTOPp->mkTopMAC__DOT__x___05Fh141853 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141652) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141653));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1912 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150258) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150257)) 
            << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150104) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150103)) 
                         << 0xdU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1911)));
    vlTOPp->mkTopMAC__DOT__y___05Fh150211 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150257) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150258));
    vlTOPp->mkTopMAC__DOT__x___05Fh158816 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158615) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158616));
    vlTOPp->mkTopMAC__DOT__y___05Fh141807 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141853) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141854));
    vlTOPp->mkTopMAC__DOT__x___05Fh150411 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150210) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150211));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1712 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158817) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158816)) 
            << 0xeU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158663) 
                          ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158662)) 
                         << 0xdU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1711)));
    vlTOPp->mkTopMAC__DOT__y___05Fh158770 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158816) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158817));
    vlTOPp->mkTopMAC__DOT__x___05Fh142007 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141806) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141807));
    vlTOPp->mkTopMAC__DOT__y___05Fh150365 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150411) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150412));
    vlTOPp->mkTopMAC__DOT__x___05Fh158970 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158769) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158770));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1513 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142008) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142007)) 
            << 0x10U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141854) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141853)) 
                          << 0xfU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1512)));
    vlTOPp->mkTopMAC__DOT__y___05Fh141961 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142007) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142008));
    vlTOPp->mkTopMAC__DOT__x___05Fh150565 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150364) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150365));
    vlTOPp->mkTopMAC__DOT__y___05Fh158924 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158970) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158971));
    vlTOPp->mkTopMAC__DOT__x___05Fh142161 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh141960) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh141961));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1913 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150566) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150565)) 
            << 0x10U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150412) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150411)) 
                          << 0xfU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1912)));
    vlTOPp->mkTopMAC__DOT__y___05Fh150519 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150565) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150566));
    vlTOPp->mkTopMAC__DOT__x___05Fh159124 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158923) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158924));
    vlTOPp->mkTopMAC__DOT__y___05Fh142115 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142161) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142162));
    vlTOPp->mkTopMAC__DOT__x___05Fh150719 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150518) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150519));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1713 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159125) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159124)) 
            << 0x10U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh158971) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh158970)) 
                          << 0xfU) | (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1712)));
    vlTOPp->mkTopMAC__DOT__y___05Fh159078 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159124) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159125));
    vlTOPp->mkTopMAC__DOT__x___05Fh142315 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142114) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142115));
    vlTOPp->mkTopMAC__DOT__y___05Fh150673 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150719) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150720));
    vlTOPp->mkTopMAC__DOT__x___05Fh159278 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159077) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159078));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1514 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142316) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142315)) 
            << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142162) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142161)) 
                          << 0x11U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1513));
    vlTOPp->mkTopMAC__DOT__y___05Fh142269 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142315) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142316));
    vlTOPp->mkTopMAC__DOT__x___05Fh150873 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150672) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150673));
    vlTOPp->mkTopMAC__DOT__y___05Fh159232 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159278) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159279));
    vlTOPp->mkTopMAC__DOT__x___05Fh142469 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142268) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142269));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1914 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150874) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150873)) 
            << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150720) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150719)) 
                          << 0x11U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1913));
    vlTOPp->mkTopMAC__DOT__y___05Fh150827 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150873) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150874));
    vlTOPp->mkTopMAC__DOT__x___05Fh159432 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159231) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159232));
    vlTOPp->mkTopMAC__DOT__y___05Fh142423 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142469) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142470));
    vlTOPp->mkTopMAC__DOT__x___05Fh151027 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150826) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150827));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1714 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159433) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159432)) 
            << 0x12U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159279) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159278)) 
                          << 0x11U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1713));
    vlTOPp->mkTopMAC__DOT__y___05Fh159386 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159432) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159433));
    vlTOPp->mkTopMAC__DOT__x___05Fh142623 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142422) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142423));
    vlTOPp->mkTopMAC__DOT__y___05Fh150981 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151027) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151028));
    vlTOPp->mkTopMAC__DOT__x___05Fh159586 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159385) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159386));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1515 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142624) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142623)) 
            << 0x14U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142470) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142469)) 
                          << 0x13U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1514));
    vlTOPp->mkTopMAC__DOT__y___05Fh142577 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142623) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142624));
    vlTOPp->mkTopMAC__DOT__x___05Fh151181 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh150980) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh150981));
    vlTOPp->mkTopMAC__DOT__y___05Fh159540 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159586) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159587));
    vlTOPp->mkTopMAC__DOT__x___05Fh142777 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142576) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142577));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1915 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151182) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151181)) 
            << 0x14U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151028) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151027)) 
                          << 0x13U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1914));
    vlTOPp->mkTopMAC__DOT__y___05Fh151135 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151181) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151182));
    vlTOPp->mkTopMAC__DOT__x___05Fh159740 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159539) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159540));
    vlTOPp->mkTopMAC__DOT__y___05Fh142731 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142777) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142778));
    vlTOPp->mkTopMAC__DOT__x___05Fh151335 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151134) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151135));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1715 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159741) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159740)) 
            << 0x14U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159587) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159586)) 
                          << 0x13U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1714));
    vlTOPp->mkTopMAC__DOT__y___05Fh159694 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159740) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159741));
    vlTOPp->mkTopMAC__DOT__x___05Fh142931 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142730) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142731));
    vlTOPp->mkTopMAC__DOT__y___05Fh151289 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151335) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151336));
    vlTOPp->mkTopMAC__DOT__x___05Fh159894 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159693) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159694));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1516 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142932) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142931)) 
            << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142778) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142777)) 
                          << 0x15U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1515));
    vlTOPp->mkTopMAC__DOT__y___05Fh142885 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142931) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142932));
    vlTOPp->mkTopMAC__DOT__x___05Fh151489 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151288) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151289));
    vlTOPp->mkTopMAC__DOT__y___05Fh159848 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159894) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159895));
    vlTOPp->mkTopMAC__DOT__x___05Fh143085 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh142884) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh142885));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1916 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151490) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151489)) 
            << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151336) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151335)) 
                          << 0x15U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1915));
    vlTOPp->mkTopMAC__DOT__y___05Fh151443 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151489) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151490));
    vlTOPp->mkTopMAC__DOT__x___05Fh160048 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159847) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159848));
    vlTOPp->mkTopMAC__DOT__y___05Fh143039 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143085) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143086));
    vlTOPp->mkTopMAC__DOT__x___05Fh151643 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151442) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151443));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1716 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160049) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160048)) 
            << 0x16U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh159895) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh159894)) 
                          << 0x15U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1715));
    vlTOPp->mkTopMAC__DOT__y___05Fh160002 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160048) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160049));
    vlTOPp->mkTopMAC__DOT__x___05Fh143239 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143038) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143039));
    vlTOPp->mkTopMAC__DOT__y___05Fh151597 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151643) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151644));
    vlTOPp->mkTopMAC__DOT__x___05Fh160202 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160001) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160002));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1517 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143240) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143239)) 
            << 0x18U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143086) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143085)) 
                          << 0x17U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1516));
    vlTOPp->mkTopMAC__DOT__y___05Fh143193 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143239) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143240));
    vlTOPp->mkTopMAC__DOT__x___05Fh151797 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151596) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151597));
    vlTOPp->mkTopMAC__DOT__y___05Fh160156 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160202) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160203));
    vlTOPp->mkTopMAC__DOT__x___05Fh143393 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143192) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143193));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1917 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151798) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151797)) 
            << 0x18U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151644) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151643)) 
                          << 0x17U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1916));
    vlTOPp->mkTopMAC__DOT__y___05Fh151751 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151797) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151798));
    vlTOPp->mkTopMAC__DOT__x___05Fh160356 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160155) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160156));
    vlTOPp->mkTopMAC__DOT__y___05Fh143347 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143393) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143394));
    vlTOPp->mkTopMAC__DOT__x___05Fh151951 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151750) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151751));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1717 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160357) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160356)) 
            << 0x18U) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160203) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160202)) 
                          << 0x17U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1716));
    vlTOPp->mkTopMAC__DOT__y___05Fh160310 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160356) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160357));
    vlTOPp->mkTopMAC__DOT__x___05Fh143547 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143346) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143347));
    vlTOPp->mkTopMAC__DOT__y___05Fh151905 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151951) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151952));
    vlTOPp->mkTopMAC__DOT__x___05Fh160510 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160309) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160310));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1518 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143548) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143547)) 
            << 0x1aU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143394) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143393)) 
                          << 0x19U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1517));
    vlTOPp->mkTopMAC__DOT__y___05Fh143501 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143547) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143548));
    vlTOPp->mkTopMAC__DOT__x___05Fh152105 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151904) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151905));
    vlTOPp->mkTopMAC__DOT__y___05Fh160464 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160510) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160511));
    vlTOPp->mkTopMAC__DOT__x___05Fh143701 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143500) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143501));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1918 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152106) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152105)) 
            << 0x1aU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh151952) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh151951)) 
                          << 0x19U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1917));
    vlTOPp->mkTopMAC__DOT__y___05Fh152059 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152105) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152106));
    vlTOPp->mkTopMAC__DOT__x___05Fh160664 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160463) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160464));
    vlTOPp->mkTopMAC__DOT__y___05Fh143655 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143701) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143702));
    vlTOPp->mkTopMAC__DOT__x___05Fh152259 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152058) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152059));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1718 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160665) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160664)) 
            << 0x1aU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160511) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160510)) 
                          << 0x19U) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1717));
    vlTOPp->mkTopMAC__DOT__y___05Fh160618 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160664) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160665));
    vlTOPp->mkTopMAC__DOT__x___05Fh143855 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143654) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143655));
    vlTOPp->mkTopMAC__DOT__y___05Fh152213 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152259) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152260));
    vlTOPp->mkTopMAC__DOT__x___05Fh160818 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160617) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160618));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1519 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143856) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143855)) 
            << 0x1cU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143702) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143701)) 
                          << 0x1bU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1518));
    vlTOPp->mkTopMAC__DOT__y___05Fh143809 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143855) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143856));
    vlTOPp->mkTopMAC__DOT__x___05Fh152413 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152212) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152213));
    vlTOPp->mkTopMAC__DOT__y___05Fh160772 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160818) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160819));
    vlTOPp->mkTopMAC__DOT__x___05Fh144009 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143808) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143809));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1919 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152414) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152413)) 
            << 0x1cU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152260) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152259)) 
                          << 0x1bU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1918));
    vlTOPp->mkTopMAC__DOT__y___05Fh152367 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152413) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152414));
    vlTOPp->mkTopMAC__DOT__x___05Fh160972 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160771) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160772));
    vlTOPp->mkTopMAC__DOT__y___05Fh143963 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh144009) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh144010));
    vlTOPp->mkTopMAC__DOT__x___05Fh152567 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152366) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152367));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1719 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160973) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160972)) 
            << 0x1cU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160819) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160818)) 
                          << 0x1bU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1718));
    vlTOPp->mkTopMAC__DOT__y___05Fh160926 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160972) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160973));
    vlTOPp->mkTopMAC__DOT__y___05Fh144269 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh143962) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh143963));
    vlTOPp->mkTopMAC__DOT__y___05Fh152521 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152567) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152568));
    vlTOPp->mkTopMAC__DOT__x___05Fh161126 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh160925) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh160926));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1520 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh144268) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh144269)) 
            << 0x1eU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh144010) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh144009)) 
                          << 0x1dU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1519));
    vlTOPp->mkTopMAC__DOT__y___05Fh152827 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152520) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152521));
    vlTOPp->mkTopMAC__DOT__y___05Fh161080 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh161126) 
                                             & (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh161127));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1920 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152826) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152827)) 
            << 0x1eU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh152568) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh152567)) 
                          << 0x1dU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1919));
    vlTOPp->mkTopMAC__DOT__y___05Fh161386 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh161079) 
                                             | (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh161080));
    vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1720 
        = ((((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh161385) 
             ^ (IData)(vlTOPp->mkTopMAC__DOT__y___05Fh161386)) 
            << 0x1eU) | ((((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh161127) 
                           ^ (IData)(vlTOPp->mkTopMAC__DOT__x___05Fh161126)) 
                          << 0x1dU) | vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1719));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
        = ((IData)(vlTOPp->mkTopMAC__DOT__rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_4___05FETC___05F_d16)
            ? vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1520
            : ((IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1290)
                ? vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1720
                : vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d1920));
    vlTOPp->mkTopMAC__DOT__sum_mant___05Fh188982 = 
        (0x7fffffU & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922);
    vlTOPp->mkTopMAC__DOT__mant_mid___05F_1___05Fh163838 
        = (0x7fffffU & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                        >> 1U));
    vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq29 
        = ((1U & ((vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                   >> 1U) & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922))
            ? 2ULL : 0ULL);
    vlTOPp->mkTopMAC__DOT__x___05Fh165619 = (1U & ((IData)(
                                                           (vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq29 
                                                            >> 1U)) 
                                                   & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                      >> 2U)));
    vlTOPp->mkTopMAC__DOT__x___05Fh165769 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165619) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 3U));
    vlTOPp->mkTopMAC__DOT__x___05Fh165919 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165769) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 4U));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1997 
        = ((0x10U & ((0x7ffffff0U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                     >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165919) 
                                                << 4U))) 
           | ((8U & ((0x7ffffff8U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                     >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165769) 
                                                << 3U))) 
              | ((4U & ((0x7ffffffcU & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                        >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165619) 
                                                   << 2U))) 
                 | ((2U & ((0x7ffffffeU & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                           >> 1U)) 
                           ^ ((IData)((vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq29 
                                       >> 1U)) << 1U))) 
                    | (1U & ((vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                              >> 1U) ^ vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922))))));
    vlTOPp->mkTopMAC__DOT__x___05Fh166069 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh165919) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 5U));
    vlTOPp->mkTopMAC__DOT__x___05Fh166219 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166069) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 6U));
    vlTOPp->mkTopMAC__DOT__x___05Fh166369 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166219) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 7U));
    vlTOPp->mkTopMAC__DOT__x___05Fh166519 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166369) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 8U));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1999 
        = ((0x100U & ((0x7fffff00U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                      >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166519) 
                                                 << 8U))) 
           | ((0x80U & ((0x7fffff80U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                        >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166369) 
                                                   << 7U))) 
              | ((0x40U & ((0x7fffffc0U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                           >> 1U)) 
                           ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166219) 
                              << 6U))) | ((0x20U & 
                                           ((0x7fffffe0U 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 1U)) 
                                            ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166069) 
                                               << 5U))) 
                                          | (IData)(vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1997)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh166669 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166519) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 9U));
    vlTOPp->mkTopMAC__DOT__x___05Fh166819 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166669) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xaU));
    vlTOPp->mkTopMAC__DOT__x___05Fh166969 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166819) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xbU));
    vlTOPp->mkTopMAC__DOT__x___05Fh167119 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166969) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xcU));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2001 
        = ((0x1000U & ((0x7ffff000U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                       >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167119) 
                                                  << 0xcU))) 
           | ((0x800U & ((0x7ffff800U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                         >> 1U)) ^ 
                         ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166969) 
                          << 0xbU))) | ((0x400U & (
                                                   (0x7ffffc00U 
                                                    & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                       >> 1U)) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166819) 
                                                    << 0xaU))) 
                                        | ((0x200U 
                                            & ((0x7ffffe00U 
                                                & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                   >> 1U)) 
                                               ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh166669) 
                                                  << 9U))) 
                                           | (IData)(vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1999)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh167269 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167119) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xdU));
    vlTOPp->mkTopMAC__DOT__x___05Fh167419 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167269) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xeU));
    vlTOPp->mkTopMAC__DOT__x___05Fh167569 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167419) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0xfU));
    vlTOPp->mkTopMAC__DOT__x___05Fh167719 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167569) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x10U));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2003 
        = ((0x10000U & ((0x7fff0000U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                        >> 1U)) ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167719) 
                                                   << 0x10U))) 
           | ((0x8000U & ((0x7fff8000U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                          >> 1U)) ^ 
                          ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167569) 
                           << 0xfU))) | ((0x4000U & 
                                          ((0x7fffc000U 
                                            & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                               >> 1U)) 
                                           ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167419) 
                                              << 0xeU))) 
                                         | ((0x2000U 
                                             & ((0x7fffe000U 
                                                 & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                    >> 1U)) 
                                                ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167269) 
                                                   << 0xdU))) 
                                            | (IData)(vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2001)))));
    vlTOPp->mkTopMAC__DOT__x___05Fh167869 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167719) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x11U));
    vlTOPp->mkTopMAC__DOT__x___05Fh168019 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167869) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x12U));
    vlTOPp->mkTopMAC__DOT__x___05Fh168169 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168019) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x13U));
    vlTOPp->mkTopMAC__DOT__x___05Fh168319 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168169) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x14U));
    vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2005 
        = ((0x100000U & ((0x7ff00000U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                         >> 1U)) ^ 
                         ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168319) 
                          << 0x14U))) | ((0x80000U 
                                          & ((0x7ff80000U 
                                              & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                 >> 1U)) 
                                             ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168169) 
                                                << 0x13U))) 
                                         | ((0x40000U 
                                             & ((0x7ffc0000U 
                                                 & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                    >> 1U)) 
                                                ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168019) 
                                                   << 0x12U))) 
                                            | ((0x20000U 
                                                & ((0x7ffe0000U 
                                                    & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                       >> 1U)) 
                                                   ^ 
                                                   ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh167869) 
                                                    << 0x11U))) 
                                               | vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2003))));
    vlTOPp->mkTopMAC__DOT__x___05Fh168469 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168319) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x15U));
    vlTOPp->mkTopMAC__DOT__x___05Fh168619 = ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168469) 
                                             & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 0x16U));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2___05Fh163839 
        = ((2U & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922)
            ? ((0xff800000U & (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168619) 
                                << 0x17U) & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922)) 
               | ((0x400000U & ((0x7fc00000U & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                >> 1U)) 
                                ^ ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168619) 
                                   << 0x16U))) | ((0x200000U 
                                                   & ((0x7fe00000U 
                                                       & (vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922 
                                                          >> 1U)) 
                                                      ^ 
                                                      ((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh168469) 
                                                       << 0x15U))) 
                                                  | vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d2005)))
            : vlTOPp->mkTopMAC__DOT__mant_mid___05F_1___05Fh163838);
    vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq33 
        = ((0x1000000U & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922)
            ? vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2___05Fh163839
            : vlTOPp->mkTopMAC__DOT__sum_mant___05Fh188982);
    vlTOPp->mkTopMAC__DOT__IF_IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_E_ETC___05F_d2066 
        = ((0x800000U & vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2___05Fh163839)
            ? (((IData)(vlTOPp->mkTopMAC__DOT__x___05Fh183325) 
                << 9U) | (IData)(vlTOPp->mkTopMAC__DOT__IF_IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_ETC___05F_d2059))
            : (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183176) 
                << 8U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh183026) 
                           << 7U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182876) 
                                      << 6U) | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182726) 
                                                 << 5U) 
                                                | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182576) 
                                                    << 4U) 
                                                   | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182426) 
                                                       << 3U) 
                                                      | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182276) 
                                                          << 2U) 
                                                         | (((IData)(vlTOPp->mkTopMAC__DOT__y___05Fh182125) 
                                                             << 1U) 
                                                            | (1U 
                                                               & (~ (IData)(vlTOPp->mkTopMAC__DOT__IF_0_CONCAT_rg_a_BIT_14_7_XOR_rg_b_1_BIT_14_8___05FETC___05F_d2012))))))))))));
    vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh163842 
        = vlTOPp->mkTopMAC__DOT__IF_IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_E_ETC___05F_d2066;
    vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq32 
        = ((0x1000000U & vlTOPp->mkTopMAC__DOT__IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_rg_c_ETC___05F_d1922)
            ? vlTOPp->mkTopMAC__DOT___theResult___05F___05F_2_fst___05Fh163842
            : vlTOPp->mkTopMAC__DOT__sum_exp___05Fh18612);
    vlTOPp->mkTopMAC__DOT__acc2___05Fh562 = (((IData)(vlTOPp->mkTopMAC__DOT___theResult___05F___05F_3_snd___05Fh70087) 
                                              << 0x1fU) 
                                             | ((0x7f800000U 
                                                 & (vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq32 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & vlTOPp->mkTopMAC__DOT__IF_IF_rg_a_BIT_15_0_XOR_rg_b_1_BIT_15_2_3_EQ_r_ETC___05Fq33)));
    vlTOPp->mkTopMAC__DOT__rg_out_D_IN = ((IData)(vlTOPp->mkTopMAC__DOT__rg_s)
                                           ? vlTOPp->mkTopMAC__DOT__acc2___05Fh562
                                           : vlTOPp->mkTopMAC__DOT__IF_IF_SEXT_rg_b_1_BITS_7_TO_0_076_077_BIT_7_07_ETC___05F_d2697);
}

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mkTopMAC__DOT__rg_s_EN = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__rg_s_D_IN = vlTOPp->start_s;
    vlTOPp->mkTopMAC__DOT__rg_inp_valid_D_IN = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__rg_c_EN = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__rg_c_D_IN = vlTOPp->start_c;
    vlTOPp->mkTopMAC__DOT__rg_b_EN = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__rg_b_D_IN = vlTOPp->start_b;
    vlTOPp->mkTopMAC__DOT__rg_a_EN = vlTOPp->EN_start;
    vlTOPp->mkTopMAC__DOT__rg_a_D_IN = vlTOPp->start_a;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RST_N & 0xfeU))) {
        Verilated::overWidthError("RST_N");}
    if (VL_UNLIKELY((start_s & 0xfeU))) {
        Verilated::overWidthError("start_s");}
    if (VL_UNLIKELY((EN_start & 0xfeU))) {
        Verilated::overWidthError("EN_start");}
}
#endif  // VL_DEBUG
