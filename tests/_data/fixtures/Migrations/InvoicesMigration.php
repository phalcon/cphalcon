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

    public function create()
    {
        $this->drop();

        $sql = <<<SQL
create table co_invoices
(
    inv_id          int(10) auto_increment primary key,
    inv_cst_id      int(10)      null,
    inv_status_flag tinyint(1)   null,
    inv_title       varchar(100) null,
    inv_total       float(10, 2) null,
    inv_created_at  datetime     null
);
SQL;
        $this->connection->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
SQL;
        $this->connection->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
SQL;
        $this->connection->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
SQL;
        $this->connection->execute($sql);
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

        $sql = "insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, "
            . "inv_title, inv_total, inv_created_at) values ("
            . "{$id}, {$cstId}, {$statusId}, \"{$title}\", {$total}, {$dateTime})";

        $this->connection->execute($sql);
    }
}
