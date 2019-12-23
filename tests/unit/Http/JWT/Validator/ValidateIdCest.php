<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Validator;

use Phalcon\Http\JWT\Exceptions\ValidatorException;
use Phalcon\Http\JWT\Validator;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ValidateIdCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Http\JWT\Validator :: validateId()
     *
     * @since  2019-12-22
     */
    public function httpJWTValidatorValidateId(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - validateId()');

        $token = $this->newToken();
        $I->expectThrowable(
            new ValidatorException(
                "Validation: incorrect Id"
            ),
            function () use ($token, $I) {
                $validator = new Validator($token);
                $I->assertInstanceOf(Validator::class, $validator);
                $validator->validateId("unknown");
            }
        );
    }
}
