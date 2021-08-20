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
values ({$column1}, "{$column2}", "{$column3}");
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
    `column1`  varchar(100) null,
    `column2`  varchar(100) null,
    `column3`  varchar(100) null
);
            ",
            "",
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
create table co_sources
    (
    column1    text,
    column2    text,
    column3    text
);
            ",
            "",
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
