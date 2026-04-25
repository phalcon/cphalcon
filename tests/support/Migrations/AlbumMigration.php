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

use PHPUnit\Framework\Assert;

class AlbumMigration extends AbstractMigration
{
    protected $table = 'album';

    public function insert(
        ?int $id,
        string $name,
        ?int $albumId = null,
        ?int $photoId = null,
    ): int {
        $sql = <<<'SQL'
INSERT INTO album (
    id, name, album_id, proto_id
) VALUES (
    :id, :name, :album_id, :proto_id
)
SQL;

        $params = [
            ':id'       => $id ?? null,
            ':name'     => $name,
            ':album_id' => $albumId ?? null,
            ':proto_id' => $photoId ?? null,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `album`;
            ",
            "
CREATE TABLE `album` (
	`id`       int(11) unsigned not null auto_increment,
	`name`     varchar(100)     not null collate 'utf8mb4_unicode_520_ci',
	`album_id` int(11) unsigned null default null,
	`photo_id` int(11) unsigned null default null comment 'The ID of the featured photo',
	primary key (`id`) using BTREE,
	index `index_foreignkey_album_album` (`album_id`) using BTREE,
	index `album_ibfk_2` (`photo_id`) using BTREE,
	constraint `album_ibfk_1` foreign key (`album_id`) references `album` (`id`) on update cascade on delete cascade,
	constraint `album_ibfk_2` foreign key (`photo_id`) references `photo` (`id`) on update cascade on delete set null
) collate='utf8mb4_unicode_520_ci';
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists album;
            ",
            "
CREATE TABLE album (
    id       INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name     VARCHAR(100) NOT NULL,
    album_id INTEGER REFERENCES album(id) ON DELETE CASCADE,
    photo_id INTEGER REFERENCES photo(id) ON DELETE SET NULL,
    CONSTRAINT album_ibfk_1 FOREIGN KEY (album_id) REFERENCES album(id) ON DELETE CASCADE,
    CONSTRAINT album_ibfk_2 FOREIGN KEY (photo_id) REFERENCES photo(id) ON DELETE SET NULL
)
            ",
            "
CREATE INDEX index_foreignkey_album_album ON album(album_id)
            ",
            "
CREATE INDEX album_ibfk_2 ON album(photo_id)
            ",
            "
COMMENT ON COLUMN album.photo_id IS 'The ID of the featured photo'            
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists album;
            ",
            "
create table album
(
    id       integer constraint album_pk primary key autoincrement not null,
    name     text    not null,
    album_id integer null,
    photo_id integer null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
