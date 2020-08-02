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
     * Tests Phalcon\Mvc\Model :: getRelated()
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

        $I->assertEquals(
            2,
            $invoices->count()
        );

        $I->assertInstanceOf(
            Invoices::class,
            $invoices[0]
        );

        $I->assertEquals(
            $unpaidInvoiceId,
            $invoices[0]->id
        );

        $I->assertEquals(
            $paidInvoiceId,
            $invoices[1]->id
        );

        $paidInvoices = $customer->getRelated(
            'paidInvoices'
        );

        $I->assertEquals(
            1,
            $paidInvoices->count()
        );

        $I->assertInstanceOf(
            Invoices::class,
            $paidInvoices[0]
        );

        $I->assertEquals(
            $paidInvoiceId,
            $paidInvoices[0]->id
        );
    }
}
