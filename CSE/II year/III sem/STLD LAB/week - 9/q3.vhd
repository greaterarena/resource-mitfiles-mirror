library ieee;
use ieee.std_logic_1164.all;

ENTITY q3 IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 f1,f2,f3: OUT std_logic);
END q3;

ARCHITECTURE arch_4fa1 OF q3 IS
	Signal x: std_logic_vector(7 downto 0);
	component dec38comp
		PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		x: OUT std_logic_vector(7 downto 0));
 	end component;
	begin
	stage0: dec38comp port map(v,e,x);
	f1<= x(2) or x(4) or x(7);
	f2<= x(0) or x(3);
	f3<= x(0) or x(2) or x(3) or x(4) or x(7);
	END arch_4fa1;

