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

namespace Phalcon\Tests\Unit\Encryption\Security\Random;

use Codeception\Example;
use Phalcon\Encryption\Security\Random;
use UnitTester;

/**
 * Class Base64SafeCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\Random
 */
class Base64SafeCest
{
    /**
     * Tests Phalcon\Encryption\Security\Random :: base64Safe()
     *
     * @param UnitTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
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

    /**
     * @return array[]
     */
    private function securityRandomBase64SafeProvider(): array
    {
        return [
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
