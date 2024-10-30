package Testbench;
import mac::*;
module mkTestbench (Empty);
TopMAC_ifc mac_inst <-mkTopMAC;
   rule rl_print_answer;
   	mac_inst.start(16'h0000,16'h0000,32'd0,1);
   endrule
   rule r2;
   	let z = mac_inst.get_result;
   	$display("MAC = %b",z);
   endrule
endmodule
endpackage
