<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use UnitTester;

class GetSetCipherCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: getCipher() / setCipher()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function encryptionCryptGetSetCipher(UnitTester $I)
    {
        $I->wantToTest('Encryption\Crypt - getCipher() / setCipher()');

        $cipher = 'aes-256-cfb';
        $crypt  = new Crypt();
        $crypt->setCipher($cipher);

        $I->assertSame($cipher, $crypt->getCipher());
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: setCipher() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function encryptionCryptGetSetCipherUnknown(UnitTester $I)
    {
        $I->wantToTest('Encryption\Crypt - setCipher() - unknown');
        $I->expectThrowable(
            new Exception(
                "The cipher algorithm 'xxx-yyy-zzz' is not supported on this system."
            ),
            function () {
                $crypt = new Crypt();

                $crypt->setCipher('xxx-yyy-zzz');
            }
        );
    }
}
