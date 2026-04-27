<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Migrations;

/**
 * Class StuffMigration
 */
class StuffMigration extends AbstractMigration
{
    protected $table = "stuff";

    /**
     * @param int    $id
     * @param string $name
     * @param int    $type
     */
    public function insert(
        ?int $id,
        string $name,
        int $type
    ): int {
        $sql    = <<<SQL
insert into stuff (stf_id, stf_name, stf_type)
values (:id, :name, :type)
SQL;
        $params = [
            ':id'   => $id,
            ':name' => $name,
            ':type' => $type,
        ];

        $result = $this->execute($sql, $params);

        if ($id !== null) {
            $this->advanceSequence('stf_id', $id);
        }

        return $result;
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `stuff`;
            ",
            "
create table stuff
(
    `stf_id`   int(10) auto_increment primary key,
    `stf_name` varchar(100) not null,
    `stf_type` tinyint(3) unsigned not null
);
            ",
            //            $this->insertStuff($db, 1, 'stuff data', 1);
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists stuff;
            ",
            "
create table stuff
(
    stf_id      integer constraint stf_id_pk primary key autoincrement,
    stf_name    text not null,
    stf_type    integer not null
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists stuff;
            ",
            "
create table stuff
(
    stf_id   serial       constraint stuff_pk primary key,
    stf_name varchar(100) not null,
    stf_type smallint     not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
