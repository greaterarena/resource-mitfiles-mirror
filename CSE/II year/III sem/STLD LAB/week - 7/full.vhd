library ieee;
use ieee.std_logic_1164.all;

ENTITY full IS
	PORT(v: IN std_logic_vector(2 downto 0);
		s,c:OUT std_logic);
END full;

ARCHITECTURE arch_4fa1 OF full IS
	Signal m1,m2,m3:std_logic;
	component mux4_1sig
		PORT(w0,w1,w2,w3: IN std_logic;
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
	end component;
	BEGIN
	m1 <= not v(0);
	m2 <= '0';
	m3 <= '1';
	stage0: mux4_1sig port map(v(0),m1,m1,v(0),v(2 downto 1),s);
	stage1: mux4_1sig port map(m2,v(0),v(0),m3,v(2 downto 1),c);
	END arch_4fa1;



