DROP TABLE IF EXISTS "co_manufacturers";

create table co_manufacturers
(
    id serial not null
    constraint manufacturers_pk
      primary key,
    name varchar(100) not null,
    country varchar(100) null,
    founded_year int not null
);
