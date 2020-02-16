<?php

declare(strict_types=1);

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
 * Class RobotMigration
 */
class RobotMigration extends AbstractMigration
{
    protected $table = "robot";

    /**
     * @param int         $robot_id
     * @param string|null $robot_name
     *
     * @return int
     */
    public function insert(
        $robot_id,
        string $robot_name = null
    ): int {
        $robot_id    = $robot_id ?: 'null';
        $robot_name  = $robot_name ?: uniqid();
        $sql    = <<<SQL
insert into robot (
    robot_id, robot_name
) values (
    {$robot_id}, {$robot_name}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists public.`robot`;
            ",
            "
CREATE TABLE public.`robot` (
  `robot_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `robot_name` VARCHAR(70) NULL,
  PRIMARY KEY (`robot_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
CREATE SCHEMA IF NOT EXISTS hardware;
            ",
            "
drop table if exists hardware.robot;            
            ",
            "
create table hardware.robot
(
  robot_id serial not null
    constraint robot_pk
      primary key,
  robot_name varchar(70)
);
            ",
            "
alter table hardware.robot owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
