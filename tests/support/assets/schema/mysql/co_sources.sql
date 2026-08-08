DROP TABLE IF EXISTS `co_sources`;

create table co_sources
(
    `id`       int(10) auto_increment primary key,
    `username` varchar(100) null,
    `source`   varchar(100) null
);

create index co_sources_username_index
    on co_sources (username);
