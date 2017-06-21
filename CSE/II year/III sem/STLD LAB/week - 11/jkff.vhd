library ieee;
use ieee.std_logic_1164.all;
entity jkff is
port(j,k,clock,reset:IN std_logic;
	 q: out std_logic);
end jkff;
architecture arch_tff of jkff is
signal q_calc: std_logic;
signal q_next: std_logic;
begin 
process(clk,j,k)
	begin
		if reset='0' then
		q <='0';
		if (clock'EVENT and clock='1') then
			if(j = '0' and k = '0') then
				q<=q;
				qn<=qn;
			elsif(
			
		
		else
		q_next <= q_calc;
		end if;
	end process;
q <= q_next;
end arch_tff;
