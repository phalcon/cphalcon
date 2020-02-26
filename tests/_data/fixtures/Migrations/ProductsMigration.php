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
 * Class ProductsMigration
 */
class ProductsMigration extends AbstractMigration
{
    protected $table = "co_products";

    /**
     * @param int         $prd_id
     * @param string|null $prd_name
     *
     * @return int
     */
    public function insert(
        $prd_id,
        string $prd_name = null
    ): int {
        $prd_id    = $prd_id ?: 'null';
        $prd_name  = $prd_name ?: uniqid();
        $sql    = <<<SQL
insert into co_products (
    prd_id, prd_name
) values (
    {$prd_id}, {$prd_name}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_products`;
            ",
            "
CREATE TABLE `co_products` (
    `prd_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `prd_name` VARCHAR(70) NULL,
    PRIMARY KEY (`prd_id`)
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
drop table if exists co_products;            
            ",
            "
create table co_products
(
    prd_id serial not null
    constraint prd_pk
      primary key,
      prd_name varchar(70)
);
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
