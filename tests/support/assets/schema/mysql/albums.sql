DROP TABLE IF EXISTS `albums`;

create table `albums`
(
    `id`         int(10) auto_increment primary key,
    `artists_id` int(10)      not null,
    `name`       varchar(100) not null
);

create index albums_artists_id_index on `albums` (`artists_id`);
