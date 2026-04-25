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
 * Class ProductsMigration
 */
class ProductsMigration extends AbstractMigration
{
    protected $table = "co_products";

    public function insert(
        ?int $id,
        ?string $name = null,
    ): int {
        $sql  = <<<SQL
insert into co_products (
    prd_id, prd_name
) values (
    :id, :name
)
SQL;

        $params = [
            ':id'   => $id ?? null,
            ':name' => $name ?? null,
        ];

        return $this->execute($sql, $params);
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
            ",
        ];
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
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
