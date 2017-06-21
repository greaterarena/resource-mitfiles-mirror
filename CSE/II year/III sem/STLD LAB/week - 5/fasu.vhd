library ieee;
use ieee.std_logic_1164.all;
ENTITY fasu IS
	PORT(x,y: IN std_logic_vector(3 downto 0);
		s: OUT std_logic_vector(3 downto 0);
		cin: IN std_logic;
		cout:OUT std_logic);
END fasu;

ARCHITECTURE arch_4fa1 OF fasu IS
	Signal m:std_logic_vector(3 downto 0);
	component fa41
		PORT(x,y: IN std_logic_vector(3 downto 0);
		s: OUT std_logic_vector(3 downto 0);
		cin: IN std_logic;
		cout:OUT std_logic);
	end component;
	BEGIN
	m(0) <= y(0) xor cin;
	m(1) <= y(1) xor cin;
	m(2) <= y(2) xor cin;
	m(3) <= y(3) xor cin;
	stage0: fa41 port map(x,m,s,cin,cout);
	END arch_4fa1;
