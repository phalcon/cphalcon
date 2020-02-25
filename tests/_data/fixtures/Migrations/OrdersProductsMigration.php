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
 * Class OrdersProductsMigration
 */
class OrdersProductsMigration extends AbstractMigration
{
    protected $table = "co_orders_x_products";

    /**
     * @param int $oxp_ord_id
     * @param int $oxp_prd_id
     *
     * @return int
     */
    public function insert(
        int $oxp_ord_id,
        int $oxp_prd_id,
        int $oxp_quantity
    ): int {
        $oxp_ord_id   = $oxp_ord_id ?: 'null';
        $oxp_prd_id   = $oxp_prd_id ?: 'null';
        $oxp_quantity = $oxp_quantity ?: 'null';
        $sql    = <<<SQL
insert into co_order_products (
    oxp_ord_id, oxp_prd_id, oxp_quantity
) values (
    {$oxp_ord_id}, {$oxp_prd_id}, {$oxp_quantity}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists private.`co_orders_x_products`;
            ",
            "
CREATE TABLE private.`co_orders_x_products` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NOT NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id` )
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
drop table if exists private.co_orders_x_products;
            ",
            "
create table private.co_orders_x_products
(
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int not null
);
            ",
            "
alter table private.co_orders_x_products owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
