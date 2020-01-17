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
 * Class InvoicesMigration
 */
class InvoicesMigration extends AbstractMigration
{
    protected $table = "co_invoices";

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
insert into co_invoices (
    inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at
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
create index co_invoices_inv_cst_id_index
    on `co_invoices` (`inv_cst_id`);
            ",
            "
create index co_invoices_inv_status_flag_index
    on `co_invoices` (`inv_status_flag`);
            ",
            "
create index co_invoices_inv_created_at_index
    on `co_invoices` (`inv_created_at`);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_invoices;
            ",
            "
create table co_invoices
    (
    inv_id          integer constraint co_invoices_pk primary key autoincrement not null,
    inv_cst_id      integer,
    inv_status_flag integer,
    inv_title       text,
    inv_total       real,
    inv_created_at  text
);
            ",
            "
create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
            ",
            "
create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
            ",
            "
create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_invoices;
            ",
            "
create table co_invoices
(
    inv_id          serial not null constraint co_invoices_pk primary key,
    inv_cst_id      integer,
    inv_status_flag smallint,
    inv_title       varchar(100),
    inv_total       numeric(10, 2),
    inv_created_at  timestamp
);
            ",
            "
alter table co_invoices owner to postgres;
            ",
            "
create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
            ",
            "
create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
            ",
            "
create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }

    public function clear(AdapterInterface $db)
    {
        $db->execute("delete from `co_invoices`");
    }

    public function drop(AdapterInterface $db)
    {
        $db->execute("drop table if exists `co_invoices`");
    }

    /**
     * @param int|null    $id
     * @param int|null    $cstId
     * @param int|null    $statusId
     * @param string|null $title
     * @param float|null  $total
     * @param string|null $dateTime
     */
    public function insert(
        int $id = null,
        int $cstId = null,
        int $statusId = null,
        string $title = null,
        float $total = null,
        string $dateTime = null
    ) {
        if (0 === $id) {
            $id = null;
        }

        $id       = null === $id       ? "null" : $id;
        $cstId    = null === $cstId    ? "null" : $cstId;
        $statusId = null === $statusId ? "null" : $statusId;
        $title    = null === $title    ? "null" : '"' . $title . '"';
        $total    = null === $total    ? "null" : $total;
        $dateTime = null === $dateTime ? "null" : '"' . $dateTime . '"';

        $sql = "insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, "
            . "inv_title, inv_total, inv_created_at) values ("
            . "{$id}, {$cstId}, {$statusId}, {$title}, {$total}, {$dateTime})";

        $this->connection->execute($sql);
    }
}
