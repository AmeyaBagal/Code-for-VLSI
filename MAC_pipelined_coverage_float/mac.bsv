/**********************************************
 * Authors: Ameya Bagal, Balabhadra Saketh
 * Descr  : Pipelined Top module for Project 1
***********************************************/

package mac;

import DReg :: *;
import FIFO::*;
import SpecialFIFOs::*;

typedef struct{
        Bit#(32) carry;
        Bit#(32) sum;
    } CSAresult deriving(Bits, Eq);

typedef struct{
        Bit#(1)  overflow;
        Bit#(32) sum;
    } AdderResult deriving(Bits, Eq);
    
typedef struct{
        Bit#(16) a;
        Bit#(16) b;
        Bit#(32) c;
    } MACinput deriving(Bits, Eq);
    
typedef struct{
        Bit#(32) val1;
        Bit#(32) val2;
    } AdderInp deriving(Bits, Eq);


interface TopMAC_ifc;
    method Action start(Bit#(16) a, Bit#(16) b, Bit#(32) c, Bit#(1) s);
    method Bit#(32) get_result();
endinterface : TopMAC_ifc
    
(* synthesize *)
module mkTopMAC (TopMAC_ifc);
	FIFO#(MACinput)      inp_fifo <- mkPipelineFIFO();
    FIFO#(AdderInp)    stage1_fifo <- mkPipelineFIFO(); 

    Reg#(Bit#(32))  rg_out       <- mkReg(0);
    Reg#(Bool)      rg_out_valid <- mkDReg(False);
    Reg#(Bit#(1))   rg_s         <- mkReg(0);
    
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
    
    function Bit#(32) carry_save_multint(
        Bit#(8)  a8,
        Bit#(8)  b8
    );
    	Bit#(32) a = signExtend(a8);
    	Bit#(32) b = signExtend(b8);
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

        AdderResult fin = ripple_carry_addition(product, carry, 1'b0);
        product = fin.sum;

        if(sign == 1'b1) begin
            product = negate(product);
        end

        return product;
    endfunction : carry_save_multint
    
    function Bit#(32) carry_save_mult (
        Bit#(16)  a,
        Bit#(16)  b
    );
        Bit#(1) sign_a = a[15];
        Bit#(8) exp_a = a[14:7];
        Bit#(8) mant_a = {1'b1, a[6:0]};
            
        Bit#(1) sign_b = b[15];
    	Bit#(8) exp_b = b[14:7];
        Bit#(8) mant_b = {1'b1, b[6:0]};
            
        Bit#(32) product = 0;
        Bit#(32) carry = 0;
        Bit#(1) prod_sign = sign_a ^ sign_b;
        for(Integer i = 0; i < 8; i = i + 1) begin
            if(mant_b[i] == 1'b1) begin
                Bit#(32) partial_product = {24'b0, mant_a} << i;
                CSAresult csa_result;

                csa_result = carry_save_adder(partial_product, carry, product);

                product = csa_result.sum;
                carry = csa_result.carry;
            end
        end

        AdderResult fin = ripple_carry_addition(product, carry, 1'b0);
        product = fin.sum;
            
	    Bit#(32) fraction = 32'b0;  
	    Bit#(23) prod_mant = 23'b0;
	    Bit#(1) round_carry = 1'b0;
        if(product[15] == 1) begin 
      		fraction = zeroExtend(product[14:8]);
      			if (product[7] == 1 && product[8:0] != 9'b010000000) begin
	        		AdderResult ripple1 = ripple_carry_addition(fraction, 32'b1, 1'b0);
	         		fraction = ripple1.sum;
	      		end
	    end
	  
	    else if(product[15] == 0) begin
	      fraction = zeroExtend(product[14:7]); 	
	      if (product[6] == 1 && product[7:0] != 8'b01000000) begin
	      	AdderResult ripple2 = ripple_carry_addition(fraction, 32'b1, 1'b0);
	        fraction = ripple2.sum;
	        if(fraction[8] == 1) begin
		   		AdderResult ripple3 = ripple_carry_addition((fraction>>1), {31'b0, fraction[0]}, 1'b0);
		   		fraction = ripple3.sum;
		   		round_carry = 1'b1;
	        end
	      end
	    end
	    prod_mant = {fraction[6:0], 16'b0};
	  
	  	Bit#(8) prod_exp = 8'b0;
	  	Bit#(32) bias = 32'b0;
	  
	  	if((product[15] == 1)||(round_carry == 1)) bias = 126;
	  	else if(product[15] == 0) bias = 127;
	  
	  	AdderResult ripple4 = ripple_carry_addition({24'b0, exp_a}, {24'b0, exp_b}, 1'b0);
	  	Bit#(32) intermediate = ripple4.sum;
	  	AdderResult ripple5 = ripple_carry_addition(intermediate, ~bias, 1'b1);
	  	prod_exp = ripple5.sum[7:0];
	  	Bit#(32) result = {prod_sign,prod_exp,prod_mant};
	  	return result; 
            
    endfunction : carry_save_mult
        
    function Bit#(32) f32_sum(Bit#(32) a, Bit#(32) b);
	  Bit#(1) sign_a = a[31];
	  Bit#(32) exp_a = zeroExtend(a[30:23]);
	  
	  Bit#(32) mant_a = zeroExtend(a[22:0]);
	  mant_a[23]=1;

	  Bit#(1) sign_b = b[31];
	  Bit#(32) exp_b = zeroExtend(b[30:23]);
	  
	  Bit#(32) mant_b = zeroExtend(b[22:0]);
	  mant_b[23]=1;

	  Bit#(32) exp_diff = 32'b0;
	  Bit#(32) mant_a_adj = 32'b0;
	  Bit#(32) mant_b_adj = 32'b0;
	  Bit#(32) sum_exp = 32'b0;
	  Bit#(32) mant_sum = 32'b0;
	  Bit#(1) sum_sign = 1'b0;
	  Bit#(32) mant_mid = 32'b0;
	  Bit#(32) sum_mant = 32'b0;
	  Bit#(32) bitmask = 32'b1;
	  
	  
	  if (exp_a > exp_b) begin
	    AdderResult ripple9 = ripple_carry_addition(exp_a, ~exp_b, 1'b1);
	    exp_diff = ripple9.sum;
	    mant_a_adj = mant_a;
	    AdderResult ripple10 = ripple_carry_addition(exp_diff, ~bitmask, 1'b1);
	    Bit#(32) exp_diff_sub = ripple10.sum;
	    AdderResult ripple11 = ripple_carry_addition(bitmask << exp_diff_sub, ~bitmask, 1'b1);
	    bitmask = ripple11.sum;
	    if(mant_b[exp_diff] == 0 && (bitmask & mant_b)==0) begin
	      mant_b_adj = mant_b >> exp_diff; 
	    end
	    else begin
	      AdderResult ripple12 = ripple_carry_addition(mant_b >> exp_diff, {31'b0,mant_b[exp_diff_sub]}, 1'b0);
	      mant_b_adj = ripple12.sum;
	    end
	    sum_exp = exp_a;
	  end 
	  else begin
	    AdderResult ripple13 = ripple_carry_addition(exp_b, ~exp_a, 1'b1);
	    exp_diff = ripple13.sum;
	    mant_b_adj = mant_b;
	    AdderResult ripple14 = ripple_carry_addition(exp_diff, ~bitmask, 1'b1);
	    Bit#(32) exp_diff_sub = ripple14.sum; 
	    AdderResult ripple15 = ripple_carry_addition(bitmask << exp_diff_sub, ~bitmask, 1'b1);
	    bitmask = ripple15.sum;  
	    if(mant_a[exp_diff] != 0 && (bitmask & mant_a)==0) begin
	      mant_a_adj = mant_a >> exp_diff; 
	    end
	    else begin
	      AdderResult ripple16 = ripple_carry_addition(mant_a >> exp_diff, {31'b0,mant_a[exp_diff_sub]}, 1'b0);
	      mant_a_adj = ripple16.sum;
	    end
	    sum_exp = exp_b;
	  end
	  AdderResult ripple17 = ripple_carry_addition(mant_a_adj, 32'b1, 1'b1);
	  Bit#(32) mant_a_adj_ = ripple17.sum;
	  AdderResult ripple18 = ripple_carry_addition(mant_b_adj, 32'b1, 1'b1);
	  Bit#(32) mant_b_adj_ = ripple18.sum;
	  if (sign_a == sign_b) begin
	    AdderResult ripple19 = ripple_carry_addition(mant_a_adj, mant_b_adj, 1'b0);
	    mant_sum = ripple19.sum;
	    sum_sign = sign_a;
	  end 
	  else begin
	    if (mant_a_adj >= mant_b_adj) begin
	      AdderResult ripple20 = ripple_carry_addition(mant_a_adj, ~mant_b_adj, 1'b1);
	      mant_sum = ripple20.sum;
	      sum_sign = sign_a;
	    end
	    else begin
	      AdderResult ripple21 = ripple_carry_addition(mant_b_adj, ~mant_a_adj, 1'b1);
	      mant_sum = ripple21.sum;
	      sum_sign = sign_b;
	    end
	  end

	  
	  if (mant_sum[24]==1) begin  
	    mant_mid = zeroExtend(mant_sum[23:1]);
	    if(mant_sum[1] != 0) begin
	      AdderResult ripple22 = ripple_carry_addition(mant_mid, {31'b0,mant_sum[0]}, 1'b0);
	      sum_mant = ripple22.sum;
	    end
	    else begin
	      sum_mant = mant_mid;
	    end
	    AdderResult ripple23 = ripple_carry_addition(sum_exp, 32'b1, 1'b0);
	    sum_exp = ripple23.sum;
	    if (sum_mant[23] ==1) begin 
	        AdderResult ripple24 = ripple_carry_addition(sum_exp, 32'b1, 1'b0);
	        sum_exp = ripple24.sum;
	    end
	  end 
	  else begin
	    sum_mant = zeroExtend(mant_sum[22:0]);
	  end

	  
	  return {sum_sign, sum_exp[7:0], sum_mant[22:0]};
	endfunction: f32_sum
	
	rule r1_stage1;
		MACinput inp_stage1 = inp_fifo.first();
		Bit#(16) rg_a = inp_stage1.a;
		Bit#(16) rg_b = inp_stage1.b;
		if (rg_s == 1'b0) begin
			Bit#(32) mult1 = carry_save_multint(rg_a[7:0], rg_b[7:0]);
			
			AdderInp out_stage1_int;
			out_stage1_int.val1 = mult1;
			out_stage1_int.val2 = inp_stage1.c;
			
			inp_fifo.deq();
			stage1_fifo.enq(out_stage1_int);
		end
		else begin
			Bit#(32) mult2 = carry_save_mult(rg_a, rg_b);
			
			AdderInp out_stage1_fp;
			out_stage1_fp.val1 = mult2;
			out_stage1_fp.val2 = inp_stage1.c;
			
			inp_fifo.deq();
			stage1_fifo.enq(out_stage1_fp);
			
		end
	endrule : r1_stage1
	
	rule r1_stage2;
		AdderInp inp_stage2 = stage1_fifo.first();
		Bit#(32) product = inp_stage2.val1;
		Bit#(32) rg_c = inp_stage2.val2;
		
		if (rg_s == 1'b0) begin
			AdderResult acc1 = ripple_carry_addition(product, rg_c, 1'b0);
			
			rg_out <= acc1.sum;
			rg_out_valid <= True;
			
			stage1_fifo.deq();
		end
		else begin
			Bit#(32) acc2 = f32_sum(product,rg_c);
			
			rg_out <= acc2;
			rg_out_valid <= True;
			
			stage1_fifo.deq();
		end
	endrule : r1_stage2
	
	method Action start (Bit#(16) a, Bit#(16) b, Bit#(32) c, Bit#(1) s);
        MACinput inp;
        inp.a = a;
        inp.b = b;
        inp.c = c;
        
        rg_s <= s;
        
        inp_fifo.enq(inp);
    endmethod : start

   method Bit#(32) get_result() if(rg_out_valid);
        return rg_out;
   endmethod : get_result
   
endmodule : mkTopMAC

endpackage : mac
