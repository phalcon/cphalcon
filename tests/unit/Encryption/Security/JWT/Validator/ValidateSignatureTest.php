<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateSignatureTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateNotBefore(): void
    {
        $signer     = new Hmac();
        $builder    = new Builder($signer);
        $expiry     = strtotime('+1 day');
        $issued     = strtotime('now');
        $notBefore  = strtotime('-1 day');
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

        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $this->assertInstanceOf(
            Validator::class,
            $validator->validateSignature($signer, $passphrase)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTValidatorValidateNotBeforeException(): void
    {
        $token      = $this->newToken();
        $signer     = new Hmac();
        $passphrase = '123456';
        $validator  = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $this->assertInstanceOf(
            Validator::class,
            $validator->validateSignature($signer, $passphrase)
        );

        $expected = ["Validation: the signature does not match"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}
