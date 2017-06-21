library ieee;
use ieee.std_logic_1164.all;
entity tff is
port(t,clock,reset:IN std_logic;
	 q: OUT std_logic);
end tff;
architecture arch_tff of tff is
signal q_calc: std_logic;
signal q_next: std_logic;
begin 
q_calc <= q_next when t = '0' else not(q_next);
	process
	begin
		wait until clock'EVENT and clock='0';
		if reset='0' then
		q_next <='0';
		else
		q_next <= q_calc;
		end if;
	end process;
q<=q_next;
end arch_tff;
