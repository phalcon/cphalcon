<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Token;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-23
     */
    public function testEncryptionSecurityJWTTokenTokenValidate(): void
    {
        $signer     = new Hmac();
        $builder    = new Builder($signer);
        $now        = time();
        $expiry     = $now + 3600;
        $issued     = $now - 10;
        $notBefore  = $now - 10;
        $passphrase = '&vsJBETaizP3A3VX&TPMJUqi48fJEgN7';

        $token = $builder
            ->setAudience('my-audience')
            ->setExpirationTime($expiry)
            ->setIssuer('Phalcon JWT')
            ->setIssuedAt($issued)
            ->setId('PH-JWT')
            ->setNotBefore($notBefore)
            ->setSubject('Mary had a little lamb')
            ->setPassphrase($passphrase)
            ->getToken()
        ;

        $validator = new Validator($token, 10);

        $validator
            ->set(Enum::AUDIENCE, 'my-audience')
            ->set(Enum::EXPIRATION_TIME, $now)
            ->set(Enum::ISSUER, 'Phalcon JWT')
            ->set(Enum::ISSUED_AT, $issued)
            ->set(Enum::ID, 'PH-JWT')
            ->set(Enum::NOT_BEFORE, $notBefore)
            ->set(Enum::SUBJECT, 'Mary had a little lamb')
        ;

        $errors = $token->validate($validator);
        $this->assertCount(0, $errors);
    }

    /**
     * Tests that a freshly constructed Validator can be passed to validate()
     * without throwing. The audience, id, issuer and subject claims are seeded
     * as null, which expresses no expectation, and must be skipped instead of
     * being forwarded to the validate*() methods.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTTokenTokenValidateDefaultValidator(): void
    {
        $token = $this->newToken();

        $errors = $token->validate(new Validator($token));

        $this->assertSame([], $errors);
    }

    /**
     * Tests that the subject claim is validated by validate(). It is seeded by
     * the Validator constructor but was never consumed.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTTokenTokenValidateIncorrectSubject(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);

        $validator->set(Enum::SUBJECT, 'Mary had a big lamb');

        $errors = $token->validate($validator);

        $this->assertSame(['Validation: incorrect subject'], $errors);
    }
}
