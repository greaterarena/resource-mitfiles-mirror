library ieee;
use ieee.std_logic_1164.all;

ENTITY fa41 IS
	PORT(x,y: IN std_logic_vector(3 downto 0);
		s: OUT std_logic_vector(3 downto 0);
		cin: IN std_logic;
		cout:OUT std_logic);
END fa41;

ARCHITECTURE arch_4fa1 OF fa41 IS
	Signal c:std_logic_vector(2 downto 0);
	component fulladd
		port(cin,x,y: IN std_logic;
			 s, cout: OUT std_logic);
	end component;
	BEGIN
	stage0: fulladd port map(cin,x(0),y(0),s(0),c(0));
	stage1: fulladd port map(c(0),x(1),y(1),s(1),c(1));
	stae2: fulladd port map(c(1),x(2),y(2),s(2),c(2));
	stage3: fulladd port map(c(2),x(3),y(3),s(3),cout);
	END arch_4fa1;
