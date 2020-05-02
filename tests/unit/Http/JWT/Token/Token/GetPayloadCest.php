<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Token\Token;

use Phalcon\Security\JWT\Token\Item;
use Phalcon\Security\JWT\Token\Signature;
use Phalcon\Security\JWT\Token\Token;
use UnitTester;

class GetPayloadCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Token :: getPayload()
     *
     * @since  2019-12-22
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
