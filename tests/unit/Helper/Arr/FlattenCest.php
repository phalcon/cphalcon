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

class FlattenCest
{
    /**
     * Tests Phalcon\Helper\Arr :: flatten()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrFlatten(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - flatten()');

        $source = [1, [2], [[3], 4], 5];

        $expected = [1, 2, [3], 4, 5];
        $actual   = Arr::flatten($source);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: flatten() - deep
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrFlattenDeep(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - flatten() - deep');

        $source = [1, [2], [[3], 4], 5];

        $expected = [1, 2, 3, 4, 5];
        $actual   = Arr::flatten($source, true);
        $I->assertEquals($expected, $actual);
    }
}
