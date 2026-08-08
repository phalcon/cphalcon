DROP TABLE IF EXISTS `photo`;

CREATE TABLE `photo` (
	`id`                int(10) unsigned not null auto_increment,
	`date_uploaded`     datetime not null default current_timestamp(),
	`original_filename` text not null collate 'utf8mb4_unicode_520_ci',
	`path`              text not null collate 'utf8mb4_unicode_520_ci',
	`width`             smallint(11) unsigned not null,
	`height`            smallint(11) unsigned not null,
	`thumb_path`        text not null collate 'utf8mb4_unicode_520_ci',
	`thumb_width`       smallint(5) unsigned not null,
	`thumb_height`      smallint(5) unsigned not null,
	`display_path`      text not null collate 'utf8mb4_unicode_520_ci',
	`display_width`     smallint(5) unsigned not null,
	`display_height`    smallint(5) unsigned not null,
	`mime_type`         VARCHAR(255) not null collate 'utf8mb4_unicode_520_ci',
	`filesize`          int(11) unsigned NULL DEFAULT NULL comment 'In bytes',
	`phash`             bigint(255) unsigned not null,
	`battles`           int(10) unsigned not null DEFAULT '0',
	`wins`              int(10) unsigned not null DEFAULT '0',
	primary key (`id`) using BTREE
) collate='utf8mb4_unicode_520_ci';
