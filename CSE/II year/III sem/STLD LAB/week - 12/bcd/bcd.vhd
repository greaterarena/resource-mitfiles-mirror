library ieee;
use ieee.std_logic_1164.all;

entity bcd is
port(clock,reset:IN std_logic;
	 q:BUFFER std_logic_vector(3 downto 0));
end bcd;

architecture am of bcd is

COMPONENT tff1
port(t,clock,reset:IN std_logic;
	 q:OUT std_logic);
END COMPONENT;
SIGNAL s1,s2,s3,s4:std_logic;
begin
s1<='1';s2<=q(0) and not q(3);s3<=q(0) and q(1) and not q(3);
s4<=(q(0) and q(1) and q(2) and not q(3)) or (q(3) and q(0) and (not q(2)) and (not q(1)));
stage1: tff1 port map(s1,clock,reset,q(0));
stage2: tff1 port map(s2,clock,reset,q(1));
stage3: tff1 port map(s3,clock,reset,q(2));
stage4: tff1 port map(s4,clock,reset,q(3));
end am;
