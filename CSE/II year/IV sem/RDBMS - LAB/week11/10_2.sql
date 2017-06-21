CREATE or replace FUNCTION get_emp_name(int) RETURNS TABLE(f2 varchar)
    AS $$ SELECT emp_name from employee where dept_no = $1 $$
    LANGUAGE SQL;

SELECT * FROM get_emp_name(21);