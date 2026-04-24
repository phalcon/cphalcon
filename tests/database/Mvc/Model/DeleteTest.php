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

use PDO;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function uniqid;

/**
 *
 * @group phql
 */
final class DeleteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelDelete(): void
    {
        /**
         * The following tests need to skip sqlite because we will get
         * a General Error 5 database is locked error
         */
        $title                    = uniqid('inv-');
        $date                     = date('Y-m-d H:i:s');
        $invoice                  = new Invoices();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 3;
        $invoice->inv_title       = $title;
        $invoice->inv_total       = 100.12;
        $invoice->inv_created_at  = $date;

        $result = $invoice->create();
        $this->assertNotFalse($result);

        $result = $invoice->delete();
        $this->assertTrue($result);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-08-02
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelDeleteCascadeRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $custId = 2;

        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custId, 0, $firstName, $lastName);

        $paidInvoiceId   = 4;
        $unpaidInvoiceId = 5;

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $paidInvoiceId,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoicesMigration->insert(
            $unpaidInvoiceId,
            $custId,
            Invoices::STATUS_UNPAID,
            $title . '-unpaid'
        );

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst($custId);

        $expected = 2;
        $actual   = $customer->invoices->count();
        $this->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = $customer->paidInvoices->count();
        $this->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = $customer->unpaidInvoices->count();
        $this->assertEquals($expected, $actual);

        $actual = $customer->delete();
        $this->assertTrue($actual);

        $invoices = Invoices::find();

        $expected = 1;
        $actual   = $invoices->count();
        $this->assertEquals($expected, $actual);

        $expected = $unpaidInvoiceId;
        $actual   = $invoices[0]->inv_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-18
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelDeleteGetRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $custId    = 2;
        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        /**
         * Set up a customer
         */
        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custId, 0, $firstName, $lastName);

        $title = uniqid('inv-');

        /**
         * Set up invoices for the customer
         *
         * 2 paid
         * 3 unpaid
         */
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            40,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoicesMigration->insert(
            41,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );

        $invoicesMigration->insert(
            50,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoicesMigration->insert(
            51,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoicesMigration->insert(
            52,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );

        /**
         * Get the customer from the database
         *
         * @var Customers $customer
         */
        $customer = Customers::findFirst($custId);

        /**
         * Check for the number of invoices
         */
        $expected = 5;
        $actual   = $customer->invoices->count();
        $this->assertEquals($expected, $actual);

        /**
         * Get paid invoices using the property
         */
        $invoices = $customer->paidInvoices;
        /** @var Invoices $invoice */
        foreach ($invoices as $invoice) {
            if ($invoice->inv_id < 50) {
                $actual = $invoice->delete();
                $this->assertTrue($actual);
            }
        }

        /**
         * Just in case for a refresh
         *
         * @var Customers $customer
         */
        $customer = Customers::findFirst($custId);

        /**
         * Check for the number of invoices
         */
        $expected = 3;
        $actual   = $customer->invoices->count();
        $this->assertEquals($expected, $actual);

        /**
         * Get unpaid invoices using getRelated()
         */
        $invoices = $customer->getRelated('invoices');
        /** @var Invoices $invoice */
        foreach ($invoices as $invoice) {
            $actual = $invoice->delete();
            $this->assertTrue($actual);
        }

        /**
         * Check for the number of invoices
         */
        $expected = 0;
        $customer->invoices->refresh();
        $actual   = $customer->invoices->count();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-17
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelDeleteRestrictRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customerId = 2;

        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($customerId, 0, $firstName, $lastName);

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            1,
            $customerId,
            Invoices::STATUS_INACTIVE,
            $title . '-inactive'
        );

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst($customerId);

        $expected = 1;
        $actual   = $customer->inactiveInvoices->count();
        $this->assertEquals($expected, $actual);

        $actual = $customer->delete();
        $this->assertFalse($actual);

        $expected = 1;
        $actual   = $customer->getMessages();
        $this->assertCount($expected, $actual);

        $expected = 'Record is referenced by model ' . Invoices::class;
        $actual   = current($customer->getMessages())->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-17
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelDeleteRestrictRelatedInTransaction(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoiceId  = 1;
        $customerId = 2;

        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($customerId, 0, $firstName, $lastName);

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $customerId,
            Invoices::STATUS_INACTIVE,
            $title . '-inactive'
        );

        /**
         * Step 1:
         * Create two models Model A and Model B and setup relations
         * so that Model A cannot be deleted if it is used in Model B
         *
         * @var Customers $customer
         * @var Invoices  $invoice
         */
        $customer = Customers::findFirst($customerId); // Model A
        $invoice  = Invoices::findFirst($invoiceId);   // Model B

        /**
         * Step 2:
         * Start a transaction and set both models to use that same transaction
         *
         * @var Manager $transactionManager
         */
        $transactionManager = $this->getDi()->getShared('transactionManager');

        $transaction = $transactionManager->get();

        $customer->setTransaction($transaction);
        $invoice->setTransaction($transaction);

        /**
         * Make sure foreign key restrict works
         */
        $actual = $customer->delete();
        $this->assertFalse($actual);

        /**
         * Step 3:
         * Delete Model B first so that Model A passes FK constraint check successfully
         */
        $actual = $invoice->delete();
        $this->assertTrue($actual);

        /**
         * Step 4:
         * Then try to delete Model A
         */
        $actual = $customer->delete();
        $this->assertTrue($actual);

        $transaction->rollback();

        /**
         * Test again foreign key restrict
         */
        $actual = $customer->delete();
        $this->assertFalse($actual);
    }
}
