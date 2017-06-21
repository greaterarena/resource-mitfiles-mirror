select to_char(dob,'DD-MON-YYYY') from employee;
select to_char(dob,'DD-MON-YY') from employee;
select to_char(dob,'DD-MM-YY') from employee; /*4.3.16*/

select empname,to_char(dob,'Day') from employee;
select empname,to_char(dob,'DAY') from employee; /*4.3.18*/

select empname,to_char(dob,'Month') from employee;
select empname,to_char(dob,'MONTH') from employee; /*4.3.19*/

select ((CAST(to_char(now(),'YYYY') AS integer) - 
CAST(to_char(dob,'YYYY') AS integer))*12) + CAST(to_char(dob,'MM') AS integer) +
- CAST(to_char(now(),'MM') AS integer)from employee; /*4.3.21*/

select empname from employee where to_char(dob,'YYYY') = '1961';/*4.3.23*/

select empname,to_char(dob,'YYYY')
from employee where CAST(to_char(dob,'YYYY') AS integer) > 1960
and CAST(to_char(dob,'YYYY') AS integer) < 1965; /*4.3.24*/



/*4.3.23*/

select CAST(to_char(now(),'MM') AS integer) from employee;