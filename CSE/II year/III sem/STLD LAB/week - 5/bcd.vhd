library ieee;
use ieee.std_logic_1164.all;

ENTITY bcd IS
	PORT(x,y: IN std_logic_vector(3 downto 0);
		s: OUT std_logic_vector(3 downto 0);
		cin: IN std_logic;
		cout:OUT std_logic);
END bcd;

ARCHITECTURE arch_4fa1 OF bcd IS
	Signal c:std_logic_vector(2 downto 0);
	Signal z:std_logic_vector(3 downto 0);
	Signal w:std_logic_vector(1 downto 0);
	Signal c1,c2,c3,c4:std_logic;
	component fulladd
		port(cin,x,y: IN std_logic;
			 s, cout: OUT std_logic);
	end component;
	BEGIN
	stage0: fulladd port map(cin,x(0),y(0),z(0),c(0));
	stage1: fulladd port map(c(0),x(1),y(1),z(1),c(1));
	stage2: fulladd port map(c(1),x(2),y(2),z(2),c(2));
	stage3: fulladd port map(c(2),x(3),y(3),z(3),c1);
	s(0) <= z(0);
	c2 <= z(3) and z(2);
	c3 <= z(3) and z(1);
	c4 <= c1 or c2 or c3;
	stage4: fulladd port map(cin,z(1),c4,s(1),w(0));
	stage5: fulladd port map(w(0),z(2),c4,s(2),w(1));
	cout <= c4;
	s(3) <= z(3) xor w(1);
	END arch_4fa1;
