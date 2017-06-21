select customer_name from loan natural join borrower
where branch_name = 'Perryridge' and customer_name not in
('Smith', 'Jones');