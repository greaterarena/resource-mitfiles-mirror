library ieee;
use ieee.std_logic_1164.all;

entity tf2 is 
port(t,clock: in std_logic;
	 q: buffer std_logic);
end tf2;

architecture behaviour of tf2 is

begin
	process(clock)
	begin		
		if clock'event and clock = '0' then
		   if t = '1' then
   			q<=not q;
			else 
			q<=q;
		end if;
		end if;
	end process;		
end behaviour;


