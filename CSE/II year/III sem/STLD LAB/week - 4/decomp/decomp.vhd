Entity decomp IS
PORT( A,B,C,D:IN BIT;
		F:OUT BIT);
END decomp;
Architecture ar_nand2 of decomp is
Signal g : BIT;
BEGIN
g <= ((not a) and b) or (a and (not b));
f <= (g and c) or ((not g) and d);
END ar_nand2;
