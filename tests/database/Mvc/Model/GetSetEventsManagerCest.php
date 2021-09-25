<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

use function uniqid;

/**
 * Class GetEventsManagerCest
 */
class GetSetEventsManagerCest
{
    use DiTrait;

    /**
     * @var InvoicesMigration
     */
    private InvoicesMigration $invoiceMigration;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (\Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);

        $this->invoiceMigration = new InvoicesMigration($I->getConnection());
    }

    /**
     * Tests Phalcon\Mvc\Model :: getEventsManager()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetEventsManager(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getEventsManager()');

        $this->invoiceMigration->insert(4, null, 0, uniqid('inv-', true));

        $invoice = Invoices::findFirst();

        $I->assertNull(
            $invoice->getEventsManager()
        );

        $manager = new Manager();
        $invoice->setEventsManager($manager);

        $I->assertEquals(
            $manager,
            $invoice->getEventsManager()
        );
    }
}
