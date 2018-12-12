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
 * Class Base64Cest
 *
 * @package Phalcon\Test\Unit\Security\Random
 */
class Base64Cest
{
    /**
     * Tests Phalcon\Security\Random :: base64()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase64(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base64()");
        $examples = [null, 2, 12, 16, 24, 48, 100];

        foreach ($examples as $len) {
            $random = new Random();

            $isValid = function ($base64) {
                return (preg_match("#[^a-z0-9+_=/-]+#i", $base64) === 0);
            };

            $base64 = $random->base64($len);

            $expected = ($len === null) ? 16 : $len;
            $actual   = strlen($base64);
            $I->assertTrue($this->checkSize($base64, $expected));
            $I->assertTrue($isValid($actual));
        }
    }
}
