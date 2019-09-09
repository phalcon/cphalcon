<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter\QueryBuilder;

use IntegrationTester;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Repository;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;

class PaginatorQueryBuilderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testQueryBuilderPaginator(IntegrationTester $I)
    {
        $manager = $this->getService('modelsManager');

        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from(Personnes::class)
                           ->orderBy('cedula')
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 10,
                'page'    => 1,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(218, $page->getLast());
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->getCurrent());
        $I->assertEquals(2180, $page->getTotalItems());

        $I->assertInternalType('int', $page->getTotalItems());

        //Middle page
        $paginator->setCurrentPage(100);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(99, $page->getPrevious());
        $I->assertEquals(101, $page->getNext());
        $I->assertEquals(218, $page->getLast());

        $I->assertEquals(100, $page->getCurrent());

        $I->assertInternalType('int', $page->getTotalItems());

        //Last page
        $paginator->setCurrentPage(218);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(217, $page->getPrevious());
        $I->assertEquals(218, $page->getNext());
        $I->assertEquals(218, $page->getLast());

        $I->assertEquals(218, $page->getCurrent());

        $I->assertInternalType('int', $page->getTotalItems());

        // test of getter/setters of querybuilder adapter

        // -- current page --
        $currentPage = $paginator->getCurrentPage();
        $I->assertEquals(218, $currentPage);
    }

    public function testQueryBuilderPaginatorGroupBy(IntegrationTester $I)
    {
        $database = $this->getService('db');

        $database->query(
            "SET SESSION sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE," .
            'NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,' .
            "NO_ENGINE_SUBSTITUTION'"
        );

        // test paginator with group by string value
        $manager = $this->getService('modelsManager');

        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from(Personnes::class)
                           ->groupBy('email')
        ;

        $this->paginatorBuilderTest($I, $builder);

        // test paginator with group by array value
        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from(Personnes::class)
                           ->groupBy(['email'])
        ;

        $this->paginatorBuilderTest($I, $builder);

        // test of getter/setters of querybuilder adapter

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 10,
                'page'    => 1,
            ]
        );

        $paginator->setCurrentPage(18);

        // -- current page --
        $currentPage = $paginator->getCurrentPage();

        $I->assertEquals(18, $currentPage);

        // -- limit --
        $rowsLimit = $paginator->getLimit();
        $I->assertEquals(10, $rowsLimit);

        $setterResult = $paginator->setLimit(25);
        $rowsLimit    = $paginator->getLimit();
        $I->assertEquals(25, $rowsLimit);
        $I->assertEquals($paginator, $setterResult);

        // -- builder --
        $queryBuilder = $paginator->getQueryBuilder();
        $I->assertEquals($builder, $queryBuilder);

        $builder2 = $manager->createBuilder()
                            ->columns('cedula, nombres')
                            ->from(Personnes::class)
                            ->groupBy(['email'])
        ;

        $setterResult = $paginator->setQueryBuilder($builder2);
        $queryBuilder = $paginator->getQueryBuilder();
        $I->assertEquals($builder2, $queryBuilder);
        $I->assertEquals($paginator, $setterResult);
    }

    private function paginatorBuilderTest(IntegrationTester $I, $builder)
    {
        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 10,
                'page'    => 1,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(18, $page->getLast());
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->getCurrent());
        $I->assertEquals(178, $page->getTotalItems());

        $I->assertInternalType('int', $page->getTotalItems());

        //Middle page
        $paginator->setCurrentPage(10);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(9, $page->getPrevious());
        $I->assertEquals(11, $page->getNext());
        $I->assertEquals(18, $page->getLast());

        $I->assertEquals(10, $page->getCurrent());

        $I->assertInternalType('int', $page->getTotalItems());

        //Last page
        $paginator->setCurrentPage(18);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(9, $page->getItems());

        $I->assertEquals(17, $page->getPrevious());
        $I->assertEquals(18, $page->getNext());
        $I->assertEquals(18, $page->getLast());

        $I->assertEquals(18, $page->getCurrent());

        $I->assertInternalType('int', $page->getTotalItems());
    }
}
