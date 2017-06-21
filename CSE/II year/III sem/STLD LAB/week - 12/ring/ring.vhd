library ieee;
use ieee.std_logic_1164.all;
entity ring is
port(start,clock,reset:in std_logic; 
	 q:buffer std_logic_vector(3 downto 0));
end ring;
architecture atf1 of ring is
component dffring
port(d,start,clock,reset:IN std_logic;
	q: OUT std_logic);
end component;
signal i,j:std_logic;
begin
i<=not start;
j<=reset;
stg1: dffring port map(q(0),i,clock,j,q(3));
stg2: dffring port map(q(3),j,clock,i,q(2));
stg3: dffring port map(q(2),j,clock,i,q(1));
stg4: dffring port map(q(1),j,clock,i,q(0));
end atf1;
