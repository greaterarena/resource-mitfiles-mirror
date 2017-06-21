select * from item_master

update item_master
set cost = 100

alter table item_master
add column cost int

select * from item_transaction

alter table item_transaction 
add column user_id int

-- first disable triggers then reenable after update

update item_transaction 
set user_id = 1

CREATE OR REPLACE FUNCTION magic1(c_id int) RETURNS int as $$
DECLARE 
	data record;
	costy int;
	total_cost int;
	curs CURSOR FOR select * from item_transaction where user_id = c_id;
	cur_temp CURSOR (ic_r integer) IS SELECT cost FROM item_master WHERE itemid = ic_r;
	BEGIN

	total_cost := 0;
	open curs;
	
	loop
		fetch curs into data;
		exit when not found;
		open cur_temp(data.itemid);
		fetch cur_temp into costy;
		total_cost := total_cost + (data.quantity*costy);
		close cur_temp;
	end loop;
	return total_cost;
end;
$$ LANGUAGE plpgsql STRICT;

select magic1(1);






