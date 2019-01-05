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

namespace Phalcon\Test\Unit\Security\Random;

use UnitTester;

/**
 * Class HexCest
 */
class HexCest
{
    /**
     * Tests Phalcon\Security\Random :: hex()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomHex(UnitTester $I)
    {
        $I->wantToTest("Security\Random - hex()");
        $random = new \Phalcon\Security\Random;
        $hex    = $random->hex();

        //test forbidden characters
        $I->assertRegExp("/^[0-9a-f]+$/", $hex);

        //Default length is 16 bytes
        $I->assertEquals(16, strlen($hex) / 2); //Hex is 2 characters

        $differentString = $random->hex();
        //Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($hex, $differentString);

        $expectedLength = 30;
        $hex            = $random->hex($expectedLength);
        $I->assertEquals($expectedLength, strlen($hex) / 2); //Hex is 2 characters
    }
}
