<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Token\Signature;

use Phalcon\Http\JWT\Token\Signature;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Token\Signature :: __construct()
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenSignatureConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Signature - __construct()');

        $signature = new Signature('sig-hash', 'encoded-string-here');

        $I->assertInstanceOf(Signature::class, $signature);
    }
}
