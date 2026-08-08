DROP TABLE IF EXISTS "co_setters";

create table co_setters
(
    id      SERIAL PRIMARY KEY,
    column1 varchar(100) not null,
    column2 varchar(100) not null,
    column3 varchar(100) not null
);
