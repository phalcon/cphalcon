<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Token;

use Codeception\Stub;
use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Validator;
use UnitTester;

class VerifyCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: verify()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-09
     */
    public function encryptionSecurityJWTTokenTokenVerify(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Token\Token - verify()');

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
        $I->assertTrue($actual);
    }

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: verify() wrong algo
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-09
     */
    public function encryptionSecurityJWTTokenTokenVerifyWrongAlgo(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Token\Token - verify() wrong algo');

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

        $signer     = Stub::make(
            Hmac::class,
            [
                'getAlgHeader' => 'xyz',
            ]
        );

        $actual = $token->verify($signer, $passphrase);
        $I->assertFalse($actual);
    }
}
