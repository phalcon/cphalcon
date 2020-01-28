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

namespace Phalcon\Test\Integration\Paginator\Adapter\NativeArray;

use IntegrationTester;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;

/**
 * Class PaginateCest
 */
class PaginateCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: paginate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearrayPaginate(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - paginate()');

        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $page = $paginator->paginate();

        $I->assertInstanceOf(
            Repository::class,
            $page
        );

        $I->assertCount(
            25,
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
            2,
            $page->getLast()
        );

        $I->assertEquals(
            25,
            $page->getLimit()
        );

        $I->assertEquals(
            1,
            $page->getCurrent()
        );
    }
}
