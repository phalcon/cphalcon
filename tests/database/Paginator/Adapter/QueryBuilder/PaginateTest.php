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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilder;

use PDO;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Repository;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function is_int;

/**
 * @group phql
 */
final class PaginateTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderPaginate(): void
    {
        /**
         * Sqlite does not like `where` that much and locks the database
         */
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

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

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(4, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
        $this->assertEquals(5, $page->limit);
        $this->assertEquals(17, $page->getTotalItems());
        $this->assertTrue(is_int($page->getTotalItems()));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate() - groupBy
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function testPaginatorAdapterQuerybuilderPaginateGroupBy(): void
    {
        /**
         * Sqlite does not like `where` that much and locks the database
         */

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

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

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(6, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
        $this->assertEquals(5, $page->limit);
        $this->assertEquals(28, $page->getTotalItems());
        $this->assertTrue(is_int($page->getTotalItems()));

        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->where('inv_cst_id = :custId:', ['custId' => 2])
        ;

        $paginator->setQueryBuilder($builder);

        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(4, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
        $this->assertEquals(5, $page->limit);
        $this->assertEquals(17, $page->getTotalItems());
        $this->assertTrue(is_int($page->getTotalItems()));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate() - groupBy with
     * NULL column values and the columns option to handle them
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-21
     *
     * @issue  15266
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderPaginateGroupByNullColumnsOption(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';
        $this->insertDataInvoices($migration, 2, $invId, 1, 'grp1');
        $this->insertDataInvoices($migration, 2, $invId, 2, 'grp2');

        $now = date('Y-m-d H:i:s');
        $connection->exec(
            "INSERT INTO co_invoices "
            . "(inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at) "
            . "VALUES (NULL, 1, 'grp-null-1', 0, '{$now}')"
        );
        $connection->exec(
            "INSERT INTO co_invoices "
            . "(inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at) "
            . "VALUES (NULL, 1, 'grp-null-2', 0, '{$now}')"
        );

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->columns(['inv_cst_id'])
            ->from(Invoices::class)
            ->groupBy('inv_cst_id')
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
                'columns' => 'IFNULL(inv_cst_id, 0)',
            ]
        );

        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(3, $page->getItems());
        $this->assertSame(3, $page->getTotalItems());
        $this->assertSame(1, $page->getLast());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate()
     *
     * @issue  14639
     *
     * @group mysql
     * @group sqlite
     *
     * @throws Exception
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-15
     */
    public function testPaginatorAdapterQuerybuilderPaginateView(): void
    {
        $this->setDiService('view');

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $criteria = Criteria::fromInput(
            $this->container,
            Invoices::class,
            []
        );
        $builder  = $criteria->createBuilder();

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $page = $paginator->paginate();
        $this->assertCount(5, $page->getItems());

        $view = $this->getService('view');
        $view->setVar('page', $page);

        $actual = $view->getVar('page');
        $this->assertInstanceOf(Repository::class, $actual);


        $view = $this->getService('view');
        $view->setVar('paginate', $paginator->paginate());

        $actual = $view->getVar('paginate');
        $this->assertInstanceOf(Repository::class, $actual);
    }
}
