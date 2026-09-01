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

final class ValidateIssuedAtTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateIssuedAt(): void
    {
        $token     = $this->newToken();
        $timestamp = strtotime(("-1 day"));
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $validator->validateIssuedAt($timestamp);

        $expected = ["Validation: the token cannot be used yet (future)"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that a token issued at exactly the passed timestamp is valid. Only
     * a token issued in the future is rejected.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTValidatorValidateIssuedAtSameSecond(): void
    {
        $token     = $this->newToken();
        $timestamp = $token->getClaims()->get(Enum::ISSUED_AT);
        $validator = new Validator($token);

        $validator->validateIssuedAt($timestamp);

        $expected = [];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
