alter table marks 
add sum int;
update marks
set sum=marks.sub1+marks.sub2+marks.sub3