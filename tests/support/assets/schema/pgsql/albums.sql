DROP TABLE IF EXISTS "albums";

create table albums
(
    id         serial       constraint albums_pk primary key,
    artists_id integer      not null,
    name       varchar(100) not null
);

create index albums_artists_id_index on albums (artists_id);
