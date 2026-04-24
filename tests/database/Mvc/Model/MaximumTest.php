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
final class MaximumTest extends AbstractDatabaseTestCase
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
    public function testMvcModelMaximum(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 7, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 1, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 11, $invId, 1, 'aaa');


        $total = Invoices::maximum(
            [
                'column' => 'inv_total',
            ]
        );
        $this->assertEquals(89.00, $total);

        $total = Invoices::maximum(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $this->assertEquals(3, $total);

        $total = Invoices::maximum(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(13.00, $total);

        $total = Invoices::maximum(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $this->assertEquals(89.00, $total);

        $total = Invoices::maximum(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        $this->assertEquals(13.00, $total);

        $results = Invoices::maximum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(1, (int)$results[0]->inv_cst_id);
        $this->assertEquals(89, (int)$results[0]->maximum);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(13, (int)$results[1]->maximum);
        $this->assertEquals(3, (int)$results[2]->inv_cst_id);
        $this->assertEquals(1, (int)$results[2]->maximum);

        $results = Invoices::maximum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $this->assertInstanceOf(Simple::class, $results);
        $this->assertEquals(3, (int)$results[0]->inv_cst_id);
        $this->assertEquals(1, (int)$results[0]->maximum);
        $this->assertEquals(2, (int)$results[1]->inv_cst_id);
        $this->assertEquals(13, (int)$results[1]->maximum);
        $this->assertEquals(1, (int)$results[2]->inv_cst_id);
        $this->assertEquals(89, (int)$results[2]->maximum);
    }
}
