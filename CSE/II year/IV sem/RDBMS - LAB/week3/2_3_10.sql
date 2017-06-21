delete from borrower where loan_number in
(select loan_number from loan where amount<1000);
delete from loan where amount<1000;