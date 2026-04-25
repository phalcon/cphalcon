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
 * Class StringPrimaryMigration
 */
class StringPrimaryMigration extends AbstractMigration
{
    protected $table = "table_with_uuid_primary";

    /**
     * @param string $uuid
     * @param int    $id
     */
    public function insert(
        string $uuid,
        ?int $intField
    ): int {
        $sql    = <<<SQL
insert into table_with_uuid_primary (uuid, int_field)
values (:uuid, :intField)
SQL;
        $params = [
            ':uuid'     => $uuid,
            ':intField' => $intField,
        ];

        return $this->execute($sql, $params);
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
            ",
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
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists table_with_uuid_primary;
            ",
            "
create table table_with_uuid_primary
(
    uuid char(36) not null primary key,
    int_field int null
);
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
