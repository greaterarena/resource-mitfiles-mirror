library ieee;
use ieee.std_logic_1164.all;

entity final is
port(a,b:IN std_logic;
	 s:IN std_logic_vector(1 downto 0); 
	 result:OUT std_logic_vector(1 downto 0));
end final;

architecture am of final is

COMPONENT mux4
	port(s:IN std_logic_vector(1 downto 0);
	 w:IN std_logic_vector(3 downto 0);
	 y:OUT std_logic);
END COMPONENT;

COMPONENT hafa
port(x,y:IN std_logic;
	 s,c:OUT std_logic);
END COMPONENT;

SIGNAL xin,yin : std_logic_vector(3 downto 0);
SIGNAL x,y: std_logic;

begin
xin(3)<=not a;xin(2)<=not a;xin(1)<=not a;xin(0)<=not a;
yin(3)<=b;yin(2)<='1';yin(1)<=not a;yin(0)<='0';
stage1: mux4 port map(s,xin,x);
stage2: mux4 port map(s,yin,y);
stage3: hafa port map(x,y,result(0),result(1));
end am;
