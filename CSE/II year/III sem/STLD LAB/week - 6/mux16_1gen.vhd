library ieee;
use ieee.std_logic_1164.all;

ENTITY mux16_1gen IS
	PORT(w: IN std_logic_vector(0 to 15);
		s: IN std_logic_vector(3 downto 0);
		x:OUT std_logic);
END mux16_1gen;

ARCHITECTURE arch_4fa1 OF mux16_1gen IS
	Signal m:std_logic_vector(0 to 3);
	component mux4_1sig
		PORT(w0,w1,w2,w3: IN std_logic;
		s: in std_logic_vector(1 downto 0);
		x:OUT std_logic);
	end component;
	BEGIN
	G1: for i IN 0 to 3 Generate
		muxs: mux4_1sig port map(w(4*i),w(4*i+1),w(4*i+2),w(4*i+3),s(1 downto 0),m(i));
	end generate;
	stage0: mux4_1sig port map(m(3),m(2),m(1),m(0),s(3 downto 2),x);
	END arch_4fa1;


