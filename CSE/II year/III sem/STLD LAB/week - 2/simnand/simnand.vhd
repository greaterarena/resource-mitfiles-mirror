library ieee;
use ieee.std_logic_1164.all;

ENTITY simnand IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END simnand;

ARCHITECTURE func_code4 OF simnand IS
	BEGIN
	f <= ((c NAND c) NAND a) NAND (b NAND b);
	END func_code4;
