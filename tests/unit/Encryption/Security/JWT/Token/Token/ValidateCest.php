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
use Phalcon\Encryption\Security\JWT\Validator;
use UnitTester;

class ValidateCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: getToken()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-23
     */
    public function encryptionSecurityJWTTokenTokenValidate(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Token\Token - validate()');

        $headers   = new Item(["typ" => "JWT"], "header-encoded");
        $claims    = new Item(["aud" => ["valid-audience"]], "claim-encoded");
        $signature = new Signature("signature-hash", "signature-encoded");

        $token = new Token($headers, $claims, $signature);
        $validator = new Validator($token);

        $errors = $token->validate($validator);
        $I->assertCount(4, $errors);

        $expected = [
            "Validation: incorrect Id",
            "Validation: the token cannot be used yet (future)",
            "Validation: incorrect issuer",
            "Validation: the token cannot be used yet (not before)"
        ];
        $actual = $errors;
        $I->assertSame($expected, $actual);
    }
}
