library ieee;
use ieee.std_logic_1164.all;

ENTITY dec24 IS
	PORT(v: IN std_logic_vector(1 downto 0);
		 e: IN std_logic;
		 x: OUT std_logic_vector(3 downto 0));
END dec24;

ARCHITECTURE arch_4fa1 OF dec24 IS
	Signal s: std_logic_vector(2 downto 0);	
	begin 
	s <= e & v;
	process(s)
		begin
		   case s is
		when "100" =>
			x<="0001";
		when "101" =>
			x<="0010";
		when "110" =>
			x<="0100";
		when "111" =>
			x<="1000";
		when others =>
			x<="0000";
		end case;
	end process;	
	END arch_4fa1;



