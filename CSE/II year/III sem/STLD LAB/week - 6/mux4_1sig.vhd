library ieee;
use ieee.std_logic_1164.all;

ENTITY mux4_1sig IS
	PORT(w0,w1,w2,w3: IN std_logic;
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
END mux4_1sig;

ARCHITECTURE arch_4fa1 OF mux4_1sig IS
	begin
	with s select
			x<= w0 when "00",
			 	w1 when "01",
				w2 when "10",
				w3 when others;
	END arch_4fa1;
