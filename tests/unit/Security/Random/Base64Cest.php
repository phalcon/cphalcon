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
            $random = new \Phalcon\Security\Random();

            $isValid = function ($base64) {
                return (preg_match("#[^a-z0-9+_=/-]+#i", $base64) === 0);
            };

            $base64 = $random->base64($len);
            $I->assertTrue(is_string($base64));

            $expected = ($len === null) ? 16 : $len;
            $actual   = strlen($base64);
            $I->assertTrue($this->checkSize($base64, $expected));
            $I->assertTrue($isValid($base64));
        }
    }

    /**
     * Size formula: 4 * ($n / 3) and this need to be rounded up to a multiple
     * of 4.
     *
     * @param string $string
     * @param int    $n
     *
     * @return bool
     */
    protected function checkSize($string, $n)
    {
        if (round(4 * ($n / 3)) % 4 === 0) {
            $len = round(4 * ($n / 3));
        } else {
            $len = round((4 * ($n / 3) + 4 / 2) / 4) * 4;
        }

        return strlen($string) == $len;
    }
}
