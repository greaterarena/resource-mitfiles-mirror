create table marks(
roll_no int,
sub1 int,
sub2 int,
sub3 int,
foreign key (roll_no) references student
);