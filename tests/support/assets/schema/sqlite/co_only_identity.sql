DROP TABLE IF EXISTS "co_only_identity";

create table co_only_identity
(
    oid_id integer constraint co_only_identity_pk primary key autoincrement
);
