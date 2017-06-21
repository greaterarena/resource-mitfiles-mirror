create table item_master(
itemid int primary key,
description varchar(50),
bal_stock int);

create table item_transaction(
itemid int,
description varchar(50),
quantity int,
foreign key (itemid) references item_master(itemid));

insert into item_master values(1,'I am a tea pot',10);
insert into item_master values(2,'I am a knife',20);
insert into item_master values(3,'I am a plane',30);
insert into item_master values(4,'I am batman',40);
insert into item_master values(5,'We can make the world stop',50);

create trigger explode after insert on item_transaction
FOR EACH ROW
execute procedure update_master();

drop trigger explode on item_transaction

create or replace function update_master()
returns trigger as $body$
DECLARE
	curs cursor for select * from salary;	
	temp record;
begin
	update item_master
	set bal_stock = bal_stock - NEW.quantity
	where itemid = NEW.itemid;
	return NEW;
end;
$body$ language plpgsql STRICT;

CREATE OR REPLACE FUNCTION buy_stuff(icode int, qty int)
RETURNS varchar AS $$
DECLARE
temp record;
cur_temp CURSOR (ic_r integer) IS SELECT * FROM item_master WHERE itemid = ic_r;
BEGIN
	open cur_temp(icode);
	fetch cur_temp into temp;
	if temp.bal_stock >= qty Then
		begin
			insert into item_transaction values(icode,temp.description,qty);
			return 'all done';
		end;
	else
		return 'Insufficient Quantity or item doesnt exist';
	end if;
end;
$$ LANGUAGE plpgsql STRICT;

select buy_stuff(2,5);

select * from item_master;

select * from item_transaction;
