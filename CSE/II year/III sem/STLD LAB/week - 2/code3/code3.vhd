library ieee;
use ieee.std_logic_1164.all;

ENTITY code3 IS
	PORT(a, b, c: IN STD_LOGIC;
		f, g : OUT STD_LOGIC);
END code3;

ARCHITECTURE func_code3 OF code3 IS
	BEGIN
	f <= NOT(a OR b OR c);
	g <= (NOT a) AND (NOT b) AND (NOT c);
	END func_code3;
