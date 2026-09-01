DROP TABLE IF EXISTS "ph_select";

create table ph_select
(
    sel_id   integer not null,
    sel_name text    not null,
    sel_text text             default null,
    primary key (sel_id autoincrement)
);
