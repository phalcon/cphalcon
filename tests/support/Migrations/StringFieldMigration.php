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

class StringFieldMigration extends AbstractMigration
{
    protected $table = 'table_with_string_field';

    protected function getSqlMysql(): array
    {
        return [
            "drop table if exists `table_with_string_field`;",
            "create table `table_with_string_field`
            (
                `id`    int(10) unsigned not null auto_increment primary key,
                `field` varchar(255) not null
            ) engine=InnoDB default charset=utf8;",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "drop table if exists table_with_string_field;",
            "create table table_with_string_field
            (
                id    integer constraint table_with_string_field_pk primary key autoincrement not null,
                field text not null
            );",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "drop table if exists table_with_string_field;",
            "create table table_with_string_field
            (
                id    serial       constraint table_with_string_field_pk primary key,
                field varchar(255) not null
            );",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}