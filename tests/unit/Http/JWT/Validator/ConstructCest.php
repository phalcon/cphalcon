<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Validator;

use Phalcon\Http\JWT\Validator;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ConstructCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Http\JWT\Validator :: __construct()
     *
     * @since  2019-12-22
     */
    public function httpJWTValidatorConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - __construct()');

        $token     = $this->newToken();
        $now       = strtotime("now");
        $validator = new Validator($token);
        $I->assertInstanceOf(Validator::class, $validator);
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateAudience("my-audience")
        );
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateExpiration($now)
        );
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateId("PH-JWT")
        );
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateNotBefore($now)
        );
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateIssuedAt($now + 100)
        );
        $I->assertInstanceOf(
            Validator::class,
            $validator->validateIssuer("Phalcon JWT")
        );
    }
}
