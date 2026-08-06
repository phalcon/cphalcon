DROP TABLE IF EXISTS "album_photo";

create table album_photo
(
    id       serial   constraint album_photo_pk primary key,
    photo_id integer  null,
    album_id integer  null,
    position integer  not null default 999999999,
    constraint UQ_cadf1c545153612614511f15197cae7b6dacac97 unique (album_id, photo_id)
);

create index index_foreignkey_album_photo_photo on album_photo (photo_id);

create index index_foreignkey_album_photo_album on album_photo (album_id);
