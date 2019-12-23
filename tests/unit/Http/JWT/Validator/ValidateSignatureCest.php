<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Validator;

use Phalcon\Http\JWT\Builder;
use Phalcon\Http\JWT\Exceptions\ValidatorException;
use Phalcon\Http\JWT\Signer\Hmac;
use Phalcon\Http\JWT\Validator;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ValidateSignatureCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Http\JWT\Validator :: validateSignature()
     *
     * @since  2019-12-22
     */
    public function httpJWTValidatorValidateNotBefore(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - validateSignature()');

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
        $I->assertInstanceOf(Validator::class, $validator);

        $I->assertInstanceOf(
            Validator::class,
            $validator->validateSignature($signer, $passphrase)
        );
    }

    /**
     * Unit Tests Phalcon\Http\JWT\Validator :: validateSignature() - exception
     *
     * @since  2019-12-22
     */
    public function httpJWTValidatorValidateNotBeforeException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Validator - validateSignature()');

        $token = $this->newToken();
        $I->expectThrowable(
            new ValidatorException(
                "Validation: the signature does not match"
            ),
            function () use ($token, $I) {
                $signer     = new Hmac();
                $passphrase = '123456';
                $validator  = new Validator($token);
                $I->assertInstanceOf(Validator::class, $validator);

                $I->assertInstanceOf(
                    Validator::class,
                    $validator->validateSignature($signer, $passphrase)
                );
            }
        );
    }
}
