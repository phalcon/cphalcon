DROP TABLE IF EXISTS "songs";

create table songs
(
    id        integer constraint songs_pk primary key autoincrement not null,
    albums_id integer not null,
    name      text    not null
);

create index songs_albums_id_index on songs (albums_id);
