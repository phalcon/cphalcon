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
class OrdersProductsFieldsMultMigration extends AbstractMigration
{
    protected $table = "co_orders_x_products_mult";

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
        int $oxp_quantity,
        int $oxp_ord_status_flag = 0,
        int $oxp_prd_status_flag = 0
    ): int {
        $oxp_id   = $oxp_id ?: 'null';
        $oxp_ord_id   = $oxp_ord_id ?: 'null';
        $oxp_prd_id   = $oxp_prd_id ?: 'null';
        $oxp_quantity = $oxp_quantity ?: 'null';
        $oxp_ord_status_flag = $oxp_ord_status_flag ?: 0;
        $oxp_prd_status_flag = $oxp_prd_status_flag ?: 0;
        $sql    = <<<SQL
insert into co_orders_x_products_mult (
    oxp_id, oxp_ord_id, oxp_prd_id, oxp_quantity, oxp_ord_status_flag, oxp_prd_status_flag
) values (
    {$oxp_id}, {$oxp_ord_id}, {$oxp_prd_id}, {$oxp_quantity}, {$oxp_ord_status_flag}, {$oxp_prd_status_flag}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_orders_x_products_mult`;
            ",
            "
CREATE TABLE  `co_orders_x_products_mult` (
  `oxp_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_ord_status_flag` tinyint(1) NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_prd_status_flag` tinyint(1) NOT NULL,
  `oxp_quantity` int(10) unsigned NULL,
  PRIMARY KEY (`oxp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
"drop table if exists co_orders_x_products_mult;",
"create table co_orders_x_products_mult (
  `oxp_id` integer constraint co_oxp_mult_pk primary key autoincrement,
  `oxp_ord_id` integer NOT NULL,
  `oxp_ord_status_flag` integer NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_prd_status_flag` integer NULL,
  `oxp_quantity` integer NULL
);"
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_orders_x_products_mult;
            ",
            "
create table co_orders_x_products_mult
(
    oxp_id serial not null constraint co_oxp_mult_pk primary key,
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null,
    oxp_ord_status_flag integer,
    oxp_prd_status_flag integer
);
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
