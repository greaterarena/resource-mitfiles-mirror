library ieee;
use ieee.std_logic_1164.all;

entity q4 is
port(clock: in std_logic;
	 q: buffer std_logic_vector(3 downto 0));
end q4;

architecture behaviour of q4 is
component tf2 is
port(t,clock: in std_logic;
	 q: out std_logic);
end component;
signal a,b,c,d: std_logic;
begin
 a<='1';
 s1: tf2 port map(a,clock,q(0));
 b<= a and q(0);
 s2: tf2 port map(b,clock,q(1));
 c<= b and q(1);
 s3: tf2 port map(c,clock,q(2));
 d<= c and q(2);
 s4: tf2 port map(d,clock,q(3));
end behaviour;
		 	
