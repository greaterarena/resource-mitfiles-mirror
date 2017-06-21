library ieee;
use ieee.std_logic_1164.all;

ENTITY sopsim2 IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END sopsim2;

ARCHITECTURE func_code4 OF sopsim2 IS
	BEGIN
	f <= (((a NAND b) NAND (B NAND c)) NAND ((a NAND b) NAND (b NAND c))) NAND (a NAND c);
	END func_code4;
