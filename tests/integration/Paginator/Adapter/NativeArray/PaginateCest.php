<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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

        $expected = Repository::class;
        $I->assertInstanceOf($expected, $page);

        $I->assertCount(25, $page->getItems());
        $I->assertEquals($page->getPrevious(), 1);
        $I->assertEquals($page->getNext(), 2);
        $I->assertEquals($page->getLast(), 2);
        $I->assertEquals($page->getLimit(), 25);
        $I->assertEquals($page->getCurrent(), 1);
    }
}
