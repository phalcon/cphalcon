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
use Phalcon\Encryption\Security\JWT\Token\Item;
use Phalcon\Encryption\Security\JWT\Token\Signature;
use Phalcon\Encryption\Security\JWT\Token\Token;
use Phalcon\Encryption\Security\JWT\Validator;
use UnitTester;

use function strtotime;
use function usleep;

class ValidateCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Token :: getToken()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-23
     */
    public function encryptionSecurityJWTTokenTokenValidate(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Token\Token - validate()');

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
            ->getToken();

        $validator = new Validator($token);

        $errors = $token->validate($validator);
        $I->assertCount(2, $errors);

        $expected = [
            "Validation: the token cannot be used yet (future)",
            "Validation: the token cannot be used yet (not before)"
        ];
        $actual = $errors;
        $I->assertSame($expected, $actual);
    }
}
