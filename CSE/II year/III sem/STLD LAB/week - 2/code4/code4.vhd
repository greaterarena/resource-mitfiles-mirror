library ieee;
use ieee.std_logic_1164.all;

ENTITY code4 IS
	PORT(a, b, c: IN STD_LOGIC;
		f, g : OUT STD_LOGIC);
END code4;

ARCHITECTURE func_code4 OF code4 IS
	BEGIN
	f <= NOT (a AND b AND c);
	g <= (NOT a) OR (NOT b) OR (NOT c);
	END func_code4;
