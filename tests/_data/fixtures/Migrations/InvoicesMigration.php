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

class InvoicesMigration
{
    public function __invoke(AdapterInterface $db)
    {
        $sql = <<<SQL
drop table if exists `co_invoices`
SQL;
        $db->execute($sql);

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
        $db->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
SQL;
        $db->execute($sql);
    }

    public function clear(AdapterInterface $db)
    {
        $db->execute("delete from `co_invoices`");
    }

    public function drop(AdapterInterface $db)
    {
        $db->execute("drop table if exists `co_invoices`");
    }
}
