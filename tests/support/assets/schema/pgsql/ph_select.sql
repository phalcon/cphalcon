DROP TABLE IF EXISTS "ph_select";

create table ph_select
(
    sel_id   serial      not null constraint ph_select_pk primary key,
    sel_name varchar(16) not null,
    sel_text varchar(32)          default null
);
