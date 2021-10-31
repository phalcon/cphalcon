<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac;

use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use UnitTester;

use function hash_hmac;

/**
 * Class SignCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac
 */
class SignCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\Hmac :: sign()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerHmacSign(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\Hmac - sign()');

        $signer = new Hmac();

        $payload    = 'test payload';
        $passphrase = '12345';

        $expected = hash_hmac('sha512', $payload, $passphrase, true);
        $actual   = $signer->sign($payload, $passphrase);
        $I->assertEquals($expected, $actual);
    }
}
