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
use Phalcon\Encryption\Crypt\Exception\Mismatch;
use Phalcon\Tests\Fixtures\Crypt\CryptFixture;
use UnitTester;

use function str_repeat;

/**
 * Class DecryptCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class DecryptCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: decrypt() - no exception on key mismatch
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptUnsignedKeyMismatchNoException(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decrypt() unsigned key mismatch no exception'
        );

        $crypt = new Crypt();
        $crypt->useSigning(false);
        $actual = $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );

        $I->assertNotEmpty($actual);
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: decrypt() - exception hash mismatch
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptSignedKeyMismatchThrowsException(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decrypt() signed key mismatch throws exception'
        );

        $I->expectThrowable(
            new Mismatch('Hash does not match.'),
            function () {
                $crypt = new Crypt();
                $crypt->decrypt(
                    $crypt->encrypt('le text', 'encrypt key'),
                    'wrong key'
                );
            }
        );
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: decrypt() - signed key
     * Tests decrypt using HMAC
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptSignedString(UnitTester $I)
    {
        $I->wantToTest('Crypt - decrypt() - signed key');
        $crypt = new Crypt();

        $crypt->useSigning(true);
        $crypt->setKey('secret');

        $expected  = 'le text';
        $encrypted = $crypt->encrypt($expected);
        $actual    = $crypt->decrypt($encrypted);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: decrypt() - empty key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptDecryptExceptionEmptyKey(UnitTester $I)
    {
        $I->wantToTest('Crypt - decrypt() - exception empty key');

        $I->expectThrowable(
            new Exception(
                'Decryption key cannot be empty'
            ),
            function () {
                $crypt = new Crypt();
                $crypt->decrypt('sample text', '');
            }
        );
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - Zero padding returns input
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptDecryptCryptUnpadZeroPaddingReturnsInput(UnitTester $I)
    {
        $I->wantToTest('Crypt - decrypt() - cryptUnpadText() - zero padding returns input');

        $crypt       = new CryptFixture();
        $input       = str_repeat("A", 32);
        $mode        = "ccb";
        $blockSize   = 16;
        $paddingType = Crypt::PADDING_PKCS7;

        $expected = $input;
        $actual   = $crypt->cryptUnpadText($input, $mode, $blockSize, $paddingType);
        $I->assertEquals($expected, $actual);
    }
}
