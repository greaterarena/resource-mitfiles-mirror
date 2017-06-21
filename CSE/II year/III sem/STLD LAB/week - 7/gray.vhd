library ieee;
use ieee.std_logic_1164.all;

ENTITY gray IS
	PORT(b: IN std_logic_vector(3 downto 0);
		g: OUT std_logic_vector(3 downto 0));
END gray;

ARCHITECTURE gray_func OF gray IS
	Signal m0,m1,m2,m3:std_logic_vector(0 to 7);
	component mux8_1
		PORT(w: IN std_logic_vector(0 to 7);
		s: in std_logic_vector(2 downto 0);
		x:OUT std_logic);
	end component;
	BEGIN
	m0<="00001111";
	m1<="00110011";
	m2<="01010101";
	m3(0) <= b(0);
	m3(1) <= not b(0);
	m3(2) <= b(0);
	m3(3) <= not b(0);
	m3(4) <= b(0);
	m3(5) <= not b(0);
	m3(6) <= b(0);
	m3(7) <= not b(0);

	stage0: mux8_1 port map(m0,b(3 downto 1),g(3));
	stage1: mux8_1 port map(m1,b(3 downto 1),g(2));
	stage2: mux8_1 port map(m2,b(3 downto 1),g(1));
	stage3: mux8_1 port map(m3,b(3 downto 1),g(0));

	END gray_func;


