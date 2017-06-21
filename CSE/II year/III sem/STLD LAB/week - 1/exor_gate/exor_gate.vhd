ENTITY exor_gate IS
	PORT(x1, x2 : IN BIT;
		 f : OUT BIT);
END exor_gate;

ARCHITECTURE func_exor OF exor_gate IS
BEGIN
f <= x1 XOR x2;
END func_exor;
