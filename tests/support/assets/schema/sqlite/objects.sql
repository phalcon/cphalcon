DROP TABLE IF EXISTS "objects";

create table objects
    (
    obj_id     integer constraint objects_pk primary key autoincrement,
    obj_name   text not null,
    obj_type   integer not null
);
