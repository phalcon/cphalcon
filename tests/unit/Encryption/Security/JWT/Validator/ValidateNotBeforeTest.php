<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateNotBeforeTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateNotBefore(): void
    {
        $token     = $this->newToken();
        $timestamp = strtotime(("-2 days"));
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $validator->validateNotBefore($timestamp);

        $expected = ["Validation: the token cannot be used yet (not before)"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that a token is valid at exactly the "nbf" claim. Only a timestamp
     * before it is rejected.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTValidatorValidateNotBeforeSameSecond(): void
    {
        $token     = $this->newToken();
        $timestamp = $token->getClaims()->get(Enum::NOT_BEFORE);
        $validator = new Validator($token);

        $validator->validateNotBefore($timestamp);

        $expected = [];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
