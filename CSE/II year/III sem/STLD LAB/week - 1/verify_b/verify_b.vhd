ENTITY verify_b IS
	PORT ( x, y, z : IN BIT;
		   f, g : OUT BIT);
END verify_b;

ARCHITECTURE func_b OF verify_b IS
BEGIN
	f <= x OR (y AND z);
	g <= (x OR y) AND (x OR z);
END func_b;
