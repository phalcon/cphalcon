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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilderCursor;

use PDO;
use Phalcon\Paginator\Adapter\QueryBuilderCursor;
use Phalcon\Paginator\Repository;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: paginate() -
     * empty table returns empty items and zero cursor
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14754
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorPaginateEmpty(): void
    {
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertIsArray($page->getItems());
        $this->assertCount(0, $page->getItems());
        $this->assertSame(0, $page->getNext());
        $this->assertSame(0, $page->getCurrent());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: paginate() -
     * exact multiple of limit has no next page on the last page
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14754
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorPaginateExactMultiple(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 10, $invId, 1, 'bbb');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $page1 = $paginator->paginate();
        $page1Next = $page1->getNext();
        $this->assertCount(5, $page1->getItems());
        $this->assertGreaterThan(0, $page1Next);

        $paginator->setCursor($page1Next);
        $page2 = $paginator->paginate();
        $this->assertCount(5, $page2->getItems());
        $this->assertSame(0, $page2->getNext());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: paginate() -
     * first page returns correct slice and a valid next cursor
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14754
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorPaginateFirstPage(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 12, $invId, 1, 'aaa');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertIsArray($page->getItems());
        $this->assertCount(5, $page->getItems());
        $this->assertSame(0, $page->getCurrent());
        $this->assertSame(5, $page->getLimit());
        $this->assertSame(0, $page->getTotalItems());
        $this->assertSame(0, $page->getLast());
        $this->assertGreaterThan(0, $page->getNext());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: paginate() -
     * traversing all pages forward yields every row exactly once
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14754
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorPaginateForwardTraversal(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 11, $invId, 1, 'aaa');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        // page 1 - 5 rows, next cursor set
        $page1 = $paginator->paginate();
        $page1Items = $page1->getItems();
        $this->assertCount(5, $page1Items);
        $this->assertGreaterThan(0, $page1->getNext());

        // Capture cursor before the next paginate() call overwrites the shared
        // repository object
        $page1Next = $page1->getNext();

        // page 2 - 5 rows, next cursor set
        $paginator->setCursor($page1Next);
        $page2 = $paginator->paginate();
        $page2Items = $page2->getItems();
        $this->assertCount(5, $page2Items);
        $this->assertSame($page1Next, $page2->getCurrent());
        $this->assertGreaterThan(0, $page2->getNext());

        // Capture before page 3 overwrites
        $page2Next = $page2->getNext();

        // page 3 - 1 remaining row, no further page
        $paginator->setCursor($page2Next);
        $page3 = $paginator->paginate();
        $page3Items = $page3->getItems();
        $this->assertCount(1, $page3Items);
        $this->assertSame(0, $page3->getNext());

        // Collect all IDs and verify no duplicates and correct count
        $allIds = array_merge(
            array_column($page1Items, 'inv_id'),
            array_column($page2Items, 'inv_id'),
            array_column($page3Items, 'inv_id')
        );
        $this->assertCount(11, $allIds);
        $this->assertCount(11, array_unique($allIds));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: paginate() -
     * setCursor(null) resets to the first page
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14754
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorPaginateResetCursor(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 6, $invId, 1, 'ccc');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $page1 = $paginator->paginate();
        $page1Items = $page1->getItems();
        $page1Next  = $page1->getNext();
        $this->assertCount(5, $page1Items);

        // Advance to page 2
        $paginator->setCursor($page1Next);
        $page2 = $paginator->paginate();
        $this->assertCount(1, $page2->getItems());

        // Reset to first page
        $paginator->setCursor(null);
        $pageReset = $paginator->paginate();
        $this->assertCount(5, $pageReset->getItems());
        $this->assertSame(0, $pageReset->getCurrent());
        $this->assertSame($page1Items, $pageReset->getItems());
    }
}
