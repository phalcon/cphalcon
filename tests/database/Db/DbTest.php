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

namespace Phalcon\Tests\Database\Db;

use PDO;
use Phalcon\Db\Enum;
use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

use function is_array;

final class DbTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db :: execute() / insert() / update() / delete() / fetch methods / views / transactions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDb(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        $db = $this->getService('db');

        // Raw SQL execute
        $this->assertTrue(
            $db->execute('DELETE FROM co_invoices')
        );

        $this->assertTrue(
            $db->execute(
                'INSERT INTO co_invoices(inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total)'
                . ' VALUES (' . $db->getDefaultIdValue() . ', ?, ?, ?, ?)',
                [1, 1, 'LOL 1', 100.00]
            )
        );

        $this->assertTrue(
            $db->execute(
                'UPDATE co_invoices SET inv_title = ?, inv_status_flag = ?',
                ['LOL 11', 2]
            )
        );

        $this->assertTrue(
            $db->execute(
                'DELETE FROM co_invoices WHERE inv_status_flag = ?',
                [2]
            )
        );

        // insert() method
        $this->assertTrue(
            $db->insert(
                'co_invoices',
                [
                    $db->getDefaultIdValue(),
                    1,
                    1,
                    'LOL 1',
                    100.00,
                    null,
                ]
            )
        );

        $this->assertTrue(
            $db->insert(
                'co_invoices',
                [1, 2, 'LOL 2', 200.00],
                ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total']
            )
        );

        $this->assertTrue(
            $db->insert(
                'co_invoices',
                [1, 3, 'LOL 3', 300.00],
                ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total']
            )
        );

        $this->assertTrue(
            $db->insert(
                'co_invoices',
                [
                    new RawValue('current_date'),
                    4,
                ],
                ['inv_title', 'inv_status_flag']
            )
        );

        for ($i = 0; $i < 50; $i++) {
            $this->assertTrue(
                $db->insert(
                    'co_invoices',
                    [1, 5, 'LOL ' . $i, (float)$i],
                    ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total']
                )
            );
        }

        // update() method
        $this->assertTrue(
            $db->update(
                'co_invoices',
                ['inv_title', 'inv_status_flag'],
                ['LOL 1000', 9],
                'inv_status_flag = 2'
            )
        );

        $this->assertTrue(
            $db->update(
                'co_invoices',
                ['inv_title'],
                ['LOL 3000'],
                'inv_status_flag = 9'
            )
        );

        $this->assertTrue(
            $db->update(
                'co_invoices',
                ['inv_title'],
                [new RawValue('current_date')],
                'inv_status_flag = 9'
            )
        );

        // Array syntax for $whereCondition
        $this->assertTrue(
            $db->insert(
                'co_invoices',
                [1, 6, 'LOL array syntax', 600.00],
                ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total']
            )
        );

        $success = $db->update(
            'co_invoices',
            ['inv_title', 'inv_status_flag'],
            ['LOL array syntax 2', 7],
            [
                'conditions' => 'inv_title = ? AND inv_status_flag = ?',
                'bind'       => ['LOL array syntax', 6],
                'bindTypes'  => [PDO::PARAM_STR, PDO::PARAM_INT],
            ],
            [PDO::PARAM_STR, PDO::PARAM_INT]
        );
        $this->assertTrue($success);

        $row = $db->fetchOne(
            'SELECT COUNT(*) AS cnt FROM co_invoices WHERE inv_title = ? AND inv_status_flag = ?',
            Enum::FETCH_ASSOC,
            ['LOL array syntax 2', 7]
        );
        $this->assertEquals(1, $row['cnt']);

        $success = $db->update(
            'co_invoices',
            ['inv_title', 'inv_status_flag'],
            ['LOL array syntax 3', 8],
            [
                'conditions' => 'inv_title = ? AND inv_status_flag = ?',
                'bind'       => ['LOL array syntax 2', 7],
            ]
        );
        $this->assertTrue($success);

        $row = $db->fetchOne(
            'SELECT COUNT(*) AS cnt FROM co_invoices WHERE inv_title = ? AND inv_status_flag = ?',
            Enum::FETCH_ASSOC,
            ['LOL array syntax 3', 8]
        );
        $this->assertEquals(1, $row['cnt']);

        // insertAsDict / updateAsDict
        $success = $db->insertAsDict(
            'co_invoices',
            [
                'inv_cst_id'      => 1,
                'inv_status_flag' => 10,
                'inv_title'       => 'LOL insertAsDict',
                'inv_total'       => 999.00,
            ]
        );
        $this->assertTrue($success);

        $row = $db->fetchOne(
            'SELECT COUNT(*) AS cnt FROM co_invoices WHERE inv_title = ? AND inv_status_flag = ?',
            Enum::FETCH_ASSOC,
            ['LOL insertAsDict', 10]
        );
        $this->assertEquals(1, $row['cnt']);

        $this->assertTrue(
            $db->updateAsDict(
                'co_invoices',
                [
                    'inv_title'       => 'LOL updateAsDict',
                    'inv_status_flag' => 11,
                ],
                "inv_title = 'LOL insertAsDict' AND inv_status_flag = 10"
            )
        );

        $row = $db->fetchOne(
            'SELECT COUNT(*) AS cnt FROM co_invoices WHERE inv_title = ? AND inv_status_flag = ?',
            Enum::FETCH_ASSOC,
            ['LOL updateAsDict', 11]
        );
        $this->assertEquals(1, $row['cnt']);

        $this->assertTrue(
            $db->delete('co_invoices', 'inv_status_flag = 9')
        );

        $this->assertTrue(
            $db->delete('co_invoices')
        );

        $this->assertGreaterThan(0, $db->affectedRows());

        // Seed rows for fetchOne / fetchAll / fetchColumn tests
        for ($i = 1; $i <= 10; $i++) {
            $migration->insert($i, 1, 1, 'Fetch Test ' . $i, (float)($i * 100));
        }

        $this->assertCount(6, $db->fetchOne('SELECT * FROM co_invoices'));

        $this->assertCount(6, $db->fetchOne('SELECT * FROM co_invoices', Enum::FETCH_NUM));

        $this->assertCount(10, $db->fetchAll('SELECT * FROM co_invoices LIMIT 10'));

        $rows = $db->fetchAll('SELECT * FROM co_invoices LIMIT 10', Enum::FETCH_NUM);
        $this->assertCount(10, $rows);
        $this->assertCount(6, $rows[0]);

        $this->assertEquals(
            10,
            $db->fetchColumn('SELECT inv_id FROM co_invoices ORDER BY inv_id DESC')
        );

        $this->assertEquals(
            1,
            $db->fetchColumn('SELECT * FROM co_invoices WHERE inv_id = ?', [1], 1)
        );

        $this->assertEquals(
            1,
            $db->fetchColumn('SELECT * FROM co_invoices WHERE inv_id = ?', [1], 'inv_cst_id')
        );

        // Auto-increment / lastInsertId
        $sql = 'INSERT INTO co_invoices(inv_id, inv_cst_id, inv_status_flag, inv_title)'
            . ' VALUES (' . $db->getDefaultIdValue() . ', ?, ?, ?)';
        $this->assertTrue(
            $db->execute($sql, [99, 99, 'auto increment test'])
        );
        $this->assertGreaterThan(0, $db->lastInsertId());

        // View tests
        $this->assertTrue(
            $db->createView(
                'phalcon_test_view',
                ['sql' => 'SELECT 1 AS one, 2 AS two, 3 AS three']
            )
        );

        $this->assertTrue($db->viewExists('phalcon_test_view'));

        $views = $db->listViews();
        $this->assertTrue(is_array($views));
        $this->assertContains('phalcon_test_view', $views);

        $row = $db->fetchOne('SELECT * FROM phalcon_test_view');
        $this->assertCount(3, $row);
        $this->assertArrayHasKey('one', $row);
        $this->assertEquals(2, $row['two']);

        $this->assertTrue($db->dropView('phalcon_test_view'));

        // Transactions without savepoints
        $db->setNestedTransactionsWithSavepoints(false);

        // level 1 - real
        $this->assertTrue($db->begin());
        // level 2 - virtual
        $this->assertFalse($db->begin());
        // level 3 - virtual
        $this->assertFalse($db->begin());
        // level 2 - virtual
        $this->assertFalse($db->rollback());
        // level 1 - virtual
        $this->assertFalse($db->commit());
        // commit - real
        $this->assertTrue($db->commit());

        // level 1 - real
        $this->assertTrue($db->begin());
        // level 2 - virtual
        $this->assertFalse($db->begin());
        // level 1 - virtual
        $this->assertFalse($db->commit());
        // rollback - real
        $this->assertTrue($db->rollback());

        // Transactions with savepoints
        $db->setNestedTransactionsWithSavepoints(true);

        // level 1 - begin transaction
        $this->assertTrue($db->begin());
        // level 2 - uses savepoint_1
        $this->assertTrue($db->begin());
        // level 3 - uses savepoint_2
        $this->assertTrue($db->begin());
        // level 2 - rollback savepoint_2
        $this->assertTrue($db->rollback());
        // level 1 - release savepoint_1
        $this->assertTrue($db->commit());
        // commit - real commit
        $this->assertTrue($db->commit());

        // level 1 - real begin transaction
        $this->assertTrue($db->begin());
        // level 2 - uses savepoint_1
        $this->assertTrue($db->begin());
        // level 1 - release savepoint_1
        $this->assertTrue($db->commit());
        // rollback - real rollback
        $this->assertTrue($db->rollback());
    }
}
