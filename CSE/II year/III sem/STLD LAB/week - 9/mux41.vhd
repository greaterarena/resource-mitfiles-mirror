library ieee;
use ieee.std_logic_1164.all;

ENTITY mux41 IS
	PORT(w: IN std_logic_vector(0 to 3);
		 s: in std_logic_vector(1 downto 0);
		 e: IN std_logic;
		 x:OUT std_logic);
END mux41;

ARCHITECTURE arch_4fa1 OF mux41 IS
	Signal p,r: std_logic_vector(3 downto 0);
	component dec24
	 PORT(v: IN std_logic_vector(1 downto 0);
		  e: IN std_logic;
		  x: OUT std_logic_vector(3 downto 0));
 	end component;
	begin
	stage0: dec24 port map(s,e,p);
	r(3) <= p(3) AND w(3);
	r(2) <= p(2) AND w(2);
	r(1) <= p(1) AND w(1);
	r(0) <= p(0) AND w(0);	
	x<= r(0) or r(1) or r(2) or r(3);
END arch_4fa1;
