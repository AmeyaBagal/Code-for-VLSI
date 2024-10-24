/**********************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Unpipelined carry save multiplier for int8
***********************************************/

package MultInt8

    import DReg :: *;

    // typedef Bit#(32) MultResult deriving(Bits, Eq);

    typedef struct{
        Bit#(1)  carry;
        Bit#(32) sum;
    } CSAresult deriving(Bits, Eq);

    interface CSM_ifc;
        method Action start(Bit#(8) a, Bit#(8) b)
        method MultResult get_result();
    endinterface : CSM_ifc

    (*synthesize*)
    module mkMultInt8 (CSM_ifc);

        Reg#(Bit#(8)) rg_inp1      <- mkReg(0);
        Reg#(Bit#(8)) rg_inp2      <- mkReg(0);
        Reg#(Bool)    rg_inp_valid <- mkDReg(False);

        Reg#(Bit#(32))  rg_out       <- mkReg(0);
        Reg#(Bool)      rg_out_valid <- mkDReg(False);

        function CSAresult carry_save_adder (
            Bit#(32) a,
            Bit#(32) b,
            Bit#(32) cin
        );
            Bit#(32) sum;
            Bit#(32) cout;
            CSAresult result;

            sum = a ^ b ^ cin;
            cout = (a & b) | (b & cin) | (cin & a);
            cout = cout << 1;

            result.sum = sum;
            result.carry = cout;

            return result;
        endfunction : carry_save_adder

        function Bit#(32) negate (Bit#(32) x);
            return ~x + 1;
        endfunction : negate

        function Bit#(32) carry_save_mult (
            Bit#(8)  a;
            Bit#(8)  b;
        );
            Bit#(32) product = 0;
            Bit#(32) sum = 0;
            Bit#(1)  sign = 0;

            if (a[7] == 1'b1) begin
                a    = negate(a);  
                sign = ~sign;      
            end
            if (b[7] == 1'b1) begin
                b    = negate(b);  
                sign = ~sign;     
            end

            for(Integer i = 0; i < 8; i = i + 1) begin
                if(b[i] == 1'b1) begin
                    Bit#(32) shift_a = a << 1;
                    CSAresult csa_result;

                    csa_result = carry_save_adder(shift_a, carry, product);

                    product = csa_result.sum;
                    carry = csa_result.carry;
                end
            end

            product = product + carry;

            if(sign = 1'b1) begin
                product = negate(product);
            end

            return product
        endfunction : carry_save_mult

        rule r1_csm (rg_inp_valid);
            rg_out       <= carry_save_mult(rg_inp1, rg_inp2);
            rg_out_valid <= True;
        endrule : r1_csm

        method Action start (Bit#(8) a, Bit#(8) b);
            rg_inp1      <= a;
            rg_inp2      <= b;
            rg_inp_valid <= True;
        endmethod : start  

        method Bit#(32) get_result() if(rg_out_valid);
            return rg_out;
        endmethod : get_result
    endmodule : mkMultInt8

endpackage : MultInt8            