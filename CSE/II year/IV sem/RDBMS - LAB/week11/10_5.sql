create table movie_transact(
id int primary key,
mv_no int,
u_name varchar,
qty int,
cost int,
foreign key (mv_no) references movie(mv_no));

create table movie(
mv_no int primary key,
mv_name varchar,
mv_type varchar);

insert into movie values (1,'Alpha','Action');
insert into movie values (2,'Beta','Detective');
insert into movie values (3,'Gamma','Childrens');
insert into movie values (4,'Delta','Mystery');
insert into movie values (5,'Rho','Thriller');

insert into movie_transact values(1,2,'IVAN',3,300);
insert into movie_transact values(2,1,'Vandana',2,200);
insert into movie_transact values(3,2,'Vandana',3,300);
insert into movie_transact values(4,3,'Vandana',4,400);
insert into movie_transact values(5,4,'Vandana',5,500);

select * from movie_transact

-- first procedure

CREATE OR REPLACE FUNCTION magic2(c_id varchar) RETURNS int as $$
DECLARE temp int;	
	curs CURSOR FOR select mv_no from movie_transact where u_name = c_id;
	BEGIN

		open curs;
		fetch curs into temp;	
		close curs;
		return temp;		
end;
$$ LANGUAGE plpgsql STRICT;

select magic2('IVAN');

-- second procedure

CREATE or replace FUNCTION magic2() RETURNS TABLE(Name varchar,mv_no int)
    AS $$ SELECT u_name,mv_no from movie_transact $$
    LANGUAGE SQL;

SELECT * FROM magic2();

-- third procedure

CREATE or replace FUNCTION magic3() RETURNS TABLE(Name varchar,Type varchar)
    AS $$ SELECT mv_name,mv_type from movie_transact natural join movie where u_name='Vandana' $$
    LANGUAGE SQL;

SELECT * FROM magic3();