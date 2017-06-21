create view all_customer as
select customer_name, branch_name 
from account natural join depositor

/* select * from all_customer */