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

namespace Phalcon\Test\Integration\Paginator\Adapter\Model;

use IntegrationTester;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Paginator\Repository;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;

class PaginateCest
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

    public function paginatorAdapterModelPaginate(IntegrationTester $I): void
    {
        $paginator = new Model(
            [
                'model' => Personnes::class,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        //First Page
        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(
            10,
            $page->getItems()
        );

        $I->assertEquals(
            1,
            $page->getPrevious()
        );

        $I->assertEquals(
            2,
            $page->getNext()
        );

        $I->assertEquals(
            218,
            $page->getLast()
        );

        $I->assertEquals(
            10,
            $page->getLimit()
        );

        $I->assertEquals(
            1,
            $page->getCurrent()
        );

        //Middle Page
        $paginator->setCurrentPage(50);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(
            10,
            $page->getItems()
        );

        $I->assertEquals(
            49,
            $page->getPrevious()
        );

        $I->assertEquals(
            51,
            $page->getNext()
        );

        $I->assertEquals(
            218,
            $page->getLast()
        );

        $I->assertEquals(
            50,
            $page->getCurrent()
        );

        //Last Page
        $paginator->setCurrentPage(218);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(
            10,
            $page->getItems()
        );

        $I->assertEquals(
            217,
            $page->getPrevious()
        );

        $I->assertEquals(
            218,
            $page->getNext()
        );

        $I->assertEquals(
            218,
            $page->getLast()
        );

        $I->assertEquals(
            218,
            $page->getCurrent()
        );
    }

    public function paginatorAdapterModelPaginateBind(IntegrationTester $I)
    {
        $parameters = [
            'conditions' => 'cedula >=:d1: AND cedula>=:d2: ',
            'bind'       => [
                'd1' => '1',
                'd2' => '5',
            ],
            'order'      => 'cedula, nombres',
            'limit'      => '33',   // will be ignored
        ];

        $paginator = new Model(
            [
                'model'      => Personnes::class,
                'parameters' => $parameters,
                'limit'      => 10,
                'page'       => 1,
            ]
        );

        //First Page
        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(
            10,
            $page->getItems()
        );

        $I->assertEquals(
            1,
            $page->getPrevious()
        );

        $I->assertEquals(
            2,
            $page->getNext()
        );

        $I->assertEquals(
            54,
            $page->getLast()
        );

        $I->assertEquals(
            10,
            $page->getLimit()
        );

        $I->assertEquals(
            1,
            $page->getCurrent()
        );
    }

    public function paginatorAdapterModelPaginateParametersAsString(IntegrationTester $I): void
    {
        $paginator = new Model(
            [
                'model'      => Personnes::class,
                'parameters' => 'ciudad_id % 3',
                'limit'      => 10,
                'page'       => 4,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(Repository::class, $page);

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(3, $page->getPrevious());

        $I->assertEquals(5, $page->getNext());

        $I->assertEquals(171, $page->getLast());

        $I->assertEquals(10, $page->getLimit());

        $I->assertEquals(4, $page->getCurrent());
    }

    public function paginatorAdapterModelPaginateParametersArrayString(IntegrationTester $I): void
    {
        $paginator = new Model(
            [
                'model'      => Personnes::class,
                'parameters' => [
                    'ciudad_id % 3',
                ],
                'limit'      => 10,
                'page'       => 4,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(Repository::class, $page);

        $I->assertCount(10, $page->getItems());

        $I->assertEquals(3, $page->getPrevious());

        $I->assertEquals(5, $page->getNext());

        $I->assertEquals(171, $page->getLast());

        $I->assertEquals(10, $page->getLimit());

        $I->assertEquals(4, $page->getCurrent());
    }
}
