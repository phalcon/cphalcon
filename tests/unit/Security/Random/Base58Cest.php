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

class Base58Cest
{
    /**
     * Tests Phalcon\Security\Random :: base58()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityRandomBase58(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base58()");

        $random = new Random();


        $base58 = $random->base58();

        // Test forbidden characters
        $I->assertRegExp(
            '/^[1-9A-Za-z][^OIl0]+$/',
            $base58
        );

        // Default length is 16 bytes
        $I->assertEquals(
            16,
            strlen($base58)
        );


        $differentString = $random->base58();

        // Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($base58, $differentString);


        $expectedLength = 30;
        $base58         = $random->base58($expectedLength);

        $I->assertEquals(
            $expectedLength,
            strlen($base58)
        );
    }
}
