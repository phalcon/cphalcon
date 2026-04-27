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
 * Class NoPrimaryKeyMigration
 */
class NoPrimaryKeyMigration extends AbstractMigration
{
    protected $table = "no_primary_key";

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `no_primary_key`;
            ",
            "
create table no_primary_key
(
    `nokey_id`   int(10) unsigned,
    `nokey_name` varchar(100) not null
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists no_primary_key;
            ",
            "
create table no_primary_key
(
    nokey_id   integer,
    nokey_name text not null
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists no_primary_key;
            ",
            "
create table no_primary_key
(
    nokey_id   integer,
    nokey_name varchar(100) not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}