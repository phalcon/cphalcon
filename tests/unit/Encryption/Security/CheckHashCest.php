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

/**
 * Class CheckHashCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security
 */
class CheckHashCest
{
    /**
     * Tests Phalcon\Security :: checkHash()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function securityCheckHash(UnitTester $I, Example $example)
    {
        $I->wantToTest('Security - checkHash() ' . $example[0]);

        $security = new Security();
        $password = 'PhalconROCKS!';

        $security->setDefaultHash($example[1]);

        $actual = $security->checkHash($password, $security->hash($password));
        $I->assertTrue($actual);
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
            ["CRYPT_ARGON2I", Security::CRYPT_ARGON2I],
            ["CRYPT_ARGON2ID", Security::CRYPT_ARGON2ID],
            ["CRYPT_BCRYPT", Security::CRYPT_BCRYPT],
            ["CRYPT_DEFAULT", Security::CRYPT_DEFAULT],
            ["CRYPT_BLOWFISH", Security::CRYPT_BLOWFISH],
            ["CRYPT_BLOWFISH_A", Security::CRYPT_BLOWFISH_A],
            ["CRYPT_BLOWFISH_X", Security::CRYPT_BLOWFISH_X],
            ["CRYPT_BLOWFISH_Y", Security::CRYPT_BLOWFISH_Y],
            ["CRYPT_MD5", Security::CRYPT_MD5],
            ["CRYPT_SHA256", Security::CRYPT_SHA256],
            ["CRYPT_SHA512", Security::CRYPT_SHA512],
        ];
    }
}
