select branch_name from branch where assets > 
(select min(assets) from branch where branch_city = 'Brooklyn');