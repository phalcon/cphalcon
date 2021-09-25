<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Validator;

use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use Phalcon\Security\JWT\Validator;
use Phalcon\Tests\Fixtures\Traits\JWTTrait;
use UnitTester;

class SetTokenCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Security\JWT\Validator :: setToken()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTValidatorSetToken(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Validator - setToken()');

        $token1 = $this->newToken();
        $token2 = $this->newToken(Hmac::class, 5);
        $now = strtotime("+1 second");
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
