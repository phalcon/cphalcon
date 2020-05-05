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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesMap;

class CountCest
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
     * Tests Phalcon\Mvc\Model :: count()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelCount(DatabaseTester $I)
    {
        /**
         * @todo The following tests need to skip sqlite because we will get
         *       a General Error 5 database is locked error
         */
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';
        $this->seed($invId);

        $total = Invoices::count();
        $I->assertEquals(33, $total);

        $total = Invoices::count(
            [
                'distinct' => 'inv_cst_id',
            ]
        );
        $I->assertEquals(3, $total);

        $total = Invoices::count(
            'inv_cst_id = 2'
        );
        $I->assertEquals(12, $total);

        $results = Invoices::count(
            [
                'group' => 'inv_cst_id',
                'order' => 'inv_cst_id',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(1, (int) $results[0]->inv_cst_id);
        $I->assertEquals(20, (int) $results[0]->rowcount);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(12, (int) $results[1]->rowcount);
        $I->assertEquals(3, (int) $results[2]->inv_cst_id);
        $I->assertEquals(1, (int) $results[2]->rowcount);

        $results = Invoices::count(
            [
                'group' => 'inv_cst_id',
                'order' => 'inv_cst_id DESC',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(3, (int) $results[0]->inv_cst_id);
        $I->assertEquals(1, (int) $results[0]->rowcount);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(12, (int) $results[1]->rowcount);
        $I->assertEquals(1, (int) $results[2]->inv_cst_id);
        $I->assertEquals(20, (int) $results[2]->rowcount);
    }

    /**
     * Tests Phalcon\Mvc\Model :: count() - Column Map
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelCountColumnMap(DatabaseTester $I)
    {
        /**
         * @todo The following tests need to skip sqlite because we will get
         *       a General Error 5 database is locked error
         */
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';
        $this->seed($invId);

        $total = InvoicesMap::count();
        $I->assertEquals(33, $total);

        $total = InvoicesMap::count(
            [
                'distinct' => 'cst_id',
            ]
        );
        $I->assertEquals(3, $total);

        $total = InvoicesMap::count(
            'cst_id = 2'
        );
        $I->assertEquals(12, $total);

        $results = InvoicesMap::count(
            [
                'group' => 'cst_id',
                'order' => 'cst_id',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(1, (int) $results[0]->cst_id);
        $I->assertEquals(20, (int) $results[0]->rowcount);
        $I->assertEquals(2, (int) $results[1]->cst_id);
        $I->assertEquals(12, (int) $results[1]->rowcount);
        $I->assertEquals(3, (int) $results[2]->cst_id);
        $I->assertEquals(1, (int) $results[2]->rowcount);

        $results = InvoicesMap::count(
            [
                'group' => 'cst_id',
                'order' => 'cst_id DESC',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(3, (int) $results[0]->cst_id);
        $I->assertEquals(1, (int) $results[0]->rowcount);
        $I->assertEquals(2, (int) $results[1]->cst_id);
        $I->assertEquals(12, (int) $results[1]->rowcount);
        $I->assertEquals(1, (int) $results[2]->cst_id);
        $I->assertEquals(20, (int) $results[2]->rowcount);
    }

    private function seed(string $invId)
    {
        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, $invId, 1, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 9, $invId, 1, 'bbb');
        $this->insertDataInvoices($this->invoiceMigration, 5, $invId, 2, 'aaa');
    }
}
