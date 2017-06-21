library ieee;
use ieee.std_logic_1164.all;

ENTITY f1 IS
	PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 f1,f2,f3: OUT std_logic);
END f1;

ARCHITECTURE arch_4fa1 OF f1 IS
	Signal x: std_logic_vector(0 to 7);
	component dec38comp
		PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		x: OUT std_logic_vector(0 to 7));
 	end component;
	begin
	stage0: dec38comp port map(v,e,x);
	f1<= x(7) or x(2) or x(0);
	f2<= x(5) or x(4) or x(3);
	f3<= x(1) or x(0) or x(6);
	END arch_4fa1;
