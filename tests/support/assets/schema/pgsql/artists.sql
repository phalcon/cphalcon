DROP TABLE IF EXISTS "artists";

create table artists
(
    id   serial constraint artists_pk primary key,
    name varchar(100) not null
);
