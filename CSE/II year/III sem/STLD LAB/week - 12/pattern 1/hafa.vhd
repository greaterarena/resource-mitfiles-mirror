library ieee;
use ieee.std_logic_1164.all;

entity hafa is
port(x,y:IN std_logic;
	 s,c:OUT std_logic);
end hafa;

architecture am of hafa is
begin
s<=x xor y;
c<=x and y;
end am;
