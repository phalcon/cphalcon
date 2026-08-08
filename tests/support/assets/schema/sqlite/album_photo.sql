DROP TABLE IF EXISTS "album_photo";

create table album_photo
(
    id       integer constraint album_photo_pk primary key autoincrement not null,
    photo_id integer null,
    album_id integer null,
    position integer not null default 999999999
);
