DROP TABLE IF EXISTS "stuff";

create table stuff
(
    stf_id      integer constraint stf_id_pk primary key autoincrement,
    stf_name    text not null,
    stf_type    integer not null
);
