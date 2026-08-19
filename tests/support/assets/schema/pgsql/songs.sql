DROP TABLE IF EXISTS "songs";

create table songs
(
    id        serial       constraint songs_pk primary key,
    albums_id integer      not null,
    name      varchar(100) not null
);

create index songs_albums_id_index on songs (albums_id);
