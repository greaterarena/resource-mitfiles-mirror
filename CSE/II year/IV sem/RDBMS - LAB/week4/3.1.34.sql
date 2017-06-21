select branch_name from branch where
assets > some(select assets from branch 
where branch_city = 'Brooklyn')