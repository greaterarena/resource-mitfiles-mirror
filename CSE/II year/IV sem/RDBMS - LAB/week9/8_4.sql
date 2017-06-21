create table emp (
emp_no numeric(5,0),
emp_name varchar,
sal int);

delete from emp;

insert into emp values(1,'Anand',8000);
insert into emp values(2,'Mohan',9000);

CREATE OR REPLACE FUNCTION magic() RETURNS varchar as $$
DECLARE temp int;
	data record;
	data1 record;
	curs CURSOR FOR select sum(sal) from emp;
	curs1 CURSOR FOR select * from emp where emp_name in ('Anand', 'Mohan');
BEGIN

	open curs1;

	fetch curs1 into data;

	fetch curs1 into data1;
	
	insert into emp values(3,'Karan',1000);
	
	update emp set sal = case
		when emp_name = 'Anand' then sal + 2000
		when emp_name = 'Mohan' then sal + 1500
		else sal
		end;

	open curs;

	fetch curs into temp;

	if temp > 20000 then
	begin
		update emp set sal = case
		when emp_name = 'Anand' then data.sal
		when emp_name = 'Mohan' then data1.sal
		else sal
		end;
		return 'update nullified';
		
	end;
	else 
		return 'all done';
	end if;

end;
$$ LANGUAGE plpgsql STRICT;

select * from emp;		

select magic();




