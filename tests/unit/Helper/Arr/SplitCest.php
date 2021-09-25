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

class SplitCest
{
    /**
     * Tests Phalcon\Helper\Arr :: split()
     *
     * @author Phalcon Team <team@phalcon.io>
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
            ['Phalcon', 'Framework'],
        ];
        $actual   = Arr::split($collection);
        $I->assertEquals($expected, $actual);
    }
}
