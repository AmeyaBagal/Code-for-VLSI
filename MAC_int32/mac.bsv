/**********************************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Pipelined MAC unit for int32 operation
 **********************************************************/

package MACint32;

import FIFO::*;
import DReg :: *;
import SpecialFIFOs::*;

typedef struct {
  Bit#(32) val1;
  Bit#(32) val2;
} AdderInput deriving(Bits, Eq);

typedef struct {
    Bit#(32) val1;
    Bit#(32) val2;
    Bit#(33)  sum;
} AdderPipeStage deriving(Bits, Eq);

typedef struct {
    Bit#(1)  overflow;
    Bit#(32) sum;
} AdderResult deriving(Bits, Eq);

typedef struct {
    Bit#(32) sum;
    Bit#(32) carry;
} CSAresult deriving(Bits, Eq);

typedef struct {
    Bit#(32) a;
    Bit#(32) b;
    Bit#(32) c;
    Bit#(1)  sign;
} CSMinput deriving(Bits, Eq);

typedef struct {
    Bit#(32)  a;
    Bit#(32)  b;
    Bit#(32)  c;
    Bit#(1)   sign;
    CSAresult res;
} CSMpipeStage deriving(Bits, Eq);


interface MACint_ifc;
    method Action start(Bit#(8) a, Bit#(8) b, Bit#(32) c);
    method Bit#(32) get_result();
endinterface : MACint_ifc  

(*synthesize*)
module mkMACint32 (MACint_ifc);

    FIFO#(CSMinput)        inp_fifo <- mkPipelineFIFO();
    FIFO#(CSMpipeStage)    stage1_fifo <- mkPipelineFIFO();
    FIFO#(AdderInput)      adder_ififo <- mkPipelineFIFO();
    FIFO#(AdderPipeStage)  stage2_fifo <- mkPipelineFIFO();
    FIFO#(AdderPipeStage)  stage3_fifo <- mkPipelineFIFO();
    FIFO#(AdderPipeStage)  stage4_fifo <- mkPipelineFIFO();
    FIFO#(AdderResult)     adder_ofifo <- mkPipelineFIFO();
    
    Reg#(Bit#(32)) ans <- mkReg(0);
    Reg#(Bool)     rg_out_valid <- mkDReg(False);

    function AdderResult ripple_carry_addition (
        Bit#(32) a,
        Bit#(32) b,
        Bit#(1)  cin
    );
        Bit#(32) sum;
        Bit#(33) carry = '0;

        carry[0] = cin;

        for (Integer i = 0; i < 32; i = i + 1) begin
            sum  [i]   = (a[i] ^ b[i] ^ carry[i]);
            carry[i+1] = (a[i] & b[i]) | (carry[i] & (a[i] ^ b[i]));
        end

        AdderResult out;
        out.sum      = sum;
        out.overflow = carry[32];

        return out;

    endfunction : ripple_carry_addition

    function Bit#(9) rca_addition(Bit#(8) a, Bit#(8) b, Bit#(1) cin);
        Bit#(8) sum;
        Bit#(9) carry = 0;

    
        carry[0] = cin;

        for (int i = 0; i < 8;  i = i + 1) begin
            sum  [i] = (a[i] ^ b[i] ^ carry[i]);
            carry[i+1] = (a[i] & b[i]) | (carry[i] & (a[i] ^ b[i]));
        end

        Bit#(9) rca_result = {carry[8], sum};
        return rca_result;
    endfunction : rca_addition

    function CSAresult carry_save_adder(Bit#(32) a, Bit#(32) b, Bit#(32) cin);
        CSAresult result;
        result.sum = a ^ b ^ cin;
        result.carry = ((a & b) | (b & cin) | (cin & a)) << 1;
        return result;
    endfunction : carry_save_adder

    function Bit#(32) negate(Bit#(32) x);
        return ~x + 1;
    endfunction : negate

    rule r1_pipe_stage1;
        CSMinput  inp_stage1 = inp_fifo.first();
        Bit#(32)  a = inp_stage1.a;
        Bit#(32)  b = inp_stage1.b;
        CSAresult lsb_result;
        lsb_result.sum   = 32'b0;
        lsb_result.carry = 32'b0;

        for (Integer i = 0; i < 4; i = i + 1) begin
            if (b[i] == 1'b1) begin
                Bit#(32) shift_a = a << i;
                lsb_result = carry_save_adder(shift_a, lsb_result.carry, lsb_result.sum);
            end
        end

        CSMpipeStage out_stage1;
        out_stage1.a    = a;
        out_stage1.b    = b;
        out_stage1.c    = inp_stage1.c;
        out_stage1.sign = inp_stage1.sign;
        out_stage1.res  = lsb_result;

        inp_fifo.deq();
        stage1_fifo.enq(out_stage1);

    endrule : r1_pipe_stage1

    rule r1_pipe_stage2;
        CSMpipeStage inp_stage2 = stage1_fifo.first();
        Bit#(32)     a = inp_stage2.a;
        Bit#(32)     b = inp_stage2.b;
        CSAresult    stage_result = inp_stage2.res;
        Bit#(1)      sign = inp_stage2.sign;

        for (Integer i = 4; i < 8; i = i + 1) begin
            if (b[i] == 1'b1) begin
            Bit#(32) shift_a = a << i;
            stage_result = carry_save_adder(shift_a, stage_result.carry, stage_result.sum);
            end
        end
	
	AdderResult outp = ripple_carry_addition(stage_result.sum, stage_result.carry, 1'b0);
        Bit#(32)    product = outp.sum;

        if (sign == 1'b1) begin
            product = negate(product);
        end

        AdderInput out_stage2;
        out_stage2.val1 = product;
        out_stage2.val2 = inp_stage2.c;

        stage1_fifo.deq();
        adder_ififo.enq(out_stage2);

    endrule : r1_pipe_stage2

    rule r1_pipe_stage3;
        AdderInput inp_stage3 = adder_ififo.first();
        Bit#(8)    inp_val1 = inp_stage3.val1[7:0];
        Bit#(8)    inp_val2 = inp_stage3.val2[7:0];
        Bit#(1)    cin = 1'b0;
        Bit#(9)    psum1 = rca_addition(inp_val1, inp_val2, cin);

        AdderPipeStage out_stage3;
        out_stage3.val1 = inp_stage3.val1;
        out_stage3.val2 = inp_stage3.val2;
        out_stage3.sum  = zeroExtend(psum1);

        adder_ififo.deq();
        stage2_fifo.enq(out_stage3);
    endrule : r1_pipe_stage3

    rule r1_pipe_stage4;
        AdderPipeStage inp_stage4 = stage2_fifo.first();
        Bit#(8)        inp_val1 = inp_stage4.val1[15:8];
        Bit#(8)        inp_val2 = inp_stage4.val2[15:8];
        Bit#(9)        psum1 = inp_stage4.sum[8:0];
        Bit#(1)        cin = psum1[8];
        Bit#(9)        psum2 = rca_addition(inp_val1, inp_val2, cin);

        AdderPipeStage out_stage4;
        out_stage4.val1 = inp_stage4.val1;
        out_stage4.val2 = inp_stage4.val2;
        out_stage4.sum  = zeroExtend({psum2,psum1[7:0]});

        stage2_fifo.deq();
        stage3_fifo.enq(out_stage4);
    endrule : r1_pipe_stage4

    rule r1_pipe_stage5;
        AdderPipeStage inp_stage5 = stage3_fifo.first();
        Bit#(8)        inp_val1 = inp_stage5.val1[23:16];
        Bit#(8)        inp_val2 = inp_stage5.val2[23:16];
        Bit#(17)       psum1 = inp_stage5.sum[16:0];
        Bit#(1)        cin = psum1[16];
        Bit#(9)        psum2 = rca_addition(inp_val1, inp_val2, cin);

        AdderPipeStage out_stage5;
        out_stage5.val1 = inp_stage5.val1;
        out_stage5.val2 = inp_stage5.val2;
        out_stage5.sum  = zeroExtend({psum2,psum1[15:0]});

        stage3_fifo.deq();
        stage4_fifo.enq(out_stage5);
    endrule : r1_pipe_stage5

    rule r1_pipe_stage6;
        AdderPipeStage inp_stage6 = stage4_fifo.first();
        Bit#(8)        inp_val1 = inp_stage6.val1[31:24];
        Bit#(8)        inp_val2 = inp_stage6.val2[31:24];
        Bit#(25)       psum1 = inp_stage6.sum[24:0];
        Bit#(1)        cin = psum1[24];
        Bit#(9)        psum2 = rca_addition(inp_val1, inp_val2, cin);

        AdderResult out_stage6;
        out_stage6.overflow = psum2[8];
        out_stage6.sum = {psum2[7:0], psum1[23:0]};

        stage4_fifo.deq();
        adder_ofifo.enq(out_stage6);
    endrule : r1_pipe_stage6
    
    rule r1_fin;
    	AdderResult out = adder_ofifo.first();
    	ans <= out.sum;
    	rg_out_valid <= True;
    	
    	adder_ofifo.deq();
    endrule : r1_fin

    method Action start(Bit#(8) a, Bit#(8) b, Bit#(32) c);
        CSMinput inp;
        Bit#(32) a_ext = signExtend(a);
        Bit#(32) b_ext = signExtend(b);
        Bit#(1)  sign = 1'b0;

        if (a[7] == 1'b1) begin
            a_ext = negate(a_ext);
            sign = ~sign;
        end

        if (b[7] == 1'b1) begin
            b_ext = negate(b_ext);
            sign = ~sign;
        end

        inp.a    = a_ext;
        inp.b    = b_ext;
        inp.c    = c;
        inp.sign = sign;

        inp_fifo.enq(inp);
    endmethod : start

    method Bit#(32) get_result() if (rg_out_valid);
        return ans;
    endmethod : get_result

endmodule : mkMACint32

endpackage : MACint32
