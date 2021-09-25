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

namespace Phalcon\Tests\Unit\Security\Random;

use Phalcon\Security\Random;
use UnitTester;

class HexCest
{
    /**
     * Tests Phalcon\Security\Random :: hex()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityRandomHex(UnitTester $I)
    {
        $I->wantToTest("Security\Random - hex()");

        $random = new Random();


        $hex = $random->hex();

        // Test forbidden characters
        $I->assertRegExp(
            '/^[0-9a-f]+$/',
            $hex
        );

        // Default length is 16 bytes
        $I->assertEquals(
            16,
            strlen($hex) / 2
        ); // Hex is 2 characters


        $differentString = $random->hex();

        // Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($hex, $differentString);


        $expectedLength = 30;
        $hex            = $random->hex($expectedLength);

        $I->assertEquals(
            $expectedLength,
            strlen($hex) / 2
        ); // Hex is 2 characters
    }
}
