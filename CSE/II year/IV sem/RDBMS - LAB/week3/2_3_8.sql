update account
set balance = case
		when account_number='A-101' then balance-100
		when account_number='A-215' then balance+100
		else balance
	      end