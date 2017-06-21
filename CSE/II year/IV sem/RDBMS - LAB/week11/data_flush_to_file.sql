copy (select * from employee) to 'C:\3\abc.txt';

create table emp1 as select * from employee;

select * from emp1;

delete from emp1;

copy emp1 from 'C:\3\abc.txt';

select * from emp1
