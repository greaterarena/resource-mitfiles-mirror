begin;
/*3.1.47*/
savepoint q1;	
create view loany(no) as select loan_number from loan 
where amount > 1299 and amount < 1501;
delete from borrower where loan_number in (select no from loany);
delete from loan where loan_number in (select no from loany);
savepoint q2;

select * from loan;

/*3.1.48*/
create view acc1(no) as select account_number from account 
where branch_name in (select branch_name from branch where
branch_city='Brooklyn');

delete from depositor where account_number in (select no from acc1);
delete from account where account_number in (select no from acc1);

savepoint q3;

select * from depositor;

/*3.1.49*/

insert into depositor
select customer_name,CONCAT('A',loan_number) from loan
natural join borrower where branch_name = 'Perryridge';
insert into account 
select CONCAT('A',loan_number), branch_name, 200
from loan where branch_name='Perryridge';

/*delete from account where account_number like 'AL%'*/

savepoint q4;

select * from account;

/*3.1.50*/

update account 
set balance = balance + ((balance * 5) / 100)
where balance > 1000;

savepoint q5;

select * from account;

/*3.1.51*/

update account 
set balance = balance + ((balance * 5) / 100)
where account_number in (
select account_number from account 
where balance > (select avg(balance)
from account));

savepoint q6;

select * from account;

/*3.1.52*/

update account 
set balance = case
	when balance > 1000 then balance + ((balance * 6) / 100)
	else balance + ((balance * 5) / 100)
	end;

savepoint q9;

select * from account;

rollback to q1;

end;







