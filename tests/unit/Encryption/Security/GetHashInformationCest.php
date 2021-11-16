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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Codeception\Example;
use Phalcon\Encryption\Security;
use UnitTester;

use const PASSWORD_ARGON2_DEFAULT_MEMORY_COST;
use const PASSWORD_ARGON2_DEFAULT_THREADS;
use const PASSWORD_ARGON2_DEFAULT_TIME_COST;

class GetHashInformationCest
{
    /**
     * Tests Phalcon\Security :: getHashInformation()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function securityGetHashInformation(UnitTester $I, Example $example)
    {
        $I->wantToTest('Security - getHashInformation() ' . $example[0]);

        $security = new Security();
        $password = 'PhalconROCKS!';

        $security->setDefaultHash($example[1]);

        $hash     = $security->hash($password);
        $expected = $example[2];
        $actual   = $security->getHashInformation($hash);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Security :: checkHash() - false
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityCheckHashFalse(UnitTester $I)
    {
        $I->wantToTest('Security - checkHash() - false');

        $security = new Security();
        $password = 'PhalconROCKS!';

        $actual = $security->checkHash($password, $password, 2);
        $I->assertFalse($actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                "CRYPT_ARGON2I",
                Security::CRYPT_ARGON2I,
                [
                    "algo"     => "argon2i",
                    "algoName" => "argon2i",
                    "options"  => [
                        "memory_cost" => PASSWORD_ARGON2_DEFAULT_MEMORY_COST,
                        "time_cost"   => PASSWORD_ARGON2_DEFAULT_TIME_COST,
                        "threads"     => PASSWORD_ARGON2_DEFAULT_THREADS,
                    ],
                ],
            ],
            [
                "CRYPT_ARGON2ID",
                Security::CRYPT_ARGON2ID,
                [
                    "algo"     => "argon2id",
                    "algoName" => "argon2id",
                    "options"  => [
                        "memory_cost" => PASSWORD_ARGON2_DEFAULT_MEMORY_COST,
                        "time_cost"   => PASSWORD_ARGON2_DEFAULT_TIME_COST,
                        "threads"     => PASSWORD_ARGON2_DEFAULT_THREADS,
                    ],
                ],
            ],
            [
                "CRYPT_BCRYPT",
                Security::CRYPT_BCRYPT,
                [
                    "algo"     => "2y",
                    "algoName" => "bcrypt",
                    "options"  => [
                        "cost" => 10,
                    ],
                ],
            ],
            [
                "CRYPT_DEFAULT",
                Security::CRYPT_DEFAULT,
                [
                    "algo"     => "2y",
                    "algoName" => "bcrypt",
                    "options"  => [
                        "cost" => 10,
                    ],
                ],
            ],
            [
                "CRYPT_BLOWFISH",
                Security::CRYPT_BLOWFISH,
                [
                    "algo"     => "2y",
                    "algoName" => "bcrypt",
                    "options"  => [
                        "cost" => 10,
                    ],
                ],
            ],
            [
                "CRYPT_BLOWFISH_A",
                Security::CRYPT_BLOWFISH_A,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                "CRYPT_BLOWFISH_X",
                Security::CRYPT_BLOWFISH_X,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                "CRYPT_BLOWFISH_Y",
                Security::CRYPT_BLOWFISH_Y,
                [
                    "algo"     => "2y",
                    "algoName" => "bcrypt",
                    "options"  => [
                        "cost" => 10,
                    ],
                ],
            ],
            [
                "CRYPT_MD5",
                Security::CRYPT_MD5,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                "CRYPT_SHA256",
                Security::CRYPT_SHA256,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                "CRYPT_SHA512",
                Security::CRYPT_SHA512,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
        ];
    }
}
