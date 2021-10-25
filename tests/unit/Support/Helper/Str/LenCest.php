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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Len;
use UnitTester;

/**
 * Class LenCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class LenCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: len()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrLen(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - len()');

        $object = new Len();
        $actual = $object('hello');
        $I->assertEquals(5, $actual);

        $actual = $object('1234');
        $I->assertEquals(4, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: len() - multi-bytes encoding
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrLenMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - len() - multi byte encoding');

        $object = new Len();
        $actual = $object('привет мир!');
        $I->assertEquals(11, $actual);

        $actual = $object('männer');
        $I->assertEquals(6, $actual);
    }
}
