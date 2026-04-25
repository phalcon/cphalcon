<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Migrations;

/**
 * Class ObjectsMigration
 */
class ObjectsMigration extends AbstractMigration
{
    protected $table = "objects";

    public function insert(
        int $id,
        string $name,
        int $type,
    ) {
        $sql = <<<SQL
insert into objects (
    obj_id, obj_name, obj_type
) values (
    :id, :name, :type
);
SQL;

        $params = [
            ':id'    => $id > 0 ? $id : null,
            ':name'  => $name,
            ':type'  => $type,
        ];

        return $this->execute($sql, $params);

        $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists objects;
            ",
            "
create table objects
(
    `obj_id`   int(10) auto_increment primary key,
    `obj_name` varchar(100) not null,
    `obj_type` tinyint(3) unsigned not null
);
            ",
            //        $this->insertObject($db, 1, 'random data', 1);
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists objects;
            ",
            "
create table objects
(
    obj_id serial not null constraint objects_pk primary key,
    obj_name varchar(100) not null,
    obj_type smallint not null
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists `objects`;
            ",
            "
create table objects
    (
    obj_id     integer constraint objects_pk primary key autoincrement,
    obj_name   text not null,
    obj_type   integer not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
