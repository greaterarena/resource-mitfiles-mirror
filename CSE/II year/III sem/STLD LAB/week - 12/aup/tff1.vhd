library ieee;
use ieee.std_logic_1164.all;
entity tff1 is
port(t,clock,reset:IN std_logic;
	q: BUFFER std_logic);
end tff1;
architecture arch_dff of tff1 is
begin 
	process(reset,clock)
	begin
		if reset='0' then
		q<='0';
		elsif clock'EVENT and clock='1' then
			if t='0' then q<=q;
			else q<=not q; 
			end if;
		end if;
	end process;
end arch_dff;
	
