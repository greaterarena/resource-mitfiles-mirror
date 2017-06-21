with max_bal(value,bname) as 
(select sum(balance),branch_name from account group by branch_name),
x(val) as
(select avg(value) from max_bal)
select bname from max_bal,x 
where max_bal.value>x.val