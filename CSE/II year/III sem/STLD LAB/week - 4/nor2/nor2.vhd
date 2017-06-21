Entity nor2 IS
PORT( A,B,C,D:IN BIT;
		F:OUT BIT);
END nor2;
Architecture ar_nor2 of nor2 is
Signal s1,s2:BIT;
BEGIN
s1<=((a nor b) nor (b nor d)) nor ((a nor b) nor (b nor d));
s2<=((d nor d) nor (c nor c));
F<=(s1 nor s2) nor (s1 nor s2);
END ar_nor2;
