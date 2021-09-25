<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Signer\Hmac;

use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

use function hash_hmac;

class VerifyCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\Hmac :: verify()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTSignerHmacVerify(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\Hmac - verify()');

        $signer = new Hmac();

        $payload    = 'test payload';
        $passphrase = '12345';

        $hash   = hash_hmac('sha512', $payload, $passphrase, true);
        $actual = $signer->verify($hash, $payload, $passphrase);
        $I->assertTrue($actual);
    }
}
