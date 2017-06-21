select customer_name from loan natural join borrower
where customer_name not in
(select customer_name from account natural join depositor);