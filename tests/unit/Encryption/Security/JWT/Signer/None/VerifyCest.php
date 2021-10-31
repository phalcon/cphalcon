<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\None;

use Phalcon\Encryption\Security\JWT\Signer\None;
use UnitTester;

/**
 * Class VerifyCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\None
 */
class VerifyCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\None :: verify()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerNoneVerify(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\None - verify()');

        $signer = new None();

        $payload    = 'test payload';
        $passphrase = '12345';

        $actual = $signer->verify('', $payload, $passphrase);
        $I->assertTrue($actual);
    }
}
