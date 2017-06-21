select patient_no, date_discharged, sum(charge)
from patients natural join billed
group by patient_no, date_discharged
