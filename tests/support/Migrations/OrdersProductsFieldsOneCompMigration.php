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
 * Class OrdersProductsFieldsOneCompMigration
 */
class OrdersProductsFieldsOneCompMigration extends AbstractSchema
{
    protected string $table = "co_orders_x_products_one_comp";

    /**
     * @param int $oxp_ord_id
     * @param int $oxp_prd_id
     *
     * @return int
     */
    public function insert(
        int $oxpOrdId,
        int $oxpPrdId,
        ?int $oxpQuantity = null
    ): int {
        $sql = <<<SQL
insert into co_orders_x_products_one_comp (
    oxp_ord_id, oxp_prd_id, oxp_quantity
) values (
    :oxpOrdId, :oxpPrdId, :oxpQuantity
)
SQL;
        $params = [
            ':oxpOrdId'    => $oxpOrdId,
            ':oxpPrdId'    => $oxpPrdId,
            ':oxpQuantity' => $oxpQuantity,
        ];

        return $this->execute($sql, $params);
    }

    protected function getStatementsMysql(): array
    {
        return [
            "
CREATE TABLE `co_orders_x_products_one_comp` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
"create table co_orders_x_products_one_comp (
  `oxp_ord_id` integer NOT NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_quantity` integer NULL,
  primary key (`oxp_ord_id`, `oxp_prd_id`)
);"
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
create table co_orders_x_products_one_comp
(
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null,
    primary key (oxp_ord_id, oxp_prd_id)
);
            "
        ];
    }
}
