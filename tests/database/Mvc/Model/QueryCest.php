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
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\Row;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RecordsTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\CustomersKeepSnapshots;
use Phalcon\Tests\Models\InvoicesKeepSnapshots;

use function uniqid;

/**
 * Class QueryCest
 */
class QueryCest
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

        $this->customerMigration = new CustomersMigration($I->getConnection());
        $this->invoiceMigration = new InvoicesMigration($I->getConnection());
    }

    public function _after(DatabaseTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: query()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelQuery(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query()');
        $this->addTestData($I);

        $query = Customers::query();
        $query->limit(20, 0);
        $resultsets = $query->execute();

        $I->assertEquals(20, $resultsets->count());
        foreach ($resultsets as $resultset) {
            $I->assertInstanceOf(Customers::class, $resultset);
        }
    }

    /**
     * Tests Phalcon\Mvc\Model :: query() - Issue 14535
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-01
     * @issue  14535
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelQueryIssue14535(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query() - #14535');
        $this->addTestData($I);

        $query = Customers::query();
        $query->columns(
            [
                'Customer ID' => 'cst_id',
                'Stätûs'      => 'cst_status_flag',
            ]
        );
        $query->limit(1, 0);
        $resultsets = $query->execute();

        $I->assertTrue(isset($resultsets[0]['Customer ID']));
        $I->assertTrue(isset($resultsets[0]['Stätûs']));
    }

    /**
     * Tests Phalcon\Mvc\Model :: query() - Issue 14783
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @issue  14783
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelQueryIssue14783(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query() - #14783');

        $this->addTestData($I);

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

        $I->assertEquals(20, $resultsets->count());
        foreach ($resultsets as $resultset) {
            /** @var Row $resultset */
            $model = $this->transform($resultset);
            $I->assertInstanceOf(CustomersKeepSnapshots::class, $model);
            $I->assertInstanceOf(Simple::class, $model->invoices);
        }
    }

    /**
     * Transforming method used for test
     *
     * @param Row $row
     *
     * @issue 14783
     *
     * @return mixed
     */
    private function transform(Row $row): CustomersKeepSnapshots
    {
        $invoice           = $row->readAttribute(lcfirst(CustomersKeepSnapshots::class));
        $customer          = $row->readAttribute('join_1');
        $invoice->customer = $customer;

        return $invoice;
    }

    /**
     * Seed Invoices' table by some data.
     *
     * @param DatabaseTester $I
     * @return void
     */
    private function addTestData(DatabaseTester $I)
    {
        for ($counter = 1; $counter <= 50; $counter++) {
            $firstName = uniqid('inv-', true);
            $lastName  = uniqid('inv-', true);

            $this->customerMigration->insert($counter, 1, $firstName, $lastName);
            $this->invoiceMigration->insert($counter, $counter, 1, $firstName);
        }
    }
}
