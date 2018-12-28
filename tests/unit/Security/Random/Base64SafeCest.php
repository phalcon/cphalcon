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
 * Class Base64SafeCest
 */
class Base64SafeCest
{
    /**
     * Tests Phalcon\Security\Random :: base64Safe()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase64Safe(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base64Safe()");
        $examples = [
            [null, false, 'a-z0-9_-'],
            [null, true, 'a-z0-9_=-'],
            [2, false, 'a-z0-9_-'],
            [2, true, 'a-z0-9_=-'],
            [12, false, 'a-z0-9_-'],
            [12, true, 'a-z0-9_=-'],
            [16, false, 'a-z0-9_-'],
            [16, true, 'a-z0-9_=-'],
            [24, false, 'a-z0-9_-'],
            [24, true, 'a-z0-9_=-'],
            [48, false, 'a-z0-9_-'],
            [48, true, 'a-z0-9_=-'],
            [100, false, 'a-z0-9_-'],
            [100, true, 'a-z0-9_=-'],
        ];

        foreach ($examples as $example) {
            $len     = $example[0];
            $padding = $example[1];
            $pattern = $example[2];

            $random = new \Phalcon\Security\Random();

            $isValid = function ($base64) use ($pattern) {
                return (preg_match("#[^$pattern]+#i", $base64) === 0);
            };

            $actual = $random->base64Safe($len, $padding);
            $I->assertTrue($isValid($actual));
        }
    }
}
