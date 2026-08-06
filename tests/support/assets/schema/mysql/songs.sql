DROP TABLE IF EXISTS `songs`;

create table `songs`
(
    `id`        int(10) auto_increment primary key,
    `albums_id` int(10)      not null,
    `name`      varchar(100) not null
);

create index songs_albums_id_index on `songs` (`albums_id`);
