<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Token\Token;

use Phalcon\Security\JWT\Token\Item;
use Phalcon\Security\JWT\Token\Signature;
use Phalcon\Security\JWT\Token\Token;
use UnitTester;

class GetHeadersCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Token :: getHeaders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTTokenTokenGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Token\Token - getHeaders()');

        $headers   = new Item(["typ" => "JWT"], "header-encoded");
        $claims    = new Item(["aud" => ["valid-audience"]], "claim-encoded");
        $signature = new Signature("signature-hash", "signature-encoded");

        $token = new Token($headers, $claims, $signature);

        $I->assertInstanceOf(Item::class, $token->getHeaders());
        $I->assertEquals("JWT", $token->getHeaders()->get('typ'));
    }
}
