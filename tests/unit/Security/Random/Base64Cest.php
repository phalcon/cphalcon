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
use function is_string;

class Base64Cest
{
    /**
     * Tests Phalcon\Security\Random :: base64()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider securityRandomBase64Provider
     */
    public function securityRandomBase64(UnitTester $I, Example $example)
    {
        $I->wantToTest("Security\Random - base64()");

        $len = $example[0];

        $random = new Random();

        $base64 = $random->base64($len);

        $I->assertTrue(is_string($base64));

        $expected = ($len === null) ? 16 : $len;

        $I->assertTrue(
            $this->checkSize($base64, $expected)
        );

        $I->assertRegExp(
            '#^[a-z0-9+_=/-]+$#i',
            $base64
        );
    }

    /**
     * Size formula: 4 * ($n / 3) and this need to be rounded up to a multiple
     * of 4.
     */
    protected function checkSize(string $string, int $n): bool
    {
        if (round(4 * ($n / 3)) % 4 === 0) {
            $len = round(4 * ($n / 3));
        } else {
            $len = round((4 * ($n / 3) + 4 / 2) / 4) * 4;
        }

        return strlen($string) == $len;
    }

    private function securityRandomBase64Provider(): array
    {
        return [
            [null],
            [2],
            [12],
            [16],
            [24],
            [48],
            [100],
        ];
    }
}
