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

use DatabaseTester;
use PDO;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;

use function date;
use function uniqid;

/**
 * Class DeleteCest
 */
class DeleteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelDelete(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - delete()');

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
        $I->assertNotFalse($result);

        $result = $invoice->delete();
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete() with related items
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-08-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelDeleteCascadeRelated(DatabaseTester $I): void
    {
        $I->wantToTest('Mvc\Model - delete() with related items');

        /** @var PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = $customer->paidInvoices->count();
        $I->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = $customer->unpaidInvoices->count();
        $I->assertEquals($expected, $actual);

        $actual = $customer->delete();
        $I->assertTrue($actual);

        $invoices = Invoices::find();

        $expected = 1;
        $actual   = $invoices->count();
        $I->assertEquals($expected, $actual);

        $expected = $unpaidInvoiceId;
        $actual   = $invoices[0]->inv_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete() from getRelated
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-18
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelDeleteGetRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - delete() from getRelated');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $custId    = 2;
        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        /**
         * Set up a customer
         */
        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custId, 0, $firstName, $lastName);

        $paidInvoiceId   = 40;
        $unpaidInvoiceId = 50;

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
        $I->assertEquals($expected, $actual);

        /**
         * Get paid invoices using the property
         */
        $invoices = $customer->paidInvoices;
        /** @var Invoices $invoice */
        foreach ($invoices as $invoice) {
            if ($invoice->inv_id < 50) {
                $actual = $invoice->delete();
                $I->assertTrue($actual);
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
        $I->assertEquals($expected, $actual);

        /**
         * Get unpaid invoices using getRelated()
         */
        $invoices = $customer->getRelated('invoices');
        /** @var Invoices $invoice */
        foreach ($invoices as $invoice) {
            $actual = $invoice->delete();
            $I->assertTrue($actual);
        }

        /**
         * Check for the number of invoices
         */
        $expected = 0;
        $actual   = $customer->invoices->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete() with restricted related items
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-17
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelDeleteRestrictRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - delete() with restricted related items');

        /** @var PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertEquals($expected, $actual);

        $actual = $customer->delete();
        $I->assertFalse($actual);

        $expected = 1;
        $actual   = $customer->getMessages();
        $I->assertCount($expected, $actual);

        $expected = 'Record is referenced by model ' . Invoices::class;
        $actual   = current($customer->getMessages())->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete() with restricted related items
     * in transaction
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14114
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-17
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelDeleteRestrictRelatedInTransaction(DatabaseTester $I)
    {
        $I->wantToTest(
            'Mvc\Model - delete() with restricted related items in transaction'
        );

        /** @var PDO $connection */
        $connection = $I->getConnection();

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
        $invoice  = Invoices::findFirst($invoiceId); // Model B

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
        $I->assertFalse($actual);

        /**
         * Step 3:
         * Delete Model B first so that Model A passes FK constraint check successfully
         */
        $actual = $invoice->delete();
        $I->assertTrue($actual);

        /**
         * Step 4:
         * Then try to delete Model A
         */
        $actual = $customer->delete();
        $I->assertTrue($actual);

        $transaction->rollback();

        /**
         * Test again foreign key restrict
         */
        $actual = $customer->delete();
        $I->assertFalse($actual);
    }
}
