<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Fixtures\Migrations;

/**
 * Class SettersMigration
 */
class SettersMigration extends AbstractMigration
{
    protected $table = "co_setters";

    /**
     * @param string $column1
     * @param string $column2
     * @param string $column3
     */
    public function insert(
        string $column1,
        string $column2,
        string $column3
    ) {
        $sql = <<<SQL
insert into co_setters (column1, column2, column3)
values ('{$column1}', '{$column2}', '{$column3}');
SQL;

        $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_setters`;
            ",
            "
create table co_setters
(
    `id`       int(10) auto_increment primary key,
    `column1`  varchar(100) null,
    `column2`  varchar(100) null,
    `column3`  varchar(100) null
);
            ",
            //            $this->insert($db, 'val1', 'val2', 'val3');
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_setters;
            ",
            "
create table co_setters
    (
    id        integer constraint co_setters_defaults_pk primary key autoincrement,
    column1    text,
    column2    text,
    column3    text
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_setters;
            ",
            "
create table co_setters
(
    id      SERIAL PRIMARY KEY,
    column1 varchar(100) not null,
    column2 varchar(100) not null,
    column3 varchar(100) not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
