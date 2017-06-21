select customer_name from account natural join depositor
where branch_name = 'Perryridge' group by customer_name 
having count(account_number)>=2
