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
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class SumCest
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
     * @param DatabaseTester $I
     *
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


    public function _after(DatabaseTester $I): void
    {
        /**
         * @var Manager $transactionManager
         */
        $transactionManager = $this->getDi()->getShared('transactionManager');

        if ($transactionManager->has()) {
            $transactionManager->rollback();
        }
    }

    /**
     * Tests Phalcon\Mvc\Model :: sum()
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelSum(DatabaseTester $I)
    {
        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, $invId, 1, 'aaa');


        $total = Invoices::sum(
            [
                'column' => 'inv_total',
            ]
        );
        $I->assertEquals(266.00, $total);

        $total = Invoices::sum(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $I->assertEquals(6, $total);

        $total = Invoices::sum(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        $I->assertEquals(33.00, $total);

        $total = Invoices::sum(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $I->assertEquals(266.00, $total);

        $total = Invoices::sum(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        $I->assertEquals(33.00, $total);

        $results = Invoices::sum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(1, (int)$results[0]->inv_cst_id);
        $I->assertEquals(232, (int)$results[0]->sumatory);
        $I->assertEquals(2, (int)$results[1]->inv_cst_id);
        $I->assertEquals(33, (int)$results[1]->sumatory);
        $I->assertEquals(3, (int)$results[2]->inv_cst_id);
        $I->assertEquals(1, (int)$results[2]->sumatory);

        $results = Invoices::sum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(3, (int)$results[0]->inv_cst_id);
        $I->assertEquals(1, (int)$results[0]->sumatory);
        $I->assertEquals(2, (int)$results[1]->inv_cst_id);
        $I->assertEquals(33, (int)$results[1]->sumatory);
        $I->assertEquals(1, (int)$results[2]->inv_cst_id);
        $I->assertEquals(232, (int)$results[2]->sumatory);
    }

    /**
     * Tests Phalcon\Mvc\Model :: sum()
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelSumTransaction(DatabaseTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model :: sum() - with transaction');

        $this->insertDataInvoices($this->invoiceMigration, 7, 'default', 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, 'default', 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, 'default', 1, 'aaa');

        $originalTotal = Invoices::sum(
            [
                'column' => 'inv_total'
            ]
        );

        /**
         * @var Manager $transactionManager
         */
        $transactionManager = $this->getDi()->getShared('transactionManager');
        $transaction        = $transactionManager->get();

        /**
         * @var Invoices $deletedInvoice
         */
        $deletedInvoice = Invoices::findFirst();
        $deletedInvoice->setTransaction($transaction);
        $deletedInvoice->delete();

        $total = Invoices::sum(
            [
                'column'      => 'inv_total',
                'transaction' => $transaction
            ]
        );

        $I->assertEquals(
            $originalTotal - $deletedInvoice->inv_total,
            $total
        );

        $transaction->rollback();
    }
}
