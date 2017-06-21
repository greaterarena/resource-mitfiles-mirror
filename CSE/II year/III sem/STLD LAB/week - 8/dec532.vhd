library ieee;
use ieee.std_logic_1164.all;

ENTITY dec532 IS
	PORT(v: IN std_logic_vector(4 downto 0);
		 x: OUT std_logic_vector(31 downto 0));
END dec532;

ARCHITECTURE arch_4fa1 OF dec532 IS
	Signal t: std_logic_vector(3 downto 0);	
	component dec38
		PORT(v: IN std_logic_vector(2 downto 0);
		 e: IN std_logic;
		 x: OUT std_logic_vector(7 downto 0));
 	end component;
	begin
	with v(4 downto 3) select
		t<= "1000" when "00",
			"0100" when "01",
			"0010" when "10",
			"0001" when others;
	stage0: dec38 port map(v(2 downto 0),t(3),x(31 downto 24));
	stage1: dec38 port map(v(2 downto 0),t(2),x(23 downto 16));
	stage2: dec38 port map(v(2 downto 0),t(1),x(15 downto 8));
	stage3: dec38 port map(v(2 downto 0),t(0),x(7 downto 0));
	END arch_4fa1;
