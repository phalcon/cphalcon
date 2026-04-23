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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateClaimTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-10-10
     */
    public function testEncryptionSecurityJWTValidatorValidateClaim(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $validator->validateClaim('uid', 123);

        $expected = ["Validation: incorrect uid"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);

        $validator->validateClaim('sid', 'incorrect');

        $expected = [
            "Validation: incorrect uid",
            "Validation: incorrect sid",
        ];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);

        $validator->validateClaim('bid', false);

        $expected = [
            "Validation: incorrect uid",
            "Validation: incorrect sid",
            "Validation: incorrect bid"
        ];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);

        $validator = new Validator($token);
        $validator->validateClaim('uid', 456);
        $validator->validateClaim('sid', 'string');
        $validator->validateClaim('bid', true);

        $expected = [];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
