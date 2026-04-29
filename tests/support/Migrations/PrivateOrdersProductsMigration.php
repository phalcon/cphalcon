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
 * Class PrivateOrdersProductsMigration
 *
 * Creates co_orders_x_products in the private schema, used by the
 * OrdersProductsPrivate model for cross-schema relation tests.
 */
class PrivateOrdersProductsMigration extends AbstractMigration
{
    protected $table = "private.co_orders_x_products";

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
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            ",
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
    oxp_ord_id  int not null,
    oxp_prd_id  int not null,
    oxp_quantity int not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}