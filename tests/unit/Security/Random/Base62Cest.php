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

namespace Phalcon\Test\Unit\Security\Random;

use Phalcon\Security\Random;
use UnitTester;

class Base62Cest
{
    /**
     * Tests Phalcon\Security\Random :: base62()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityRandomBase62(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base62()");

        $random = new Random();


        $base62 = $random->base62();

        // Test forbidden characters
        $I->assertRegExp(
            '/^[0-9A-Za-z]+$/',
            $base62
        );

        // Default length is 16 bytes
        $I->assertEquals(
            16,
            strlen($base62)
        );


        $differentString = $random->base62();

        // Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($base62, $differentString);


        $expectedLength = 30;
        $base62         = $random->base62($expectedLength);

        $I->assertEquals(
            $expectedLength,
            strlen($base62)
        );
    }
}
