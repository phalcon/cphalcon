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
     * @group sqlite
     * @group pgsql
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
     * @group sqlite
     * @group pgsql
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
}
