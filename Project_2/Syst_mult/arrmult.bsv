/**********************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Cell module using the MAC unit
***********************************************/

package arrmult;

import syst_cell::*;
import Vector::*;
import DReg::*;

interface ArrMultifc;
    method Action startP(Vector#(4, Bit#(16)) a, Vector#(4, Bit#(16)) b, Bit#(1) s);
    method Vector#(4, Bit#(32)) get_ans();
    method Bool outp_start();
endinterface : ArrMultifc

(* synthesize *)
module mkArrMult (ArrMultifc);

    Vector#(4, Vector#(4, CellIfc)) unit <- replicateM(replicateM(mkCell));

    Reg#(Vector#(4, Bit#(16))) regA <- mkReg(replicate(16'b0));
    Reg#(Vector#(4, Bit#(16))) regB <- mkReg(replicate(16'b0));
    Reg#(Vector#(4, Bit#(32))) regC <- mkReg(replicate(32'b0));
    Reg#(Bit#(1))  regS <- mkReg(0);

    Reg#(Bit#(4)) b_filled <- mkReg(0);
    Reg#(Bool)    job_done <- mkReg(False);
    Reg#(Bool)    what_to_do <- mkDReg(False);

    Vector#(4, Vector#(4, Reg#(Bit#(16)))) buffA <- replicateM(replicateM(mkReg(0)));
    Vector#(4, Vector#(4, Reg#(Bit#(16)))) buffB <- replicateM(replicateM(mkReg(0)));
    Vector#(4, Vector#(4, Reg#(Bit#(32)))) buffC <- replicateM(replicateM(mkReg(0)));
    
    rule outval (!what_to_do);
        for (Integer i = 0; i < 4; i = i + 1) begin
            for (Integer j = 0; j < 4; j = j + 1) begin
            	buffA[i][j] <= unit[i][j].getA();
            	buffB[i][j] <= unit[i][j].getB();
            	buffC[i][j] <= unit[i][j].getC();
            end
        end

        what_to_do <= True;
    endrule : outval
    

    rule inval (what_to_do);
        for (Integer i = 0; i < 4; i = i + 1) begin
            for (Integer j = 0; j < 4; j = j + 1) begin
                if (j > 0) begin
                    unit[i][j].putA(buffA[i][j-1]);
                end
                if (i > 0) begin
                    unit[i][j].putC(buffC[i-1][j]);
                    if(b_filled < 4) begin
                        unit[i][j].putB(buffB[i-1][j]);
                    end
                    else begin
                        unit[i][j].putB(buffB[i][j]);
                    end
                end
                if(i==0 && b_filled >= 4) unit[i][j].putB(buffB[i][j]);
            end
        end
    endrule : inval

    method Action startP(Vector#(4, Bit#(16)) a, Vector#(4, Bit#(16)) b, Bit#(1) s);
        regA <= a;
        regB <= b;
        regS <= s;
        for (Integer i = 0; i < 4; i = i + 1) begin
            for (Integer j = 0; j < 4; j = j + 1) begin
                unit[i][j].putS(regS);
                if (i==0 && b_filled < 4) begin
                    unit[i][j].putB(regB[j]);
                    unit[i][j].putC(32'b0);
                end
                else if (i==0 && b_filled >= 4) begin
                    unit[i][j].putC(32'b0);
                end
                if (j == 0) begin
                    unit[i][j].putA(regA[i]);
                end
            end
        end

        b_filled <= b_filled + 1;
    endmethod : startP

    method Vector#(4, Bit#(32)) get_ans();
    	Vector#(4, Bit#(32)) ans;
    	for (Integer i = 0; i < 4; i = i + 1) begin
			ans[i] = unit[3][i].getC();
    	end
        return ans;
    endmethod : get_ans

    method Bool outp_start if (b_filled > 7);
        return True;
    endmethod : outp_start

endmodule : mkArrMult

endpackage : arrmult
