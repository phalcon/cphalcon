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
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

/**
 *
 * @group phql
 */
final class GetRelatedTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-08-02
     *
     * @group mysql
     */
    public function testMvcModelGetRelated(): void
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
        $invoices = $customer->getRelated(
            'invoices',
            [
                'order' => 'inv_id DESC',
            ]
        );

        $expected = 2;
        $actual   = $invoices->count();
        $this->assertEquals($expected, $actual);

        $expected = Invoices::class;
        $actual   = $invoices[0];
        $this->assertInstanceOf($expected, $actual);

        $expected = $unpaidInvoiceId;
        $actual   = $invoices[0]->inv_id;
        $this->assertEquals($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $invoices[1]->inv_id;
        $this->assertEquals($expected, $actual);

        $paidInvoices = $customer->getRelated('paidInvoices');

        $expected = 1;
        $actual   = $paidInvoices->count();
        $this->assertEquals($expected, $actual);

        $expected = Invoices::class;
        $actual   = $paidInvoices[0];
        $this->assertInstanceOf($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $paidInvoices[0]->inv_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-01
     *
     * @group mysql
     */
    public function testMvcModelGetRelatedChangeForeignKey(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();


        $custIdOne    = 10;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $custIdTwo    = 20;
        $firstNameTwo = uniqid('cust-2-', true);
        $lastNameTwo  = uniqid('cust-2-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);
        $customersMigration->insert($custIdTwo, 0, $firstNameTwo, $lastNameTwo);

        $invoiceId         = 40;
        $title             = uniqid('inv-');
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
                ],
            ]
        );

        /**
         * Assert that the correct customer is stored
         */
        $expected = $custIdOne;
        $actual   = $invoice->inv_cst_id;
        $this->assertEquals($expected, $actual);

        /**
         * Call get related - We should get CustomerOne
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $this->assertInstanceOf($class, $customer);

        $expected = $custIdOne;
        $actual   = $customer->cst_id;
        $this->assertEquals($expected, $actual);

        $invoice->inv_cst_id = $custIdTwo;
        $result              = $invoice->save();
        $this->assertTrue($result);

        /**
         * Now call getRelated. We should get CustomerTwo
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $this->assertInstanceOf($class, $customer);

        $expected = $custIdTwo;
        $actual   = $customer->cst_id;
        $this->assertEquals($expected, $actual);
    }
}
