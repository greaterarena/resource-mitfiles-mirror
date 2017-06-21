library ieee;
use ieee.std_logic_1164.all;
ENTITY bit2 IS
	PORT(x,y: IN std_logic_vector(1 downto 0);
		p: OUT std_logic_vector(3 downto 0));
END bit2;

ARCHITECTURE arch_4fa1 OF bit2 IS
	Signal m:std_logic_vector(3 downto 0);
	Signal c:std_logic;
	component hafa
		PORT(a, b: IN std_logic;
		sha,cha : OUT std_logic);
	end component;
	BEGIN
	m(0) <= x(0) and y(0);
	m(1) <= x(1) and y(0);
	m(2) <= x(0) and y(1);
	m(3) <= x(1) and y(1);
	p(0) <= m(0);
	stage0: hafa port map(m(1),m(2),p(1),c);
	stage1: hafa port map(c,m(3),p(2),p(3));
	END arch_4fa1;
