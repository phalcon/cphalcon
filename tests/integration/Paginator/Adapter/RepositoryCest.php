<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter;

use IntegrationTester;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;

class RepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: paginate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testRepositoryPaginator(IntegrationTester $I)
    {
        $paginatorRepository = new Repository();

        $paginatorRepository->setAliases(
            [
                'myFirstPage'   => $paginatorRepository::PROPERTY_FIRST_PAGE,
                'myLastPage'    => $paginatorRepository::PROPERTY_LAST_PAGE,
                'myCurrentPage' => $paginatorRepository::PROPERTY_CURRENT_PAGE,
                'myLimit'       => $paginatorRepository::PROPERTY_LIMIT,
            ]
        );

        $paginator = new NativeArray(
            [
                'data'       => array_fill(0, 30, 'banana'),
                'limit'      => 25,
                'page'       => 1,
                'repository' => $paginatorRepository,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );


        // Test getters
        $I->assertCount(25, $page->getItems());
        $I->assertEquals(1, $page->getPrevious());
        $I->assertEquals(2, $page->getNext());
        $I->assertEquals(2, $page->getLast());
        $I->assertEquals(25, $page->getLimit());
        $I->assertEquals(1, $page->getCurrent());


        // Test aliases
        $I->assertEquals(2, $page->myLastPage);
        $I->assertEquals(25, $page->myLimit);
        $I->assertEquals(1, $page->myCurrentPage);

        $paginator->setCurrentPage(2);

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );


        // Test magic getters
        $I->assertCount(5, $page->items);
        $I->assertEquals(1, $page->previous);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(2, $page->last);
        $I->assertEquals(2, $page->current);


        // Test aliases
        $I->assertEquals(2, $page->myLastPage);
        $I->assertEquals(25, $page->myLimit);
        $I->assertEquals(2, $page->myCurrentPage);
    }
}
