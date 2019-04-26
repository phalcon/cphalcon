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
 * Class SplitCest
 */
class SplitCest
{
    /**
     * Tests Phalcon\Helper\Arr :: split()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-07
     */
    public function helperArrSplit(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - split()');
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = [
            [1, 3],
            ['Phalcon', 'Framework']
        ];
        $actual   = Arr::split($collection);
        $I->assertEquals($expected, $actual);
    }
}
