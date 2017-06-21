select customer_name,loan_number,amount from depositor
natural join loan where loan.branch_name='Perryridge';