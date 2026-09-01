DROP TABLE IF EXISTS "album";

create table album
(
    id       integer constraint album_pk primary key autoincrement not null,
    name     text    not null,
    album_id integer null,
    photo_id integer null
);
