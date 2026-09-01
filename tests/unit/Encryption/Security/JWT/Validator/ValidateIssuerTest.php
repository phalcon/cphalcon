<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateIssuerTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateIssuer(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $validator->validateIssuer("unknown");

        $expected = ["Validation: incorrect issuer"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that a null issuer expresses no expectation and is skipped.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTValidatorValidateIssuerNull(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);

        $validator->validateIssuer(null);

        $expected = [];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
