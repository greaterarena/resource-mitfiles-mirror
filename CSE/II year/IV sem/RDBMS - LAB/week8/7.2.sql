drop table commission_payable;
drop table salesman_master;

CREATE TABLE salesman_master (
salesman_no int primary key,
salesman_name varchar(10),
rate_of_commission int,
tgt_to_get int,
total_sales int);

CREATE TABLE commission_payable (
salesman_no int,
date_of_payment date,
c_amount int,
foreign key (salesman_no) references salesman_master(salesman_no) on delete cascade);

insert into salesman_master values(1,'Batra',10,5000,8000);
insert into salesman_master values(2,'Suri',7,4000,6000);
insert into salesman_master values(3,'Narula',20,6000,10000);
insert into salesman_master values(4,'Karkhanis',8,7000,2000);

select * from salesman_master;

CREATE OR REPLACE FUNCTION get_commission(s_no int)
RETURNS varchar AS $$
DECLARE target int; sales int; comm int; pay int; sno int;
BEGIN
        for temp in select * from empl
		sno := s_no;
		SELECT * from n
		FROM    salesman_master
		WHERE   salesman_no = s_no;
			        
	if sales>=target then
		begin
			pay := (sales/100)*comm;
			insert into commission_payable values(sno,'2014-08-08',pay);
			RETURN 'Eligible for Commission';		
		end;	
	elsif sales<target THEN
		Return 'NOT Eligible for commission';
	else 
		Return 'Record not Found';
	end if;	
END;

$$ LANGUAGE plpgsql STRICT;

select get_commission(1);

select * from commission_payable;