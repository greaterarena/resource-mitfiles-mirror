library ieee;
use ieee.std_logic_1164.all;

ENTITY code2 IS
	PORT(a, b, c, d: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END code2;

ARCHITECTURE func_code2 OF code2 IS
	BEGIN
	f <= (a AND NOT(b)) OR (c AND d AND b) OR (NOT(a) AND c AND d);
	END func_code2;
