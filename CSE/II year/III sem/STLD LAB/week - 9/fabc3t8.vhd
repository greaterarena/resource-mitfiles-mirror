library ieee;
use ieee.std_logic_1164.all;

ENTITY fabc3t8 IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 r: OUT std_logic);
END fabc3t8;

ARCHITECTURE arch_4fa1 OF fabc3t8 IS
	Signal x: std_logic_vector(0 to 7);
	Signal s: std_logic_vector(3 downto 0);
	begin 
	s <= e & v;
	with s select
		x<= "10000000" when "1000",
			"01000000" when "1001",
			"00100000" when "1010",
			"00010000" when "1011",
			"00001000" when "1100",
			"00000100" when "1101",
			"00000010" when "1110",
			"00000001" when "1111",
			"00000000" when others;
	r<= x(0) OR x(2) OR x(3) OR x(4) OR x(5) OR x(7);
	END arch_4fa1;




