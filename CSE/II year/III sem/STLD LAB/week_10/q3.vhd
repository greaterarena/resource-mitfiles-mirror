library ieee;
use ieee.std_logic_1164.all;


entity q3 is 
generic(n: integer:=4);
port(b: in std_logic_vector((n-1) downto 0);
	 g: out std_logic_vector((n-1) downto 0));
end q3;

architecture behaviour of q3 is
begin
	g(n-1)<=b(n-1);
	stage0: for i in(n-2) downto 0 generate
		g(i)<= b(i+1) xor b(i);
	end generate;
end behaviour;

