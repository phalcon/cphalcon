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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class OrderCest
{
    /**
     * Tests Phalcon\Helper\Arr :: order()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrOrder(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - order()');

        $collection = [
            ['id' => 2, 'name' => 'Paul'],
            ['id' => 3, 'name' => 'Peter'],
            ['id' => 1, 'name' => 'John'],
        ];


        $expected = [
            ['id' => 1, 'name' => 'John'],
            ['id' => 2, 'name' => 'Paul'],
            ['id' => 3, 'name' => 'Peter'],
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id')
        );


        $expected = [
            ['id' => 3, 'name' => 'Peter'],
            ['id' => 2, 'name' => 'Paul'],
            ['id' => 1, 'name' => 'John'],
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id', 'desc')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: order() - object
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrOrderObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - order()');

        $collection = [
            Arr::arrayToObject(['id' => 2, 'name' => 'Paul']),
            Arr::arrayToObject(['id' => 3, 'name' => 'Peter']),
            Arr::arrayToObject(['id' => 1, 'name' => 'John']),
        ];


        $expected = [
            Arr::arrayToObject(['id' => 1, 'name' => 'John']),
            Arr::arrayToObject(['id' => 2, 'name' => 'Paul']),
            Arr::arrayToObject(['id' => 3, 'name' => 'Peter']),
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id')
        );


        $expected = [
            Arr::arrayToObject(['id' => 3, 'name' => 'Peter']),
            Arr::arrayToObject(['id' => 2, 'name' => 'Paul']),
            Arr::arrayToObject(['id' => 1, 'name' => 'John']),
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id', 'desc')
        );
    }
}
