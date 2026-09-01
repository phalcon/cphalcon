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

use Phalcon\Talon\Database\Schema\AbstractSchema;

/**
 * Class OrdersMigration
 */
class OrdersMigration extends AbstractSchema
{
    protected string $table = "co_orders";

    public function insert(
        ?int $id,
        ?string $name = null,
        int $statusFlag = 0
    ): int {
        $sql    = <<<SQL
insert into co_orders (
    ord_id, ord_name, ord_status_flag
) values (
    :id, :name, :statusFlag
)
SQL;
        $params = [
            ':id'         => $id,
            ':name'       => $name ?: uniqid(),
            ':statusFlag' => $statusFlag,
        ];

        $result = $this->execute($sql, $params);

        if ($id !== null) {
            $this->advanceSequence('ord_id', $id);
        }

        return $result;
    }

    protected function getStatementsMysql(): array
    {
        return [
            "
CREATE TABLE `co_orders` (
    `ord_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `ord_name` VARCHAR(70) NULL,
    `ord_status_flag` tinyint(1) NULL,
    PRIMARY KEY (`ord_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
"create table `co_orders` (
    `ord_id` integer constraint ord_id_pk primary key autoincrement,
    `ord_name` text NULL,
    `ord_status_flag` integer NULL
);"
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
create table co_orders
(
    ord_id serial not null constraint ord_pk primary key,
    ord_name varchar(70),
    ord_status_flag integer
);
            "
        ];
    }
}
