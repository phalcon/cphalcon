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
 * Class RemoveLeftCest
 */
class SliceLeftCest
{
    /**
     * Tests Phalcon\Helper\Arr :: sliceLeft()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrSliceLeft(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - sliceLeft()');
        $collection = [
            'Phalcon',
            'Framework',
            'for',
            'PHP',
        ];

        $expected = [
            'Phalcon',
        ];
        $actual   = Arr::sliceLeft($collection, 1);
        $I->assertEquals($expected, $actual);

        $expected = [
            'Phalcon',
            'Framework',
            'for',
        ];
        $actual   = Arr::sliceLeft($collection, 3);
        $I->assertEquals($expected, $actual);
    }
}
