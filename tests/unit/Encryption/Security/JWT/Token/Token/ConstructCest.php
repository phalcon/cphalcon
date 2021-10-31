<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Token;

use Phalcon\Encryption\Security\JWT\Token\Item;
use Phalcon\Encryption\Security\JWT\Token\Signature;
use Phalcon\Encryption\Security\JWT\Token\Token;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Token
 */
class ConstructCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTTokenTokenConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Token - __construct()');

        $headers   = new Item(["typ" => "JWT"], "header-encoded");
        $claims    = new Item(["sub" => "subject"], "claim-encoded");
        $signature = new Signature("signature-hash", "signature-encoded");

        $token = new Token($headers, $claims, $signature);

        $I->assertInstanceOf(Token::class, $token);
    }
}
