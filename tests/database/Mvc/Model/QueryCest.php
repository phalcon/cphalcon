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
use Phalcon\Test\Models\Invoices;

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
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQuery(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Mvc\Model :: query() - Issue 14783
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryIssue14783(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - query()');
        $query = Invoices::query();

        $query->columns([Invoices::class . '.*', 'join_1.*']);
        $query->leftJoin(Customers::class, 'join_1.id = ' . Invoices::class . '.model2_id', 'join_1');
        $query->limit(20, 0);//I have 50 rows in my db
        $resultsets = $query->execute();

        foreach ($resultsets as $resultset) {
            $model1 = $this->traitement($resultset);
        }
        echo 'OK';
    }
}
