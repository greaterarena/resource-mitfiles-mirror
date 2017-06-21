drop table product_master;
drop table old_price_table;

create table product_master(
product_no varchar(6) primary key,
sell_price int);

create table old_price_table(
product_no varchar(6) primary key,
date_change date,
old_price int,
foreign key(product_no) references product_master(product_no));

insert into product_master values('p00001',3500);
insert into product_master values('p00002',4500);
insert into product_master values('p00003',5500);
insert into product_master values('p00004',6500);

select * from product_master;

CREATE OR REPLACE FUNCTION update_it2()
RETURNS varchar AS $$
DECLARE amount numeric;
BEGIN
        SELECT  into amount sell_price
        FROM    product_master
        WHERE   product_no = 'p00001';
	if amount<4000 then
	 begin
		update product_master set sell_price = 4000
		where  product_no = 'p00001';
		insert into old_price_table values('p00001','2014-03-04',amount);
		return 'updated';
	 end;	
	else return 'already updated';
	end if;
END;
$$ LANGUAGE plpgsql STRICT;

select update_it2();

select * from old_price_table;

select * from product_master;