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

use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class SumTest extends AbstractDatabaseTestCase
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
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getConnection());
    }

    public function tearDown(): void
    {
        /**
         * @var Manager $transactionManager
         */
        $transactionManager = $this->getDi()->getShared('transactionManager');

        if ($transactionManager->has()) {
            $transactionManager->rollback();
        }
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group mysql
     * @group pgsql
     */
    public function testMvcModelSum(): void
    {
        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, $invId, 1, 'aaa');


        $total = Invoices::sum(
            [
                'column' => 'inv_total',
            ]
        );
        $this->assertEquals(266.00, $total);

        $total = Invoices::sum(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $this->assertEquals(6, $total);

        $total = Invoices::sum(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(33.00, $total);

        $total = Invoices::sum(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(266.00, $total);

        $total = Invoices::sum(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        $this->assertEquals(33.00, $total);

        $results = Invoices::sum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(1, (int)$results[0]->inv_cst_id);
        $this->assertEquals(232, (int)$results[0]->sumatory);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(33, (int)$results[1]->sumatory);
        $this->assertEquals(3, (int)$results[2]->inv_cst_id);
        $this->assertEquals(1, (int)$results[2]->sumatory);

        $results = Invoices::sum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(3, (int)$results[0]->inv_cst_id);
        $this->assertEquals(1, (int)$results[0]->sumatory);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(33, (int)$results[1]->sumatory);
        $this->assertEquals(1, (int)$results[2]->inv_cst_id);
        $this->assertEquals(232, (int)$results[2]->sumatory);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group mysql
     * @group pgsql
     */
    public function testMvcModelSumTransaction(): void
    {
        $this->insertDataInvoices($this->invoiceMigration, 7, 'default', 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, 'default', 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, 'default', 1, 'aaa');

        $originalTotal = Invoices::sum(
            [
                'column' => 'inv_total',
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
                'transaction' => $transaction,
            ]
        );

        $this->assertEquals(
            $originalTotal - $deletedInvoice->inv_total,
            $total
        );

        $transaction->rollback();
    }
}
