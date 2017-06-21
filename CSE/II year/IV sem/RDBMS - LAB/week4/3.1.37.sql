select customer_name from
account as b1 natural join depositor
where exists (select * from branch
where b1.branch_name = 'Downtown'
and b1.branch_name='Brighton');
