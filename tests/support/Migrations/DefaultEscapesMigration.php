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
 * Defaults whose literals need escaping. MariaDB reports `COLUMN_DEFAULT` as
 * the quoted DDL source, so these exercise the unquoting in
 * `Pdo\Mysql::describeColumns()`; MySQL resolves them itself and pins the
 * values that unquoting has to reproduce.
 *
 * mysql/mariadb only - the behavior under test is specific to their
 * `INFORMATION_SCHEMA`.
 */
class DefaultEscapesMigration extends AbstractMigration
{
    protected $table = 'co_default_escapes';

    protected function getSqlMysql(): array
    {
        return [
            <<<'SQL'
drop table if exists `co_default_escapes`;
SQL,
            <<<'SQL'
create table co_default_escapes
(
    `field_id`         int(10) auto_increment primary key,
    `field_quote`      varchar(20) not null default 'it''s',
    `field_apostrophe` varchar(20) not null default '''',
    `field_backslash`  varchar(20) not null default 'a\\b',
    `field_newline`    varchar(20) not null default 'a\nb',
    `field_tab`        varchar(20) not null default 'a\tb',
    `field_null_word`  varchar(20) not null default 'NULL',
    `field_empty`      varchar(20) not null default '',
    `field_bit`        bit(1)      not null default b'1',
    `field_nullable`   varchar(20)     null default null
);
SQL,
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
