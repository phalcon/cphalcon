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
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class UnderscoreCallTest extends AbstractDatabaseTestCase
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
     * @since  2019-10-03
     *
     * @group mysql
     */
    public function testMvcModelCall(): void
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

        $belongsToCustomer = $belongsToInvoice->getCustomer();

        $this->assertInstanceOf(
            Models\Customers::class,
            $belongsToCustomer
        );

        $nonExistentBelongsToCustomer = $belongsToInvoice->getCustomer(
            [
                'cst_id < 0',
                'order' => 'cst_id DESC',
            ]
        );

        $this->assertNull(
            $nonExistentBelongsToCustomer
        );

        /**
         * Testing has-one relationship
         */
        $invoice = Models\Invoices::findFirst();

        $invoiceCustomer = $invoice->getCustomer();

        $this->assertInstanceOf(
            Models\Customers::class,
            $invoiceCustomer
        );

        $nonExistentCustomer = $invoice->getCustomer(
            [
                'cst_id < 0',
                'order' => 'cst_id DESC',
            ]
        );

        $this->assertNull(
            $nonExistentCustomer
        );

        /**
         * Has-many relationship
         */
        $customer = Models\Customers::findFirst();

        $customerInvoices = $customer->getInvoices();

        $this->assertInstanceOf(
            Simple::class,
            $customerInvoices
        );

        $countCustomerInvoices = $customer->countInvoices();

        $this->assertEquals(
            2,
            $countCustomerInvoices
        );

        $nonExistentInvoices = $customer->getInvoices(
            [
                'inv_id < 0',
                'order' => 'inv_id DESC',
            ]
        );

        $this->assertCount(
            0,
            $nonExistentInvoices
        );
    }
}
