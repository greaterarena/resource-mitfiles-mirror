library ieee;
use ieee.std_logic_1164.all;

ENTITY dec416 IS
	PORT(v: IN std_logic_vector(3 downto 0);
		 x: OUT std_logic_vector(15 downto 0));
END dec416;

ARCHITECTURE arch_4fa1 OF dec416 IS
		Signal s: std_logic;	
	component dec38
		PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 x: OUT std_logic_vector(7 downto 0));
 	end component;
	begin
	s<= not v(3);
	stage0: dec38 port map(v(2 downto 0),s,x(15 downto 8));
	stage1: dec38 port map(v(2 downto 0),v(3),x(7 downto 0));
	END arch_4fa1;
	
	
