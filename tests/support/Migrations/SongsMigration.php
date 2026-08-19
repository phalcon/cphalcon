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

use Phalcon\Talon\Database\Schema\AbstractSchema;


/**
 * Class SongsMigration
 */
class SongsMigration extends AbstractSchema
{
    protected string $table = 'songs';
    /**
     * @param int    $id
     * @param int    $albumsId
     * @param string $name
     *
     * @return int
     */
    public function insert(int $id, int $albumsId, string $name): int
    {
        $sql    = <<<SQL
insert into songs (id, albums_id, name) values (:id, :albumsId, :name)
SQL;
        $params = [
            ':id'       => $id,
            ':albumsId' => $albumsId,
            ':name'     => $name,
        ];

        $result = $this->execute($sql, $params);
        $this->advanceSequence('id', $id);

        return $result;
    }
    protected function getStatementsMysql(): array
    {
        return [
            "
create table `songs`
(
    `id`        int(10) auto_increment primary key,
    `albums_id` int(10)      not null,
    `name`      varchar(100) not null
);
            ",
            "
create index songs_albums_id_index on `songs` (`albums_id`);
            ",
        ];
    }
    protected function getStatementsSqlite(): array
    {
        return [
            "
create table songs
(
    id        integer constraint songs_pk primary key autoincrement not null,
    albums_id integer not null,
    name      text    not null
);
            ",
            "
create index songs_albums_id_index on songs (albums_id);
            ",
        ];
    }
    protected function getStatementsPgsql(): array
    {
        return [
            "
create table songs
(
    id        serial       constraint songs_pk primary key,
    albums_id integer      not null,
    name      varchar(100) not null
);
            ",
            "
create index songs_albums_id_index on songs (albums_id);
            ",
        ];
    }
}
