<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

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

    public function paginatorAdapterModelPaginate(IntegrationTester $I)
    {
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
        $personnes = Personnes::find(
            [
                'conditions' => 'cedula >=:d1: AND cedula>=:d2: ',
                'bind'       => [
                    'd1' => '1',
                    'd2' => '5',
                ],
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
            4,
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
}
