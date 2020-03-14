<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Token\Signature;

use Phalcon\Security\JWT\Token\Signature;
use UnitTester;

class UnderscoreCallCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Signature :: __call()
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenSignatureUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Signature - __call()');

        $signature = new Signature('sig-hash', 'encoded-string-here');

        $I->assertEquals('encoded-string-here', $signature->getEncoded());
        $I->assertEquals('sig-hash', $signature->getHash());
    }
}
