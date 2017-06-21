select customer_name from loan natural join borrower
where branch_name = 'Perryridge' and
customer_name in
(select customer_name from account natural join depositor 
where branch_name = 'Perryridge');