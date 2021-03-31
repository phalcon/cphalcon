<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Signer\Hmac;

use Phalcon\Security\JWT\Exceptions\UnsupportedAlgorithmException;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\Hmac :: __construct()
     *
     * @since  2019-12-15
     */
    public function securityJWTSignerHmacConstruct(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\Hmac - __construct()');

        $signer = new Hmac();
        $I->assertInstanceOf(Hmac::class, $signer);
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Signer\Hmac :: __construct() - exception
     *
     * @since  2019-12-15
     */
    public function securityJWTSignerHmacConstructException(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\Hmac - __construct() - exception');

        $I->expectThrowable(
            new UnsupportedAlgorithmException(
                'Unsupported HMAC algorithm'
            ),
            function () {
                $signer = new Hmac('unknown');
            }
        );
    }
}
