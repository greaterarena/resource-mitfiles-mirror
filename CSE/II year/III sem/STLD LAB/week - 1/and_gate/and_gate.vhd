ENTITY and_gate IS
	PORT(x1, x2 : IN BIT;
		 f : OUT BIT);
END and_gate;

ARCHITECTURE func_and OF and_gate IS
BEGIN
f <= x1 AND x2;
END func_and;
