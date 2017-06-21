/* first sample function */

create function go_kill() returns setof account as
'Select * from account where account_number = ' language sql;

drop function go_kill();

select go_kill();

/* first second function */

create or replace function gen(v int) returns integer as $$
begin
	for i in 1..v loop
	raise notice 'i is %',i;
	end loop;
end;
$$ language plpgsql;

drop function gen(int);

select gen(7);


