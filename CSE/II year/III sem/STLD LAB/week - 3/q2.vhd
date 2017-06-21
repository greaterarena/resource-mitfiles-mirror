library ieee;
use ieee.std_logic_1164.all;

ENTITY q2 IS
	PORT(a, b, c, d: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END q2;

ARCHITECTURE arch_q2 OF q2 IS
	BEGIN
		f <= (c AND NOT d) OR (NOT b AND NOT d) OR (a AND b AND (NOT c) AND d);
	END arch_q2;
