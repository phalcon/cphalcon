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
 * Class ProductsMigration
 */
class ProductsMigration extends AbstractSchema
{
    protected string $table = "co_products";

    public function insert(
        ?int $id,
        ?string $name = null,
        int $statusFlag = 0
    ): int {
        $sql    = <<<SQL
insert into co_products (
    prd_id, prd_name, prd_status_flag
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
            $this->advanceSequence('prd_id', $id);
        }

        return $result;
    }

    protected function getStatementsMysql(): array
    {
        return [
            "
CREATE TABLE `co_products` (
    `prd_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `prd_name` VARCHAR(70) NULL,
    `prd_status_flag` tinyint(1) NULL,
    PRIMARY KEY (`prd_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
"create table `co_products` (
    `prd_id` integer constraint prd_id_pk primary key autoincrement,
    `prd_name` text NULL,
    `prd_status_flag` integer NULL
);"
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
create table co_products
(
    prd_id serial constraint co_prd_pk primary key,
    prd_name varchar(70),
    prd_status_flag integer
);
            "
        ];
    }
}
