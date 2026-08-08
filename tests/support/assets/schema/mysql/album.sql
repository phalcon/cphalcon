DROP TABLE IF EXISTS `album`;

CREATE TABLE `album` (
	`id`       int(11) UNSIGNED not null AUTO_INCREMENT,
	`name`     varchar(100)     not null collate 'utf8mb4_unicode_520_ci',
	`album_id` int(11) unsigned null default null,
	`photo_id` int(11) unsigned null default null COMMENT 'The ID of the featured photo',
	primary key (`id`) using BTREE,
	index `index_foreignkey_album_album` (`album_id`) using BTREE,
	index `album_ibfk_2` (`photo_id`) using BTREE,
	constraint `album_ibfk_1` foreign key (`album_id`) references `album` (`id`) on update cascade on delete cascade,
	constraint `album_ibfk_2` foreign key (`photo_id`) references `photo` (`id`) on update cascade on delete set null
) collate='utf8mb4_unicode_520_ci';
