library ieee;
use ieee.std_logic_1164.all;

ENTITY f1 IS
	PORT(v: IN std_logic_vector(3 downto 0);
		x:OUT std_logic);
END f1;

ARCHITECTURE arch_4fa1 OF f1 IS
	Signal m:std_logic_vector(1 downto 0);
	begin
	m(1) <= v(3);
	m(0) <= v(2);
	process (v,m)
		begin
		if m="00" then
			x<=v(0);
		elsif m="01" then
			x<= v(1) XOR v(0);
		elsif m="10" then
			x<=v(0);
		else
			x<='0';
		end if;
	end process;
	END arch_4fa1;


