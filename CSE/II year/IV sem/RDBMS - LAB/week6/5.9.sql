select description, normal_charge,
(normal_charge*0.06 + normal_charge) as
new_rate from item;