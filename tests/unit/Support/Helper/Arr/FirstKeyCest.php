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

use Phalcon\Support\Helper\Arr\FirstKey;
use UnitTester;

/**
 * Class FirstKeyCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class FirstKeyCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: firstKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFirstKey(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - firstKey()');

        $object     = new FirstKey();
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 1;
        $actual   = $object($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: firstKey() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFirstKeyFunction(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - firstKey() - function');

        $object     = new FirstKey();
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 3;
        $actual   = $object(
            $collection,
            function ($element) {
                return strlen($element) > 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
