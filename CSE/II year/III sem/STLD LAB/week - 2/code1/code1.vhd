library ieee;
use ieee.std_logic_1164.all;

ENTITY code1 IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END code1;

ARCHITECTURE func_code1 OF code1 IS
	BEGIN
	f <= (a AND NOT(b)) OR (NOT(a) AND c) OR (b AND c);
	END func_code1;
