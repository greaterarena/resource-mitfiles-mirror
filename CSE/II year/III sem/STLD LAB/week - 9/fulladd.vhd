library ieee;
use ieee.std_logic_1164.all;

ENTITY fulladd IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 s,c: OUT std_logic);
END fulladd;

ARCHITECTURE arch_4fa1 OF fulladd IS
	Signal x: std_logic_vector(7 downto 0);
	component dec38case
		PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		x: OUT std_logic_vector(7 downto 0));
 	end component;
	begin
	stage0: dec38case port map(v,e,x);
	s<= x(2) or x(4) or x(1) or x(7);
	c<= x(7) or x(5) or x(3) or x(6);
	END arch_4fa1;


