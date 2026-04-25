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
final class AverageTest extends AbstractDatabaseTestCase
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelAverage(): void
    {
        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($this->invoiceMigration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($this->invoiceMigration, 11, $invId, 1, 'aaa');

        $total = Invoices::average(
            [
                'column' => 'inv_total',
            ]
        );
        $this->assertEquals(14.00, $total);

        $total = Invoices::average(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $this->assertEquals(2, $total);

        $total = Invoices::average(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        //Handle Postgres need round because Postgres send (4.7142857142857143) and mysql (4.714286)
        $this->assertEquals('4.714286', round($total, 6));

        $total = Invoices::average(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(14.00, $total);

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
        $this->assertEquals('4.714286', round($total, 6));

        $results = Invoices::average(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(1, (int)$results[0]->inv_cst_id);
        $this->assertEquals(21, (int)$results[0]->average);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(4, (int)$results[1]->average);
        $this->assertEquals(3, (int)$results[2]->inv_cst_id);
        $this->assertEquals(1, (int)$results[2]->average);

        $results = Invoices::average(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(3, (int)$results[0]->inv_cst_id);
        $this->assertEquals(1, (int)$results[0]->average);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(4, (int)$results[1]->average);
        $this->assertEquals(1, (int)$results[2]->inv_cst_id);
        $this->assertEquals(21, (int)$results[2]->average);
    }
}
