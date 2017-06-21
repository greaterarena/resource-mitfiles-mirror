CREATE OR REPLACE FUNCTION magic4(eno int) RETURNS numeric as $$
DECLARE temp numeric;	
	curs CURSOR FOR select job_salary from employee where emp_no = eno;
	BEGIN
		open curs;
		fetch curs into temp;	
		close curs;
		return temp;		
end;
$$ LANGUAGE plpgsql STRICT;

select magic4(3)
