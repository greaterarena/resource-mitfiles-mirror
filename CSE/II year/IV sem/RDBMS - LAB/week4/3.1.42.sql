with max_bal(value) as 
(select max(balance) from account)
select balance from account,max_bal 
where balance = max_bal.value