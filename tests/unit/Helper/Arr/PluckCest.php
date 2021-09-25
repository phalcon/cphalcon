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

class PluckCest
{
    /**
     * Tests Phalcon\Helper\Arr :: pluck()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrPluck(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - pluck()');
        $collection = [
            ['product_id' => 'prod-100', 'name' => 'Desk'],
            ['product_id' => 'prod-200', 'name' => 'Chair'],
        ];

        $expected = ['Desk', 'Chair'];
        $actual   = Arr::pluck($collection, 'name');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: pluck() - object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrPluckObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - pluck()');
        $collection = [
            Arr::toObject(['product_id' => 'prod-100', 'name' => 'Desk']),
            Arr::toObject(['product_id' => 'prod-200', 'name' => 'Chair']),
        ];

        $expected = ['Desk', 'Chair'];
        $actual   = Arr::pluck($collection, 'name');
        $I->assertEquals($expected, $actual);
    }
}
