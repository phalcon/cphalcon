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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Complex;

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Row;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class CurrentTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @var CustomersMigration
     */
    private CustomersMigration $customerMigration;

    /**
     * @var InvoicesMigration
     */
    private InvoicesMigration $invoiceMigration;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->customerMigration = new CustomersMigration(self::getConnection());
        $this->invoiceMigration  = new InvoicesMigration(self::getConnection());
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @issue  16239
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelResultsetComplexCurrentLeftJoinNullResult(): void
    {
        $this->customerMigration->insert(1, 1, 'cst-first-1', 'cst-last-1');
        $this->customerMigration->insert(2, 1, 'cst-first-2', 'cst-last-2');
        $this->invoiceMigration->insert(1, 1, 1, 'inv-title-1');

        $query = Customers::query();
        $query->columns(
            [
                Customers::class . '.*',
                'invoice.*',
            ]
        );
        $query->leftJoin(
            Invoices::class,
            'invoice.inv_cst_id = ' . Customers::class . '.cst_id',
            'invoice'
        );
        $query->orderBy(Customers::class . '.cst_id ASC');

        /** @var Complex $resultsets */
        $resultsets = $query->execute();

        $this->assertSame(2, $resultsets->count());

        $resultsets->rewind();

        // Customer 1 has a matching invoice
        /** @var Row $row */
        $row      = $resultsets->current();
        $customer = $row->readAttribute(Customers::class);
        $invoice  = $row->readAttribute('invoice');

        $this->assertInstanceOf(Row::class, $row);
        $this->assertInstanceOf(Customers::class, $customer);
        $this->assertEquals(1, $customer->cst_id);
        $this->assertInstanceOf(Invoices::class, $invoice);
        $this->assertEquals(1, $invoice->inv_id);

        $resultsets->next();

        // Customer 2 has no invoice - LEFT JOIN must return null, not an empty model
        /** @var Row $row */
        $row      = $resultsets->current();
        $customer = $row->readAttribute(Customers::class);
        $invoice  = $row->readAttribute('invoice');

        $this->assertInstanceOf(Row::class, $row);
        $this->assertInstanceOf(Customers::class, $customer);
        $this->assertEquals(2, $customer->cst_id);
        $this->assertNull($invoice);
    }
}
