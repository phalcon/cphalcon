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

namespace Phalcon\Tests\Fixtures\Migrations;

use PHPUnit\Framework\Assert;

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
        $id,
        string $name,
        int $albumId = null,
        int $photoId = null
    ): int {

        $id     = $id ?: 'null';
        $sql    = <<<SQL
insert into album (
    id, name, album_id, proto_id
) values (
    {$id}, {$name}, {$albumId}, '{$photoId}'
)
SQL;

        if (!$result = $this->connection->exec($sql)) {
            $table  = $this->getTable();
            $driver = $this->getDriverName();
            Assert::fail(
                sprintf("Failed to insert row #%d into table '%s' using '%s' driver", $id, $table, $driver)
            );
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
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }
}
