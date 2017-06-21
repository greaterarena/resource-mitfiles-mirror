select patients.*, phy_name from patients
natural join treats join physician using(phy_id)