DROP TABLE IF EXISTS "artists";

create table artists
(
    id   integer constraint artists_pk primary key autoincrement not null,
    name text not null
);
