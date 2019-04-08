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

/**
 * Class PluckCest
 */
class PluckCest
{
    /**
     * Tests Phalcon\Helper\Arr :: pluck()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
}
