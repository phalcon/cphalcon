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
 * Class LastKeyCest
 */
class LastKeyCest
{
    /**
     * Tests Phalcon\Helper\Arr :: last()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrLast(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last()');
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 3;
        $actual   = Arr::lastKey($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: last() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrLastFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last() - function');
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 1;
        $actual   = Arr::lastKey(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
