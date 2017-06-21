drop table area;

create table area(
radius float,
area float);

drop function circle();


CREATE FUNCTION circle()
RETURNS varchar AS $$
DECLARE area float;rad float;
BEGIN
	rad := 3;
	while(rad <= 7) loop
		area := 3.14*rad*rad;
		insert into area values(rad,area);
		rad := rad + 0.1;
		end loop;	
	return 'all done';       
END;
$$ LANGUAGE plpgsql STRICT;

select circle();

select * from area;
