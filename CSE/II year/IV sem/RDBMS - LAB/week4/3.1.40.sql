select avg(balance),branch_name from account
where balance > 200 group by branch_name