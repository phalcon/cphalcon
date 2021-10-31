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
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Tests\Fixtures\Traits\JWTTrait;
use UnitTester;

/**
 * Class SetTokenCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Validator
 */
class SetTokenCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Validator :: setToken()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTValidatorSetToken(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - setToken()');

        $token1    = $this->newToken();
        $token2    = $this->newToken(Hmac::class, 5);
        $now       = strtotime("+1 second");
        $validator = new Validator($token1);
        $I->assertInstanceOf(Validator::class, $validator);
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateIssuedAt($now)
        );

        $validator->setToken($token2);
        $I->expectThrowable(
            new ValidatorException(
                "Validation: the token cannot be used yet (future)"
            ),
            function () use ($validator, $now, $I) {
                $I->assertInstanceOf(
                    Validator::class,
                    $validator->validateIssuedAt($now)
                );
            }
        );
    }
}
