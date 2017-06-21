create view perryridge_customer as
select customer_name from all_customer
where branch_name = 'Perryridge'