ENTITY three_nand IS
	PORT(x1, x2, x3 : IN BIT;
		 f : OUT BIT);
END three_nand;

ARCHITECTURE func_tnand OF three_nand IS
	BEGIN
	f <= ((x1 NAND x2) NAND (x1 NAND x2)) NAND x3;
	END func_tnand;
