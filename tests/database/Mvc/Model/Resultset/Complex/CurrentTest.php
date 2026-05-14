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
use Phalcon\Support\Settings;
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
        // Make sure no test leaks the orm.resultset_empty_left_join_model
        // toggle into the next test in the suite.
        Settings::reset();
        $this->tearDownDatabase();
    }

    /**
     * Default behavior: `orm.resultset_empty_left_join_model` is `true`, so
     * a LEFT JOIN with no matching row hydrates an empty Model instance
     * (every property is null). This preserves pre-5.12 behavior and is
     * what existing applications upgrading from 5.9.x get out of the box.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     * @issue  16960
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetComplexCurrentLeftJoinEmptyModelByDefault(): void
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

        // Customer 2 has no invoice - default behavior returns an Invoices
        // instance whose every property is null (the pre-5.12 shape).
        /** @var Row $row */
        $row      = $resultsets->current();
        $customer = $row->readAttribute(Customers::class);
        $invoice  = $row->readAttribute('invoice');

        $this->assertInstanceOf(Row::class, $row);
        $this->assertInstanceOf(Customers::class, $customer);
        $this->assertEquals(2, $customer->cst_id);
        $this->assertInstanceOf(Invoices::class, $invoice);
        $this->assertNull($invoice->inv_id);
    }

    /**
     * Opt-in behavior: setting `orm.resultset_empty_left_join_model` to
     * `false` restores the 5.12.x "explicit null on no match" semantics so
     * the LEFT JOIN slot is plainly `null` instead of an empty Model
     * instance. New applications that prefer the cleaner contract enable
     * this once at bootstrap.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     * @issue  16239
     * @issue  16960
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetComplexCurrentLeftJoinNullResult(): void
    {
        Settings::set('orm.resultset_empty_left_join_model', false);

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
