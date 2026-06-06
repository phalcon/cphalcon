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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use PDO;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class UpdateJoinTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration  = new InvoicesMigration($connection);
        $customersMigration = new CustomersMigration($connection);

        $invoicesMigration->clear();
        $customersMigration->clear();

        /**
         * Two customers; invoices 1 and 2 belong to customer 1, invoice 3 to
         * customer 2. Every invoice starts with a total of 100.
         */
        $customersMigration->insert(1, 1, 'first-1', 'last-1');
        $customersMigration->insert(2, 1, 'first-2', 'last-2');

        $invoicesMigration->insert(1, 1, 0, 'inv-1', 100);
        $invoicesMigration->insert(2, 1, 0, 'inv-2', 100);
        $invoicesMigration->insert(3, 2, 0, 'inv-3', 100);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: UPDATE with a JOIN used to filter the
     * records to update.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16984
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelQueryUpdateWithJoin(): void
    {
        /** @var ManagerInterface $manager */
        $manager = $this->getService('modelsManager');

        $phql = 'UPDATE [' . Invoices::class . '] '
            . 'INNER JOIN [' . Customers::class . '] '
            . 'ON [' . Customers::class . '].cst_id = '
            . '[' . Invoices::class . '].inv_cst_id '
            . 'SET [' . Invoices::class . '].inv_total = 999 '
            . 'WHERE [' . Customers::class . '].cst_id = :custId:';

        $status = $manager->executeQuery($phql, ['custId' => 1]);

        $this->assertInstanceOf(StatusInterface::class, $status);
        $this->assertTrue($status->success());

        /**
         * Invoices belonging to customer 1 are updated; the one belonging to
         * customer 2 is left untouched.
         */
        $this->assertEquals(999.0, (float) Invoices::findFirst(1)->inv_total);
        $this->assertEquals(999.0, (float) Invoices::findFirst(2)->inv_total);
        $this->assertEquals(100.0, (float) Invoices::findFirst(3)->inv_total);
    }
}
