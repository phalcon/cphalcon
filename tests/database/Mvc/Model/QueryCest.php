<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\CustomersKeepSnapshots;
use Phalcon\Test\Models\InvoicesKeepSnapshots;

use function uniqid;

/**
 * Class QueryCest
 */
class QueryCest
{
    use DiTrait;
    use RecordsTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group common
     */
    public function mvcModelQuery(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query()');
        $this->addTestData($I);

        $query = Customers::query();
        $query->limit(20, 0);//I have 50 rows in my db
        $resultsets = $query->execute();

        foreach ($resultsets as $resultset) {
            $I->assertInstanceOf(Customers::class, $resultset);
        }
    }

    /**
     * Tests Phalcon\Mvc\Model :: query() - Issue 14783
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @issue  14783
     *
     * @group common
     */
    public function mvcModelQueryIssue14783(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query()');

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
        $query->limit(20, 0);//I have 50 rows in my db
        $resultsets = $query->execute();

        foreach ($resultsets as $resultset) {
            $model = $this->transform($resultset);
            $I->assertInstanceOf(CustomersKeepSnapshots::class, $model);
            $I->assertInstanceOf(InvoicesKeepSnapshots::class, $model->invoices);
        }
    }

    /**
     * Transforming method used for test
     *
     * @param $resultset
     *
     * @issue 14783
     *
     * @return mixed
     */
    private function transform($resultset)
    {
        $invoice           = $resultset->readAttribute(lcfirst(InvoicesKeepSnapshots::class));
        $customer          = $resultset->readAttribute('join_1');
        $invoice->customer = $customer;

        return $invoice;
    }

    private function addTestData(DatabaseTester $I)
    {
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);

        for ($counter = 1; $counter <= 50; $counter++) {
            $migration->insert(
                $counter,
                1,
                1,
                uniqid('inv-')
            );
        }
    }
}
