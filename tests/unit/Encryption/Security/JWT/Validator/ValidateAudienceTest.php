<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Token\Item;
use Phalcon\Encryption\Security\JWT\Token\Signature;
use Phalcon\Encryption\Security\JWT\Token\Token;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateAudienceTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateAudience(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);

        $validator->validateAudience('unknown');

        $expected = ["Validation: audience not allowed"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }

    /**
     * The audience claim is compared strictly: a numeric or boolean claim
     * value does not satisfy a string audience.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testEncryptionSecurityJWTValidatorValidateAudienceStrictTypes(): void
    {
        $token = new Token(
            new Item(['typ' => 'JWT', 'alg' => 'none'], ''),
            new Item(['aud' => [123, true]], ''),
            new Signature()
        );
        $validator = new Validator($token);

        $validator->validateAudience('123');
        $validator->validateAudience('abc');

        $expected = [
            "Validation: audience not allowed",
            "Validation: audience not allowed",
        ];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
