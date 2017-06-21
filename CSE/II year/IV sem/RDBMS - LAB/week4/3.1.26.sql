select count(Distinct customer_name),branch_name 
from account natural join depositor
group by branch_name
