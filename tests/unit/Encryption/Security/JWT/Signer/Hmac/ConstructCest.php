<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac;

use Phalcon\Encryption\Security\JWT\Exceptions\UnsupportedAlgorithmException;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac
 */
class ConstructCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\Hmac :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerHmacConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\Hmac - __construct()');

        $signer = new Hmac();
        $I->assertInstanceOf(Hmac::class, $signer);
    }

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\Hmac :: __construct() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerHmacConstructException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\Hmac - __construct() - exception');

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
