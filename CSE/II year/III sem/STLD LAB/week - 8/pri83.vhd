library ieee;
use ieee.std_logic_1164.all;

ENTITY pri83 IS
	PORT(v: IN std_logic_vector(7 downto 0);
		 e: OUT std_logic;
		 x: OUT std_logic_vector(3 downto 0));
END pri83;

ARCHITECTURE arch_4fa1 OF pri83 IS
	begin
 	x<= "111" when v(7) = '1' else
		"110" when v(6) = '1' else
		"101" when v(5) = '1' else
		"100" when v(4) = '1' else
		"011" when v(3) = '1' else
		"010" when v(2) = '1' else
		"001" when v(1) = '1' else
		"000";
	e<= '0' when v = "00000000" else
		'1';
	END arch_4fa1;

