/* ultra create now */


create table room(
room_location char(4) primary key,
room_accomodation char(2),
room_extension numeric(4));

create table patients(
patient_no numeric(4) primary key,
date_admitted date,
date_discharged date,
pat_name varchar(250),
room_location char(4),
constraint f_room_location
foreign key (room_location) references room(room_location));

create table physician(
phy_id numeric(4) primary key,
phy_phone char(8),
phy_name varchar(250));

create table procedures(
procedure_no numeric(4) primary key,
proc_description varchar(250));

create table item(
item_code numeric(4) primary key,
description varchar(250),
normal_charge numeric(7,2));

create table treats(
phy_id numeric(4),
patient_no numeric(4),
procedure_no numeric(4),
date_treated date,
treat_result varchar(250),
constraint f_key1 foreign key(phy_id) references physician(phy_id),
constraint f_key2 foreign key(patient_no) references patients(patient_no),
constraint f_key3 foreign key(procedure_no) references procedures(procedure_no));

create table billed(
bill_no numeric(5) primary key,
patient_no numeric(4),
item_code numeric(4),
charge numeric(7,2),
constraint p_key1 foreign key(patient_no) references patients(patient_no),
constraint p_key2 foreign key(item_code) references item(item_code));