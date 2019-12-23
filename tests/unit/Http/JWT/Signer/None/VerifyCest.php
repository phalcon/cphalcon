<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Signer\None;

use Phalcon\Http\JWT\Signer\None;
use UnitTester;

class VerifyCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Signer\None :: verify()
     *
     * @since  2019-12-22
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
