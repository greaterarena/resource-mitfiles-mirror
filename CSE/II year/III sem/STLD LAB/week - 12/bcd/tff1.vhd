library ieee;
use ieee.std_logic_1164.all;

entity tff1 is
port(t,clock,reset:IN std_logic;
	 q:BUFFER std_logic);
end tff1;

architecture am of tff1 is
begin
process
	begin
	wait until clock'event and clock='0';
	if reset='0' then q <= '0';
	else
		if t='0' then q <= q;
		else q <= not q;
		end if;
	end if;
end process;
end am;
