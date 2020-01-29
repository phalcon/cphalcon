<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\Db\Adapter\AdapterInterface;

class StringPrimaryMigration extends AbstractMigration
{
    protected $table = "table_with_uuid_primary";

    /**
     * @param string $uuid
     * @param int    $id
     */
    public function insert(
        string $uuid,
        int $id
    ) {
        if (0 === $id) {
            $id = null;
        }

//        $sql = <<<SQL
//insert into `table_with_uuid_primary` (`uuid`, `int_field`) VALUES
//    ('5741bfd7-6870-40b7-adf6-cbacb515b9a9', 1),
//    ('1c53079c-249e-0c63-af8d-52413bfa2a2b', 2);
//SQL;
        $sql = <<<SQL
insert into `table_with_uuid_primary` (`uuid`, `int_field`)
VALUES ('{$uuid}', {$id});
SQL;

        $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `table_with_uuid_primary`;
            ",
            "
create table table_with_uuid_primary
(
    `uuid`          char(36) not null primary key,
    `int_field`     int null
);
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists table_with_uuid_primary;
            ",
            "
create table table_with_uuid_primary
(
    uuid        text constraint uuid_pk primary key,
    int_field   integer
);
            "
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
