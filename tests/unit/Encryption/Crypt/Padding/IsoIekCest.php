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

namespace Phalcon\Tests\Unit\Encryption\Crypt\Padding;

use Phalcon\Encryption\Crypt\Padding\IsoIek;
use UnitTester;

use function chr;
use function str_repeat;

/**
 * Class IsoIekCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class IsoIekCest
{
    /**
     * Tests Phalcon\Encryption\Crypt\Padding\IsoIek :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function cryptPaddingIsoIek(UnitTester $I)
    {
        $I->wantToTest('Crypt\Padding\IsoIek - pad()/unpad()');

        $object = new IsoIek();

        $paddingSize = 16;
        $padding     = chr(0x80) . str_repeat(chr(0), $paddingSize - 1);
        $expected    = $padding;
        $actual      = $object->pad(16);
        $I->assertEquals($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $actual;
        $expected = 16;
        $actual   = $object->unpad($source, 16);
        $I->assertEquals($expected, $actual);

        $paddingSize = 16;
        $padding     = chr(0x80) . str_repeat(chr(0), $paddingSize + 1);
        $source      = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected    = 0;
        $actual      = $object->unpad($source, 16);
        $I->assertEquals($expected, $actual);
    }
}
