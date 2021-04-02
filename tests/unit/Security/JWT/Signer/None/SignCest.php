<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Signer\None;

use Phalcon\Security\JWT\Signer\None;
use UnitTester;

class SignCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\None :: sign()
     *
     * @since  2019-12-22
     */
    public function securityJWTSignerNoneSign(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\None - sign()');

        $signer = new None();

        $payload    = 'test payload';
        $passphrase = '12345';

        $actual = $signer->sign($payload, $passphrase);
        $I->assertEmpty($actual);
    }
}
