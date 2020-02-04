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

namespace Phalcon\Test\Database\Paginator\Adapter\Model;

use DatabaseTester;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

/**
 * Class SetGetLimitCest
 */
class SetGetLimitCest
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
     * Tests Phalcon\Paginator\Adapter\Model :: getLimit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-1
     */
    public function paginatorAdapterModelGetLimit(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\Model - getLimit()');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $this->insertDataInvoices($migration, 17, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, 2, 'bbb');

        $paginator = new Model(
            [
                'model' => Invoices::class,
                'limit' => 5,
                'page'  => 1,
            ]
        );

        $I->assertEquals(5, $paginator->getLimit());
        $paginator->setLimit(12);
        $I->assertEquals(12, $paginator->getLimit());
    }
}
