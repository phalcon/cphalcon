DROP TABLE IF EXISTS "photo";

create table photo
(
    id                serial        constraint photo_pk primary key,
    date_uploaded     timestamp     not null default current_timestamp,
    original_filename text          not null,
    path              text          not null,
    width             smallint      not null,
    height            smallint      not null,
    thumb_path        text          not null,
    thumb_width       smallint      not null,
    thumb_height      smallint      not null,
    display_path      text          not null,
    display_width     smallint      not null,
    display_height    smallint      not null,
    mime_type         varchar(255)  not null,
    filesize          integer       null,
    phash             bigint        not null,
    battles           integer       not null default 0,
    wins              integer       not null default 0
);
