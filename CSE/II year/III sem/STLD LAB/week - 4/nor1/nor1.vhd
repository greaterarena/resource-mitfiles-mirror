Entity nor1 IS
PORT( A,B,C,D:IN BIT;
		F:OUT BIT);
END nor1;
Architecture ar_nor1 of nor1 is
Signal s1:BIT;
BEGIN
s1<=(((A NOR B)NOR (C NOR D))NOR((A NOR B)NOR (C NOR D)));
F<=(s1 NOR (B NOR C)) NOR (s1 NOR (B NOR C));
END ar_nor1;
