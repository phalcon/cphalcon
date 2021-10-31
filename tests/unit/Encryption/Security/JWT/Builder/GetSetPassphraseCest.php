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
use UnitTester;

/**
 * Class GetSetPassphraseCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetPassphraseCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getPassphrase()/setPassphrase()
     *
     * @param UnitTester $I
     *
     * @throws UnsupportedAlgorithmException
     *
     * @throws ValidatorException
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderGetSetPassphrase(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getPassphrase()/setPassphrase()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $passphrase = '6U#5xK!uFmUtwRZ3SCLjC*K%i8f@4MNE';
        $return     = $builder->setPassphrase($passphrase);
        $I->assertInstanceOf(Builder::class, $return);
        $I->assertEquals($passphrase, $builder->getPassphrase());
    }

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: setPassphrase() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderSetPassphraseException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - setPassphrase() - exception');

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
