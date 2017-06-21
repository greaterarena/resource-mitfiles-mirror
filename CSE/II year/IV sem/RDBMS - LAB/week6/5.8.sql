select proc_description as x from procedures where 
procedure_no in ( select distinct 
procedure_no from treats);