drop table employee;
drop table emp_raise;

create table employee (
emp_no int primary key,
emp_name varchar(15),
job_salary numeric(10,3),
dept_no int);

create table emp_raise (
emp_no int,
date_up date,
raise numeric(10,3),
foreign key(emp_no) references employee(emp_no));


insert into employee values(1,'Suri',40000,20);
insert into employee values(2,'Narula',50000,20);
insert into employee values(3,'Batra',20000,21);
insert into employee values(4,'Varghese',10000,20);
insert into employee values(5,'Karkhanis',70000,21);
insert into employee values(6,'Agarwal',5000,22);
insert into employee values(7,'Mukherjee',1100,23);
insert into employee values(8,'Mishra',90000,20);
insert into employee values(9,'Khetan',5000,20);
insert into employee values(10,'Shah',100,19);


-- NEW RXPLICIT CURSOR FUNCTION

CREATE OR REPLACE FUNCTION cursor_up()
RETURNS varchar AS $$
DECLARE 
	temp employee%ROWTYPE;
	my_cursor CURSOR FOR select * from employee where dept_no=20;
BEGIN
        /*BEGIN*/
	open my_cursor;
	
	LOOP

		fetch my_cursor into temp;

		EXIT WHEN NOT FOUND;

		PERFORM update_it( temp.emp_no, temp.job_salary );

	END LOOP;

	return 'all done';
END;
$$ LANGUAGE plpgsql STRICT;

CREATE OR REPLACE FUNCTION update_it(yahoo1 int, yahoo2 numeric)
RETURNS varchar AS $$
DECLARE raiset numeric;
BEGIN
	update employee
	set job_salary = job_salary + (job_salary * 0.05)
	where emp_no = yahoo1;
	raiset := yahoo2 * 0.05;
	insert into emp_raise values(yahoo1,'2013-03-1',raiset);
	return 'update done';
END;
$$ LANGUAGE plpgsql STRICT;

select cursor_up();

select * from emp_raise;

select * from employee;



-- FOR LOOP CURSOR METHOD 

create table top5 (
emp_no int primary key,
emp_name varchar(15),
job_salary int,
dept_no int);

select * from employee order by job_salary desc;

CREATE OR REPLACE FUNCTION top_5()
RETURNS varchar AS $$
DECLARE count int; temp RECORD;
BEGIN
        /*BEGIN*/
	count:=0;
        for temp in select * from employee order by job_salary desc
	LOOP
	 insert into top5 values(temp.emp_no,temp.emp_name,temp.job_salary,temp.dept_no);
	 count := count + 1;
	 if count >= 5 then
		return 'All done';
	 end if;
	END LOOP;
END;

$$ LANGUAGE plpgsql STRICT;


select top_5();

select * from top5;


-- END FOR LOOP CUROSR METHOD


-- DISPLAY INFORMATION FOR EMPOYEES WHO GET 