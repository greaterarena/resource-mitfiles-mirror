select student.name,student.branchname from student,marks
where student.roll_no=marks.roll_no and
 student.branchname='MECH' and marks.sub1>=10;