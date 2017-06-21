create table item_master(
itemid int primary key,
description varchar(50),
bal_stock int);

create table item_transaction(
itemid int,
description varchar(50),
quantity int,
foreign key (itemid) references item_master(itemid));

select * from item_master;

select * from item_transaction;

/*
update employee
set job_salary = case
	when dept_no = 19 then (delete job_salary from employee where dept_no = 19)
	end;
*/


insert into item_master values(1,'I am a tea pot',10);
insert into item_master values(2,'I am a knife',20);
insert into item_master values(3,'I am a plane',30);
insert into item_master values(4,'I am batman',40);
insert into item_master values(5,'We can make the world stop',50);

CREATE OR REPLACE FUNCTION buy_stuff(icode int, qty int)
RETURNS varchar AS $$
DECLARE
temp record;
cur_temp CURSOR (ic_r integer) IS SELECT * FROM item_master WHERE itemid = ic_r;
BEGIN
	open cur_temp(icode);
	fetch cur_temp into temp;
	--EXCEPTION
	--	WHEN data_exception THEN
	--		return 'Item does not exist';
	if temp.bal_stock >= qty Then
		begin
			update item_master
			set bal_stock = bal_stock - qty
			where itemid = icode;
			insert into item_transaction values(icode,temp.description,qty);
			return 'all done';
		end;
	else
		return 'Insufficient Quantity or item doesnt exist';
	end if;
end;
$$ LANGUAGE plpgsql STRICT;

select buy_stuff(66,5);

select * from item_master;

select * from item_transaction;