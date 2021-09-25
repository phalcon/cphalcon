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

class FirstKeyCest
{
    /**
     * Tests Phalcon\Helper\Arr :: firstKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrFirstKey(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - firstKey()');
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 1;
        $actual   = Arr::firstKey($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: firstKey() - function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrFirstKeyFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - firstKey() - function');
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 3;
        $actual   = Arr::firstKey(
            $collection,
            function ($element) {
                return strlen($element) > 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
