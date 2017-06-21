library ieee;
use ieee.std_logic_1164.all;

ENTITY q4 IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END q4;

ARCHITECTURE arh_q4 OF q4 IS
	BEGIN
		f <= (a AND b) OR (b AND c) OR (a AND c);
	END arh_q4;
