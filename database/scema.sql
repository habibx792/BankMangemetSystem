create database Bank;
use  Bank;
drop table owner;
drop table admin;
create table owner
(
	
	cnic varchar(50) not null primary key,
	OwnName varchar(50) not null ,
	password varchar(255)not null ,
	email varchar (50)not null
);
create table admin
(
	cnic varchar(50) not null primary key,
	OwnName varchar(50) not null ,
	password varchar(255)not null ,
);
