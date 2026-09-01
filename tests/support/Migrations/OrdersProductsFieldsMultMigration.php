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
 * Class OrdersProductsMigration
 */
class OrdersProductsFieldsMultMigration extends AbstractSchema
{
    protected string $table = "co_orders_x_products_mult";

    /**
     * @param int $oxp_ord_id
     * @param int $oxp_prd_id
     *
     * @return int
     */
    public function insert(
        ?int $oxpId,
        int $oxpOrdId,
        int $oxpPrdId,
        ?int $oxpQuantity = null,
        int $oxpOrdStatusFlag = 0,
        int $oxpPrdStatusFlag = 0
    ): int {
        $sql = <<<SQL
insert into co_orders_x_products_mult (
    oxp_id, oxp_ord_id, oxp_prd_id, oxp_quantity, oxp_ord_status_flag, oxp_prd_status_flag
) values (
    :oxpId, :oxpOrdId, :oxpPrdId, :oxpQuantity, :oxpOrdStatusFlag, :oxpPrdStatusFlag
)
SQL;
        $params = [
            ':oxpId'            => $oxpId,
            ':oxpOrdId'         => $oxpOrdId,
            ':oxpPrdId'         => $oxpPrdId,
            ':oxpQuantity'      => $oxpQuantity,
            ':oxpOrdStatusFlag' => $oxpOrdStatusFlag,
            ':oxpPrdStatusFlag' => $oxpPrdStatusFlag,
        ];

        $result = $this->execute($sql, $params);

        if ($oxpId !== null) {
            $this->advanceSequence('oxp_id', $oxpId);
        }

        return $result;
    }

    protected function getStatementsMysql(): array
    {
        return [
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

    protected function getStatementsSqlite(): array
    {
        return [
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

    protected function getStatementsPgsql(): array
    {
        return [
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
}
