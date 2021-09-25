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

class SliceRightCest
{
    /**
     * Tests Phalcon\Helper\Arr :: sliceRight()
     *
     * @author Phalcon Team <team@phalcon.io>
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

        $I->assertEquals(
            $expected,
            Arr::sliceRight($collection, 1)
        );


        $expected = [
            'PHP',
        ];

        $I->assertEquals(
            $expected,
            Arr::sliceRight($collection, 3)
        );
    }
}
