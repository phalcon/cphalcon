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

namespace Phalcon\Tests\Database\Paginator\Adapter\Model;

use PDO;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Paginator\Repository;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

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
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginate(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $paginator = new Model(
            [
                'model' => Invoices::class,
                'limit' => 5,
                'page'  => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(15, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());

        // Middle Page
        $paginator->setCurrentPage(3);
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(5, $page->getItems());
        $this->assertEquals(2, $page->getPrevious());
        $this->assertEquals(4, $page->getNext());
        $this->assertEquals(15, $page->getLast());
        $this->assertEquals(3, $page->getCurrent());

        // Last Page
        $paginator->setCurrentPage(5);
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(5, $page->getItems());
        $this->assertEquals(4, $page->getPrevious());
        $this->assertEquals(6, $page->getNext());
        $this->assertEquals(15, $page->getLast());
        $this->assertEquals(5, $page->getCurrent());
    }

    /**
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginateBind(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $parameters = [
            'columns'    => 'inv_cst_id',
            'conditions' => 'inv_cst_id >= :d1:',
            'bind'       => [
                'd1' => '2',
            ],
            'order'      => 'inv_cst_id',
            'limit'      => '11',   // will be ignored
        ];

        $paginator = new Model(
            [
                'model'      => Invoices::class,
                'parameters' => $parameters,
                'limit'      => 5,
                'page'       => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(9, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
    }

    /**
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginateEmpty(): void
    {
        $paginator = new Model(
            [
                'model'      => Invoices::class,
                'parameters' => [
                    'inv_cst_id < -1',
                ],
                'limit'      => 5,
                'page'       => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(0, $page->getItems());
        $this->assertIsArray($page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(0, $page->getNext());
        $this->assertEquals(0, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
    }

    /**
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginateParametersArrayString(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $paginator = new Model(
            [
                'model'      => Invoices::class,
                'parameters' => [
                    'inv_cst_id >= 2',
                ],
                'limit'      => 5,
                'page'       => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(9, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
    }

    /**
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginateParametersString(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $paginator = new Model(
            [
                'model'      => Invoices::class,
                'parameters' => 'inv_cst_id >= 2',
                'limit'      => 5,
                'page'       => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(9, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
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
    public function testPaginatorAdapterModelPaginateView(): void
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

        $paginator = new Model(
            [
                'model' => Invoices::class,
                'limit' => 5,
                'page'  => 1,
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-12-26
     * @issue  https://github.com/phalcon/cphalcon/issues/16471
     *
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterModelPaginateWithOrder(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $paginator = new Model(
            [
                'model'      => Invoices::class,
                'parameters' => [
                    'inv_cst_id >= 2',
                    'order' => 'inv_cst_id',
                ],
                'limit'      => 5,
                'page'       => 1,
            ]
        );

        // First Page
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(5, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(9, $page->getLast());
        $this->assertEquals(5, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
    }
}
