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


class AlbumMigration extends AbstractMigration
{
    protected $table = 'album';

    /**
     * @param int      $id
     * @param string   $title
     * @param int|null $albumId
     * @param int|null $photoId
     *
     * @return int
     */
    public function insert(
        ?int $id,
        string $name,
        ?int $albumId = null,
        ?int $photoId = null
    ): int {
        $sql    = <<<SQL
insert into album (
    id, name, album_id, proto_id
) values (
    :id, :name, :albumId, :photoId
)
SQL;
        $params = [
            ':id'      => $id ?? null,
            ':name'    => $name,
            ':albumId' => $albumId,
            ':photoId' => $photoId
        ];

        $result = $this->execute($sql, $params);

        if ($id !== null) {
            $this->advanceSequence('id', $id);
        }

        return $result;
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `album`;
            ",
            "
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

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists album;
            ",
            "
create table album
(
    id       serial        constraint album_pk primary key,
    name     varchar(100)  not null,
    album_id integer       null,
    photo_id integer       null
);
            ",
            "
create index index_foreignkey_album_album on album (album_id);
            ",
            "
create index album_ibfk_2 on album (photo_id);
            ",
        ];
    }
}
