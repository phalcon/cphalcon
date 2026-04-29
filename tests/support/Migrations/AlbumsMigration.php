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


/**
 * Class AlbumsMigration
 *
 * Manages the `albums` table used by the AlbumORama model fixtures.
 * Note: distinct from AlbumMigration which manages the singular `album` table.
 */
class AlbumsMigration extends AbstractMigration
{
    protected $table = 'albums';
    /**
     * @param int    $id
     * @param int    $artistsId
     * @param string $name
     *
     * @return int
     */
    public function insert(int $id, int $artistsId, string $name): int
    {
        $sql    = <<<SQL
insert into albums (id, artists_id, name) values (:id, :artistsId, :name)
SQL;
        $params = [
            ':id'        => $id,
            ':artistsId' => $artistsId,
            ':name'      => $name,
        ];

        $result = $this->execute($sql, $params);
        $this->advanceSequence('id', $id);

        return $result;
    }
    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `albums`;
            ",
            "
create table `albums`
(
    `id`         int(10) auto_increment primary key,
    `artists_id` int(10)      not null,
    `name`       varchar(100) not null
);
            ",
            "
create index albums_artists_id_index on `albums` (`artists_id`);
            ",
        ];
    }
    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists albums;
            ",
            "
create table albums
(
    id         integer constraint albums_pk primary key autoincrement not null,
    artists_id integer not null,
    name       text    not null
);
            ",
            "
create index albums_artists_id_index on albums (artists_id);
            ",
        ];
    }
    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists albums;
            ",
            "
create table albums
(
    id         serial       constraint albums_pk primary key,
    artists_id integer      not null,
    name       varchar(100) not null
);
            ",
            "
create index albums_artists_id_index on albums (artists_id);
            ",
        ];
    }
    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
