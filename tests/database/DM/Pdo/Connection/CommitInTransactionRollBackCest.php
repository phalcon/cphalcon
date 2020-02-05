<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

use function date;
use function str_replace;
use function uniqid;

class CommitInTransactionRollBackCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: commit()/inTransaction()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionCommitInTransaction(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - commit()/inTransaction()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
        $connection->beginTransaction();

        $I->assertTrue($connection->inTransaction());

        $template = 'insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, '
            . 'inv_title, inv_total, inv_created_at) values ('
            . '%id%, 1, 1, "%title%", %total%, "%now%")';

        $sql = str_replace(
            [
                '%id%',
                '%title%',
                '%total%',
                '%now%',
            ],
            [
                2,
                uniqid(),
                102,
                date('Y-m-d H:i:s'),
            ],
            $template
        );

        $result = $connection->exec($sql);
        $I->assertEquals(1, $result);

        $connection->commit();

        /**
         * Committed record
         */
        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => 2,
                ]
            );

        $I->assertIsArray($all);
        $I->assertEquals(2, $all['inv_id']);
    }

    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: rollBack()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionRollBack(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - rollBack()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
        $connection->beginTransaction();

        $I->assertTrue($connection->inTransaction());

        $template = 'insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, '
            . 'inv_title, inv_total, inv_created_at) values ('
            . '%id%, 1, 1, "%title%", %total%, "%now%")';

        $sql = str_replace(
            [
                '%id%',
                '%title%',
                '%total%',
                '%now%',
            ],
            [
                2,
                uniqid(),
                102,
                date('Y-m-d H:i:s'),
            ],
            $template
        );

        $result = $connection->exec($sql);
        $I->assertEquals(1, $result);

        /**
         * Committed record
         */
        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => 2,
                ]
            );

        $connection->rollBack();

        $all = $connection
            ->fetchOne(
                'select * from co_invoices WHERE inv_id = ?',
                [
                    0 => 2,
                ]
            );

        $I->assertIsArray($all);
        $I->assertEmpty($all);
    }
}
