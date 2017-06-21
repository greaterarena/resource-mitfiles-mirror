library ieee;
use ieee.std_logic_1164.all;

ENTITY q1 IS
	PORT(a, b, d: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END q1;

ARCHITECTURE arch_q1 OF q1 IS
	BEGIN
	f <= ((NOT d)AND (NOT b)) OR ((NOT a)AND b) OR (b AND d);
	END arch_q1;
