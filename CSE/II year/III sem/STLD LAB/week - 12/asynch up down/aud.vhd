library ieee;
use ieee.std_logic_1164.all;
entity aud is
port(ud,cl,reset:in std_logic; 
	 q:BUFFER std_logic_vector(3 downto 0)); 
end aud;
architecture atf1 of aud is
component tff1
port(t,clock,reset:IN std_logic;
	 q: OUT std_logic);
end component;
signal i:std_logic;
signal r:std_logic_vector(3 downto 0);
begin
i<='1';
r(0)<=(ud and q(0)) or (not ud and not q(0)); 
r(1)<=(ud and q(1)) or (not ud and not q(1)); 
r(2)<=(ud and q(2)) or (not ud and not q(2)); 
r(3)<=(cl and ud) or (not ud and not cl);
stg1: tff1 port map(i,cl,reset,q(0));
stg2: tff1 port map(i,r(0),reset,q(1));
stg3: tff1 port map(i,r(1),reset,q(2));
stg4: tff1 port map(i,r(2),reset,q(3));
end atf1;
