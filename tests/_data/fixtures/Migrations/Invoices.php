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

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\DM\Pdo\Connection;

use function date;
use function uniqid;

class Invoices
{
    /**
     * Invoices constructor.
     *
     * @param Connection $connection
     */
    public function __construct(Connection $connection)
    {
        $this->truncate($connection);
    }

    /**
     * @param Connection  $connection
     * @param int         $id
     * @param string|null $title
     *
     * @return int
     */
    public function insert(
        Connection $connection,
        int $id,
        string $title = null
    ): int {
        $title = $title ?: uniqid();
        $now   = date('Y-m-d H:i:s');
        $total = 100 + $id;
        $flag  = (int) ($id % 2);
        $sql   = <<<SQL
insert into co_invoices (
    inv_id, 
    inv_cst_id, 
    inv_status_flag, 
    inv_title, 
    inv_total, 
    inv_created_at 
) values (
    {$id}, 
    1, 
    {$flag}, 
    "{$title}", 
    {$total}, 
    "{$now}"
)
SQL;

        return $connection->exec($sql);
    }

    /**
     * @param Connection  $connection
     */
    public function truncate(Connection $connection): void
    {
        $sql   = "delete from co_invoices";

        $connection->exec($sql);
    }
}
