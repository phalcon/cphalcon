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
 * Class GetPayloadCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Token
 */
class GetPayloadCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: getPayload()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTTokenTokenGetPayload(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Token - getPayload()');

        $headers   = new Item(["typ" => "JWT"], "header-encoded");
        $claims    = new Item(["aud" => ["valid-audience"]], "claim-encoded");
        $signature = new Signature("signature-hash", "signature-encoded");

        $token = new Token($headers, $claims, $signature);

        $I->assertEquals("header-encoded.claim-encoded", $token->getPayload());
    }
}
