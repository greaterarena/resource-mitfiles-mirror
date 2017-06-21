library ieee;
use ieee.std_logic_1164.all;

ENTITY mux16_1select IS
	PORT(w: IN std_logic_vector(0 to 15);
		s: IN std_logic_vector(3 downto 0);
		x:OUT std_logic);
END mux16_1select;

ARCHITECTURE arch_4fa1 OF mux16_1select IS
	Signal m:std_logic_vector(0 to 3);
	component mux4_1select
		PORT(w: IN std_logic_vector(0 to 3);
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
	end component;
	BEGIN
	stage0: mux4_1select port map(w(0 to 3),s(1 downto 0),m(0));
	stage1: mux4_1select port map(w(4 to 7),s(1 downto 0),m(1));
	stage2: mux4_1select port map(w(8 to 11),s(1 downto 0),m(2));
	stage3: mux4_1select port map(w(12 to 15),s(1 downto 0),m(3));
	stage5: mux4_1select port map(m(3 downto 0),s(3 downto 2),x);
	END arch_4fa1;

