CREATE OR REPLACE FUNCTION squarer(i int) RETURNS int as $$
DECLARE temp int;	
BEGIN
	temp := i*i;
	return temp;
end;
$$ LANGUAGE plpgsql STRICT;

select squarer(2);