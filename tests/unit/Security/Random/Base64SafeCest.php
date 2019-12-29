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

use Codeception\Example;
use Phalcon\Security\Random;
use UnitTester;

class Base64SafeCest
{
    /**
     * Tests Phalcon\Security\Random :: base64Safe()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider securityRandomBase64SafeProvider
     */
    public function securityRandomBase64Safe(UnitTester $I, Example $example)
    {
        $I->wantToTest("Security\Random - base64Safe()");

        $len     = $example[0];
        $padding = $example[1];
        $pattern = $example[2];

        $random = new Random();

        $I->assertRegExp(
            '#^[' . $pattern . ']+$#i',
            $random->base64Safe($len, $padding)
        );
    }

    private function securityRandomBase64SafeProvider(): array
    {
        return [
            [
                null,
                false,
                'a-z0-9_-',
            ],

            [
                null,
                true,
                'a-z0-9_=-',
            ],

            [
                2,
                false,
                'a-z0-9_-',
            ],

            [
                2,
                true,
                'a-z0-9_=-',
            ],

            [
                12,
                false,
                'a-z0-9_-',
            ],

            [
                12,
                true,
                'a-z0-9_=-',
            ],

            [
                16,
                false,
                'a-z0-9_-',
            ],

            [
                16,
                true,
                'a-z0-9_=-',
            ],

            [
                24,
                false,
                'a-z0-9_-',
            ],

            [
                24,
                true,
                'a-z0-9_=-',
            ],

            [
                48,
                false,
                'a-z0-9_-',
            ],

            [
                48,
                true,
                'a-z0-9_=-',
            ],

            [
                100,
                false,
                'a-z0-9_-',
            ],

            [
                100,
                true,
                'a-z0-9_=-',
            ],
        ];
    }
}
