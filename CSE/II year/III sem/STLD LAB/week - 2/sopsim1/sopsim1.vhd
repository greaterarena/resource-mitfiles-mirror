library ieee;
use ieee.std_logic_1164.all;

ENTITY sopsim1 IS
	PORT(a, b, c: IN STD_LOGIC;
		f : OUT STD_LOGIC);
END sopsim1;

ARCHITECTURE func_code4 OF sopsim1 IS
	BEGIN
	f <= (a AND b) OR (a AND c) OR (b AND c);
	END func_code4;
