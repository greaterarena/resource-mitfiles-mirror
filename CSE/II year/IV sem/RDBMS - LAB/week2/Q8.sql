select student.name,marks.*from student,marks
where student.roll_no=marks.roll_no and
 student.branchname!='CSE' and student.branchname!='IT';