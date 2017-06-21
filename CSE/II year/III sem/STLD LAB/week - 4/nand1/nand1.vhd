Entity nand1 IS
PORT( A,B,C,D:IN BIT;
		F:OUT BIT);
END nand1;
Architecture ar_nand1 of nand1 is
Signal s1,s2,s3,s4:BIT;
BEGIN
s1<=(c nand (d nand d)) nand ((a nand a) nand (d nand d));
s2<=(b nand (d nand d)) nand ((((a nand a) nand b) nand ((a nand a) nand b)) nand c);
F<=((s1 nand s1) nand (s2 nand s2)) ;
END ar_nand1;
