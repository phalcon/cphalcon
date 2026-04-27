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

/**
 * Class SelectMigration
 */
class SelectMigration extends AbstractMigration
{
    protected $table = 'ph_select';

    /**
     * @param string      $name
     * @param string|null $text
     */
    public function insert(
        string $name,
        ?string $text = null
    ): int {
        $sql    = <<<SQL
insert into ph_select (sel_name, sel_text)
values (:name, :text)
SQL;
        $params = [
            ':name' => $name,
            ':text' => $text,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `ph_select`;
            ",
            "
create table `ph_select`
(
    `sel_id`   int(11) unsigned not null auto_increment,
    `sel_name` varchar(16)      not null,
    `sel_text` varchar(32)               default null,
    primary key (`sel_id`)
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists ph_select;
            ",
            "
create table ph_select
(
    sel_id   integer not null,
    sel_name text    not null,
    sel_text text             default null,
    primary key (sel_id autoincrement)
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists ph_select;
            ",
            "
create table ph_select
(
    sel_id   serial      not null constraint ph_select_pk primary key,
    sel_name varchar(16) not null,
    sel_text varchar(32)          default null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}

