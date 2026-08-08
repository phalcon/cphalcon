DROP TABLE IF EXISTS "co_manufacturers";

create table co_manufacturers (
    id integer constraint co_manufacturers_pk primary key autoincrement,
    name text not null,
    country text null,
    founded_year integer not null
);
