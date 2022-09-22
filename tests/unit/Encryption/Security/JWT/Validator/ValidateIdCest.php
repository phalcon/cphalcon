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
 * Class ValidateIdCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Validator
 */
class ValidateIdCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Validator :: validateId()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityJWTValidatorValidateId(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Validator - validateId()');

        $token = $this->newToken();
        $validator = new Validator($token);
        $I->assertInstanceOf(Validator::class, $validator);

        $validator->validateId("unknown");

        $expected = ["Validation: incorrect Id"];
        $actual   = $validator->getErrors();
        $I->assertSame($expected, $actual);
    }
}
