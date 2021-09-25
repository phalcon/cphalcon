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
 * Class OrdersMigration
 */
class OrdersMigration extends AbstractMigration
{
    protected $table = "co_orders";

    /**
     * @param int         $prdt_id
     * @param string|null $prdt_name
     *
     * @return int
     */
    public function insert(
        $ord_id,
        string $ord_name = null
    ): int {
        $ord_id    = $ord_id ?: 'null';
        $ord_name  = $ord_name ?: uniqid();
        $sql    = <<<SQL
insert into co_orders (
    ord_id, ord_name
) values (
    {$ord_id}, {$ord_name}
)
SQL;

        return $this->connection->exec($sql);
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
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
