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
 * Class FlattenCest
 */
class FlattenCest
{
    /**
     * Tests Phalcon\Helper\Arr :: flatten()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrFlatten(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - flatten()');

        $source   = [1, [2], [[3], 4], 5];
        $expected = [1, 2, [3], 4, 5];
        $actual   = Arr::flatten($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: flatten() - deep
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrFlattenDeep(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - flatten() - deep');

        $source   = [1, [2], [[3], 4], 5];
        $expected = [1, 2, 3, 4, 5];
        $actual   = Arr::flatten($source, true);
        $I->assertEquals($expected, $actual);
    }
}
