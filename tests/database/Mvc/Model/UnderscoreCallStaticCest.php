<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Test\Fixtures\Migrations\CustomersMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;

class UnderscoreCallStaticCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: __callStatic()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-10-14
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreCallStatic(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __callStatic()");

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');
        $customersMigration->insert(2, 0, 'test_firstName_2', 'test_lastName_2');

        /**
         * Testing Model::findByField()
         */
        $magicInvoices = Models\Invoices::findByInvId(
            77
        );

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $magicInvoices
        );

        $I->assertCount(
            1,
            $magicInvoices
        );

        $I->assertInstanceOf(
            Models\Invoices::class,
            $magicInvoices->getFirst()
        );

        /**
         * Testing Model::findByField()
         * with impossible conditions
         */
        $nonExistentInvoices = Models\Invoices::findByInvId(0);

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $nonExistentInvoices
        );

        $I->assertCount(
            0,
            $nonExistentInvoices
        );

        /**
         * Testing Model::findFirstByField()
         */
        $firstMagicInvoice = Models\Invoices::findFirstByInvCstId(
            1
        );

        $I->assertInstanceOf(
            Models\Invoices::class,
            $firstMagicInvoice
        );

        /**
         * Testing Model::findFirstByField()
         * with impossible conditions
         */
        $nonExistentFirstInvoice = Models\Invoices::findFirstByInvCstId(0);

        $I->assertNull(
            $nonExistentFirstInvoice
        );

        /**
         * Testing Model::countByField()
         */
        $countMagicInvoices = Models\Invoices::countByInvCstId(
            1
        );

        $I->assertIsInt(
            $countMagicInvoices
        );

        $I->assertEquals(
            2,
            $countMagicInvoices
        );

        /**
         * Testing Model::countByField()
         * with impossible conditions
         */
        $countEmptyMagicInvoices = Models\Invoices::countByInvCstId(null);

        $I->assertIsInt(
            $countEmptyMagicInvoices
        );

        $I->assertEquals(
            0,
            $countEmptyMagicInvoices
        );

        /**
         * Testing with unknown method
         */
        $I->expectThrowable(
            new Exception(
                "The method 'nonExistentStaticMethod' doesn't exist on model '" . Models\Invoices::class . "'"
            ),
            function () {
                Models\Invoices::nonExistentStaticMethod(1);
            }
        );

        /**
         * Testing Model::findFirstByField() with unknown field
         */
        $I->expectThrowable(
            new Exception(
                "Cannot resolve attribute 'UnknownField' in the model"
            ),
            function () {
                Models\Invoices::findFirstByUnknownField(1);
            }
        );

        /**
         * Testing Model::countByField() with unknown field
         */
        $I->expectThrowable(
            new Exception(
                "Cannot resolve attribute 'UnknownField' in the model"
            ),
            function () {
                Models\Invoices::countByUnknownField(1);
            }
        );
    }
}
