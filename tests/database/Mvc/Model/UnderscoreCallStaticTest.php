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
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class UnderscoreCallStaticTest extends AbstractDatabaseTestCase
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
     * @since  2019-10-14
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelUnderscoreCallStatic(): void
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
         * Testing Model::findByField()
         */
        $magicInvoices = Invoices::findByInvId(77);

        $this->assertInstanceOf(Resultset\Simple::class, $magicInvoices);
        $this->assertCount(1, $magicInvoices);
        $this->assertInstanceOf(Invoices::class, $magicInvoices->getFirst());

        /**
         * Testing Model::findByField()
         * with impossible conditions
         */
        $nonExistentInvoices = Invoices::findByInvId(0);

        $this->assertInstanceOf(Resultset\Simple::class, $nonExistentInvoices);
        $this->assertCount(0, $nonExistentInvoices);

        /**
         * Testing Model::findFirstByField()
         */
        $firstMagicInvoice = Invoices::findFirstByInvCstId(1);
        $this->assertInstanceOf(Invoices::class, $firstMagicInvoice);

        /**
         * Testing Model::findFirstByField()
         * with impossible conditions
         */
        $nonExistentFirstInvoice = Invoices::findFirstByInvCstId(0);

        $this->assertNull($nonExistentFirstInvoice);

        /**
         * Testing Model::countByField()
         */
        $countMagicInvoices = Invoices::countByInvCstId(1);

        $this->assertIsInt($countMagicInvoices);
        $this->assertEquals(2, $countMagicInvoices);

        /**
         * Testing Model::countByField()
         * with impossible conditions
         */
        $countEmptyMagicInvoices = Invoices::countByInvCstId(null);

        $this->assertIsInt($countEmptyMagicInvoices);
        $this->assertEquals(0, $countEmptyMagicInvoices);

        /**
         * Testing with unknown method
         */
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "The method 'nonExistentStaticMethod' does not exist on model '"
            . Invoices::class . "'"
        );
        Invoices::nonExistentStaticMethod(1);

        /**
         * Testing Model::findFirstByField() with unknown field
         */
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Cannot resolve attribute 'UnknownField' in the model '"
            . Invoices::class . "'"
        );
        Invoices::findFirstByUnknownField(1);

        /**
         * Testing Model::countByField() with unknown field
         */
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Cannot resolve attribute 'UnknownField' in the model '"
            . Invoices::class . "'"
        );

        Invoices::countByUnknownField(1);
    }
}
