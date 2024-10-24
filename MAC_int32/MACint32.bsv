/**********************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Unpipelined carry save multiplier for int8
***********************************************/

package MACint32

    import DReg :: *;

    typedef struct{
        Bit#(32) carry;
        Bit#(32) sum;
    } CSAresult deriving(Bits, Eq);

    typedef struct{
        Bit#(1)  overflow;
        Bit#(32) sum;
    } AdderResult deriving(Bits, Eq);

    interface MACint_ifc
        method Action start(Bit#(8) a, Bit#(8) b, Bit#(32) c)
        method AdderResult get_result();
    endinterface : MACint_ifc

    (*synthesize*)
    module mkMACint32 (MACint_ifc);
        Reg#(Bit#(8))  rg_inp1      <- mkReg(0);
        Reg#(Bit#(8))  rg_inp2      <- mkReg(0);
        Reg#(Bit#(32)) rg_inp3      <- mkReg(0);
        Reg#(Bool)     rg_inp_valid <- mkDReg(False);

        Reg#(Bit#(32))  rg_out       <- mkReg(0);
        Reg#(Bool)         rg_out_valid <- mkDReg(False);

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
            Bit#(32) carry = 0;
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
                    Bit#(32) shift_a = a << i;
                    CSAresult csa_result;

                    csa_result = carry_save_adder(shift_a, carry, product);

                    product = csa_result.sum;
                    carry = csa_result.carry;
                end
            end

            AdderResult final = ripple_carry_addition(product, carry, 1'b0);
            product = final.sum;

            if(sign = 1'b1) begin
                product = negate(product);
            end

            return product;
        endfunction : carry_save_mult

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

        rule r1_mac (rg_inp_valid);
            Bit#(32) mult = carry_save_mult(rg_inp1, rg_inp2);

            AdderResult acc = ripple_carry_addition(mult, rg_inp3, 1'b0);

            rg_out       <= acc.sum;
            rg_out_valid <= True;
        endrule : r1_mac

        method Action start (Bit#(8) a, Bit#(8) b, Bit#(32) c);
            rg_inp1      <= a;
            rg_inp2      <= b;
            rg_inp3      <= c;
            rg_inp_valid <= True;
        endmethod : start

        method Bit#(32) get_result() if(rg_out_valid);
            return rg_out;
        endmethod : get_result

    endmodule : mkMACint32
endpackage : MACint32


