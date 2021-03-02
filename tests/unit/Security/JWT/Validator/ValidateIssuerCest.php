<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Validator;

use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Validator;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ValidateIssuerCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Security\JWT\Validator :: validateIssuer()
     *
     * @since  2019-12-22
     */
    public function securityJWTValidatorValidateIssuer(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Validator - validateIssuer()');

        $token = $this->newToken();
        $I->expectThrowable(
            new ValidatorException(
                "Validation: incorrect issuer"
            ),
            function () use ($token, $I) {
                $validator = new Validator($token);
                $I->assertInstanceOf(Validator::class, $validator);
                $validator->validateIssuer("unknown");
            }
        );
    }
}
