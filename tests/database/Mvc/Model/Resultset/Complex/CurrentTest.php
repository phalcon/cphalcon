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
use Phalcon\Tests\Support\Models\InvoicesLateStateBinding;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class CurrentTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private CustomersMigration $customerMigration;

    private InvoicesMigration $invoiceMigration;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->customerMigration = new CustomersMigration(self::getPdoConnection());
        $this->invoiceMigration  = new InvoicesMigration(self::getPdoConnection());
    }

    public function tearDown(): void
    {
        // Make sure no test leaks the orm.resultset_empty_left_join_model
        // toggle into the next test in the suite.
        Settings::reset();
        $this->tearDownDatabase();
    }

    /**
     * With late state binding on, both models of each row are hydrated with
     * the cloneResultMap() of the model class.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexCurrentLateStateBinding(): void
    {
        Settings::set('orm.late_state_binding', true);

        $count = 0;
        foreach ($this->getInvoicesSelfJoin('copy.inv_id = invoice.inv_id') as $row) {
            $this->assertTrue($row->readAttribute('copy')->lateStateBound);
            $this->assertTrue($row->readAttribute('invoice')->lateStateBound);
            $count++;
        }

        $this->assertSame(3, $count);
    }

    /**
     * Each row reads the setting. A change of the setting between two rows
     * applies to the next row.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexCurrentLateStateBindingChangeBetweenRows(): void
    {
        Settings::set('orm.late_state_binding', true);

        $resultset = $this->getInvoicesSelfJoin('copy.inv_id = invoice.inv_id');

        $resultset->rewind();
        $first = $resultset->current();

        Settings::set('orm.late_state_binding', false);

        $resultset->next();
        $second = $resultset->current();

        $this->assertTrue($first->readAttribute('copy')->lateStateBound);
        $this->assertTrue($first->readAttribute('invoice')->lateStateBound);
        $this->assertFalse($second->readAttribute('copy')->lateStateBound);
        $this->assertFalse($second->readAttribute('invoice')->lateStateBound);
    }

    /**
     * The first model of each row has no match and is null. The second model
     * reads the setting.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexCurrentLateStateBindingLeftJoinNoMatch(): void
    {
        Settings::set('orm.late_state_binding', true);
        Settings::set('orm.resultset_empty_left_join_model', false);

        $count = 0;
        foreach ($this->getInvoicesSelfJoin('copy.inv_id = invoice.inv_id AND copy.inv_id < 0') as $row) {
            $this->assertNull($row->readAttribute('copy'));
            $this->assertTrue($row->readAttribute('invoice')->lateStateBound);
            $count++;
        }

        $this->assertSame(3, $count);
    }

    /**
     * With late state binding off (the default), both models of each row are
     * hydrated with Phalcon\Mvc\Model::cloneResultMap().
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexCurrentLateStateBindingOff(): void
    {
        $count = 0;
        foreach ($this->getInvoicesSelfJoin('copy.inv_id = invoice.inv_id') as $row) {
            $this->assertFalse($row->readAttribute('copy')->lateStateBound);
            $this->assertFalse($row->readAttribute('invoice')->lateStateBound);
            $count++;
        }

        $this->assertSame(3, $count);
    }

    /**
     * Default behavior: `orm.resultset_empty_left_join_model` is `true`, so
     * a LEFT JOIN with no matching row hydrates an empty Model instance
     * (every property is null). This preserves pre-5.12 behavior and is
     * what existing applications upgrading from 5.9.x get out of the box.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     * @issue  https://github.com/phalcon/cphalcon/issues/16960
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
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
     * @issue  https://github.com/phalcon/cphalcon/issues/16239
     * @issue  https://github.com/phalcon/cphalcon/issues/16960
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
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

    /**
     * Creates 3 invoices and joins each one with itself (LEFT JOIN, alias
     * copy, with the given condition). The copy column comes first.
     */
    private function getInvoicesSelfJoin(string $condition): Complex
    {
        $this->customerMigration->insert(1, 1, 'cst-first-1', 'cst-last-1');
        $this->invoiceMigration->insert(1, 1, 1, 'inv-title-1');
        $this->invoiceMigration->insert(2, 1, 1, 'inv-title-2');
        $this->invoiceMigration->insert(3, 1, 1, 'inv-title-3');

        /** @var Complex $resultset */
        $resultset = $this->container->getShared('modelsManager')->executeQuery(
            'SELECT copy.*, invoice.* FROM ' . InvoicesLateStateBinding::class . ' invoice '
            . 'LEFT JOIN ' . InvoicesLateStateBinding::class . ' copy ON ' . $condition . ' '
            . 'ORDER BY invoice.inv_id'
        );

        return $resultset;
    }
}
