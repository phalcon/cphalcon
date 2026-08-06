DROP TABLE IF EXISTS "albums";

create table albums
(
    id         integer constraint albums_pk primary key autoincrement not null,
    artists_id integer not null,
    name       text    not null
);

create index albums_artists_id_index on albums (artists_id);
