DROP TABLE IF EXISTS "table_with_uuid_primary";

create table table_with_uuid_primary
(
    uuid char(36) not null primary key,
    int_field int null
);
