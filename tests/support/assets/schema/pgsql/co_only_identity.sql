DROP TABLE IF EXISTS "co_only_identity";

create table co_only_identity
(
    oid_id serial not null constraint co_only_identity_pk primary key
);
