/* q7 */
ALTER TABLE employee RENAME 
CONSTRAINT employee_pkey to empno_pkey;

alter table employee validate
constraint forgn;

/* q8 */

/*
CREATE FUNCTION concater(varchar, varchar) RETURNS varchar
    AS 'select concat($1,$2);'
    LANGUAGE SQL
    IMMUTABLE
    RETURNS NULL ON NULL INPUT;

CREATE FUNCTION killemall() RETURNS table(x_11 varchar)
    AS 'select concater(employee.empname,employee.dno) from employee;'
    Language sql;
    
    $emp_stamp$ LANGUAGE plpgsql;

select killemall(); */

select * from employee;

CREATE FUNCTION checker() RETURNS trigger AS $gender_check$
    BEGIN
        -- Check that empname and salary are given
        IF NEW.sex IS NULL THEN
            RAISE EXCEPTION 'sex cannot be null';
        END IF;
        IF NEW.salary IS NULL THEN
            RAISE EXCEPTION '% cannot have null salary', NEW.empname;
        END IF;
        RETURN NEW;
    END;
$emp_stamp$ LANGUAGE plpgsql;




CREATE TABLE emp (
    empname text,
    salary integer,
    last_date timestamp,
    last_user text
);

CREATE FUNCTION emp_stamp() RETURNS trigger AS $emp_stamp$
    BEGIN
        -- Check that empname and salary are given
        IF NEW.empname IS NULL THEN
            RAISE EXCEPTION 'empname cannot be null';
        END IF;
        IF NEW.salary IS NULL THEN
            RAISE EXCEPTION '% cannot have null salary', NEW.empname;
        END IF;

        -- Who works for us when she must pay for it?
        IF NEW.salary < 0 THEN
            RAISE EXCEPTION '% cannot have a negative salary', NEW.empname;
        END IF;

        -- Remember who changed the payroll when
        NEW.last_date := current_timestamp;
        NEW.last_user := current_user;
        RETURN NEW;
    END;
$emp_stamp$ LANGUAGE plpgsql;

drop table emp;
drop function emp_stamp();
