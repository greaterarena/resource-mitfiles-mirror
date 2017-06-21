library ieee;
use ieee.std_logic_1164.all;

ENTITY dec38comp IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 x: OUT std_logic_vector(7 downto 0));
END dec38comp;

ARCHITECTURE arch_4fa1 OF dec38comp IS
	Signal s: std_logic_vector(3 downto 0);	
	begin 
	s <= e & v;
	process(s)
		begin
		   if s="1000" then
			x<="00000001";
		elsif s="1001" then
			x<="00000010";
		elsif s="1010" then
			x<="00000100";
		elsif s="1011" then
			x<="00001000";
		elsif s="1100" then
			x<="00010000";
		elsif s="1101" then
			x<="00100000";
		elsif s="1110" then
			x<="01000000";
		elsif s="1111" then
			x<="10000000";
		else 
			x<="00000000";
		end if;
	end process;	
	END arch_4fa1;

