<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use DateTimeImmutable;
use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;
use Phalcon\Time\Clock\FrozenClock;

final class ConstructTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorConstruct(): void
    {
        $token     = $this->newToken();
        $now       = strtotime("now");
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateAudience("my-audience")
        );
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateExpiration($now)
        );
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateId("PH-JWT")
        );
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateNotBefore($now)
        );
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateIssuedAt($now + 100)
        );
        $this->assertInstanceOf(
            Validator::class,
            $validator->validateIssuer("Phalcon JWT")
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-14
     */
    public function testEncryptionSecurityJWTValidatorConstructWithClock(): void
    {
        $token     = $this->newToken();
        $clock     = new FrozenClock(new DateTimeImmutable('@1700000000'));
        $validator = new Validator($token, 0, $clock);

        $this->assertSame(1700000000, $validator->get(Enum::EXPIRATION_TIME));
        $this->assertSame(1700000000, $validator->get(Enum::ISSUED_AT));
        $this->assertSame(1700000000, $validator->get(Enum::NOT_BEFORE));
    }
}
