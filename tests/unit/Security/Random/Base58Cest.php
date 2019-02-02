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
 * Class Base58Cest
 */
class Base58Cest
{
    /**
     * Tests Phalcon\Security\Random :: base58()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase58(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base58()");
        $random = new \Phalcon\Security\Random;
        $base58 = $random->base58();

        //test forbidden characters
        $I->assertRegExp("/^[1-9A-Za-z][^OIl0]+$/", $base58);

        //Default length is 16 bytes
        $I->assertEquals(16, strlen($base58));

        $differentString = $random->base58();
        //Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($base58, $differentString);

        $expectedLength = 30;
        $base58         = $random->base58($expectedLength);
        $I->assertEquals($expectedLength, strlen($base58));
    }
}
