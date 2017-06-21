library ieee;
use ieee.std_logic_1164.all;
entity dff is
port(d,clock,reset:IN std_logic;
	q: OUT std_logic);
end dff;
architecture arch_dff of dff is
begin 
	process(reset,clock)
	begin
		if reset='0' then
		q<='0';
		elsif clock'EVENT and clock='0' then
		q<=d;
		end if;
	end process;
end arch_dff;
	
