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
use Phalcon\Crypt\Exception\Exception;
use Phalcon\Crypt\Exception\Mismatch;
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
     * Tests Phalcon\Crypt\Crypt :: decrypt() - no exception on key mismatch
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptNoExceptionOnKeyMismatch(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decrypt() not throwing Exception on key mismatch'
        );

        $crypt = new Crypt();

        $actual = $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );

        $I->assertNotEmpty($actual);
    }

    /**
     * Tests Phalcon\Crypt\Crypt :: decrypt() - exception hash mismatch
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     */
    public function cryptDecryptExceptionHashMismatch(UnitTester $I)
    {
        $I->wantToTest('Crypt - decrypt() - exception hash mismatch');

        $I->expectThrowable(
            new Mismatch('Hash does not match.'),
            function () {
                $crypt = new Crypt();

                $crypt->useSigning(true);

                $crypt->decrypt(
                    $crypt->encrypt('le text', 'encrypt key'),
                    'wrong key'
                );
            }
        );
    }

    /**
     * Tests Phalcon\Crypt\Crypt :: decrypt() - signed key
     * Tests decrypt using HMAC
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * Tests Phalcon\Crypt\Crypt :: decrypt() - empty key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * Tests Phalcon\Crypt\Crypt :: encrypt() - Zero padding returns input
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
