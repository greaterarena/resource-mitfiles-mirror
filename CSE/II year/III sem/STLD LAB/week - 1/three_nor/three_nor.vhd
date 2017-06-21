ENTITY three_nor IS
	PORT(x1, x2, x3 : IN BIT;
		 f : OUT BIT);
END three_nor;

ARCHITECTURE func_tnor OF three_nor IS
	BEGIN
	f <= ((x1 NOR x2) NOR (x1 NOR x2)) NOR x3;
	END func_tnor;
