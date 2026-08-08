DROP TABLE IF EXISTS "no_primary_key";

create table no_primary_key
(
    nokey_id   integer,
    nokey_name text not null
);
