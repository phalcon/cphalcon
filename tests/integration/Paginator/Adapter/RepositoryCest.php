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

class RepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: paginate()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testRepositoryPaginator(IntegrationTester $I)
    {
        $paginatorRepository = new \Phalcon\Paginator\Repository();
        $paginatorRepository->setAliases([
            'myFirstPage'   => $paginatorRepository::PROPERTY_FIRST_PAGE,
            'myLastPage'    => $paginatorRepository::PROPERTY_LAST_PAGE,
            'myCurrentPage' => $paginatorRepository::PROPERTY_CURRENT_PAGE,
            'myLimit'       => $paginatorRepository::PROPERTY_LIMIT,
        ]);

        $paginator = new \Phalcon\Paginator\Adapter\NativeArray([
            'data'       => array_fill(0, 30, 'banana'),
            'limit'      => 25,
            'page'       => 1,
            'repository' => $paginatorRepository,
        ]);

        $page = $paginator->paginate();
        $I->assertInstanceOf(\Phalcon\Paginator\Repository::class, $page);
        // Test getters
        $I->assertEquals(count($page->getItems()), 25);
        $I->assertEquals($page->getPrevious(), 1);
        $I->assertEquals($page->getNext(), 2);
        $I->assertEquals($page->getLast(), 2);
        $I->assertEquals($page->getLimit(), 25);
        $I->assertEquals($page->getCurrent(), 1);
        // Test aliases
        $I->assertEquals($page->myLastPage, 2);
        $I->assertEquals($page->myLimit, 25);
        $I->assertEquals($page->myCurrentPage, 1);
        $paginator->setCurrentPage(2);
        $page = $paginator->paginate();
        $I->assertInstanceOf(\Phalcon\Paginator\Repository::class, $page);
        // Test magic getters
        $I->assertEquals(count($page->items), 5);
        $I->assertEquals($page->previous, 1);
        $I->assertEquals($page->next, 2);
        $I->assertEquals($page->last, 2);
        $I->assertEquals($page->current, 2);
        // Test aliases
        $I->assertEquals($page->myLastPage, 2);
        $I->assertEquals($page->myLimit, 25);
        $I->assertEquals($page->myCurrentPage, 2);
    }
}
