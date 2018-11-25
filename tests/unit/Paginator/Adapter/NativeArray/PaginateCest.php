<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Paginator\Adapter\NativeArray;

use Phalcon\Paginator\Adapter\NativeArray;
use stdClass;
use UnitTester;

class PaginateCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: paginate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearrayPaginate(UnitTester $I)
    {
        $I->wantToTest("Paginator\Adapter\NativeArray - paginate()");
        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $page = $paginator->paginate();

        $expected = stdClass::class;
        $I->assertInstanceOf($expected, $page);

        $I->assertCount(25, $page->items);
        $I->assertEquals(1, $page->previous);
        $I->assertEquals(2, $page->next);
        $I->assertEquals(2, $page->last);
        $I->assertEquals(25, $page->limit);
        $I->assertEquals(1, $page->current);
        $I->assertEquals(30, $page->total_items);
    }
}
