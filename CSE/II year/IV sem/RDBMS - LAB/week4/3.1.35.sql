select branch_name from branch where
assets > all(select assets from branch 
where branch_city = 'Brooklyn')