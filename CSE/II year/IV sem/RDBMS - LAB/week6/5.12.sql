select pat_name from patients natural join treats
where phy_id in (select phy_id from physician
where phy_name in ('Dr. Hawkeye Pierce','Dr. Trapper John',
'Dr. Jonas Salkman'));
