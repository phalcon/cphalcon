<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models;

class UnderscoreCallCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    public function _after(DatabaseTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: __call()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-10-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelCall(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __call()");

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');
        $customersMigration->insert(2, 0, 'test_firstName_2', 'test_lastName_2');

        /**
         * Belongs-to relationship
         */
        $belongsToInvoice = Models\InvoicesKeepSnapshots::findFirst();

        $belongsToCustomer = $belongsToInvoice->getCustomer();

        $I->assertInstanceOf(
            Models\Customers::class,
            $belongsToCustomer
        );

        $nonExistentBelongsToCustomer = $belongsToInvoice->getCustomer(
            [
                'cst_id < 0',
                'order' => 'cst_id DESC',
            ]
        );

        $I->assertNull(
            $nonExistentBelongsToCustomer
        );

        /**
         * Testing has-one relationship
         */
        $invoice = Models\Invoices::findFirst();

        $invoiceCustomer = $invoice->getCustomer();

        $I->assertInstanceOf(
            Models\Customers::class,
            $invoiceCustomer
        );

        $nonExistentCustomer = $invoice->getCustomer(
            [
                'cst_id < 0',
                'order' => 'cst_id DESC',
            ]
        );

        $I->assertNull(
            $nonExistentCustomer
        );

        /**
         * Has-many relationship
         */
        $customer = Models\Customers::findFirst();

        $customerInvoices = $customer->getInvoices();

        $I->assertInstanceOf(
            Simple::class,
            $customerInvoices
        );

        $countCustomerInvoices = $customer->countInvoices();

        $I->assertEquals(
            2,
            $countCustomerInvoices
        );

        $nonExistentInvoices = $customer->getInvoices(
            [
                'inv_id < 0',
                'order' => 'inv_id DESC',
            ]
        );

        $I->assertCount(
            0,
            $nonExistentInvoices
        );
    }
}
