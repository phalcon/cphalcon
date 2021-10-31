<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Tests\Fixtures\Traits\JWTTrait;
use UnitTester;

/**
 * Class ValidateIssuerCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Validator
 */
class ValidateIssuerCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Validator :: validateIssuer()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTValidatorValidateIssuer(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - validateIssuer()');

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
