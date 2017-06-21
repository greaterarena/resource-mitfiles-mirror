CREATE or replace FUNCTION get_high() RETURNS TABLE(dept_no int,sal numeric)
    AS $$ SELECT dept_no,max(job_salary) from employee group by dept_no $$
    LANGUAGE SQL;

SELECT * FROM get_high();