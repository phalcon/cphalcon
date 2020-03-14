<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Validator;

use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Validator;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ValidateExpirationCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Security\JWT\Validator :: validateExpiration()
     *
     * @since  2019-12-22
     */
    public function httpJWTValidatorValidateExpiration(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - validateExpiration()');

        $token = $this->newToken();
        $I->expectThrowable(
            new ValidatorException(
                "Validation: the token has expired"
            ),
            function () use ($token, $I) {
                $timestamp = strtotime(("+2 days"));
                $validator = new Validator($token);
                $I->assertInstanceOf(Validator::class, $validator);
                $validator->validateExpiration($timestamp);
            }
        );
    }
}
