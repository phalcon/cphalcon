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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Test\Fixtures\Migrations\CustomersMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Invoices;

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

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->clear();
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
    public function mvcModelDeleteCascadeRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - delete() with related items');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $custId = 2;

        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();
        $customersMigration->insert($custId, 0, $firstName, $lastName);

        $paidInvoiceId   = 4;
        $unpaidInvoiceId = 5;

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->clear();
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

        $I->assertEquals(
            2,
            $customer->invoices->count()
        );

        $I->assertEquals(
            1,
            $customer->paidInvoices->count()
        );

        $I->assertEquals(
            1,
            $customer->unpaidInvoices->count()
        );

        $I->assertTrue(
            $customer->delete()
        );

        $invoices = Invoices::find();

        $I->assertEquals(
            1,
            $invoices->count()
        );

        $I->assertEquals(
            $unpaidInvoiceId,
            $invoices[0]->inv_id
        );
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
        $customersMigration->clear();
        $customersMigration->insert($customerId, 0, $firstName, $lastName);

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->clear();
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

        $I->assertEquals(
            1,
            $customer->inactiveInvoices->count()
        );

        $I->assertFalse(
            $customer->delete()
        );

        $I->assertCount(
            1,
            $customer->getMessages()
        );

        $I->assertEquals(
            'Record is referenced by model ' . Invoices::class,
            current($customer->getMessages())->getMessage()
        );
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
        $customersMigration->clear();
        $customersMigration->insert($customerId, 0, $firstName, $lastName);

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->clear();
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
        $I->assertFalse(
            $customer->delete()
        );

        /**
         * Step 3:
         * Delete Model B first so that Model A passes FK constraint check successfully
         */
        $I->assertTrue(
            $invoice->delete()
        );

        /**
         * Step 4:
         * Then try to delete Model A
         */
        $I->assertTrue(
            $customer->delete()
        );

        $transaction->rollback();

        /**
         * Test again foreign key restrict
         */
        $I->assertFalse(
            $customer->delete()
        );
    }
}
