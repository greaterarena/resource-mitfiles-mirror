CREATE FUNCTION update_it(ac_no varchar)
RETURNS varchar AS $$
DECLARE amount numeric;
BEGIN
        SELECT  into amount balance
        FROM    account
        WHERE   ac_no = account_number;
	if (amount-2000)>500 then
	 begin
		update account set balance = balance - 2000
		where account_number = ac_no;
		return'updated';
	 end;	
	else return 'insufficient balance';
	end if;
END;
$$ LANGUAGE plpgsql STRICT;

select update_it('A-217');

drop function update_it(varchar);

select * from account;

