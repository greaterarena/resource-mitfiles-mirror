library ieee;
use ieee.std_logic_1164.all;

ENTITY bcd2421 IS
	PORT(v: IN std_logic_vector(3 downto 0);
		w:OUT std_logic_vector(3 downto 0));
END bcd2421;

ARCHITECTURE arch_4fa1 OF bcd2421 IS
	Signal m1,m2,m3,m4,m5:std_logic;
	component mux4_1sig
	PORT(w0,w1,w2,w3: IN std_logic;
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
	end component;
	BEGIN
	m1 <= '0';
	m2 <= '1';
	m3 <= v(1) or v(0);
	m4 <= v(1) or not v(0);
	m5 <= not m4;
	stage0: mux4_1sig port map(m1,m3,m2,m1,v(3 downto 2),w(3));
	stage1: mux4_1sig port map(m1,m4,m2,m1,v(3 downto 2),w(2));
	stage2: mux4_1sig port map(v(1),m5,m2,m1,v(3 downto 2),w(1));
	w(0) <= v(0);
	END arch_4fa1;




