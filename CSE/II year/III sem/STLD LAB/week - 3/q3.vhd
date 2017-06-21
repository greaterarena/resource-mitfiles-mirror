library ieee;
use ieee.std_logic_1164.all;

ENTITY q3 IS
	PORT(a, b, c, d: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END q3;

ARCHITECTURE arch_q3 OF q3 IS
	BEGIN
		f <= (b OR NOT a) AND (b OR d) AND (c OR (NOT a) OR (NOT d)) AND (a OR (NOT c) OR (NOT d));
	END arch_q3;
