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
use Phalcon\Paginator\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class GetSetLimitCest
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getLimit() / setLimit()
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function paginatorAdapterQuerybuilderGetSetLimit(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getLimit() / setLimit()');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $I->assertEquals(5, $paginator->getLimit());
        $paginator->setLimit(12);
        $I->assertEquals(12, $paginator->getLimit());

        $I->expectThrowable(
            new Exception(
                'Limit must be greater than zero'
            ),
            function () use ($builder) {
                $paginator = new QueryBuilder(
                    [
                        'builder' => $builder,
                        'limit'   => 0,
                        'page'    => 1,
                    ]
                );

                $paginator->paginate();
            }
        );
    }
}
