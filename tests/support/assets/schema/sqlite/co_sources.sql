DROP TABLE IF EXISTS "co_sources";

create table co_sources
    (
    id          integer constraint co_sources_pk primary key autoincrement,
    username    text,
    source      text
);

create index co_sources_username_index
    on co_sources (username);
