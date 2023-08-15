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
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;

use function uniqid;

/**
 * Class GetRelatedCest
 */
class SetRelatedCest
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
     * @since  2023-08-15
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - setRelated()');

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

        $invoices = [];
        $expectedTitle = [];
        foreach ($customer->Invoices as $invoice) {
            $invoices[] = $invoice;
            $expectedTitle[] = $invoice->inv_title . 'updated';
            $invoice->inv_title = $invoice->inv_title . 'updated';
        }

        $customer->setRelated('Invoices', $invoices);

        $invoices = $customer->Invoices;

        $I->assertIsArray($invoices);

        $expected = 2;
        $actual   = count($invoices);
        $I->assertEquals($expected, $actual);

        $actual = $customer->save();

        $I->assertTrue($actual);

        $invoice = $invoices[0];
        $actual = $invoice->getDirtyState();

        $I->assertEquals(0, $actual);

        $expected = $expectedTitle[0];
        $actual = $invoice->inv_title;
        $I->assertSame($expected, $actual);

        $invoice = $invoices[1];
        $actual = $invoice->getDirtyState();
        $expected = 0;
        $I->assertEquals($expected, $actual);

        $expected = $expectedTitle[1];
        $actual = $invoice->inv_title;
        $I->assertSame($expected, $actual);

        $actual = $customer->getDirtyState();
        $expected = 0;
        $I->assertEquals($expected, $actual);

        $invoice->Customer = $customer;
        $actual = $invoice->getDirtyState();
        $expected = 1;
        $I->assertEquals($expected, $actual);

        $actual = $customer->getDirtyState();
        $expected = 1;
        $I->assertEquals($expected, $actual);
    }
}
