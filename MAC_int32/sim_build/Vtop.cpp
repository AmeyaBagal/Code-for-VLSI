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
            VL_FATAL_MT("/home/shakti/Desktop/CAD/Project1/MAC_int32/verilog/mkMACint32.v", 36, "",
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
            VL_FATAL_MT("/home/shakti/Desktop/CAD/Project1/MAC_int32/verilog/mkMACint32.v", 36, "",
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
    vlTOPp->mkMACint32__DOT__CLK = vlTOPp->CLK;
    vlTOPp->mkMACint32__DOT__RST_N = vlTOPp->RST_N;
    vlTOPp->mkMACint32__DOT__start_a = vlTOPp->start_a;
    vlTOPp->mkMACint32__DOT__start_b = vlTOPp->start_b;
    vlTOPp->mkMACint32__DOT__start_c = vlTOPp->start_c;
    vlTOPp->mkMACint32__DOT__EN_start = vlTOPp->EN_start;
    vlTOPp->mkMACint32__DOT__WILL_FIRE_start = vlTOPp->EN_start;
    vlTOPp->mkMACint32__DOT__sign___05F_1___05Fh29304 
        = (1U & (~ ((IData)(vlTOPp->start_a) >> 7U)));
    vlTOPp->mkMACint32__DOT__a_ext___05Fh29142 = ((0xffffff00U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->start_a) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(vlTOPp->start_a));
    vlTOPp->mkMACint32__DOT__b_ext___05Fh29143 = ((0xffffff00U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->start_b) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(vlTOPp->start_b));
    vlTOPp->mkMACint32__DOT__v_sign___05Fh29231 = (1U 
                                                   & ((0x80U 
                                                       & (IData)(vlTOPp->start_b))
                                                       ? (IData)(vlTOPp->mkMACint32__DOT__sign___05F_1___05Fh29304)
                                                       : 
                                                      ((IData)(vlTOPp->start_a) 
                                                       >> 7U)));
    vlTOPp->mkMACint32__DOT__a_ext___05F_1___05Fh29271 
        = ((IData)(1U) + (~ vlTOPp->mkMACint32__DOT__a_ext___05Fh29142));
    vlTOPp->mkMACint32__DOT__b_ext___05F_1___05Fh29303 
        = ((IData)(1U) + (~ vlTOPp->mkMACint32__DOT__b_ext___05Fh29143));
    vlTOPp->mkMACint32__DOT__x___05Fh29227 = ((0x80U 
                                               & (IData)(vlTOPp->start_a))
                                               ? vlTOPp->mkMACint32__DOT__a_ext___05F_1___05Fh29271
                                               : vlTOPp->mkMACint32__DOT__a_ext___05Fh29142);
    vlTOPp->mkMACint32__DOT__x___05Fh29276 = ((0x80U 
                                               & (IData)(vlTOPp->start_b))
                                               ? vlTOPp->mkMACint32__DOT__b_ext___05F_1___05Fh29303
                                               : vlTOPp->mkMACint32__DOT__b_ext___05Fh29143);
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[0U] 
        = ((0xfffffffeU & (vlTOPp->start_c << 1U)) 
           | (IData)(vlTOPp->mkMACint32__DOT__v_sign___05Fh29231));
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[1U] 
        = ((1U & (vlTOPp->start_c >> 0x1fU)) | (0xfffffffeU 
                                                & ((IData)(
                                                           (((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29227)) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29276)))) 
                                                   << 1U)));
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[2U] 
        = ((1U & ((IData)((((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29227)) 
                            << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29276)))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29227)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29276))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[3U] 
        = (2U | (1U & ((IData)(((((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29227)) 
                                  << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh29276))) 
                                >> 0x20U)) >> 0x1fU)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__rg_out_valid_EN) {
            vlTOPp->mkMACint32__DOT__rg_out_valid = vlTOPp->mkMACint32__DOT__rg_out_valid_D_IN;
        }
    } else {
        vlTOPp->mkMACint32__DOT__rg_out_valid = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__ans_EN) {
            vlTOPp->mkMACint32__DOT__ans = vlTOPp->mkMACint32__DOT__ans_D_IN;
        }
    } else {
        vlTOPp->mkMACint32__DOT__ans = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__adder_ofifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__adder_ofifo_rv 
                = vlTOPp->mkMACint32__DOT__adder_ofifo_rv_D_IN;
        }
    } else {
        vlTOPp->mkMACint32__DOT__adder_ofifo_rv = 0ULL;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__inp_fifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__inp_fifo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[2U];
            vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U] 
                = vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[3U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__inp_fifo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U] = 0U;
        vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U] = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__adder_ififo_rv_EN) {
            vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__adder_ififo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[2U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__adder_ififo_rv[2U] = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__stage4_fifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__stage4_fifo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[2U];
            vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U] 
                = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[3U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] = 0U;
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U] = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__stage2_fifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__stage2_fifo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[2U];
            vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U] 
                = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[3U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] = 0U;
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U] = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__stage3_fifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__stage3_fifo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[2U];
            vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U] 
                = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[3U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] = 0U;
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U] = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mkMACint32__DOT__stage1_fifo_rv_EN) {
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[0U];
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[1U];
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[2U];
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[3U];
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[4U];
            vlTOPp->mkMACint32__DOT__stage1_fifo_rv[5U] 
                = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[5U];
        }
    } else {
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U] = 0U;
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U] = 0U;
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U] = 0U;
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U] = 0U;
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] = 0U;
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv[5U] = 0U;
    }
    vlTOPp->mkMACint32__DOT__RDY_get_result = vlTOPp->mkMACint32__DOT__rg_out_valid;
    vlTOPp->mkMACint32__DOT__get_result = vlTOPp->mkMACint32__DOT__ans;
    vlTOPp->mkMACint32__DOT__ans_D_IN = (IData)(vlTOPp->mkMACint32__DOT__adder_ofifo_rv);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_fin = (1U 
                                                   & (IData)(
                                                             (vlTOPp->mkMACint32__DOT__adder_ofifo_rv 
                                                              >> 0x21U)));
    vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port1___05Fread 
        = ((1U & (IData)((vlTOPp->mkMACint32__DOT__adder_ofifo_rv 
                          >> 0x21U))) ? vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port0___05Fwrite_1
            : vlTOPp->mkMACint32__DOT__adder_ofifo_rv);
    vlTOPp->mkMACint32__DOT__shift_a___05Fh2032 = (0xfffffff8U 
                                                   & (vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U] 
                                                      << 2U));
    vlTOPp->mkMACint32__DOT__shift_a___05Fh2061 = (0xfffffffcU 
                                                   & (vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U] 
                                                      << 1U));
    vlTOPp->mkMACint32__DOT__shift_a___05Fh2090 = (0xfffffffeU 
                                                   & vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U]);
    vlTOPp->mkMACint32__DOT__cin___05Fh2093 = ((2U 
                                                & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])
                                                ? (
                                                   (vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U] 
                                                    << 0x1fU) 
                                                   | (vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U] 
                                                      >> 1U))
                                                : 0U);
    vlTOPp->mkMACint32__DOT__x___05Fh14006 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 7U));
    vlTOPp->mkMACint32__DOT__y___05Fh14104 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 7U));
    vlTOPp->mkMACint32__DOT__x___05Fh13724 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 6U));
    vlTOPp->mkMACint32__DOT__y___05Fh13822 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 6U));
    vlTOPp->mkMACint32__DOT__x___05Fh13442 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 5U));
    vlTOPp->mkMACint32__DOT__y___05Fh13540 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 5U));
    vlTOPp->mkMACint32__DOT__x___05Fh13160 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 4U));
    vlTOPp->mkMACint32__DOT__y___05Fh13258 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 4U));
    vlTOPp->mkMACint32__DOT__x___05Fh12878 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 3U));
    vlTOPp->mkMACint32__DOT__y___05Fh12976 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 3U));
    vlTOPp->mkMACint32__DOT__x___05Fh12596 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 2U));
    vlTOPp->mkMACint32__DOT__y___05Fh12694 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 2U));
    vlTOPp->mkMACint32__DOT__x___05Fh12313 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 1U));
    vlTOPp->mkMACint32__DOT__IF_adder_ififo_rv_BIT_32_AND_adder_ififo_rv_BI_ETC___05Fq6 
        = ((1U & (vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                  & vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]))
            ? 2U : 0U);
    vlTOPp->mkMACint32__DOT__y___05Fh12411 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                                                ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]) 
                                               >> 1U));
    vlTOPp->mkMACint32__DOT__x___05Fh27200 = (1U & 
                                              (vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U] 
                                               & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U]));
    vlTOPp->mkMACint32__DOT__y___05Fh27298 = (1U & 
                                              (vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U] 
                                               ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U]));
    vlTOPp->mkMACint32__DOT__x___05Fh26918 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1fU));
    vlTOPp->mkMACint32__DOT__y___05Fh27016 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1fU));
    vlTOPp->mkMACint32__DOT__x___05Fh26636 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1eU));
    vlTOPp->mkMACint32__DOT__y___05Fh26734 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1eU));
    vlTOPp->mkMACint32__DOT__x___05Fh26354 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1dU));
    vlTOPp->mkMACint32__DOT__y___05Fh26452 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1dU));
    vlTOPp->mkMACint32__DOT__x___05Fh26072 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1cU));
    vlTOPp->mkMACint32__DOT__y___05Fh26170 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1cU));
    vlTOPp->mkMACint32__DOT__x___05Fh25790 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1bU));
    vlTOPp->mkMACint32__DOT__y___05Fh25888 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1bU));
    vlTOPp->mkMACint32__DOT__x___05Fh25508 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1aU));
    vlTOPp->mkMACint32__DOT__y___05Fh25606 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x1aU));
    vlTOPp->mkMACint32__DOT__x___05Fh25185 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x19U));
    vlTOPp->mkMACint32__DOT__IF_stage4_fifo_rv_BIT_24_THEN_1_ELSE_0___05Fq9 
        = ((0x1000000U & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[0U])
            ? 1U : 0U);
    vlTOPp->mkMACint32__DOT__y___05Fh25323 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U]) 
                                               >> 0x19U));
    vlTOPp->mkMACint32__DOT__x___05Fh18388 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0x10U));
    vlTOPp->mkMACint32__DOT__y___05Fh18486 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0x10U));
    vlTOPp->mkMACint32__DOT__x___05Fh18106 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xfU));
    vlTOPp->mkMACint32__DOT__y___05Fh18204 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xfU));
    vlTOPp->mkMACint32__DOT__x___05Fh17824 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xeU));
    vlTOPp->mkMACint32__DOT__y___05Fh17922 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xeU));
    vlTOPp->mkMACint32__DOT__x___05Fh17542 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xdU));
    vlTOPp->mkMACint32__DOT__y___05Fh17640 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xdU));
    vlTOPp->mkMACint32__DOT__x___05Fh17260 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xcU));
    vlTOPp->mkMACint32__DOT__y___05Fh17358 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xcU));
    vlTOPp->mkMACint32__DOT__x___05Fh16978 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xbU));
    vlTOPp->mkMACint32__DOT__y___05Fh17076 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xbU));
    vlTOPp->mkMACint32__DOT__x___05Fh16696 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xaU));
    vlTOPp->mkMACint32__DOT__y___05Fh16794 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 0xaU));
    vlTOPp->mkMACint32__DOT__x___05Fh16373 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 9U));
    vlTOPp->mkMACint32__DOT__IF_stage2_fifo_rv_BIT_8_THEN_1_ELSE_0___05Fq7 
        = ((0x100U & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[0U])
            ? 1U : 0U);
    vlTOPp->mkMACint32__DOT__y___05Fh16511 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U]) 
                                               >> 9U));
    vlTOPp->mkMACint32__DOT__x___05Fh22790 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x18U));
    vlTOPp->mkMACint32__DOT__y___05Fh22888 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x18U));
    vlTOPp->mkMACint32__DOT__x___05Fh22508 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x17U));
    vlTOPp->mkMACint32__DOT__y___05Fh22606 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x17U));
    vlTOPp->mkMACint32__DOT__x___05Fh22226 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x16U));
    vlTOPp->mkMACint32__DOT__y___05Fh22324 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x16U));
    vlTOPp->mkMACint32__DOT__x___05Fh21944 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x15U));
    vlTOPp->mkMACint32__DOT__y___05Fh22042 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x15U));
    vlTOPp->mkMACint32__DOT__x___05Fh21662 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x14U));
    vlTOPp->mkMACint32__DOT__y___05Fh21760 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x14U));
    vlTOPp->mkMACint32__DOT__x___05Fh21380 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x13U));
    vlTOPp->mkMACint32__DOT__y___05Fh21478 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x13U));
    vlTOPp->mkMACint32__DOT__x___05Fh21098 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x12U));
    vlTOPp->mkMACint32__DOT__y___05Fh21196 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x12U));
    vlTOPp->mkMACint32__DOT__x___05Fh20775 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x11U));
    vlTOPp->mkMACint32__DOT__IF_stage3_fifo_rv_BIT_16_THEN_1_ELSE_0___05Fq8 
        = ((0x10000U & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[0U])
            ? 1U : 0U);
    vlTOPp->mkMACint32__DOT__y___05Fh20913 = (1U & 
                                              ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U] 
                                                ^ vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U]) 
                                               >> 0x11U));
    vlTOPp->mkMACint32__DOT__shift_a___05Fh3470 = (0xffffff80U 
                                                   & (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] 
                                                      << 6U));
    vlTOPp->mkMACint32__DOT__shift_a___05Fh3499 = (0xffffffc0U 
                                                   & (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] 
                                                      << 5U));
    vlTOPp->mkMACint32__DOT__shift_a___05Fh3528 = (0xffffffe0U 
                                                   & (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] 
                                                      << 4U));
    vlTOPp->mkMACint32__DOT__y___05Fh3648 = (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U] 
                                             & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U]);
    vlTOPp->mkMACint32__DOT__shift_a___05Fh3557 = (0xfffffff0U 
                                                   & (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U] 
                                                      << 3U));
    vlTOPp->RDY_get_result = vlTOPp->mkMACint32__DOT__RDY_get_result;
    vlTOPp->get_result = vlTOPp->mkMACint32__DOT__get_result;
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_fin = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_fin;
    vlTOPp->mkMACint32__DOT__ans_EN = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_fin;
    vlTOPp->mkMACint32__DOT__rg_out_valid_D_IN = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_fin;
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage6 
        = (1U & ((vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U] 
                  >> 1U) & (~ (IData)((vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port1___05Fread 
                                       >> 0x21U)))));
    vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2095 
        = (vlTOPp->mkMACint32__DOT__shift_a___05Fh2090 
           ^ vlTOPp->mkMACint32__DOT__cin___05Fh2093);
    vlTOPp->mkMACint32__DOT__cin093_AND_shift_a090___05Fq1 
        = (vlTOPp->mkMACint32__DOT__cin___05Fh2093 
           & vlTOPp->mkMACint32__DOT__shift_a___05Fh2090);
    vlTOPp->mkMACint32__DOT__y___05Fh12314 = (((IData)(vlTOPp->mkMACint32__DOT__IF_adder_ififo_rv_BIT_32_AND_adder_ififo_rv_BI_ETC___05Fq6) 
                                               >> 1U) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12411));
    vlTOPp->mkMACint32__DOT__y___05Fh25186 = ((IData)(vlTOPp->mkMACint32__DOT__IF_stage4_fifo_rv_BIT_24_THEN_1_ELSE_0___05Fq9) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25323));
    vlTOPp->mkMACint32__DOT__y___05Fh16374 = ((IData)(vlTOPp->mkMACint32__DOT__IF_stage2_fifo_rv_BIT_8_THEN_1_ELSE_0___05Fq7) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh16511));
    vlTOPp->mkMACint32__DOT__y___05Fh20776 = ((IData)(vlTOPp->mkMACint32__DOT__IF_stage3_fifo_rv_BIT_16_THEN_1_ELSE_0___05Fq8) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh20913));
    vlTOPp->mkMACint32__DOT__x___05Fh3670 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3557 
                                             ^ vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U]);
    vlTOPp->mkMACint32__DOT__y___05Fh3646 = (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U] 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh3557);
    vlTOPp->mkMACint32__DOT__x___05Fh3647 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3557 
                                             & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U]);
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage6 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage6;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage6) {
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv[0U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv[1U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv[2U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv[3U];
    }
    vlTOPp->mkMACint32__DOT__cin___05Fh2064 = ((4U 
                                                & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])
                                                ? vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2095
                                                : vlTOPp->mkMACint32__DOT__cin___05Fh2093);
    vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2096 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__cin093_AND_shift_a090___05Fq1 
                          << 1U));
    vlTOPp->mkMACint32__DOT__x___05Fh12693 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh12313) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12314));
    vlTOPp->mkMACint32__DOT__x___05Fh25605 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh25185) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25186));
    vlTOPp->mkMACint32__DOT__x___05Fh16793 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh16373) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh16374));
    vlTOPp->mkMACint32__DOT__x___05Fh21195 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh20775) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh20776));
    vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3562 
        = (vlTOPp->mkMACint32__DOT__x___05Fh3670 ^ 
           vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U]);
    vlTOPp->mkMACint32__DOT__x___05Fh3645 = (vlTOPp->mkMACint32__DOT__x___05Fh3647 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh3648);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage5 
        = (1U & ((vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U] 
                  >> 1U) & (~ (vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[3U] 
                               >> 1U))));
    vlTOPp->mkMACint32__DOT__y___05Fh2166 = (vlTOPp->mkMACint32__DOT__cin___05Fh2064 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh2061);
    if ((4U & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])) {
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_inp_f_ETC___05F_d54 
            = (((QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2095)) 
                << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2096)));
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27 
            = vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2096;
    } else {
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_inp_f_ETC___05F_d54 
            = ((QData)((IData)(vlTOPp->mkMACint32__DOT__cin___05Fh2093)) 
               << 0x20U);
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27 = 0U;
    }
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_34_35_XOR_a_ETC___05F_d475 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh12694) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh12693)) 
            << 2U) | ((2U & (((IData)(vlTOPp->mkMACint32__DOT__y___05Fh12411) 
                              << 1U) ^ (0xfffffffeU 
                                        & (IData)(vlTOPp->mkMACint32__DOT__IF_adder_ififo_rv_BIT_32_AND_adder_ififo_rv_BI_ETC___05Fq6)))) 
                      | (1U & (vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U] 
                               ^ vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]))));
    vlTOPp->mkMACint32__DOT__y___05Fh12597 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh12693) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12694));
    vlTOPp->mkMACint32__DOT__y___05Fh25509 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh25605) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25606));
    vlTOPp->mkMACint32__DOT__y___05Fh16697 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh16793) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh16794));
    vlTOPp->mkMACint32__DOT__y___05Fh21099 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21195) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21196));
    vlTOPp->mkMACint32__DOT__cin___05Fh3531 = ((0x20U 
                                                & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                                ? vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3562
                                                : vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U]);
    vlTOPp->mkMACint32__DOT__x645_OR_y646___05Fq2 = 
        (vlTOPp->mkMACint32__DOT__x___05Fh3645 | vlTOPp->mkMACint32__DOT__y___05Fh3646);
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage5 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage5;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage5) {
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv[0U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U];
    }
    vlTOPp->mkMACint32__DOT__x___05Fh2271 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh2061 
                                             ^ vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27);
    vlTOPp->mkMACint32__DOT__x___05Fh2167 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh2061 
                                             & vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27);
    vlTOPp->mkMACint32__DOT__y___05Fh2168 = (vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27 
                                             & vlTOPp->mkMACint32__DOT__cin___05Fh2064);
    vlTOPp->mkMACint32__DOT__x___05Fh12975 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh12596) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12597));
    vlTOPp->mkMACint32__DOT__x___05Fh25887 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh25508) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25509));
    vlTOPp->mkMACint32__DOT__x___05Fh17075 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh16696) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh16697));
    vlTOPp->mkMACint32__DOT__x___05Fh21477 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21098) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21099));
    vlTOPp->mkMACint32__DOT__y___05Fh3626 = (vlTOPp->mkMACint32__DOT__cin___05Fh3531 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh3528);
    vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3563 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x645_OR_y646___05Fq2 
                          << 1U));
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage4 
        = (1U & ((vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U] 
                  >> 1U) & (~ (vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[3U] 
                               >> 1U))));
    vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2066 
        = (vlTOPp->mkMACint32__DOT__x___05Fh2271 ^ vlTOPp->mkMACint32__DOT__cin___05Fh2064);
    vlTOPp->mkMACint32__DOT__x___05Fh2165 = (vlTOPp->mkMACint32__DOT__x___05Fh2167 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh2168);
    vlTOPp->mkMACint32__DOT__y___05Fh12879 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh12975) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12976));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_91_50_XOR_s_ETC___05F_d694 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh25888) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh25887)) 
            << 2U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh25606) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh25605)) 
                       << 1U) | (1U & ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh25323) 
                                       ^ (IData)(vlTOPp->mkMACint32__DOT__IF_stage4_fifo_rv_BIT_24_THEN_1_ELSE_0___05Fq9)))));
    vlTOPp->mkMACint32__DOT__y___05Fh25791 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh25887) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25888));
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_75_03_XOR_s_ETC___05F_d547 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh17076) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh17075)) 
            << 2U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh16794) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh16793)) 
                       << 1U) | (1U & ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh16511) 
                                       ^ (IData)(vlTOPp->mkMACint32__DOT__IF_stage2_fifo_rv_BIT_8_THEN_1_ELSE_0___05Fq7)))));
    vlTOPp->mkMACint32__DOT__y___05Fh16979 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17075) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17076));
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_83_77_XOR_s_ETC___05F_d621 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh21478) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh21477)) 
            << 2U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh21196) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh21195)) 
                       << 1U) | (1U & ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh20913) 
                                       ^ (IData)(vlTOPp->mkMACint32__DOT__IF_stage3_fifo_rv_BIT_16_THEN_1_ELSE_0___05Fq8)))));
    vlTOPp->mkMACint32__DOT__y___05Fh21381 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21477) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21478));
    vlTOPp->mkMACint32__DOT__b___05Fh3530 = ((0x20U 
                                              & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                              ? vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3563
                                              : vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U]);
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage4 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage4;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage4) {
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv[0U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U];
    }
    vlTOPp->mkMACint32__DOT__cin___05Fh2035 = ((8U 
                                                & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])
                                                ? vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2066
                                                : vlTOPp->mkMACint32__DOT__cin___05Fh2064);
    vlTOPp->mkMACint32__DOT__x165_OR_y166___05Fq10 
        = (vlTOPp->mkMACint32__DOT__x___05Fh2165 | vlTOPp->mkMACint32__DOT__y___05Fh2166);
    vlTOPp->mkMACint32__DOT__x___05Fh13257 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh12878) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh12879));
    vlTOPp->mkMACint32__DOT__x___05Fh26169 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh25790) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh25791));
    vlTOPp->mkMACint32__DOT__x___05Fh17357 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh16978) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh16979));
    vlTOPp->mkMACint32__DOT__x___05Fh21759 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21380) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21381));
    vlTOPp->mkMACint32__DOT__x___05Fh3686 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3528 
                                             ^ vlTOPp->mkMACint32__DOT__b___05Fh3530);
    vlTOPp->mkMACint32__DOT__x___05Fh3627 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3528 
                                             & vlTOPp->mkMACint32__DOT__b___05Fh3530);
    vlTOPp->mkMACint32__DOT__y___05Fh3628 = (vlTOPp->mkMACint32__DOT__b___05Fh3530 
                                             & vlTOPp->mkMACint32__DOT__cin___05Fh3531);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage3 
        = (1U & (vlTOPp->mkMACint32__DOT__adder_ififo_rv[2U] 
                 & (~ (vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[3U] 
                       >> 1U))));
    vlTOPp->mkMACint32__DOT__y___05Fh2286 = (vlTOPp->mkMACint32__DOT__cin___05Fh2035 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh2032);
    vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2067 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x165_OR_y166___05Fq10 
                          << 1U));
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_36_29_XOR_a_ETC___05F_d476 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh13258) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh13257)) 
            << 4U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh12976) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh12975)) 
                       << 3U) | (IData)(vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_34_35_XOR_a_ETC___05F_d475)));
    vlTOPp->mkMACint32__DOT__y___05Fh13161 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13257) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13258));
    vlTOPp->mkMACint32__DOT__y___05Fh26073 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26169) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26170));
    vlTOPp->mkMACint32__DOT__y___05Fh17261 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17357) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17358));
    vlTOPp->mkMACint32__DOT__y___05Fh21663 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21759) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21760));
    vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3533 
        = (vlTOPp->mkMACint32__DOT__x___05Fh3686 ^ vlTOPp->mkMACint32__DOT__cin___05Fh3531);
    vlTOPp->mkMACint32__DOT__x___05Fh3625 = (vlTOPp->mkMACint32__DOT__x___05Fh3627 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh3628);
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage3 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage3;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage3) {
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fwrite_1[2U];
    } else {
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv[2U];
    }
    if ((8U & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])) {
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_35_5_THEN_inp_f_ETC___05F_d55 
            = (((QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2066)) 
                << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2067)));
        vlTOPp->mkMACint32__DOT__b___05Fh2034 = vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2067;
    } else {
        vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_35_5_THEN_inp_f_ETC___05F_d55 
            = vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_inp_f_ETC___05F_d54;
        vlTOPp->mkMACint32__DOT__b___05Fh2034 = vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_34_8_THEN_IF_in_ETC___05F_d27;
    }
    vlTOPp->mkMACint32__DOT__x___05Fh13539 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13160) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13161));
    vlTOPp->mkMACint32__DOT__x___05Fh26451 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26072) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26073));
    vlTOPp->mkMACint32__DOT__x___05Fh17639 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17260) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17261));
    vlTOPp->mkMACint32__DOT__x___05Fh22041 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21662) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21663));
    vlTOPp->mkMACint32__DOT__cin___05Fh3502 = ((0x40U 
                                                & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                                ? vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3533
                                                : vlTOPp->mkMACint32__DOT__cin___05Fh3531);
    vlTOPp->mkMACint32__DOT__x625_OR_y626___05Fq3 = 
        (vlTOPp->mkMACint32__DOT__x___05Fh3625 | vlTOPp->mkMACint32__DOT__y___05Fh3626);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage2 
        = (1U & ((vlTOPp->mkMACint32__DOT__stage1_fifo_rv[5U] 
                  >> 1U) & (~ vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[2U])));
    vlTOPp->mkMACint32__DOT__x___05Fh2147 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh2032 
                                             ^ vlTOPp->mkMACint32__DOT__b___05Fh2034);
    vlTOPp->mkMACint32__DOT__x___05Fh2287 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh2032 
                                             & vlTOPp->mkMACint32__DOT__b___05Fh2034);
    vlTOPp->mkMACint32__DOT__y___05Fh2288 = (vlTOPp->mkMACint32__DOT__b___05Fh2034 
                                             & vlTOPp->mkMACint32__DOT__cin___05Fh2035);
    vlTOPp->mkMACint32__DOT__y___05Fh13443 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13539) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13540));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_93_44_XOR_s_ETC___05F_d695 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh26452) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh26451)) 
            << 4U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh26170) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh26169)) 
                       << 3U) | (IData)(vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_91_50_XOR_s_ETC___05F_d694)));
    vlTOPp->mkMACint32__DOT__y___05Fh26355 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26451) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26452));
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_77_97_XOR_s_ETC___05F_d548 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh17640) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh17639)) 
            << 4U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh17358) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh17357)) 
                       << 3U) | (IData)(vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_75_03_XOR_s_ETC___05F_d547)));
    vlTOPp->mkMACint32__DOT__y___05Fh17543 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17639) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17640));
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_85_71_XOR_s_ETC___05F_d622 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh22042) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh22041)) 
            << 4U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh21760) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh21759)) 
                       << 3U) | (IData)(vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_83_77_XOR_s_ETC___05F_d621)));
    vlTOPp->mkMACint32__DOT__y___05Fh21945 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22041) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22042));
    vlTOPp->mkMACint32__DOT__y___05Fh3606 = (vlTOPp->mkMACint32__DOT__cin___05Fh3502 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh3499);
    vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3534 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x625_OR_y626___05Fq3 
                          << 1U));
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage2 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage2;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage2) {
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[3U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[4U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[4U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[5U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port0___05Fwrite_1[5U];
    } else {
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[0U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[1U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[4U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[4U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[5U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv[5U];
    }
    vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2037 
        = (vlTOPp->mkMACint32__DOT__x___05Fh2147 ^ vlTOPp->mkMACint32__DOT__cin___05Fh2035);
    vlTOPp->mkMACint32__DOT__x___05Fh2285 = (vlTOPp->mkMACint32__DOT__x___05Fh2287 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh2288);
    vlTOPp->mkMACint32__DOT__x___05Fh13821 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13442) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13443));
    vlTOPp->mkMACint32__DOT__x___05Fh26733 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26354) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26355));
    vlTOPp->mkMACint32__DOT__x___05Fh17921 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17542) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17543));
    vlTOPp->mkMACint32__DOT__x___05Fh22323 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh21944) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh21945));
    vlTOPp->mkMACint32__DOT__b___05Fh3501 = ((0x40U 
                                              & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                              ? vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3534
                                              : vlTOPp->mkMACint32__DOT__b___05Fh3530);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage1 
        = (1U & ((vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U] 
                  >> 1U) & (~ (vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[5U] 
                               >> 1U))));
    vlTOPp->mkMACint32__DOT__x285_OR_y286___05Fq11 
        = (vlTOPp->mkMACint32__DOT__x___05Fh2285 | vlTOPp->mkMACint32__DOT__y___05Fh2286);
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_38_23_XOR_a_ETC___05F_d477 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh13822) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh13821)) 
            << 6U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh13540) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh13539)) 
                       << 5U) | (IData)(vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_36_29_XOR_a_ETC___05F_d476)));
    vlTOPp->mkMACint32__DOT__y___05Fh13725 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13821) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13822));
    vlTOPp->mkMACint32__DOT__y___05Fh26637 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26733) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26734));
    vlTOPp->mkMACint32__DOT__y___05Fh17825 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17921) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17922));
    vlTOPp->mkMACint32__DOT__y___05Fh22227 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22323) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22324));
    vlTOPp->mkMACint32__DOT__x___05Fh3702 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3499 
                                             ^ vlTOPp->mkMACint32__DOT__b___05Fh3501);
    vlTOPp->mkMACint32__DOT__x___05Fh3607 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3499 
                                             & vlTOPp->mkMACint32__DOT__b___05Fh3501);
    vlTOPp->mkMACint32__DOT__y___05Fh3608 = (vlTOPp->mkMACint32__DOT__b___05Fh3501 
                                             & vlTOPp->mkMACint32__DOT__cin___05Fh3502);
    vlTOPp->mkMACint32__DOT__WILL_FIRE_RL_r1_pipe_stage1 
        = vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage1;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage1) {
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port0___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv[0U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U];
    }
    vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2038 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x285_OR_y286___05Fq11 
                          << 1U));
    vlTOPp->mkMACint32__DOT__x___05Fh14103 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh13724) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh13725));
    vlTOPp->mkMACint32__DOT__x___05Fh27015 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26636) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26637));
    vlTOPp->mkMACint32__DOT__x___05Fh18203 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh17824) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh17825));
    vlTOPp->mkMACint32__DOT__x___05Fh22605 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22226) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22227));
    vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3504 
        = (vlTOPp->mkMACint32__DOT__x___05Fh3702 ^ vlTOPp->mkMACint32__DOT__cin___05Fh3502);
    vlTOPp->mkMACint32__DOT__x___05Fh3605 = (vlTOPp->mkMACint32__DOT__x___05Fh3607 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh3608);
    vlTOPp->mkMACint32__DOT__CAN_FIRE_start = (1U & 
                                               (~ (
                                                   vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[3U] 
                                                   >> 1U)));
    vlTOPp->mkMACint32__DOT__RDY_start = (1U & (~ (
                                                   vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[3U] 
                                                   >> 1U)));
    vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_36_2_THEN_inp_f_ETC___05F_d56 
        = ((0x10U & vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U])
            ? (((QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_sum___05Fh2037)) 
                << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__lsb_result_carry___05Fh2038)))
            : vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_35_5_THEN_inp_f_ETC___05F_d55);
    vlTOPp->mkMACint32__DOT__y___05Fh14007 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh14103) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh14104));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_95_38_XOR_s_ETC___05F_d696 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh27016) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh27015)) 
            << 6U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh26734) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh26733)) 
                       << 5U) | (IData)(vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_93_44_XOR_s_ETC___05F_d695)));
    vlTOPp->mkMACint32__DOT__y___05Fh26919 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh27015) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh27016));
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_79_91_XOR_s_ETC___05F_d549 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh18204) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh18203)) 
            << 6U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh17922) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh17921)) 
                       << 5U) | (IData)(vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_77_97_XOR_s_ETC___05F_d548)));
    vlTOPp->mkMACint32__DOT__y___05Fh18107 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh18203) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh18204));
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_87_65_XOR_s_ETC___05F_d623 
        = ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh22606) 
             ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh22605)) 
            << 6U) | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh22324) 
                        ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh22323)) 
                       << 5U) | (IData)(vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_85_71_XOR_s_ETC___05F_d622)));
    vlTOPp->mkMACint32__DOT__y___05Fh22509 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22605) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22606));
    vlTOPp->mkMACint32__DOT__cin___05Fh3473 = ((0x80U 
                                                & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                                ? vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3504
                                                : vlTOPp->mkMACint32__DOT__cin___05Fh3502);
    vlTOPp->mkMACint32__DOT__x605_OR_y606___05Fq4 = 
        (vlTOPp->mkMACint32__DOT__x___05Fh3605 | vlTOPp->mkMACint32__DOT__y___05Fh3606);
    vlTOPp->RDY_start = vlTOPp->mkMACint32__DOT__RDY_start;
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[0U] 
        = (IData)(vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_36_2_THEN_inp_f_ETC___05F_d56);
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[1U] 
        = (IData)((vlTOPp->mkMACint32__DOT__IF_inp_fifo_rv_port0___05Fread_BIT_36_2_THEN_inp_f_ETC___05F_d56 
                   >> 0x20U));
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[2U] 
        = vlTOPp->mkMACint32__DOT__inp_fifo_rv[0U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[3U] 
        = vlTOPp->mkMACint32__DOT__inp_fifo_rv[1U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[4U] 
        = vlTOPp->mkMACint32__DOT__inp_fifo_rv[2U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[5U] 
        = (2U | (1U & vlTOPp->mkMACint32__DOT__inp_fifo_rv[3U]));
    vlTOPp->mkMACint32__DOT__psum1___05Fh11405 = ((
                                                   ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh14006) 
                                                    | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh14007)) 
                                                   << 8U) 
                                                  | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh14104) 
                                                       ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh14103)) 
                                                      << 7U) 
                                                     | (IData)(vlTOPp->mkMACint32__DOT__adder_ififo_rv_port0___05Fread___05F12_BIT_38_23_XOR_a_ETC___05F_d477)));
    vlTOPp->mkMACint32__DOT__x___05Fh27297 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh26918) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh26919));
    vlTOPp->mkMACint32__DOT__x___05Fh18485 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh18106) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh18107));
    vlTOPp->mkMACint32__DOT__x___05Fh22887 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22508) 
                                              | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22509));
    vlTOPp->mkMACint32__DOT__y___05Fh3737 = (vlTOPp->mkMACint32__DOT__cin___05Fh3473 
                                             & vlTOPp->mkMACint32__DOT__shift_a___05Fh3470);
    vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3505 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x605_OR_y606___05Fq4 
                          << 1U));
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage1) {
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[3U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[4U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[4U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[5U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fwrite_1[5U];
    } else {
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[2U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[3U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[4U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[4U];
        vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[5U] 
            = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port1___05Fread[5U];
    }
    vlTOPp->mkMACint32__DOT__v_sum___05Fh11585 = (QData)((IData)(vlTOPp->mkMACint32__DOT__psum1___05Fh11405));
    vlTOPp->mkMACint32__DOT__v_sum___05Fh24720 = ((
                                                   ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh27298) 
                                                    ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh27297)) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port0___05Fread___05F29_BIT_95_38_XOR_s_ETC___05F_d696) 
                                                      << 0x18U) 
                                                     | (0xffffffU 
                                                        & vlTOPp->mkMACint32__DOT__stage4_fifo_rv[0U])));
    vlTOPp->mkMACint32__DOT__y___05Fh27201 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh27297) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh27298));
    vlTOPp->mkMACint32__DOT__y___05Fh18389 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh18485) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh18486));
    vlTOPp->mkMACint32__DOT__y___05Fh22791 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22887) 
                                              & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22888));
    vlTOPp->mkMACint32__DOT__b___05Fh3472 = ((0x80U 
                                              & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
                                              ? vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3505
                                              : vlTOPp->mkMACint32__DOT__b___05Fh3501);
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[0U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[1U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[2U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[2U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[3U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[3U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[4U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[4U];
    vlTOPp->mkMACint32__DOT__stage1_fifo_rv_D_IN[5U] 
        = vlTOPp->mkMACint32__DOT__stage1_fifo_rv_port2___05Fread[5U];
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[0U] 
        = (IData)(vlTOPp->mkMACint32__DOT__v_sum___05Fh11585);
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[1U] 
        = ((0xfffffffeU & ((IData)((((QData)((IData)(
                                                     vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U])))) 
                           << 1U)) | (IData)((vlTOPp->mkMACint32__DOT__v_sum___05Fh11585 
                                              >> 0x20U)));
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[2U] 
        = ((1U & ((IData)((((QData)((IData)(vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U])))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[3U] 
        = (2U | (1U & ((IData)(((((QData)((IData)(vlTOPp->mkMACint32__DOT__adder_ififo_rv[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlTOPp->mkMACint32__DOT__adder_ififo_rv[0U]))) 
                                >> 0x20U)) >> 0x1fU)));
    vlTOPp->mkMACint32__DOT__v_overflow___05Fh24719 
        = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh27200) 
           | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh27201));
    vlTOPp->mkMACint32__DOT__psum2___05Fh15743 = ((
                                                   ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh18388) 
                                                    | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh18389)) 
                                                   << 8U) 
                                                  | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh18486) 
                                                       ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh18485)) 
                                                      << 7U) 
                                                     | (IData)(vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port0___05Fread___05F81_BIT_79_91_XOR_s_ETC___05F_d549)));
    vlTOPp->mkMACint32__DOT__psum2___05Fh20145 = ((
                                                   ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh22790) 
                                                    | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh22791)) 
                                                   << 8U) 
                                                  | ((((IData)(vlTOPp->mkMACint32__DOT__y___05Fh22888) 
                                                       ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh22887)) 
                                                      << 7U) 
                                                     | (IData)(vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port0___05Fread___05F55_BIT_87_65_XOR_s_ETC___05F_d623)));
    vlTOPp->mkMACint32__DOT__x___05Fh3588 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3470 
                                             ^ vlTOPp->mkMACint32__DOT__b___05Fh3472);
    vlTOPp->mkMACint32__DOT__x___05Fh3738 = (vlTOPp->mkMACint32__DOT__shift_a___05Fh3470 
                                             & vlTOPp->mkMACint32__DOT__b___05Fh3472);
    vlTOPp->mkMACint32__DOT__y___05Fh3739 = (vlTOPp->mkMACint32__DOT__b___05Fh3472 
                                             & vlTOPp->mkMACint32__DOT__cin___05Fh3473);
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage3) {
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[2U];
        vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port1___05Fread[3U];
    }
    vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port1___05Fwrite_1 
        = (0x200000000ULL | (((QData)((IData)(vlTOPp->mkMACint32__DOT__v_overflow___05Fh24719)) 
                              << 0x20U) | (QData)((IData)(vlTOPp->mkMACint32__DOT__v_sum___05Fh24720))));
    vlTOPp->mkMACint32__DOT__x___05Fh15953 = (((IData)(vlTOPp->mkMACint32__DOT__psum2___05Fh15743) 
                                               << 8U) 
                                              | (0xffU 
                                                 & vlTOPp->mkMACint32__DOT__stage2_fifo_rv[0U]));
    vlTOPp->mkMACint32__DOT__x___05Fh20355 = (((IData)(vlTOPp->mkMACint32__DOT__psum2___05Fh20145) 
                                               << 0x10U) 
                                              | (0xffffU 
                                                 & vlTOPp->mkMACint32__DOT__stage3_fifo_rv[0U]));
    vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3475 
        = (vlTOPp->mkMACint32__DOT__x___05Fh3588 ^ vlTOPp->mkMACint32__DOT__cin___05Fh3473);
    vlTOPp->mkMACint32__DOT__x___05Fh3736 = (vlTOPp->mkMACint32__DOT__x___05Fh3738 
                                             | vlTOPp->mkMACint32__DOT__y___05Fh3739);
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[0U] 
        = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[1U] 
        = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[2U] 
        = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[2U];
    vlTOPp->mkMACint32__DOT__stage2_fifo_rv_D_IN[3U] 
        = vlTOPp->mkMACint32__DOT__stage2_fifo_rv_port2___05Fread[3U];
    vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port2___05Fread 
        = ((IData)(vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage6)
            ? vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port1___05Fwrite_1
            : vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port1___05Fread);
    vlTOPp->mkMACint32__DOT__v_sum___05Fh15918 = (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh15953));
    vlTOPp->mkMACint32__DOT__v_sum___05Fh20320 = (QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh20355));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
        = ((0x100U & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
            ? vlTOPp->mkMACint32__DOT__stage_result_sum___05Fh3475
            : vlTOPp->mkMACint32__DOT__cin___05Fh3473);
    vlTOPp->mkMACint32__DOT__x736_OR_y737___05Fq5 = 
        (vlTOPp->mkMACint32__DOT__x___05Fh3736 | vlTOPp->mkMACint32__DOT__y___05Fh3737);
    vlTOPp->mkMACint32__DOT__adder_ofifo_rv_D_IN = vlTOPp->mkMACint32__DOT__adder_ofifo_rv_port2___05Fread;
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[0U] 
        = (IData)(vlTOPp->mkMACint32__DOT__v_sum___05Fh15918);
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[1U] 
        = ((0xfffffffeU & ((IData)((((QData)((IData)(
                                                     vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U])) 
                                     << 0x3fU) | (((QData)((IData)(
                                                                   vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U])) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U])) 
                                                     >> 1U)))) 
                           << 1U)) | (IData)((vlTOPp->mkMACint32__DOT__v_sum___05Fh15918 
                                              >> 0x20U)));
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[2U] 
        = ((1U & ((IData)((((QData)((IData)(vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U])) 
                            << 0x3fU) | (((QData)((IData)(
                                                          vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U])) 
                                          << 0x1fU) 
                                         | ((QData)((IData)(
                                                            vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U])) 
                                            >> 1U)))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U])) 
                                                          << 0x3fU) 
                                                         | (((QData)((IData)(
                                                                             vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U])) 
                                                             << 0x1fU) 
                                                            | ((QData)((IData)(
                                                                               vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U])) 
                                                               >> 1U))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[3U] 
        = (2U | (1U & ((IData)(((((QData)((IData)(vlTOPp->mkMACint32__DOT__stage2_fifo_rv[3U])) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                vlTOPp->mkMACint32__DOT__stage2_fifo_rv[2U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlTOPp->mkMACint32__DOT__stage2_fifo_rv[1U])) 
                                                  >> 1U))) 
                                >> 0x20U)) >> 0x1fU)));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[0U] 
        = (IData)(vlTOPp->mkMACint32__DOT__v_sum___05Fh20320);
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[1U] 
        = ((0xfffffffeU & ((IData)((((QData)((IData)(
                                                     vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U])) 
                                     << 0x3fU) | (((QData)((IData)(
                                                                   vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U])) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U])) 
                                                     >> 1U)))) 
                           << 1U)) | (IData)((vlTOPp->mkMACint32__DOT__v_sum___05Fh20320 
                                              >> 0x20U)));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[2U] 
        = ((1U & ((IData)((((QData)((IData)(vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U])) 
                            << 0x3fU) | (((QData)((IData)(
                                                          vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U])) 
                                          << 0x1fU) 
                                         | ((QData)((IData)(
                                                            vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U])) 
                                            >> 1U)))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U])) 
                                                          << 0x3fU) 
                                                         | (((QData)((IData)(
                                                                             vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U])) 
                                                             << 0x1fU) 
                                                            | ((QData)((IData)(
                                                                               vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U])) 
                                                               >> 1U))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[3U] 
        = (2U | (1U & ((IData)(((((QData)((IData)(vlTOPp->mkMACint32__DOT__stage3_fifo_rv[3U])) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                vlTOPp->mkMACint32__DOT__stage3_fifo_rv[2U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlTOPp->mkMACint32__DOT__stage3_fifo_rv[1U])) 
                                                  >> 1U))) 
                                >> 0x20U)) >> 0x1fU)));
    vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3476 
        = (0xfffffffeU & (vlTOPp->mkMACint32__DOT__x736_OR_y737___05Fq5 
                          << 1U));
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage4) {
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[2U];
        vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port1___05Fread[3U];
    }
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage5) {
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[2U];
        vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port1___05Fread[3U];
    }
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124 
        = ((0x100U & vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U])
            ? vlTOPp->mkMACint32__DOT__stage_result_carry___05Fh3476
            : vlTOPp->mkMACint32__DOT__b___05Fh3472);
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[0U] 
        = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[1U] 
        = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[2U] 
        = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[2U];
    vlTOPp->mkMACint32__DOT__stage3_fifo_rv_D_IN[3U] 
        = vlTOPp->mkMACint32__DOT__stage3_fifo_rv_port2___05Fread[3U];
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[0U] 
        = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[1U] 
        = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[2U] 
        = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[2U];
    vlTOPp->mkMACint32__DOT__stage4_fifo_rv_D_IN[3U] 
        = vlTOPp->mkMACint32__DOT__stage4_fifo_rv_port2___05Fread[3U];
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d374 
        = (1U & (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                 ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124));
    vlTOPp->mkMACint32__DOT__x___05Fh3393 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1fU));
    vlTOPp->mkMACint32__DOT__x___05Fh8798 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1eU));
    vlTOPp->mkMACint32__DOT__y___05Fh8846 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1eU));
    vlTOPp->mkMACint32__DOT__x___05Fh8644 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1dU));
    vlTOPp->mkMACint32__DOT__y___05Fh8692 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1dU));
    vlTOPp->mkMACint32__DOT__x___05Fh8490 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1cU));
    vlTOPp->mkMACint32__DOT__y___05Fh8538 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1cU));
    vlTOPp->mkMACint32__DOT__x___05Fh8336 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1bU));
    vlTOPp->mkMACint32__DOT__y___05Fh8384 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1bU));
    vlTOPp->mkMACint32__DOT__x___05Fh8182 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1aU));
    vlTOPp->mkMACint32__DOT__y___05Fh8230 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x1aU));
    vlTOPp->mkMACint32__DOT__x___05Fh8028 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x19U));
    vlTOPp->mkMACint32__DOT__y___05Fh8076 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x19U));
    vlTOPp->mkMACint32__DOT__x___05Fh7874 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x18U));
    vlTOPp->mkMACint32__DOT__y___05Fh7922 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x18U));
    vlTOPp->mkMACint32__DOT__x___05Fh7720 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x17U));
    vlTOPp->mkMACint32__DOT__y___05Fh7768 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x17U));
    vlTOPp->mkMACint32__DOT__x___05Fh7566 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x16U));
    vlTOPp->mkMACint32__DOT__y___05Fh7614 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x16U));
    vlTOPp->mkMACint32__DOT__x___05Fh7412 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x15U));
    vlTOPp->mkMACint32__DOT__y___05Fh7460 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x15U));
    vlTOPp->mkMACint32__DOT__x___05Fh7258 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x14U));
    vlTOPp->mkMACint32__DOT__y___05Fh7306 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x14U));
    vlTOPp->mkMACint32__DOT__x___05Fh7104 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x13U));
    vlTOPp->mkMACint32__DOT__y___05Fh7152 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x13U));
    vlTOPp->mkMACint32__DOT__x___05Fh6950 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x12U));
    vlTOPp->mkMACint32__DOT__y___05Fh6998 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x12U));
    vlTOPp->mkMACint32__DOT__x___05Fh6796 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x11U));
    vlTOPp->mkMACint32__DOT__y___05Fh6844 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x11U));
    vlTOPp->mkMACint32__DOT__x___05Fh6642 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x10U));
    vlTOPp->mkMACint32__DOT__y___05Fh6690 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0x10U));
    vlTOPp->mkMACint32__DOT__x___05Fh6488 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xfU));
    vlTOPp->mkMACint32__DOT__y___05Fh6536 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xfU));
    vlTOPp->mkMACint32__DOT__x___05Fh6334 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xeU));
    vlTOPp->mkMACint32__DOT__y___05Fh6382 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xeU));
    vlTOPp->mkMACint32__DOT__x___05Fh6180 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xdU));
    vlTOPp->mkMACint32__DOT__y___05Fh6228 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xdU));
    vlTOPp->mkMACint32__DOT__x___05Fh6026 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xcU));
    vlTOPp->mkMACint32__DOT__y___05Fh6074 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xcU));
    vlTOPp->mkMACint32__DOT__x___05Fh5872 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xbU));
    vlTOPp->mkMACint32__DOT__y___05Fh5920 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xbU));
    vlTOPp->mkMACint32__DOT__x___05Fh5718 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xaU));
    vlTOPp->mkMACint32__DOT__y___05Fh5766 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 0xaU));
    vlTOPp->mkMACint32__DOT__x___05Fh5564 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 9U));
    vlTOPp->mkMACint32__DOT__y___05Fh5612 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 9U));
    vlTOPp->mkMACint32__DOT__x___05Fh5410 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 8U));
    vlTOPp->mkMACint32__DOT__y___05Fh5458 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 8U));
    vlTOPp->mkMACint32__DOT__x___05Fh5256 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 7U));
    vlTOPp->mkMACint32__DOT__y___05Fh5304 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 7U));
    vlTOPp->mkMACint32__DOT__x___05Fh5102 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 6U));
    vlTOPp->mkMACint32__DOT__y___05Fh5150 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 6U));
    vlTOPp->mkMACint32__DOT__x___05Fh4948 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 5U));
    vlTOPp->mkMACint32__DOT__y___05Fh4996 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 5U));
    vlTOPp->mkMACint32__DOT__x___05Fh4794 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 4U));
    vlTOPp->mkMACint32__DOT__y___05Fh4842 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 4U));
    vlTOPp->mkMACint32__DOT__x___05Fh4640 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 3U));
    vlTOPp->mkMACint32__DOT__y___05Fh4688 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 3U));
    vlTOPp->mkMACint32__DOT__x___05Fh4486 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 2U));
    vlTOPp->mkMACint32__DOT__y___05Fh4534 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 2U));
    vlTOPp->mkMACint32__DOT__x___05Fh4331 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 1U));
    vlTOPp->mkMACint32__DOT__IF_IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6___05FETC___05Fq12 
        = ((1U & (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                  & vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124))
            ? 2ULL : 0ULL);
    vlTOPp->mkMACint32__DOT__y___05Fh4379 = (1U & (
                                                   (vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d115 
                                                    ^ vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d124) 
                                                   >> 1U));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d372 
        = (1U & ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh4379) 
                 ^ (IData)((vlTOPp->mkMACint32__DOT__IF_IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6___05FETC___05Fq12 
                            >> 1U))));
    vlTOPp->mkMACint32__DOT__y___05Fh4332 = ((IData)(
                                                     (vlTOPp->mkMACint32__DOT__IF_IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6___05FETC___05Fq12 
                                                      >> 1U)) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4379));
    vlTOPp->mkMACint32__DOT__x___05Fh4533 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4331) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4332));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d370 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh4534) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh4533));
    vlTOPp->mkMACint32__DOT__y___05Fh4487 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4533) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4534));
    vlTOPp->mkMACint32__DOT__x___05Fh4687 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4486) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4487));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d368 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh4688) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh4687));
    vlTOPp->mkMACint32__DOT__y___05Fh4641 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4687) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4688));
    vlTOPp->mkMACint32__DOT__x___05Fh4841 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4640) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4641));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d366 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh4842) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh4841));
    vlTOPp->mkMACint32__DOT__y___05Fh4795 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4841) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4842));
    vlTOPp->mkMACint32__DOT__x___05Fh4995 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4794) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4795));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d364 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh4996) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh4995));
    vlTOPp->mkMACint32__DOT__y___05Fh4949 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4995) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4996));
    vlTOPp->mkMACint32__DOT__x___05Fh5149 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh4948) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh4949));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d362 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5150) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5149));
    vlTOPp->mkMACint32__DOT__y___05Fh5103 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5149) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5150));
    vlTOPp->mkMACint32__DOT__x___05Fh5303 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5102) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5103));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d360 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5304) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5303));
    vlTOPp->mkMACint32__DOT__y___05Fh5257 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5303) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5304));
    vlTOPp->mkMACint32__DOT__x___05Fh5457 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5256) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5257));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d358 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5458) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5457));
    vlTOPp->mkMACint32__DOT__y___05Fh5411 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5457) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5458));
    vlTOPp->mkMACint32__DOT__x___05Fh5611 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5410) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5411));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d356 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5612) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5611));
    vlTOPp->mkMACint32__DOT__y___05Fh5565 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5611) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5612));
    vlTOPp->mkMACint32__DOT__x___05Fh5765 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5564) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5565));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d354 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5766) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5765));
    vlTOPp->mkMACint32__DOT__y___05Fh5719 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5765) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5766));
    vlTOPp->mkMACint32__DOT__x___05Fh5919 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5718) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5719));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d352 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh5920) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh5919));
    vlTOPp->mkMACint32__DOT__y___05Fh5873 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5919) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5920));
    vlTOPp->mkMACint32__DOT__x___05Fh6073 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh5872) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh5873));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d350 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6074) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6073));
    vlTOPp->mkMACint32__DOT__y___05Fh6027 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6073) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6074));
    vlTOPp->mkMACint32__DOT__x___05Fh6227 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6026) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6027));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d348 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6228) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6227));
    vlTOPp->mkMACint32__DOT__y___05Fh6181 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6227) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6228));
    vlTOPp->mkMACint32__DOT__x___05Fh6381 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6180) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6181));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d346 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6382) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6381));
    vlTOPp->mkMACint32__DOT__y___05Fh6335 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6381) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6382));
    vlTOPp->mkMACint32__DOT__x___05Fh6535 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6334) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6335));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d344 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6536) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6535));
    vlTOPp->mkMACint32__DOT__y___05Fh6489 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6535) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6536));
    vlTOPp->mkMACint32__DOT__x___05Fh6689 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6488) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6489));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d342 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6690) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6689));
    vlTOPp->mkMACint32__DOT__y___05Fh6643 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6689) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6690));
    vlTOPp->mkMACint32__DOT__x___05Fh6843 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6642) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6643));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d340 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6844) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6843));
    vlTOPp->mkMACint32__DOT__y___05Fh6797 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6843) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6844));
    vlTOPp->mkMACint32__DOT__x___05Fh6997 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6796) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6797));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d338 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh6998) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh6997));
    vlTOPp->mkMACint32__DOT__y___05Fh6951 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6997) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6998));
    vlTOPp->mkMACint32__DOT__x___05Fh7151 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh6950) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh6951));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d336 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7152) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7151));
    vlTOPp->mkMACint32__DOT__y___05Fh7105 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7151) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7152));
    vlTOPp->mkMACint32__DOT__x___05Fh7305 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7104) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7105));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d334 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7306) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7305));
    vlTOPp->mkMACint32__DOT__y___05Fh7259 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7305) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7306));
    vlTOPp->mkMACint32__DOT__x___05Fh7459 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7258) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7259));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d332 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7460) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7459));
    vlTOPp->mkMACint32__DOT__y___05Fh7413 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7459) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7460));
    vlTOPp->mkMACint32__DOT__x___05Fh7613 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7412) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7413));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d330 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7614) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7613));
    vlTOPp->mkMACint32__DOT__y___05Fh7567 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7613) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7614));
    vlTOPp->mkMACint32__DOT__x___05Fh7767 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7566) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7567));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d328 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7768) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7767));
    vlTOPp->mkMACint32__DOT__y___05Fh7721 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7767) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7768));
    vlTOPp->mkMACint32__DOT__x___05Fh7921 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7720) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7721));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d326 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh7922) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh7921));
    vlTOPp->mkMACint32__DOT__y___05Fh7875 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7921) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7922));
    vlTOPp->mkMACint32__DOT__x___05Fh8075 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh7874) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh7875));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d324 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8076) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8075));
    vlTOPp->mkMACint32__DOT__y___05Fh8029 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8075) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8076));
    vlTOPp->mkMACint32__DOT__x___05Fh8229 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8028) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8029));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d322 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8230) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8229));
    vlTOPp->mkMACint32__DOT__y___05Fh8183 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8229) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8230));
    vlTOPp->mkMACint32__DOT__x___05Fh8383 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8182) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8183));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d320 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8384) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8383));
    vlTOPp->mkMACint32__DOT__y___05Fh8337 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8383) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8384));
    vlTOPp->mkMACint32__DOT__x___05Fh8537 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8336) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8337));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d318 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8538) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8537));
    vlTOPp->mkMACint32__DOT__y___05Fh8491 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8537) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8538));
    vlTOPp->mkMACint32__DOT__x___05Fh8691 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8490) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8491));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d316 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8692) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8691));
    vlTOPp->mkMACint32__DOT__y___05Fh8645 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8691) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8692));
    vlTOPp->mkMACint32__DOT__x___05Fh8845 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8644) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8645));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d314 
        = ((IData)(vlTOPp->mkMACint32__DOT__y___05Fh8846) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__x___05Fh8845));
    vlTOPp->mkMACint32__DOT__y___05Fh8799 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8845) 
                                             & (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8846));
    vlTOPp->mkMACint32__DOT__y___05Fh3394 = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh8798) 
                                             | (IData)(vlTOPp->mkMACint32__DOT__y___05Fh8799));
    vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d312 
        = ((IData)(vlTOPp->mkMACint32__DOT__x___05Fh3393) 
           ^ (IData)(vlTOPp->mkMACint32__DOT__y___05Fh3394));
    vlTOPp->mkMACint32__DOT__product___05F_1___05Fh2527 
        = ((IData)(1U) + ((0x80000000U & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d312)) 
                                          << 0x1fU)) 
                          | ((0x40000000U & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d314)) 
                                             << 0x1eU)) 
                             | ((0x20000000U & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d316)) 
                                                << 0x1dU)) 
                                | ((0x10000000U & (
                                                   (~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d318)) 
                                                   << 0x1cU)) 
                                   | ((0x8000000U & 
                                       ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d320)) 
                                        << 0x1bU)) 
                                      | ((0x4000000U 
                                          & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d322)) 
                                             << 0x1aU)) 
                                         | ((0x2000000U 
                                             & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d324)) 
                                                << 0x19U)) 
                                            | ((0x1000000U 
                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d326)) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d328)) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d330)) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d332)) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d334)) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d336)) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d338)) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d340)) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d342)) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d344)) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d346)) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d348)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d350)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d352)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d354)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d356)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d358)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d360)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d362)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d364)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d366)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d368)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d370)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d372)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d374)))))))))))))))))))))))))))))))))));
    vlTOPp->mkMACint32__DOT__product___05Fh2314 = (
                                                   ((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d312) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d314) 
                                                       << 0x1eU) 
                                                      | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d316) 
                                                          << 0x1dU) 
                                                         | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d318) 
                                                             << 0x1cU) 
                                                            | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d320) 
                                                                << 0x1bU) 
                                                               | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d322) 
                                                                   << 0x1aU) 
                                                                  | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d324) 
                                                                      << 0x19U) 
                                                                     | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d326) 
                                                                         << 0x18U) 
                                                                        | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d328) 
                                                                            << 0x17U) 
                                                                           | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d330) 
                                                                               << 0x16U) 
                                                                              | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d332) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d334) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d336) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d338) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d340) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d342) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d344) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d346) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d348) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d350) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d352) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d354) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d356) 
                                                                                << 9U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d358) 
                                                                                << 8U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d360) 
                                                                                << 7U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d362) 
                                                                                << 6U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d364) 
                                                                                << 5U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d366) 
                                                                                << 4U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d368) 
                                                                                << 3U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d370) 
                                                                                << 2U) 
                                                                                | (((IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d372) 
                                                                                << 1U) 
                                                                                | (IData)(vlTOPp->mkMACint32__DOT__IF_stage1_fifo_rv_port0___05Fread___05F8_BIT_104_6_THE_ETC___05F_d374))))))))))))))))))))))))))))))));
    vlTOPp->mkMACint32__DOT__x___05Fh2489 = ((1U & 
                                              vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U])
                                              ? vlTOPp->mkMACint32__DOT__product___05F_1___05Fh2527
                                              : vlTOPp->mkMACint32__DOT__product___05Fh2314);
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[0U] 
        = (IData)((((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh2489)) 
                    << 0x20U) | (QData)((IData)(((vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U] 
                                                  << 0x1fU) 
                                                 | (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U] 
                                                    >> 1U))))));
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[1U] 
        = (IData)(((((QData)((IData)(vlTOPp->mkMACint32__DOT__x___05Fh2489)) 
                     << 0x20U) | (QData)((IData)(((
                                                   vlTOPp->mkMACint32__DOT__stage1_fifo_rv[3U] 
                                                   << 0x1fU) 
                                                  | (vlTOPp->mkMACint32__DOT__stage1_fifo_rv[2U] 
                                                     >> 1U))))) 
                   >> 0x20U));
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[2U] = 1U;
    if (vlTOPp->mkMACint32__DOT__CAN_FIRE_RL_r1_pipe_stage2) {
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fwrite_1[2U];
    } else {
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port1___05Fread[2U];
    }
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[0U] 
        = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[1U] 
        = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__adder_ififo_rv_D_IN[2U] 
        = vlTOPp->mkMACint32__DOT__adder_ififo_rv_port2___05Fread[2U];
}

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->EN_start) {
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[0U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[1U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[2U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fwrite_1[3U];
    } else {
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[0U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[0U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[1U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[1U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[2U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[2U];
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[3U] 
            = vlTOPp->mkMACint32__DOT__inp_fifo_rv_port1___05Fread[3U];
    }
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[0U] = 
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[0U];
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[1U] = 
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[1U];
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[2U] = 
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[2U];
    vlTOPp->mkMACint32__DOT__inp_fifo_rv_D_IN[3U] = 
        vlTOPp->mkMACint32__DOT__inp_fifo_rv_port2___05Fread[3U];
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
    if (VL_UNLIKELY((EN_start & 0xfeU))) {
        Verilated::overWidthError("EN_start");}
}
#endif  // VL_DEBUG
