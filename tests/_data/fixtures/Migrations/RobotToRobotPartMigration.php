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
 * Class RobotToRobotPartMigration
 */
class RobotToRobotPartMigration extends AbstractMigration
{
    protected $table = "robot_to_robot_part";

    /**
     * @param int $robot_id
     * @param int $robot_part_id
     *
     * @return int
     */
    public function insert(
        $robot_id,
        int $robot_part_id
    ): int {
        $robot_id      = $robot_id ?: 'null';
        $robot_part_id = $robot_part_id ?: 'null';
        $sql    = <<<SQL
insert into robot_to_robot_part (
    robot_id, robot_part_id
) values (
    {$robot_id}, {$robot_part_id}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists private.`robot_to_robot_part`;
            ",
            "
CREATE TABLE private.`robot_to_robot_part` (
  `robot_id` int(10) unsigned NOT NULL,
  `robot_part_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`robot_id`, `robot_part_id` )
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
drop table if exists private.robot_to_robot_part;
            ",
            "
create table private.robot_to_robot_part
(
  robot_id int not null,
  robot_part_id int not null
);
            ",
            "
alter table private.robot_to_robot_part owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
