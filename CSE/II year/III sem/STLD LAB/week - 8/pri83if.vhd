library ieee;
use ieee.std_logic_1164.all;

ENTITY pri83if IS
	PORT(v: IN std_logic_vector(7 downto 0);
		 e: OUT std_logic;
		 x: OUT std_logic_vector(2 downto 0));
END pri83if;

ARCHITECTURE arch_4fa1 OF pri83if IS
	begin
		process(v)
			begin
			if v(7) = '1' then x<= "111";
			elsif v(6) = '1' then x<= "110";
			elsif v(5) = '1' then x<= "101";
			elsif v(4) = '1' then x<= "100";
			elsif v(3) = '1' then x<= "011";
			elsif v(2) = '1' then x<= "010";
			elsif v(1) = '1' then x<= "001";
			else  x<= "000";
			end if;
		end process; 	
	e<= '0' when v = "00000000" else '1';
	END arch_4fa1;

