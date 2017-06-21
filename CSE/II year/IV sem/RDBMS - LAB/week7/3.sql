CREATE OR REPLACE FUNCTION invert(nz int)
RETURNS int AS $$
DECLARE sample int;temp_var int;
BEGIN
	sample:=0;
	for i in 1..4 loop
		temp_var := nz % (10);
		sample := (sample*10) + temp_var;
		nz := nz/10;
	end loop;   
	return sample;
END;
$$ LANGUAGE plpgsql STRICT;

select invert(5639);

