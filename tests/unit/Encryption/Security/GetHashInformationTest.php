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

use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

use const PASSWORD_ARGON2_DEFAULT_MEMORY_COST;
use const PASSWORD_ARGON2_DEFAULT_THREADS;
use const PASSWORD_ARGON2_DEFAULT_TIME_COST;

final class GetHashInformationTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
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
                Security::CRYPT_BLOWFISH_A,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                Security::CRYPT_BLOWFISH_X,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
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
                Security::CRYPT_MD5,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                Security::CRYPT_SHA256,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
            [
                Security::CRYPT_SHA512,
                [
                    "algo"     => null,
                    "algoName" => "unknown",
                    "options"  => [],
                ],
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityCheckHashFalse(): void
    {
        $security = new Security();
        $password = 'PhalconROCKS!';

        $actual = $security->checkHash($password, $password, 2);
        $this->assertFalse($actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityGetHashInformation(
        int $hash,
        array $expected
    ): void {
        $security = new Security();
        $password = 'PhalconROCKS!';

        $security->setDefaultHash($hash);

        $hash   = $security->hash($password);
        $actual = $security->getHashInformation($hash);
        $this->assertSame($expected, $actual);
    }
}
