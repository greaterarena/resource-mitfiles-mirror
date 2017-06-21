library ieee;
use ieee.std_logic_1164.all;
entity dffring is
port(d,start,clock,reset:IN std_logic;
	q: OUT std_logic);
end dffring;
architecture arch_dff of dffring is
begin 
	process(reset,clock)
	begin
		wait until clock'EVENT and clock='0';
		if start='0' then
		q<='1';
		elsif reset = '0' then
		q<='0';
		else
		q<=d;
		end if;
	end process;
end arch_dff;
