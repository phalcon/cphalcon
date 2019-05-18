<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration;

use IntegrationTester;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;
use stdClass;

class PaginatorCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiMysql();
    }

    public function testModelPaginator(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check me');

        $personnes = Personnes::find();

        $paginator = new Model(
            [
                'data'  => $personnes,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        //First Page
        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(1, $page->before);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(218, $page->last);
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->current);
        $I->assertEquals(218, $page->total_pages);

        //Middle Page
        $paginator->setCurrentPage(50);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(49, $page->before);
        $I->assertEquals(51, $page->next);
        $I->assertEquals(218, $page->last);

        $I->assertEquals(50, $page->current);
        $I->assertEquals(218, $page->total_pages);

        //Last Page
        $paginator->setCurrentPage(218);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(217, $page->before);
        $I->assertEquals(218, (int) $page->next);
        $I->assertEquals(218, $page->last);

        $I->assertEquals(218, $page->current);
        $I->assertEquals(218, $page->total_pages);
    }

    public function testModelPaginatorBind(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check me');

        $personnes = Personnes::find(
            [
                'conditions' => 'cedula >=:d1: AND cedula>=:d2: ',
                'bind'       => ['d1' => '1', 'd2' => '5'],
                'order'      => 'cedula, nombres',
                'limit'      => '33',
            ]
        );

        $paginator = new Model(
            [
                'data'  => $personnes,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        //First Page
        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(1, $page->before);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(4, $page->last);
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->current);
        $I->assertEquals(4, $page->total_pages);
    }

    public function testQueryBuilderPaginator(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check me');

        $manager = $this->getService('modelsManager');

        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from('Personnes')
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
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(1, $page->before);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(218, $page->last);
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->current);
        $I->assertEquals(2180, $page->total_items);
        $I->assertEquals(218, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Middle page
        $paginator->setCurrentPage(100);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(10, $page->items);

        $I->assertEquals(99, $page->before);
        $I->assertEquals(101, $page->next);
        $I->assertEquals(218, $page->last);

        $I->assertEquals(100, $page->current);
        $I->assertEquals(218, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Last page
        $paginator->setCurrentPage(218);

        $page = $paginator->paginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals(217, $page->before);
        $I->assertEquals(218, $page->next);
        $I->assertEquals(218, $page->last);

        $I->assertEquals(218, $page->current);
        $I->assertEquals(218, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        // test of getter/setters of querybuilder adapter

        // -- current page --
        $currentPage = $paginator->getCurrentPage();
        $I->assertEquals(218, $currentPage);

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
                            ->from('Personnes')
        ;

        $setterResult = $paginator->setQueryBuilder($builder2);
        $queryBuilder = $paginator->getQueryBuilder();
        $I->assertEquals($builder2, $queryBuilder);
        $I->assertEquals($paginator, $setterResult);
    }

    public function testQueryBuilderPaginatorGroupBy(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check me');

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
                           ->from('Personnes')
                           ->groupBy('email')
        ;

        $this->paginatorBuilderTest($I, $builder);

        // test paginator with group by array value
        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from('Personnes')
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
                            ->from('Personnes')
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

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals(1, $page->before);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(18, $page->last);
        $I->assertEquals(10, $page->limit);

        $I->assertEquals(1, $page->current);
        $I->assertEquals(178, $page->total_items);
        $I->assertEquals(18, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Middle page
        $paginator->setCurrentPage(10);

        $page = $paginator->paginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals(9, $page->before);
        $I->assertEquals(11, $page->next);
        $I->assertEquals(18, $page->last);

        $I->assertEquals(10, $page->current);
        $I->assertEquals(18, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Last page
        $paginator->setCurrentPage(18);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            stdClass::class,
            $page
        );

        $I->assertCount(9, $page->items);

        $I->assertEquals(17, $page->before);
        $I->assertEquals(18, $page->next);
        $I->assertEquals(18, $page->last);

        $I->assertEquals(18, $page->current);
        $I->assertEquals(18, $page->total_pages);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);
    }
}
