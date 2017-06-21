library ieee;
use ieee.std_logic_1164.all;
entity john is
port(clock,reset:in std_logic; 
	 q:buffer std_logic_vector(3 downto 0));
end john;
architecture atf1 of john is
component dff1
port(d,clock,reset:IN std_logic;
	q: OUT std_logic);
end component;
signal i,j:std_logic;
begin
i<=not q(3);
j<=reset;
stg1: dff1 port map(i,clock,j,q(0));
stg2: dff1 port map(q(0),clock,j,q(1));
stg3: dff1 port map(q(1),clock,j,q(2));
stg4: dff1 port map(q(2),clock,j,q(3));
end atf1;
