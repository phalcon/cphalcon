DROP TABLE IF EXISTS "stuff";

create table stuff
(
    stf_id   serial       constraint stuff_pk primary key,
    stf_name varchar(100) not null,
    stf_type smallint     not null
);
