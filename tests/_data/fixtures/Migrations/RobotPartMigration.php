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
 * Class RobotPartMigration
 */
class RobotPartMigration extends AbstractMigration
{
    protected $table = "robot_part";

    /**
     * @param int         $robot_part_id
     * @param string|null $robot_part_name
     *
     * @return int
     */
    public function insert(
        $robot_part_id,
        string $robot_part_name = null
    ): int {
        $robot_part_id    = $robot_part_id ?: 'null';
        $robot_part_name  = $robot_part_name ?: uniqid();
        $sql    = <<<SQL
insert into robot_part (
    robot_part_id, robot_part_name
) values (
    {$robot_part_id}, {$robot_part_name}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
CREATE SCHEMA IF NOT EXISTS hardware;
            "
            ,
            "
drop table if exists hardware.`robot_part`;
            ",
            "
CREATE TABLE hardware.`robot_part` (
    `robot_part_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `robot_part_name` VARCHAR(70) NULL,
    PRIMARY KEY (`robot_part_id`)
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
drop table if exists hardware.robot_part;            
            ",
            "
create table hardware.robot_part
(
  robot_part_id serial not null
    constraint robot_part_pk
      primary key,
  robot_part_name varchar(70)
);
            ",
            "
alter table hardware.robot_part owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
