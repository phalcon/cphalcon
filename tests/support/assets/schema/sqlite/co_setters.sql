DROP TABLE IF EXISTS "co_setters";

create table co_setters
    (
    id        integer constraint co_setters_defaults_pk primary key autoincrement,
    column1    text,
    column2    text,
    column3    text
);
