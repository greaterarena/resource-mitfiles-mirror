ENTITY verify_c IS
	PORT ( a : IN BIT;
		   f, g : OUT BIT);
END verify_c;

ARCHITECTURE func_c OF verify_c IS
BEGIN
	f <= a;
	g <= NOT (NOT a);
END func_c;
