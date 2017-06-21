ENTITY fulladd IS
	PORT(x, y, cin: IN BIT;
		s,cout: OUT BIT);
END fulladd;

ARCHITECTURE arch_full OF fulladd IS
	BEGIN
	s <= x xor y xor cin;
	cout <= (x and y) or (cin and x) or (cin AND y);
	END arch_full;
