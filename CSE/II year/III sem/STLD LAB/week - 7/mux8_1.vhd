library ieee;
use ieee.std_logic_1164.all;

ENTITY mux8_1 IS
	PORT(w: IN std_logic_vector(0 to 7);
		s: in std_logic_vector(2 downto 0);
		x:OUT std_logic);
END mux8_1;

ARCHITECTURE arch_4fa1 OF mux8_1 IS
	begin
	process (w,s)
		begin
		case s is
		when "000" =>
			x<=w(0);
		when "001" =>
			x<=w(1);
		when "010" =>
			x<=w(2);
		when "011" =>
			x<=w(3);
		when "100" =>
			x<=w(4);
		when "101" =>
			x<=w(5);
		when "110" =>
			x<=w(6);
		when others =>
			x<=w(7);
		end case;
	end process;
	END arch_4fa1;

