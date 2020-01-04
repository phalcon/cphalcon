<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Signer\Hmac;

use Phalcon\Http\JWT\Signer\Hmac;
use UnitTester;

use function hash_hmac;

class SignCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Signer\Hmac :: sign()
     *
     * @since  2019-12-15
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
