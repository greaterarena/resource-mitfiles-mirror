library ieee;
use ieee.std_logic_1164.all;

entity mux4 is
port(s:IN std_logic_vector(1 downto 0);
	 w:IN std_logic_vector(3 downto 0);
	 y:OUT std_logic);
end mux4;

architecture am of mux4 is
begin
process(s,w)
	begin
	if s="00" then y<=w(0);
	elsif s="01" then y<=w(1);
	elsif s="10" then y<=w(2);
	else y<=w(3);
	end if;
end process;
end am;
