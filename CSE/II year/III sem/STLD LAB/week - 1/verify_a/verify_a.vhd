ENTITY verify_a IS
	PORT ( x, y, z : IN BIT;
		   f, g : OUT BIT);
END verify_a;

ARCHITECTURE func_a OF verify_a IS
BEGIN
	f <= x AND (y OR z);
	g <= (x AND y) OR (x AND z);
END func_a;
