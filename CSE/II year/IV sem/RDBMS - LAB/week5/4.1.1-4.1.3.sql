create table department(
deptno varchar(5) primary key,
deptname varchar(10) unique not null,
loca varchar(100) not null);

create table employee(
empno numeric Primary key,
empname varchar(100) not null,
sex varchar(1) not null,
salary numeric not null default 1000,
address varchar(300) not null,
dno varchar(5),
foreign key(dno) references department(deptno),
CONSTRAINT con1 CHECK (sex = 'M' or sex = 'F'));
