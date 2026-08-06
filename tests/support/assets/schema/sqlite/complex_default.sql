DROP TABLE IF EXISTS "complex_default";

create table complex_default
(
    id           integer constraint complex_default_pk primary key autoincrement,
    created      text default (datetime('now')),
    updated      text default (datetime('now')),
    updated_null text null
);
