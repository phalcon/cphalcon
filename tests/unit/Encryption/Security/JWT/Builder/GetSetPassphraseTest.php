<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Builder;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Exceptions\UnsupportedAlgorithmException;
use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetPassphraseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderGetSetPassphrase(): void
    {
        $signer  = new Hmac();
        $builder = new Builder($signer);

        $passphrase = '6U#5xK!uFmUtwRZ3SCLjC*K%i8f@4MNE';
        $return     = $builder->setPassphrase($passphrase);
        $this->assertInstanceOf(Builder::class, $return);
        $this->assertSame($passphrase, $builder->getPassphrase());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderSetPassphraseException(): void
    {
        $this->expectException(ValidatorException::class);
        $this->expectExceptionMessage("Invalid passphrase (too weak)");

        $signer  = new Hmac();
        $builder = new Builder($signer);
        $builder->setPassphrase('1234');
    }
}
