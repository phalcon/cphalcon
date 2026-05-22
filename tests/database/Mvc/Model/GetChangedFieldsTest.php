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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class GetChangedFieldsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $migration = new InvoicesMigration(self::getConnection());
        $migration->insert(1, 1, 0, 'Test Invoice');
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelGetChangedFieldsNewModel(): void
    {
        $invoice = new Invoices();

        $expected = [
            'inv_id',
            'inv_cst_id',
            'inv_status_flag',
            'inv_title',
            'inv_total',
            'inv_created_at',
        ];
        $this->assertSame($expected, $invoice->getChangedFields());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelGetChangedFieldsWithSnapshot(): void
    {
        $invoice = Invoices::findFirst();

        $this->assertNotFalse($invoice);
        $this->assertSame([], $invoice->getChangedFields());

        $invoice->inv_title = 'Updated Title';

        $expected = ['inv_title'];
        $this->assertSame($expected, $invoice->getChangedFields());
    }

    /**
     * Regression coverage for [#17042]: a freshly-loaded row whose nullable
     * columns hold `null` must report no changed fields, and modifying an
     * unrelated column must not list the null columns as changed. The
     * pre-fix `isset $snapshot[name]` compiled by the post-5.13.0 Zephir
     * runtime returned false for null-valued snapshot entries, causing
     * every nullable column to be reported as changed.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelGetChangedFieldsIgnoresNullValuedColumns(): void
    {
        $connection = self::getConnection();
        try {
            $stmt = $connection->prepare(
                'INSERT INTO co_invoices (inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at) '
                . 'VALUES (99, NULL, NULL, :title, NULL, :createdAt)'
            );
            $stmt->execute([
                ':title'     => 'null-cols',
                ':createdAt' => date('Y-m-d H:i:s'),
            ]);

            $invoice = InvoicesKeepSnapshots::findFirst(99);
            $this->assertNotFalse($invoice);

            $this->assertSame([], $invoice->getChangedFields());
            $this->assertFalse($invoice->hasChanged('inv_cst_id'));
            $this->assertFalse($invoice->hasChanged('inv_status_flag'));
            $this->assertFalse($invoice->hasChanged('inv_total'));

            $invoice->inv_title = 'Updated';

            $this->assertSame(['inv_title'], $invoice->getChangedFields());
            $this->assertFalse($invoice->hasChanged('inv_cst_id'));
            $this->assertTrue($invoice->hasChanged('inv_title'));
        } finally {
            $connection->exec('DELETE FROM co_invoices WHERE inv_id = 99');
        }
    }
}
