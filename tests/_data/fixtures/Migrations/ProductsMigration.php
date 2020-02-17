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
     * @param int         $prdt_id
     * @param string|null $prdt_name
     *
     * @return int
     */
    public function insert(
        $prdt_id,
        string $prdt_name = null
    ): int {
        $prdt_id    = $prdt_id ?: 'null';
        $prdt_name  = $prdt_name ?: uniqid();
        $sql    = <<<SQL
insert into co_products (
    prdt_id, prdt_name
) values (
    {$prdt_id}, {$prdt_name}
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
    `prdt_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `prdt_name` VARCHAR(70) NULL,
    PRIMARY KEY (`prdt_id`)
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
    prdt_id serial not null
    constraint robot_part_pk
      primary key,
      prdt_name varchar(70)
);
            ",
            "
alter table public.co_products owner to postgres;
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
