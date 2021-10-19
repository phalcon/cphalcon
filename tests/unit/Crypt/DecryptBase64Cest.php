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

namespace Phalcon\Tests\Unit\Crypt;

use Phalcon\Crypt\Crypt;
use Phalcon\Crypt\Exception\Mismatch;
use UnitTester;

/**
 * Class DecryptBase64Cest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class DecryptBase64Cest
{
    /**
     * Tests decrypt without using HMAC
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptBase64UnsignedKeyMismatchNoException(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decryptBase64() unsigned key mismatch no exception'
        );

        $crypt  = new Crypt();
        $crypt->useSigning(false);
        $actual = $crypt->decryptBase64(
            $crypt->encryptBase64('le text', 'encrypt key'),
            'wrong key'
        );

        $I->assertNotEmpty($actual);
    }

    /**
     * Tests decrypt using HMAC
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptBase64SignedKeyMismatchThrowsException(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decryptBase64() signed key mismatch throws exception'
        );

        $I->expectThrowable(
            new Mismatch('Hash does not match.'),
            function () {
                $crypt = new Crypt();
                $crypt->decryptBase64(
                    $crypt->encryptBase64('le text', 'encrypt key'),
                    'wrong key'
                );
            }
        );
    }

    /**
     * Tests decrypt using HMAC
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptBase64DecryptSignedString(UnitTester $I)
    {
        $crypt = new Crypt();
        $crypt
            ->useSigning(true)
            ->setKey('secret')
        ;

        $expected  = 'le text';
        $encrypted = $crypt->encryptBase64($expected);
        $actual    = $crypt->decryptBase64($encrypted);

        $I->assertEquals($expected, $actual);
    }
}
