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
        int $oxpOrdId,
        int $oxpPrdId,
        int $oxpQuantity
    ): int {
        $sql    = <<<SQL
insert into co_orders_x_products (
    oxp_ord_id, oxp_prd_id, oxp_quantity
) values (
    :oxpOrdId, :oxpPrdId, :oxpQuantity
)
SQL;
        $params = [
            ':oxpOrdId'   => $oxpOrdId,
            ':oxpPrdId'   => $oxpPrdId,
            ':oxpQuantity' => $oxpQuantity,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_orders_x_products`;
            ",
            "
CREATE TABLE `co_orders_x_products` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NOT NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_orders_x_products;
            ",
            "
create table co_orders_x_products
(
    oxp_ord_id   integer not null,
    oxp_prd_id   integer not null,
    oxp_quantity integer not null,
    primary key (oxp_ord_id, oxp_prd_id)
);
            ",
        ];
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
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
