library ieee;
use ieee.std_logic_1164.all;

ENTITY dec38case IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 x: OUT std_logic_vector(7 downto 0));
END dec38case;

ARCHITECTURE arch_4fa1 OF dec38case IS
	Signal s: std_logic_vector(3 downto 0);	
	begin 
	s <= e & v;
	process(s)
		begin
		   case s is
			when "1000" =>
			x<="00000001";
		when "1001" =>
			x<="00000010";
		when "1010" =>
			x<="00000100";
		when "1011" =>
			x<="00001000";
		when "1100" =>
			x<="00010000";
		when "1101" =>
			x<="00100000";
		when "1110" =>
			x<="01000000";
		when "1111" =>
			x<="10000000";
		when others =>
			x<="00000000";
		end case;
	end process;	
	END arch_4fa1;


