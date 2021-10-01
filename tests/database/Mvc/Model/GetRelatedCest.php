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

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Migrations\CustomersMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Invoices;

use function uniqid;

/**
 * Class GetRelatedCest
 */
class GetRelatedCest
{
    use DiTrait;

    /**
     * @param DatabaseTester $I
     */
    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getRelated()
     *
     * @param DatabaseTester $I
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-08-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getRelated()');

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
        $invoices = $customer->getRelated(
            'invoices',
            [
                'order' => 'inv_id DESC'
            ]
        );

        $expected = 2;
        $actual   = $invoices->count();
        $I->assertEquals($expected, $actual);

        $expected = Invoices::class;
        $actual   = $invoices[0];
        $I->assertInstanceOf($expected, $actual);

        $expected = $unpaidInvoiceId;
        $actual   = $invoices[0]->inv_id;
        $I->assertEquals($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $invoices[1]->inv_id;
        $I->assertEquals($expected, $actual);

        $paidInvoices = $customer->getRelated('paidInvoices');

        $expected = 1;
        $actual   = $paidInvoices->count();
        $I->assertEquals($expected, $actual);

        $expected = Invoices::class;
        $actual   = $paidInvoices[0];
        $I->assertInstanceOf($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $paidInvoices[0]->inv_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getRelated() - changing FK
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetRelatedChangeForeignKey(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getRelated() - Change Foreign Key');

        /** @var PDO $connection */
        $connection = $I->getConnection();


        $custIdOne    = 10;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $custIdTwo    = 20;
        $firstNameTwo = uniqid('cust-2-', true);
        $lastNameTwo  = uniqid('cust-2-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);
        $customersMigration->insert($custIdTwo, 0, $firstNameTwo, $lastNameTwo);

        $invoiceId = 40;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );

        /**
         * Find the invoice. Then use `getRelated` to get the customer. It
         * should return CustomerOne.
         *
         * Change the FK to the customer. Call `getRelated` again. It should
         * return CustomerTwo
         */
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => $invoiceId,
                ]
            ]
        );

        /**
         * Assert that the correct customer is stored
         */
        $expected = $custIdOne;
        $actual   = $invoice->inv_cst_id;
        $I->assertEquals($expected, $actual);

        /**
         * Call get related - We should get CustomerOne
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdOne;
        $actual   = $customer->cst_id;
        $I->assertEquals($expected, $actual);

        $invoice->inv_cst_id = $custIdTwo;
        $result = $invoice->save();
        $I->assertTrue($result);

        /**
         * Now call getRelated. We should get CustomerTwo
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdTwo;
        $actual   = $customer->cst_id;
        $I->assertEquals($expected, $actual);

        /**
         * Delete Customer Two and call getRelated again. We should get
         * the cached copy
         */
        $result = $customer->delete();
        $I->assertTrue($result);

        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdTwo;
        $actual   = $customer->cst_id;
        $I->assertEquals($expected, $actual);
    }
}
