CREATE OR REPLACE FUNCTION curse_for()
RETURNS varchar AS $$
DECLARE temp RECORD;
BEGIN
        for temp in select * from employee where dept_no=20
	LOOP
	PERFORM	update_it( temp.emp_no, temp.job_salary );	 
	END LOOP;
	return 'all done';
END;

$$ LANGUAGE plpgsql STRICT;

select curse_for();

select * from employee;

select * from emp_raise;
