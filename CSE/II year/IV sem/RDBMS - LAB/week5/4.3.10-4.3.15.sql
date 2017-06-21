select customer_name, length(customer_name) from customer; /* 4.3.10 */
select lower(customer_name) from customer; /*4.3.11*/
select substr(customer_name,0,3) from customer; /*4.3.12*/
select upper(customer_name) from customer; /*4.3.13*/
select balance,round(balance/3,5) from account; /*4.3.15*/


