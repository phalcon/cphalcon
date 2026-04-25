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
 * Class OrdersMigration
 */
class OrdersMigration extends AbstractMigration
{
    protected $table = "co_orders";

    public function insert(
        ?int $id,
        ?string $name = null,
    ): int {
        $sql  = <<<SQL
insert into co_orders (
    ord_id, ord_name
) values (
    :id, :name
)
SQL;
        $params = [
            ':id'   => $id ?? null,
            ':name' => $name ?: uniqid(),
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_orders`;
            ",
            "
CREATE TABLE `co_orders` (
    `ord_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `ord_name` VARCHAR(70) NULL,
    PRIMARY KEY (`ord_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_orders;
            ",
            "
create table co_orders
(
    ord_id serial not null
    constraint ord_pk
      primary key,
      ord_name varchar(70)
);
            ",
        ];
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
