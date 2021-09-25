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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class OrderCest
{
    /**
     * Tests Phalcon\Helper\Arr :: order()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrOrder(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - order()');

        $collection = [
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
            [
                'id'   => 1,
                'name' => 'John',
            ],
        ];


        $expected = [
            [
                'id'   => 1,
                'name' => 'John',
            ],
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id')
        );


        $expected = [
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 1,
                'name' => 'John',
            ],
        ];

        $I->assertEquals(
            $expected,
            Arr::order($collection, 'id', 'desc')
        );
    }
}
