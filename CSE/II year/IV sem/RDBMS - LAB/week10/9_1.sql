create table salary (
ecode int primary key,
sal int);

create table sal2 (
ecode int,
salary int,
dc timestamp not null default now());

insert into salary values(1,1000);
insert into salary values(2,2000);
insert into salary values(3,3000);
insert into salary values(4,4000);
insert into salary values(5,5000);

create or replace function killer()
returns trigger as $body$
DECLARE
	curs cursor for select * from salary;	
	temp record;
begin
	open curs;
	LOOP
		fetch curs into temp;
		EXIT WHEN NOT FOUND;
		insert into sal2(ecode,salary) values (temp.ecode,temp.sal);
		--insert into sal2(ecode,salary) values (new.ecode,new.sal);
	END LOOP;
	return new;
end;
$body$ language plpgsql STRICT;

create trigger injector after update on salary
for each row
execute procedure killer();

create trigger injector1 after update on salary
execute procedure killer();

drop trigger injector on salary

update salary set sal = 1500 where ecode = 1;

select * from salary

select * from sal2