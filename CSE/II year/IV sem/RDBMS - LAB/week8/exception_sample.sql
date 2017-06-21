CREATE OR REPLACE FUNCTION invert(nz int)
RETURNS int AS $$
DECLARE sample int;temp_var int;
BEGIN
	sample:=nz/0;
	EXCEPTION
	WHEN division_by_zero THEN
        RAISE NOTICE 'caught division_by_zero';
        	
END;
$$ LANGUAGE plpgsql STRICT;

select invert(7);

