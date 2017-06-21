library ieee;
use ieee.std_logic_1164.all;

entity count is
port(clock,reset:IN std_logic;
	 q:BUFFER std_logic_vector(1 downto 0));
end count;

architecture am of count is

COMPONENT tff1
port(t,clock,reset:IN std_logic;
	 q:OUT std_logic);
END COMPONENT;
SIGNAL s1,s2,s3,s4:std_logic;
begin
s1<='1';s2<=s1 and q(0);--s3<=s2 and q(1);
--s4<=s3 and q(2);
stage1: tff1 port map(s1,clock,reset,q(0));
stage2: tff1 port map(s2,clock,reset,q(1));
--stage3: tff1 port map(s3,clock,reset,q(2));
--stage4: tff1 port map(s4,clock,reset,q(3));
end am;

