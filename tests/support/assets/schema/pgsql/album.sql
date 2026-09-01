DROP TABLE IF EXISTS "album";

create table album
(
    id       serial        constraint album_pk primary key,
    name     varchar(100)  not null,
    album_id integer       null,
    photo_id integer       null
);

create index index_foreignkey_album_album on album (album_id);

create index album_ibfk_2 on album (photo_id);
