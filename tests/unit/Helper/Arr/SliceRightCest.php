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
 * Class RemoveRightCest
 */
class SliceRightCest
{
    /**
     * Tests Phalcon\Helper\Arr :: sliceRight()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrSliceRight(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - sliceRight()');
        $collection = [
            'Phalcon',
            'Framework',
            'for',
            'PHP',
        ];

        $expected = [
            'Framework',
            'for',
            'PHP',
        ];
        $actual   = Arr::sliceRight($collection, 1);
        $I->assertEquals($expected, $actual);

        $expected = [
            'PHP',
        ];
        $actual   = Arr::sliceRight($collection, 3);
        $I->assertEquals($expected, $actual);
    }
}
