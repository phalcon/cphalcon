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
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class UnderscoreGetTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group mysql
     */
    public function testMvcModelUnderscoreGet(): void
    {
        $customer = new Models\Customers();

        $customer->cst_id        = 999;
        $customer->cst_name_last = 'cst_lastName';

        $this->assertEquals(
            999,
            $customer->cst_id
        );

        $this->assertEquals(
            'cst_lastName',
            $customer->cst_name_last
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group mysql
     */
    public function testMvcModelUnderscoreGetDirtyRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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

        $this->assertInstanceOf(
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

        $this->assertIsArray(
            $dirtyInvoices
        );

        $this->assertCount(
            2,
            $dirtyInvoices
        );

        $this->assertInstanceOf(
            Models\Invoices::class,
            $dirtyInvoices[0]
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group mysql
     */
    public function testMvcModelUnderscoreGetIsUsingGetters(): void
    {
        $customer = new Models\Customers();
        $customer->setId(123);

        $this->assertEquals(
            123,
            $customer->cst_id
        );

        $associativeArray = [
            'value_0',
            'key_1' => 'value_1',
            'key_2' => 'value_2',
        ];

        $customer->setData($associativeArray);

        $this->assertEquals(
            $associativeArray,
            $customer->data
        );

        $customer->setFirstName('cst_firstName');

        $this->assertEquals(
            'cst_firstName',
            $customer->firstName
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-07
     *
     * @group mysql
     */
    public function testMvcModelUnderscoreGetRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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

        $this->assertInstanceOf(
            Models\Customers::class,
            $belongsToCustomer
        );

        /**
         * Testing has-one relationship
         */
        $invoice = Models\Invoices::findFirst();

        $invoiceCustomer = $invoice->customer;

        $this->assertInstanceOf(
            Models\Customers::class,
            $invoiceCustomer
        );

        $this->assertEquals(
            'test_lastName_1',
            $invoiceCustomer->cst_name_last
        );

        /**
         * Has-many relationship
         */
        $customer = Models\Customers::findFirst();

        $invoices = $customer->invoices;

        $this->assertInstanceOf(
            Simple::class,
            $invoices
        );

        $this->assertCount(
            2,
            $invoices
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-24
     *
     * @group mysql
     */
    public function testMvcModelUnderscorePrivateProperty(): void
    {
        $model = new Invoices();

        $this->assertFalse(
            isset($model->superSecret)
        );

        $this->assertTrue(
            isset($model->secretValue)
        );

        $model->setSecretValue(123);

        $this->assertEquals(
            123,
            $model->getSecretValue()
        );

        $model->secretValue = 321;

        $this->assertEquals(
            321,
            $model->secretValue
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-24
     *
     * @group mysql
     */
    public function testMvcModelUnderscorePrivatePropertyException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Cannot access property 'superSecret' (not public) in '"
            . Invoices::class . "'"
        );

        $model              = new Invoices();
        $model->superSecret = 123;
    }
}
