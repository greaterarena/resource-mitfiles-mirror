library ieee;
use ieee.std_logic_1164.all;

ENTITY simnor IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END simnor;

ARCHITECTURE func_code4 OF simnor IS
	BEGIN
	f <= (((a NOR a) NOR c) NOR b) NOR (((a NOR a) NOR c) NOR b);
	END func_code4;
