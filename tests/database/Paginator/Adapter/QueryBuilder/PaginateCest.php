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
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Repository;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class PaginateCest
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function paginatorAdapterQuerybuilderPaginate(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - paginate()');

        /**
         * Sqlite does not like `where` that much and locks the database
         */
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

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

        $page = $paginator->paginate();

        $I->assertInstanceOf(Repository::class, $page);
        $I->assertCount(5, $page->getItems());
        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(4, $page->getLast());
        $I->assertEquals(5, $page->getLimit());
        $I->assertEquals(1, $page->getCurrent());
        $I->assertEquals(5, $page->limit);
        $I->assertEquals(17, $page->getTotalItems());
        $I->assertInternalType('int', $page->getTotalItems());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate() - groupBy
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group mysql
     * @group pgsql
     */
    public function paginatorAdapterQuerybuilderPaginateGroupBy(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - paginate() - groupBy');

        /**
         * Sqlite does not like `where` that much and locks the database
         */

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');

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

        $page = $paginator->paginate();

        $I->assertInstanceOf(Repository::class, $page);
        $I->assertCount(5, $page->getItems());
        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(6, $page->getLast());
        $I->assertEquals(5, $page->getLimit());
        $I->assertEquals(1, $page->getCurrent());
        $I->assertEquals(5, $page->limit);
        $I->assertEquals(28, $page->getTotalItems());
        $I->assertInternalType('int', $page->getTotalItems());

        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->where('inv_cst_id = :custId:', ['custId' => 2])
        ;

        $paginator->setQueryBuilder($builder);

        $page = $paginator->paginate();

        $I->assertInstanceOf(Repository::class, $page);
        $I->assertCount(5, $page->getItems());
        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(4, $page->getLast());
        $I->assertEquals(5, $page->getLimit());
        $I->assertEquals(1, $page->getCurrent());
        $I->assertEquals(5, $page->limit);
        $I->assertEquals(17, $page->getTotalItems());
        $I->assertInternalType('int', $page->getTotalItems());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-15
     *
     * @param DatabaseTester $I
     * @issue 14639
     *
     * @group mysql
     *
     * @throws Exception
     */
    public function paginatorAdapterQuerybuilderPaginateView(DatabaseTester $I): void
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - paginate() - set in view');

        $this->setDiService('view');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $criteria = Criteria::fromInput(
            $this->container,
            Invoices::class,
            []
        );
        $builder = $criteria->createBuilder();

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $page = $paginator->paginate();
        $I->assertCount(5, $page->getItems());

        $view = $this->getService('view');
        $view->setVar('page', $page);

        $actual = $view->getVar('page');
        $I->assertInstanceOf(Repository::class, $actual);


        $view = $this->getService('view');
        $view->setVar('paginate', $paginator->paginate());

        $actual = $view->getVar('paginate');
        $I->assertInstanceOf(Repository::class, $actual);
    }
}
