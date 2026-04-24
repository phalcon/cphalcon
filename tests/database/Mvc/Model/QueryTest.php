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

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\Row;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomersKeepSnapshots;
use Phalcon\Tests\Support\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

/**
 *
 * @group phql
 */
final class QueryTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var CustomersMigration
     */
    private CustomersMigration $customerMigration;

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

        $this->customerMigration = new CustomersMigration(self::getConnection());
        $this->invoiceMigration  = new InvoicesMigration(self::getConnection());
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelQuery(): void
    {
        $this->addTestData();

        $query = Customers::query();
        $query->limit(20, 0);
        $resultsets = $query->execute();

        $this->assertEquals(20, $resultsets->count());
        foreach ($resultsets as $resultset) {
            $this->assertInstanceOf(Customers::class, $resultset);
        }
    }

    /**
     * @issue  14535
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelQueryIssue14535(): void
    {
        $this->addTestData();

        $query = Customers::query();
        $query->columns(
            [
                'Customer ID' => 'cst_id',
                'Stätûs'      => 'cst_status_flag',
            ]
        );
        $query->limit(1, 0);
        $resultsets = $query->execute();

        $this->assertTrue(isset($resultsets[0]['Customer ID']));
        $this->assertTrue(isset($resultsets[0]['Stätûs']));
    }

    /**
     * @issue  14783
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelQueryIssue14783(): void
    {
        $this->addTestData();

        $query = CustomersKeepSnapshots::query();
        $query->columns(
            [
                CustomersKeepSnapshots::class . '.*',
                'join_1.*',
            ]
        );

        $query->leftJoin(
            InvoicesKeepSnapshots::class,
            'join_1.inv_cst_id = ' . CustomersKeepSnapshots::class . '.cst_id',
            'join_1'
        );

        $query->limit(20, 0);

        /** @var Complex $resultsets */
        $resultsets = $query->execute();

        $this->assertEquals(20, $resultsets->count());
        foreach ($resultsets as $resultset) {
            /** @var Row $resultset */
            $model = $this->transform($resultset);
            $this->assertInstanceOf(CustomersKeepSnapshots::class, $model);
            $this->assertInstanceOf(Simple::class, $model->invoices);
        }
    }

    /**
     * Seed Invoices' table by some data.
     *
     * @return void
     */
    private function addTestData(): void
    {
        for ($counter = 1; $counter <= 50; $counter++) {
            $firstName = uniqid('inv-', true);
            $lastName  = uniqid('inv-', true);

            $this->customerMigration->insert($counter, 1, $firstName, $lastName);
            $this->invoiceMigration->insert($counter, $counter, 1, $firstName);
        }
    }

    /**
     * @issue 14783
     */
    private function transform(Row $row): CustomersKeepSnapshots
    {
        $invoice           = $row->readAttribute(CustomersKeepSnapshots::class);
        $customer          = $row->readAttribute('join_1');
        $invoice->customer = $customer;

        return $invoice;
    }
}
