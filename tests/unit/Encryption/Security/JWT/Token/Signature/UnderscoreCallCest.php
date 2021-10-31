<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Signature;

use Phalcon\Encryption\Security\JWT\Token\Signature;
use UnitTester;

/**
 * Class UnderscoreCallCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Signature
 */
class UnderscoreCallCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Signature :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTTokenSignatureUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Signature - __call()');

        $signature = new Signature('sig-hash', 'encoded-string-here');

        $I->assertEquals('encoded-string-here', $signature->getEncoded());
        $I->assertEquals('sig-hash', $signature->getHash());
    }
}
