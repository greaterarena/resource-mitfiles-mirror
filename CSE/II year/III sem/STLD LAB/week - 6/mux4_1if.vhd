library ieee;
use ieee.std_logic_1164.all;

ENTITY mux4_1if IS
	PORT(w: IN std_logic_vector(0 to 3);
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
END mux4_1if;

ARCHITECTURE arch_4fa1 OF mux4_1if IS
	begin
	process (w,s)
		begin
		if s="00" then
			x<=w(0);
		elsif s="01" then
			x<=w(1);
		elsif s="10" then
			x<=w(2);
		else
			x<=w(3);
		end if;
	end process;
	END arch_4fa1;


