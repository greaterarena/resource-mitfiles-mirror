Entity nand2 IS
PORT( A,B,D:IN BIT;
		F:OUT BIT);
END nand2;
Architecture ar_nand2 of nand2 is
BEGIN
F<=((b nand b) nand a) nand d;
END ar_nand2;
