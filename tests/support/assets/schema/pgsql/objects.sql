DROP TABLE IF EXISTS "objects";

create table objects
(
    obj_id serial not null constraint objects_pk primary key,
    obj_name varchar(100) not null,
    obj_type smallint not null
);
