  LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY or_gate IS
	PORT(x1, x2 : IN STD_LOGIC;
		 f : OUT STD_LOGIC);
END or_gate;

ARCHITECTURE func_or OF or_gate IS
BEGIN
f <= x1 OR x2;
END func_or;
