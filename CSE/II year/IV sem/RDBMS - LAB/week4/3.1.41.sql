select branch_name from account 
group by branch_name
having sum(balance) >= all
(select sum(balance) from account group by branch_name)

