library ieee;
use ieee.std_logic_1164.all;

ENTITY f4 IS
	PORT(v: IN std_logic_vector(2 downto 0);
		x:OUT std_logic);
END f4;

ARCHITECTURE arch_4fa1 OF f4 IS
	Signal m:std_logic_vector(1 downto 0);
	begin
	m(1) <= v(2);
	m(0) <= v(1);
	process (v,m)
		begin
		if m="00" then
			x<='1';
		elsif m="01" then
			x<= '0';
		elsif m="10" then
			x<=not v(0);
		else
			x<= v(0);
		end if;
	end process;
	END arch_4fa1;
