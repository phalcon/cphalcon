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

namespace Phalcon\Tests\Fixtures\Migrations;

/**
 * Class OrdersProductsMigration
 */
class OrdersProductsFieldsOneMigration extends AbstractMigration
{
    protected $table = "co_orders_x_products_one";

    /**
     * @param int $oxp_ord_id
     * @param int $oxp_prd_id
     *
     * @return int
     */
    public function insert(
        int $oxp_id,
        int $oxp_ord_id,
        int $oxp_prd_id,
        int $oxp_quantity
    ): int {
        $oxp_id   = $oxp_id ?: 'null';
        $oxp_ord_id   = $oxp_ord_id ?: 'null';
        $oxp_prd_id   = $oxp_prd_id ?: 'null';
        $oxp_quantity = $oxp_quantity ?: 'null';
        $sql    = <<<SQL
insert into co_orders_x_products_one (
    oxp_id, oxp_ord_id, oxp_prd_id, oxp_quantity
) values (
    {$oxp_id}, {$oxp_ord_id}, {$oxp_prd_id}, {$oxp_quantity}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_orders_x_products_one`;
            ",
            "
CREATE TABLE `co_orders_x_products_one` (
  `oxp_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NULL,
  PRIMARY KEY (`oxp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
"drop table if exists co_orders_x_products_one;",
"create table co_orders_x_products_one (
  `oxp_id` integer constraint co_oxp_one_pk primary key autoincrement,
  `oxp_ord_id` integer NOT NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_quantity` integer NULL
);"
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_orders_x_products_one;
            ",
            "
create table co_orders_x_products_one
(
    oxp_id serial not null constraint co_oxp_one_pk primary key,
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null
);
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
