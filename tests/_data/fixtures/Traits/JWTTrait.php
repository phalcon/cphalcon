<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use Phalcon\Security\JWT\Token\Token;

trait JWTTrait
{
    /**
     * @param string $signerClass
     * @param int    $issDrift
     *
     * @return Token
     * @throws ValidatorException
     */
    public function newToken($signerClass = Hmac::class, int $issDrift = 0): Token
    {
        $signer  = new $signerClass();
        $builder = new Builder($signer);
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
