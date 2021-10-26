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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Split;
use UnitTester;

/**
 * Class SplitCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class SplitCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: split()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrSplit(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - split()');

        $object     = new Split();
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = [
            [1, 3],
            ['Phalcon', 'Framework'],
        ];
        $actual   = $object($collection);
        $I->assertEquals($expected, $actual);
    }
}
