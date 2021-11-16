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
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Signature
 */
class ConstructCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Signature :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTTokenSignatureConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Signature - __construct()');

        $signature = new Signature('sig-hash', 'encoded-string-here');

        $I->assertInstanceOf(Signature::class, $signature);
    }
}
