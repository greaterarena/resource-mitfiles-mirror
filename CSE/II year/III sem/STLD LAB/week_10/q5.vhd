library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity q5 is 
port(b: in std_logic_vector(3 downto 0);
	 a: out std_logic_vector(3 downto 0));
end q5;

architecture behaviour of q5 is
begin
	a<= b + 3;
end behaviour;

