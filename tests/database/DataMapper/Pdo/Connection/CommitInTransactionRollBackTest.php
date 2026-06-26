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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\Group;

use function date;
use function uniqid;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class CommitInTransactionRollBackTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionCommitInTransaction(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        (new InvoicesMigration(self::getConnection()));
        $connection->beginTransaction();

        $this->assertTrue($connection->inTransaction());

        $invId = 2;
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $sql   = "insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, "
            . "inv_title, inv_total, inv_created_at) values ("
            . "{$invId}, 1, 1, '{$title}', 102, '{$date}')";

        $result = $connection->exec($sql);
        $this->assertSame(1, $result);

        $connection->commit();

        /**
         * Committed record
         */
        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => $invId,
                ]
            )
        ;

        $this->assertIsArray($all);
        $this->assertSame($invId, $all['inv_id']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionRollBack(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        (new InvoicesMigration(self::getConnection()));
        $connection->beginTransaction();

        $this->assertTrue($connection->inTransaction());

        $invId = 2;
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $sql   = "insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, "
            . "inv_title, inv_total, inv_created_at) values ("
            . "{$invId}, 1, 1, '{$title}', 102, '{$date}')";

        $result = $connection->exec($sql);
        $this->assertSame(1, $result);

        /**
         * Committed record
         */
        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => $invId,
                ]
            )
        ;

        $connection->rollBack();

        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => $invId,
                ]
            )
        ;

        $this->assertIsArray($all);
        $this->assertEmpty($all);
    }
}
