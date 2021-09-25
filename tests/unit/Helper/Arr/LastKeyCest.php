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

class LastKeyCest
{
    /**
     * Tests Phalcon\Helper\Arr :: last()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrLast(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last()');

        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $I->assertEquals(
            3,
            Arr::lastKey($collection)
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: last() - function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrLastFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last() - function');

        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $actual = Arr::lastKey(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            }
        );

        $I->assertEquals(
            1,
            $actual
        );
    }
}
