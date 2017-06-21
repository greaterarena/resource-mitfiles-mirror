CREATE OR REPLACE FUNCTION cursor_current()
RETURNS varchar AS $$
DECLARE 
	temp employee%ROWTYPE;
	my_cursor CURSOR FOR select * from employee where dept_no=20;
	raiset numeric;
BEGIN
	open my_cursor;
	
	LOOP
		fetch my_cursor into temp;
		EXIT WHEN NOT FOUND;
		update employee
		set job_salary = job_salary + (job_salary * 0.05)
		WHERE CURRENT OF my_cursor;		
		raiset := temp.job_salary * 0.05;		
		insert into emp_raise values(temp.emp_no,'2013-03-1',raiset);
	END LOOP;
	return 'all done';
END;
$$ LANGUAGE plpgsql STRICT;

select cursor_current();

select * from emp_raise;

select * from employee;