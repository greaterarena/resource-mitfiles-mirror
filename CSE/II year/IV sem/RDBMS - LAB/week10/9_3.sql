create table client_master (
client_no int primary key,
name varchar(300),
address varchar(300),
bal_due int);

insert into client_master values(1,'Alpha','555',1000);
insert into client_master values(2,'Beta','666',2000);
insert into client_master values(3,'Gamma','777',3000);
insert into client_master values(4,'Delta','888',4000);

create table audit_client (
client_no int,
name varchar(300),
bal_due int,
operation varchar(4),
userid varchar(10),
opdate timestamp not null default now());

create trigger del before delete or update on client_master
FOR EACH ROW
execute procedure root();

create or replace function root()
returns trigger as $BODY$
DECLARE op varchar;
	temp record;
BEGIN
	IF(TG_OP = 'DELETE') then
	begin
		op := 'DEL';
		temp := old;
	end;
	ELSIF(TG_OP = 'UPDATE') then
	begin
		op := 'UPDT';
		temp := new;
	end;
	ELSE 
		raise notice 'Invalid Operation';
	END IF;
	

	insert into audit_client(
		client_no,
		name,
		bal_due,
		operation,
		userid)
	Values(
		temp.client_no,
		temp.name,
		temp.bal_due,
		op,
		'root');
	return temp;
end;
$BODY$ Language plpgsql STRICT;

update client_master set bal_due = 1000 where client_no = 1;

delete from client_master where client_no = 1;

select * from client_master;

select * from audit_client;

