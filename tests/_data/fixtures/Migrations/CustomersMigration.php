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
 * Class CustomersMigration
 */
class CustomersMigration extends AbstractMigration
{
    protected $table = "co_customers";

    /**
     * @param int         $id
     * @param int|null    $custId
     * @param int         $status
     * @param string|null $title
     * @param float       $total
     * @param string|null $createdAt
     *
     * @return int
     */
    public function insert(
        $id,
        int $custId = null,
        int $status = 0,
        string $title = null,
        float $total = 0,
        string $createdAt = null
    ): int {
        $id     = $id ?: 'null';
        $title  = $title ?: uniqid();
        $custId = $custId ?: 1;
        $now    = $createdAt ?: date('Y-m-d H:i:s');
        $sql    = <<<SQL
insert into co_customers (
    `inv_id`, `inv_cst_id`, `inv_status_flag`, `inv_title`, `inv_total`, `inv_created_at`
) values (
    {$id}, {$custId}, {$status}, "{$title}", {$total}, "{$now}"
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_customers`;
            ",
            "
create table co_customers
(
    `cst_id`          int(10) auto_increment primary key,
    `cst_status_flag` tinyint(1)   null,
    `cst_name_last`   varchar(100) null,
    `cst_name_first`  varchar(50)  null
);
            ",
            "
create index co_customers_inv_status_flag_index
    on `co_customers` (`cst_status_flag`);
            ",
            "
create index co_customers_inv_cst_id_index
    on `co_customers` (`cst_name_last`);
            ",
            "
create index co_customers_inv_status_flag_index
    on `co_customers` (`cst_name_first`);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_customers;
            ",
            "
create table co_customers
(
    cst_id          integer constraint co_customers_pk primary key autoincrement,
    cst_status_flag integer      null,
    cst_name_last   text         null,
    cst_name_first  text         null
);
            ",
            "
create index co_customers_inv_status_flag_index
    on co_customers (cst_status_flag);
            ",
            "
create index co_customers_inv_cst_id_index
    on co_customers (cst_name_last);
            ",
            "
create index co_customers_inv_status_flag_index
    on co_customers (cst_name_first);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
