library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity q1 is 
port(a,b: in std_logic;
	 aeqb: out std_logic);
end q1;

architecture behaviour of q1 is
begin
	aeqb <= '1' when a = b else '0';
end behaviour;
