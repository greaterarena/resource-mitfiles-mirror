library ieee;
use ieee.std_logic_1164.all;

ENTITY mux4_1select IS
	PORT(w: IN std_logic_vector(0 to 3);
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
END mux4_1select;

ARCHITECTURE arch_4fa1 OF mux4_1select IS
	begin
		with s select
			x<= w(0) when "00",
			 	w(1) when "01",
				w(2) when "10",
				w(3) when others;
	END arch_4fa1;

