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

use Phalcon\Support\Helper\Arr\Flatten;
use UnitTester;

/**
 * Class FlattenCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class FlattenCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: flatten()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFlatten(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - flatten()');

        $object = new Flatten();
        $source = [1, [2], [[3], 4], 5];

        $expected = [1, 2, [3], 4, 5];
        $actual   = $object($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: flatten() - deep
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFlattenDeep(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - flatten() - deep');

        $object = new Flatten();
        $source = [1, [2], [[3], 4], 5];

        $expected = [1, 2, 3, 4, 5];
        $actual   = $object($source, true);
        $I->assertEquals($expected, $actual);
    }
}
