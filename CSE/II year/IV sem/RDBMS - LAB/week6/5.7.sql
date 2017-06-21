select proc_description from procedures where 
procedure_no in ( select distinct 
procedure_no from treats);