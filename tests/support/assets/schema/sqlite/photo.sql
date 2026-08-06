DROP TABLE IF EXISTS "photo";

create table photo
(
    id                integer constraint photo_pk primary key autoincrement not null,
    date_uploaded     text    not null default (datetime('now')),
    original_filename text    not null,
    path              text    not null,
    width             integer not null,
    height            integer not null,
    thumb_path        text    not null,
    thumb_width       integer not null,
    thumb_height      integer not null,
    display_path      text    not null,
    display_width     integer not null,
    display_height    integer not null,
    mime_type         text    not null,
    filesize          integer null,
    phash             integer not null,
    battles           integer not null default 0,
    wins              integer not null default 0
);
