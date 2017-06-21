library ieee;
use ieee.std_logic_1164.all;


entity q4 is 
generic(n: integer:=4);
port(g: in std_logic_vector((n-1) downto 0);
	 b: buffer std_logic_vector((n-1) downto 0));
end q4;

architecture behaviour of q4 is
begin
	b(n-1)<=g(n-1);
	stage0: for i in(n-2) downto 0 generate
		b(i)<= b(i+1) xor g(i);
	end generate;
end behaviour;

