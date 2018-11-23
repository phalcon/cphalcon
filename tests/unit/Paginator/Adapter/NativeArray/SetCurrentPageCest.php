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

use stdClass;
use Phalcon\Paginator\Adapter\NativeArray;
use UnitTester;

class SetCurrentPageCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setCurrentPage()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testSetCurrentPage(UnitTester $I)
    {
        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 10,
                'page'  => 1
            ]
        );

        $paginator->setCurrentPage(2);
        $page = $paginator->paginate();

        $expected = stdClass::class;
        $I->assertInstanceOf($expected, $page);

        $I->assertCount(10, $page->items);
        $I->assertEquals(1, $page->previous);
        $I->assertEquals(3, $page->next);
        $I->assertEquals(3, $page->last);
        $I->assertEquals(10, $page->limit);
        $I->assertEquals(2, $page->current);
        $I->assertEquals(30, $page->total_items);
    }
}
