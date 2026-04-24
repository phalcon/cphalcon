<?php

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class MinimumTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelMinimum(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 7, $invId, 2, 'ccc', 11);
        $this->insertDataInvoices($migration, 1, $invId, 3, 'aaa', 13);
        $this->insertDataInvoices($migration, 11, $invId, 1, 'aaa', 7);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
            ]
        );
        $this->assertEquals(21.00, $total);

        $total = Invoices::minimum(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $this->assertEquals(1, $total);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(144.00, $total);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(21.00, $total);

        $total = Invoices::minimum(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        $this->assertEquals(144.00, $total);

        $results = Invoices::minimum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(1, (int)$results[0]->inv_cst_id);
        $this->assertEquals(21, (int)$results[0]->minimum);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(144, (int)$results[1]->minimum);
        $this->assertEquals(3, (int)$results[2]->inv_cst_id);
        $this->assertEquals(377, (int)$results[2]->minimum);

        $results = Invoices::minimum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(3, (int)$results[0]->inv_cst_id);
        $this->assertEquals(377, (int)$results[0]->minimum);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(144, (int)$results[1]->minimum);
        $this->assertEquals(1, (int)$results[2]->inv_cst_id);
        $this->assertEquals(21, (int)$results[2]->minimum);
    }
}
