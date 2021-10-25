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

use Phalcon\Support\Helper\Arr\LastKey;
use UnitTester;

use function strlen;

/**
 * Class LastKeyCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class LastKeyCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: lastKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrLastKey(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - lastKey()');

        $object     = new LastKey();
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 3;
        $actual   = $object($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: lastKey() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrLastKeyFunction(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - lastKey() - function');

        $object     = new LastKey();
        $collection = [
            1 => 'Phalcon',
            3 => 'Framework',
        ];

        $expected = 1;
        $actual   = $object(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
