library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity q2 is 
port(a,b: in std_logic_vector(3 downto 0);
	 aeqb,agtb,altb: out std_logic);
end q2;

architecture behaviour of q2 is
begin
	aeqb <= '1' when a = b else '0';
	agtb <= '1' when a > b else '0';
	altb <= '1' when a < b else '0';

end behaviour;
