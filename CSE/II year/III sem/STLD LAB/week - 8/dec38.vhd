library ieee;
use ieee.std_logic_1164.all;

ENTITY dec38 IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		x: OUT std_logic_vector(7 downto 0));
END dec38;

ARCHITECTURE arch_4fa1 OF dec38 IS
	Signal s: std_logic_vector(3 downto 0);	
	begin 
	s <= e & v;
	with s select
		x<= "01111111" when "1000",
			"10111111" when "1001",
			"11011111" when "1010",
			"11101111" when "1011",
			"11110111" when "1100",
			"11111011" when "1101",
			"11111101" when "1110",
			"11111110" when "1111",
			"11111111" when others;
	END arch_4fa1;



