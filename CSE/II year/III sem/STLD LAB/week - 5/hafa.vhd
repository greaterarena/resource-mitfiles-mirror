library ieee;
use ieee.std_logic_1164.all;
ENTITY hafa IS
	PORT(a, b: IN std_logic;
		sha,cha : OUT std_logic);
END hafa;

ARCHITECTURE arch_hafa OF hafa IS
	BEGIN
	sha <= a xor b;
	cha <= a and b;
	END arch_hafa;
