DROP TABLE IF EXISTS "table_with_uuid_primary";

create table table_with_uuid_primary
(
    uuid        text constraint uuid_pk primary key,
    int_field   integer
);
