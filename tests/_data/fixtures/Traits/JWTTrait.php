<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Traits;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Token\Token;
use Phalcon\Tests\Fixtures\Security\ExtendedBuilder;

trait JWTTrait
{
    /**
     * @param string $signerClass
     * @param int    $issDrift
     *
     * @return Token
     * @throws ValidatorException
     */
    protected function newToken($signerClass = Hmac::class, int $issDrift = 0): Token
    {
        return $this->generateToken(Builder::class, $signerClass, $issDrift);
    }

    /**
     * @param string $signerClass
     * @param int    $issDrift
     *
     * @return Token
     * @throws ValidatorException
     */
    protected function newExtendedToken($signerClass = Hmac::class, int $issDrift = 0): Token
    {
        return $this->generateToken(ExtendedBuilder::class, $signerClass, $issDrift);
    }

    /**
     * @param string $builderClass
     * @param string $signerClass
     * @param int    $issDrift
     *
     * @return Token
     * @throws ValidatorException
     */
    protected function generateToken(
        string $builderClass = Builder::class,
        string $signerClass = Hmac::class,
        int $issDrift = 0
    ): Token {
        $signer  = new $signerClass();
        $builder = new $builderClass($signer);
        $expiry     = strtotime('+1 day');
        $issued     = strtotime('now') + $issDrift;
        $notBefore  = strtotime('-1 day');
        $passphrase = '&vsJBETaizP3A3VX&TPMJUqi48fJEgN7';

        return $builder
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
    }
}
