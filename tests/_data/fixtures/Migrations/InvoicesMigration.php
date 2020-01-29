<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\Db\Adapter\AdapterInterface;

class InvoicesMigration extends AbstractMigration
{
    protected $table = "co_invoices";

    /**
     * @param int         $id
     * @param string|null $title
     *
     * @return int
     */
    public function insert(
        int $id,
        string $title = null
    ): int {
        $title = $title ?: uniqid();
        $now   = date('Y-m-d H:i:s');
        $total = 100 + $id;
        $flag  = (int) ($id % 2);
        $sql   = <<<SQL
insert into co_invoices (
    `inv_id`, `inv_cst_id`, `inv_status_flag`, `inv_title`, `inv_total`, `inv_created_at`
) values (
    {$id}, 1, {$flag}, "{$title}", {$total}, "{$now}"
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_invoices`;
            ",
            "
create table co_invoices
(
    `inv_id`          int(10) auto_increment primary key,
    `inv_cst_id`      int(10)      null,
    `inv_status_flag` tinyint(1)   null,
    `inv_title`       varchar(100) null,
    `inv_total`       float(10, 2) null,
    `inv_created_at`  datetime     null
);
            ",
            "
create index co_invoices_inv_created_at_index
    on `co_invoices` (`inv_created_at`);
            ",
            "
create index co_invoices_inv_cst_id_index
    on `co_invoices` (`inv_cst_id`);
            ",
            "
create index co_invoices_inv_status_flag_index
    on `co_invoices` (`inv_status_flag`);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
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
