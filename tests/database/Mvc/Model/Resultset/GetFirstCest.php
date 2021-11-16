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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use DatabaseTester;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Row;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RecordsTrait;
use Phalcon\Tests\Models\Invoices;

class GetFirstCest
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var InvoicesMigration
     */
    private $invoiceMigration;

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
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);

        $this->invoiceMigration = new InvoicesMigration($I->getConnection());
    }

    /**
     * Tests Mvc\Model\Resultset :: getFirst() - Issue 15027
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     * @issue  15027
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelResultsetGetFirst(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset :: getFirst() - #15027');

        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');

        /** @var ManagerInterface $manager */
        $manager = $this->getService('modelsManager');

        $sql = sprintf('SELECT i.inv_id FROM [%s] AS i', Invoices::class);
        $I->assertInstanceOf(Row::class, $manager->createQuery($sql)->execute()->getFirst());

        $sql = sprintf('SELECT * FROM [%s] AS i', Invoices::class);
        $I->assertInstanceOf(Invoices::class, $manager->createQuery($sql)->execute()->getFirst());

        $sql = sprintf('SELECT i.inv_id FROM [%s] AS i WHERE inv_total = -42', Invoices::class);
        $I->assertNull($manager->createQuery($sql)->execute()->getFirst());
    }
}
