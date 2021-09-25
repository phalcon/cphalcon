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

class SliceLeftCest
{
    /**
     * Tests Phalcon\Helper\Arr :: sliceLeft()
     *
     * @author Phalcon Team <team@phalcon.io>
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

        $I->assertEquals(
            $expected,
            Arr::sliceLeft($collection, 1)
        );


        $expected = [
            'Phalcon',
            'Framework',
            'for',
        ];

        $I->assertEquals(
            $expected,
            Arr::sliceLeft($collection, 3)
        );
    }
}
