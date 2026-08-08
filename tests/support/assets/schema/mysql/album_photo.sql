DROP TABLE IF EXISTS `album_photo`;

CREATE TABLE `album_photo` (
	`id`       int(11) unsigned not null AUTO_INCREMENT,
	`photo_id` int(11) unsigned null default null,
	`album_id` int(11) unsigned null default null,
	`position` int(10) unsigned not null default '999999999',
	primary key (`id`) using BTREE,
	unique index `UQ_cadf1c545153612614511f15197cae7b6dacac97` (`album_id`, `photo_id`) using BTREE,
	index `index_foreignkey_album_photo_photo` (`photo_id`) using BTREE,
	index `index_foreignkey_album_photo_album` (`album_id`) using BTREE,
	constraint `c_fk_album_photo_album_id` foreign key (`album_id`) references `album` (`id`) on update cascade on delete cascade,
	constraint `c_fk_album_photo_photo_id` foreign key (`photo_id`) references `photo` (`id`) on update cascade on delete cascade
) collate='utf8mb4_unicode_520_ci';
