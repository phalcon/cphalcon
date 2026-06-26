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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetHasOneRecordsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getHasOneRecords()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerGetHasOneRecords(): void
    {
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 0, 'cst-first', 'cst-last');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(1, 1, 0, 'Title 1');

        $invoice = Invoices::findFirst(1);
        $manager = $invoice->getModelsManager();

        $record = $manager->getHasOneRecords(Invoices::class, Customers::class, $invoice);

        $this->assertInstanceOf(Customers::class, $record);
        $this->assertEquals(1, $record->cst_id);
    }
}
