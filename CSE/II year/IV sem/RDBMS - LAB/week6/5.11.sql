/*with q1(p_no) as
(select patient_no from
billed group by patient_no having
sum(charge) > 500),
q2(p,q) as (select patient_no, 
item_code from billed where patient_no
in (select * from q1))
select p,q,normal_charge from q2, item where
q = item.item_code and normal_charge>100;
*/

with q1(p) as
(select patient_no from
billed group by patient_no having
sum(charge) > 500),
q2(p,q) as (select patient_no, 
item_code from billed where patient_no
in (select * from q1))
select p,sum(normal_charge) from q2, item
where q = item.item_code and normal_charge>100
group by p;