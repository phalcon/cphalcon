<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Token\Signature;

use Phalcon\Security\JWT\Token\Signature;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Signature :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTTokenSignatureConstruct(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Token\Signature - __construct()');

        $signature = new Signature('sig-hash', 'encoded-string-here');

        $I->assertInstanceOf(Signature::class, $signature);
    }
}
