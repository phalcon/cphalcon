<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Migrations;

class AlbumPhotoMigration extends AbstractMigration
{
    protected $table = 'album_photo';

    /**
     * @return int
     */
    public function insert(): int
    {
        return 0;
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `album_photo`;
            ",
            "
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
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "DROP TABLE IF EXISTS album_photo;",
            "
CREATE TABLE album_photo (
    id       INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    photo_id INTEGER,
    album_id INTEGER,
    position INTEGER NOT NULL DEFAULT 999999999,
    CONSTRAINT c_fk_album_photo_album_id FOREIGN KEY (album_id) REFERENCES album(id) ON DELETE CASCADE,
    CONSTRAINT c_fk_album_photo_photo_id FOREIGN KEY (album_photo) REFERENCES photo(id) ON DELETE CASCADE,
    CONSTRAINT UQ_cadf1c545153612614511f15197cae7b6dacac97 UNIQUE (album_id, photo_id)
);

CREATE INDEX index_foreignkey_album_photo_photo ON album_photo(photo_id);
CREATE INDEX index_foreignkey_album_photo_album ON album_photo(album_id);
",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists album_photo;
            ",
            "
create table album_photo
(
    id       integer constraint album_photo_pk primary key autoincrement not null,
    photo_id integer null,
    album_id integer null,
    position integer not null default 999999999
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
