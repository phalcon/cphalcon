<?php

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class AverageCest
{
    use DiTrait;
    use RecordsTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: average()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelAverage(DatabaseTester $I)
    {
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);

        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 11, $invId, 1, 'aaa');

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
                'order'  => 'inv_cst_id'
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
