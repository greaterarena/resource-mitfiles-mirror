delete from depositor where account_number IN
(select account_number from account where branch_name='Downtown');

delete from account where branch_name='Downtown';

delete from borrower where loan_number IN
(select loan_number from loan where branch_name='Downtown');

delete from loan where branch_name='Downtown';
