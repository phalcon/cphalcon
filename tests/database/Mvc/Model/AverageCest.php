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
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RecordsTrait;
use Phalcon\Tests\Models\Invoices;

class AverageCest
{
    use DiTrait;
    use RecordsTrait;

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
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);

        $this->invoiceMigration = new InvoicesMigration($I->getConnection());
    }

    /**
     * Tests Phalcon\Mvc\Model :: average()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelAverage(DatabaseTester $I)
    {
        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, $invId, 1, 'aaa');

        $total = Invoices::average(
            [
                'column' => 'inv_total',
            ]
        );
        $I->assertEquals(14.00, $total);

        $total = Invoices::average(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $I->assertEquals(2, $total);

        $total = Invoices::average(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        //Handle Postgres need round because Postgres send (4.7142857142857143) and mysql (4.714286)
        $I->assertEquals('4.714286', round($total, 6));

        $total = Invoices::average(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $I->assertEquals(14.00, $total);

        $total = Invoices::average(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        //Handle Postgres need round because Postgres send (4.7142857142857143) and mysql (4.714286)
        $I->assertEquals('4.714286', round($total, 6));

        $results = Invoices::average(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(1, (int) $results[0]->inv_cst_id);
        $I->assertEquals(21, (int) $results[0]->average);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(4, (int) $results[1]->average);
        $I->assertEquals(3, (int) $results[2]->inv_cst_id);
        $I->assertEquals(1, (int) $results[2]->average);

        $results = Invoices::average(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(3, (int) $results[0]->inv_cst_id);
        $I->assertEquals(1, (int) $results[0]->average);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(4, (int) $results[1]->average);
        $I->assertEquals(1, (int) $results[2]->inv_cst_id);
        $I->assertEquals(21, (int) $results[2]->average);
    }
}
