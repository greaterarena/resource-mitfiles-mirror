/*select avg(balance) from account where account_number in
(
select account_number from depositor
where customer_name = 
(select customer_name from depositor group by customer_name
having count(account_number) >= 2
intersect
select customer_name from customer where
customer_city = 'Harrison'));*/

select avg(balance), customer_name from 
depositor natural join account natural join customer
where customer_city = 'Harrison' group by customer_name
having count(customer_name)>=2;