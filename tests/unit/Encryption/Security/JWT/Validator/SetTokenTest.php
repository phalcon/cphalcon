<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class SetTokenTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorSetToken(): void
    {
        $token1    = $this->newToken();
        $token2    = $this->newToken(Hmac::class, 5);
        $now       = strtotime("+1 second");
        $validator = new Validator($token1);
        $this->assertInstanceOf(Validator::class, $validator);
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateIssuedAt($now)
        );

        $validator->setToken($token2);
        $validator->validateIssuedAt($now);

        $expected = ["Validation: the token cannot be used yet (future)"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
