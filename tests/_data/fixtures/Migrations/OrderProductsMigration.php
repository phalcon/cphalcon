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
 * Class OrderProductsMigration
 */
class OrderProductsMigration extends AbstractMigration
{
    protected $table = "co_order_products";

    /**
     * @param int $cst_id
     * @param int $prdt_id
     *
     * @return int
     */
    public function insert(
        $cst_id,
        int $prdt_id
    ): int {
        $cst_id      = $cst_id ?: 'null';
        $prdt_id = $prdt_id ?: 'null';
        $sql    = <<<SQL
insert into co_order_products (
    cst_id, prdt_id
) values (
    {$cst_id}, {$prdt_id}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists private.`co_order_products`;
            ",
            "
CREATE TABLE private.`co_order_products` (
  `cst_id` int(10) unsigned NOT NULL,
  `prdt_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`cst_id`, `prdt_id` )
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
drop table if exists private.co_order_products;
            ",
            "
create table private.co_order_products
(
    cst_id int not null,
    prdt_id int not null
);
            ",
            "
alter table private.co_order_products owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
