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

namespace Phalcon\Tests\Unit\Crypt\Padding;

use Phalcon\Crypt\Padding\Pkcs7;
use UnitTester;

use function chr;
use function str_repeat;

/**
 * Class Pkcs7Cest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class Pkcs7Cest
{
    /**
     * Tests Phalcon\Crypt\Padding\Pkcs7 :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function cryptPaddingPkcs7(UnitTester $I)
    {
        $I->wantToTest('Crypt\Padding\Pkcs7 - pad()/unpad()');

        $object = new Pkcs7();

        $paddingSize = 32;
        $padding     = str_repeat(chr($paddingSize), $paddingSize);
        $expected    = $padding;
        $actual      = $object->pad($paddingSize);
        $I->assertEquals($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 32;
        $actual   = $object->unpad($source, 32);
        $I->assertEquals($expected, $actual);

        /**
         * Invalid padding results in 0
         */
        $padding  = str_repeat(chr($paddingSize), $paddingSize - 1);
        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 0;
        $actual   = $object->unpad($source, 32);
        $I->assertEquals($expected, $actual);
    }
}
