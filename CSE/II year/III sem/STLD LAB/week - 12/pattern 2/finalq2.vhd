library ieee;
use ieee.std_logic_1164.all;

entity finalq2 is
port(clock,reset:IN std_logic;
	a:IN std_logic_vector(3 downto 0); 
	o:out std_logic_vector(3 downto 0));
end finalq2;

architecture am of finalq2 is
COMPONENT count
port(clock,reset:IN std_logic;
	 q:BUFFER std_logic_vector(1 downto 0));
END COMPONENT;
COMPONENT mux4
port(s:IN std_logic_vector(1 downto 0);
	 w:IN std_logic_vector(3 downto 0);
	 y:OUT std_logic);	
END COMPONENT;
SIGNAL time:std_logic_vector(1 downto 0);
SIGNAL m1,m2,m3,m4:std_logic_vector(3 downto 0);
begin
m1(0)<=a(0);m2(0)<=a(1);m3(0)<=a(2);m4(0)<=a(3);
m1(1)<='0';m2(1)<=a(0);m3(1)<=a(1);m4(1)<=a(2);
m1(2)<=a(1);m2(2)<=a(2);m3(2)<=a(3);m4(2)<=a(3);
m1(3)<=not a(0);m2(3)<=not a(1);m3(3)<=not a(2);
m4(3)<=not a(3);
stage1: count port map(clock,reset,time);
stage2: mux4 port map(time,m1,o(0));
stage3: mux4 port map(time,m2,o(1));
stage4: mux4 port map(time,m3,o(2));
stage5: mux4 port map(time,m4,o(3));
end am;

