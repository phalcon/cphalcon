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
        $page = $paginator->getPaginate();
        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 1);
        $I->assertEquals($page->next, 2);
        $I->assertEquals($page->last, 218);
        $I->assertEquals($page->limit, 10);

        $I->assertEquals($page->current, 1);
        $I->assertEquals($page->total_pages, 218);

        //Middle Page
        $paginator->setCurrentPage(50);

        $page = $paginator->getPaginate();
        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 49);
        $I->assertEquals($page->next, 51);
        $I->assertEquals($page->last, 218);

        $I->assertEquals($page->current, 50);
        $I->assertEquals($page->total_pages, 218);

        //Last Page
        $paginator->setCurrentPage(218);

        $page = $paginator->getPaginate();
        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 217);
        $I->assertEquals((int) $page->next, 218);
        $I->assertEquals($page->last, 218);

        $I->assertEquals($page->current, 218);
        $I->assertEquals($page->total_pages, 218);
    }

    public function testModelPaginatorBind(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check me');
        $personnes = Personnes::find([
            "conditions" => "cedula >=:d1: AND cedula>=:d2: ",
            "bind"       => ["d1" => '1', "d2" => "5"],
            "order"      => "cedula, nombres",
            "limit"      => "33",
        ]);

        $paginator = new Model(
            [
                'data'  => $personnes,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        //First Page
        $page = $paginator->getPaginate();
        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 1);
        $I->assertEquals($page->next, 2);
        $I->assertEquals($page->last, 4);
        $I->assertEquals($page->limit, 10);

        $I->assertEquals($page->current, 1);
        $I->assertEquals($page->total_pages, 4);
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
                "builder" => $builder,
                "limit"   => 10,
                "page"    => 1,
            ]
        );

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 1);
        $I->assertEquals($page->next, 2);
        $I->assertEquals($page->last, 218);
        $I->assertEquals($page->limit, 10);

        $I->assertEquals($page->current, 1);
        $I->assertEquals($page->total_items, 2180);
        $I->assertEquals($page->total_pages, 218);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Middle page
        $paginator->setCurrentPage(100);

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 99);
        $I->assertEquals($page->next, 101);
        $I->assertEquals($page->last, 218);

        $I->assertEquals($page->current, 100);
        $I->assertEquals($page->total_pages, 218);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Last page
        $paginator->setCurrentPage(218);

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 217);
        $I->assertEquals($page->next, 218);
        $I->assertEquals($page->last, 218);

        $I->assertEquals($page->current, 218);
        $I->assertEquals($page->total_pages, 218);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        // test of getter/setters of querybuilder adapter

        // -- current page --
        $currentPage = $paginator->getCurrentPage();
        $I->assertEquals($currentPage, 218);

        // -- limit --
        $rowsLimit = $paginator->getLimit();
        $I->assertEquals($rowsLimit, 10);

        $setterResult = $paginator->setLimit(25);
        $rowsLimit    = $paginator->getLimit();
        $I->assertEquals($rowsLimit, 25);
        $I->assertEquals($setterResult, $paginator);

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
        $I->assertEquals($setterResult, $paginator);
    }

    public function testQueryBuilderPaginatorGroupBy(IntegrationTester $I)
    {
        $I->skipTest('TODO: Check me');
        $database = $this->getService('db');
        $database->query(
            "SET SESSION sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE," .
            "NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER," .
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
                "builder" => $builder,
                "limit"   => 10,
                "page"    => 1,
            ]
        );

        $paginator->setCurrentPage(18);

        // -- current page --
        $currentPage = $paginator->getCurrentPage();
        $I->assertEquals($currentPage, 18);

        // -- limit --
        $rowsLimit = $paginator->getLimit();
        $I->assertEquals($rowsLimit, 10);

        $setterResult = $paginator->setLimit(25);
        $rowsLimit    = $paginator->getLimit();
        $I->assertEquals($rowsLimit, 25);
        $I->assertEquals($setterResult, $paginator);

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
        $I->assertEquals($setterResult, $paginator);
    }

    private function paginatorBuilderTest(IntegrationTester $I, $builder)
    {
        $paginator = new QueryBuilder([
            "builder" => $builder,
            "limit"   => 10,
            "page"    => 1,
        ]);

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 1);
        $I->assertEquals($page->next, 2);
        $I->assertEquals($page->last, 18);
        $I->assertEquals($page->limit, 10);

        $I->assertEquals($page->current, 1);
        $I->assertEquals($page->total_items, 178);
        $I->assertEquals($page->total_pages, 18);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Middle page
        $paginator->setCurrentPage(10);

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(10, $page->items);

        $I->assertEquals($page->before, 9);
        $I->assertEquals($page->next, 11);
        $I->assertEquals($page->last, 18);

        $I->assertEquals($page->current, 10);
        $I->assertEquals($page->total_pages, 18);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);

        //Last page
        $paginator->setCurrentPage(18);

        $page = $paginator->getPaginate();

        $I->assertInstanceOf('stdClass', $page);

        $I->assertCount(9, $page->items);

        $I->assertEquals($page->before, 17);
        $I->assertEquals($page->next, 18);
        $I->assertEquals($page->last, 18);

        $I->assertEquals($page->current, 18);
        $I->assertEquals($page->total_pages, 18);

        $I->assertInternalType('int', $page->total_items);
        $I->assertInternalType('int', $page->total_pages);
    }
}
