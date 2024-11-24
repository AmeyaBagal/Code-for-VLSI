/**********************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Cell module using the MAC unit
***********************************************/

package syst_cell;

import mac::*;

interface CellIfc;
    method Action putA(Bit#(16) a);
    method Action putB(Bit#(16) b);
    method Action putC(Bit#(32) c);
    method Action putS(Bit#(1)  s);
    method Bit#(32) getC();
    method Bit#(16) getA();
    method Bit#(16) getB();
    method Bit#(1)  getS();
    method Bool     ans_ready();
endinterface : CellIfc

(* synthesize *)
module mkCell(CellIfc);

    // Instantiating the MAC module
    TopMAC_ifc mac <- mkTopMAC;

    // Registers for inputs A, B, C, and S
    Reg#(Bit#(16)) regA <- mkReg(0);
    Reg#(Bit#(16)) regB <- mkReg(0);
    Reg#(Bit#(32)) regC <- mkReg(0);
    Reg#(Bit#(1))  regS <- mkReg(0);

    // Register to store output
    Reg#(Bit#(32)) regResult <- mkReg(0);

    rule passInputsToMAC;
        mac.start(regA, regB, regC, regS);
    endrule : passInputsToMAC

    rule fetchMACResult (mac.get_result_ready);
        regResult <= mac.get_result();
    endrule : fetchMACResult

    method Action putA(Bit#(16) a);
        regA <= a;
    endmethod : putA

    method Action putB(Bit#(16) b);
        regB <= b;
    endmethod : putB

    method Action putC(Bit#(32) c);
        regC <= c;
    endmethod : putC

    method Action putS(Bit#(1) s);
        regS <= s;
    endmethod : putS

    method Bit#(32) getC() if (mac.get_result_ready);
        return regResult;
    endmethod : getC

    method Bit#(16) getA() if (mac.get_result_ready);
        return regA;
    endmethod : getA

    method Bit#(16) getB() if (mac.get_result_ready);
        return regB;
    endmethod : getB

    method Bit#(1) getS() if (mac.get_result_ready);
        return regS;
    endmethod : getS

    method Bool ans_ready() if (mac.get_result_ready);
        return mac.get_result_ready;
    endmethod : ans_ready



endmodule : mkCell

endpackage : syst_cell
