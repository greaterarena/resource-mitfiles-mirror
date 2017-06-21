create or replace function good_day() returns varchar as $$
begin
	return 'Good Day to You';
end;
$$ language plpgsql STRICT;

select good_day();