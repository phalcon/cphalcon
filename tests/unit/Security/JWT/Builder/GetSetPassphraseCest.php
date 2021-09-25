<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Builder;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Exceptions\UnsupportedAlgorithmException;
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetSetPassphraseCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getPassphrase()/setPassphrase()
     *
     * @throws ValidatorException
     * @throws UnsupportedAlgorithmException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTBuilderGetSetPassphrase(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getPassphrase()/setPassphrase()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $passphrase = '6U#5xK!uFmUtwRZ3SCLjC*K%i8f@4MNE';
        $return     = $builder->setPassphrase($passphrase);
        $I->assertInstanceOf(Builder::class, $return);
        $I->assertEquals($passphrase, $builder->getPassphrase());
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: setPassphrase() - exception
     *
     * @since  2019-12-15
     */
    public function securityJWTBuilderSetPassphraseException(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - setPassphrase() - exception');

        $I->expectThrowable(
            new ValidatorException(
                'Invalid passphrase (too weak)'
            ),
            function () {
                $signer  = new Hmac();
                $builder = new Builder($signer);
                $builder->setPassphrase('1234');
            }
        );
    }
}
