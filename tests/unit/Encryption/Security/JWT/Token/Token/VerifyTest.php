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
use Phalcon\Tests\AbstractUnitTestCase;

final class VerifyTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-09
     */
    public function testEncryptionSecurityJWTTokenTokenVerify(): void
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

        $actual = $token->verify($signer, $passphrase);
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-09
     */
    public function testEncryptionSecurityJWTTokenTokenVerifyWrongAlgo(): void
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

        $mock = $this->createMock(Hmac::class);
        $mock
            ->method('getAlgHeader')
            ->willReturn('xyz')
        ;

        $actual = $token->verify($mock, $passphrase);
        $this->assertFalse($actual);
    }
}
