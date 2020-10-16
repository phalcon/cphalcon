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

namespace Phalcon\Test\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Migrations\CustomersMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;
use Phalcon\Test\Models\Invoices;

use function is_array;

class UnderscoreGetCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreGet(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __get()');

        $customer = new Models\Customers();

        $customer->cst_id        = 999;
        $customer->cst_name_last = 'cst_lastName';

        $I->assertEquals(
            999,
            $customer->cst_id
        );

        $I->assertEquals(
            'cst_lastName',
            $customer->cst_name_last
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get() whether it is using getters correctly
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreGetIsUsingGetters(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __get() whether it is using getters correctly");

        $customer = new Models\Customers();
        $customer->setId(123);

        $I->assertEquals(
            123,
            $customer->cst_id
        );

        $associativeArray = [
            'value_0',
            'key_1' => 'value_1',
            'key_2' => 'value_2',
        ];

        $customer->setData($associativeArray);

        $I->assertEquals(
            $associativeArray,
            $customer->data
        );

        $customer->setFirstName('cst_firstName');

        $I->assertEquals(
            'cst_firstName',
            $customer->firstName
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get() related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreGetRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __get() related records');

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

        $belongsToCustomer = $belongsToInvoice->customer;

        $I->assertInstanceOf(
            Models\Customers::class,
            $belongsToCustomer
        );

        /**
         * Testing has-one relationship
         */
        $invoice = Models\Invoices::findFirst();

        $invoiceCustomer = $invoice->customer;

        $I->assertInstanceOf(
            Models\Customers::class,
            $invoiceCustomer
        );

        $I->assertEquals(
            'test_lastName_1',
            $invoiceCustomer->cst_name_last
        );

        /**
         * Has-many relationship
         */
        $customer = Models\Customers::findFirst();

        $invoices = $customer->invoices;

        $I->assertInstanceOf(
            Simple::class,
            $invoices
        );

        $I->assertCount(
            2,
            $invoices
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get() dirty related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreGetDirtyRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __get() dirty related records');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));
        $invoicesMigration->insert(99, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        $customer = Models\Customers::findFirst(1);

        /**
         * Fill up the related cache with data
         */
        $invoices = $customer->invoices;

        $I->assertInstanceOf(
            Simple::class,
            $invoices
        );

        /**
         * Add new related records
         */
        $customer->invoices = [
            new Models\Invoices(),
            new Models\Invoices(),
        ];

        /**
         * Test if the new records were returned
         */
        $dirtyInvoices = $customer->invoices;

        $I->assertIsArray(
            $dirtyInvoices
        );

        $I->assertCount(
            2,
            $dirtyInvoices
        );

        $I->assertInstanceOf(
            Models\Invoices::class,
            $dirtyInvoices[0]
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get() private property
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-24
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscorePrivateProperty(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __get() private property');

        $model = new Invoices();

        $I->assertFalse(
            isset($model->superSecret)
        );

        $I->assertTrue(
            isset($model->secretValue)
        );

        $model->setSecretValue(123);

        $I->assertEquals(
            123,
            $model->getSecretValue()
        );

        $model->secretValue = 321;

        $I->assertEquals(
            321,
            $model->secretValue
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __get() private property - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-24
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscorePrivatePropertyException(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __get() private property - exception');

        $I->expectThrowable(
            new Exception(
                "Cannot access property 'superSecret' (not public)."
            ),
            function () {
                $model              = new Invoices();
                $model->superSecret = 123;
            }
        );
    }
}
