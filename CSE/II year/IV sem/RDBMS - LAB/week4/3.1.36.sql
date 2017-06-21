select distinct customer_name from borrower as b1
where exists (select customer_name from depositor as b2
where b1.customer_name = b2.customer_name);