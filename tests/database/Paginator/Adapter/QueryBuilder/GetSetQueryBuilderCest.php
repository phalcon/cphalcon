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

namespace Phalcon\Test\Database\Paginator\Adapter\QueryBuilder;

use DatabaseTester;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class GetSetQueryBuilderCest
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getQueryBuilder() /
     * setQueryBuilder()
     *
     * @group mysql
     * @group pgsql
     */
    public function paginatorAdapterQuerybuilderGetSetQueryBuilder(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getQueryBuilder() / setQueryBuilder()');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $this->insertDataInvoices($migration, 17, 2, 'ccc');
        $this->insertDataInvoices($migration, 15, 2, 'bbb');

        $manager  = $this->getService('modelsManager');
        $builder1 = $manager
            ->createBuilder()
            ->from(Invoices::class)
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder1,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $I->assertEquals($builder1, $paginator->getQueryBuilder());

        $builder2 = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->where('inv_cst_id = :custId:', ['custId' => 2])
        ;

        $result = $paginator->setQueryBuilder($builder2);

        $I->assertEquals($builder2, $paginator->getQueryBuilder());
        $I->assertEquals($paginator, $result);
    }
}
