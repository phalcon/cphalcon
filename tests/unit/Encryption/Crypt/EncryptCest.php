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

use Codeception\Stub;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use Phalcon\Tests\Fixtures\Crypt\CryptFixture;
use UnitTester;

use function str_repeat;
use function substr;

/**
 * Class EncryptCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class EncryptCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncrypt(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt()');

        $tests = [
            md5(uniqid())            => str_repeat('x', mt_rand(1, 255)),
            time() . time()          => str_shuffle('abcdefeghijklmnopqrst'),
            'le$ki12432543543543543' => '',
        ];

        $ciphers = [
            'AES-128-CBC',
            'AES-128-CFB',
            'AES-128-OFB',
            'AES128',
        ];

        $crypt = new Crypt();

        foreach ($ciphers as $cipher) {
            $crypt->setCipher($cipher);

            foreach ($tests as $key => $test) {
                $crypt->setKey(
                    substr($key, 0, 16)
                );

                $encryption = $crypt->encrypt($test);

                $actual = rtrim(
                    $crypt->decrypt($encryption),
                    "\0"
                );

                $I->assertEquals($test, $actual);
            }

            foreach ($tests as $key => $test) {
                $encryption = $crypt->encrypt(
                    $test,
                    substr($key, 0, 16)
                );

                $actual = rtrim(
                    $crypt->decrypt(
                        $encryption,
                        substr($key, 0, 16)
                    ),
                    "\0"
                );

                $I->assertEquals($test, $actual);
            }
        }
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - empty key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptExceptionEmptyKey(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - exception empty key');

        $I->expectThrowable(
            new Exception(
                'Encryption key cannot be empty'
            ),
            function () {
                $crypt = new Crypt();
                $crypt->encrypt('sample text', '');
            }
        );
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - unsupported algo
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptExceptionUnsupportedAlgo(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - exception unsupported algo');

        $I->expectThrowable(
            new Exception(
                "The cipher algorithm 'AES-128-ECB' is not supported on this system."
            ),
            function () {
                $crypt = new Crypt();

                $crypt->setCipher('AES-128-ECB');
            }
        );
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - gcm/ccm with data
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptGcmCcmWithData(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - gcm/ccm with data');

        $ciphers = [
            'aes-128-gcm',
            'aes-128-ccm',
            'aes-256-gcm',
            'aes-256-ccm',
        ];


        foreach ($ciphers as $cipher) {
            $crypt = new Crypt();
            $crypt
                ->setCipher($cipher)
                ->setKey('123456')
                ->setAuthTag('1234')
                ->setAuthData('abcd')
            ;

            $encryption = $crypt->encrypt('phalcon');

            $crypt = new Crypt();
            $crypt
                ->setCipher($cipher)
                ->setKey('123456')
                ->setAuthData('abcd')
            ;

            $actual = $crypt->decrypt($encryption);
            $I->assertEquals('phalcon', $actual);
        }
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - gcm/ccm exception without data
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptGcmCcmExceptionWithoutData(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - gcm/ccm exception without data');

        $ciphers = [
            'aes-128-gcm',
            'aes-128-ccm',
            'aes-256-gcm',
            'aes-256-ccm',
        ];

        foreach ($ciphers as $cipher) {
            $I->expectThrowable(
                new Exception(
                    "Auth data must be provided when using AEAD mode"
                ),
                function () use ($cipher) {
                    $crypt = new Crypt();

                    $crypt
                        ->setCipher($cipher)
                        ->setKey('123456')
                    ;

                    $encryption = $crypt->encrypt('phalcon');
                }
            );
        }
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - exception invalid padding size
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptCryptPadExceptionInvalidPaddingSize(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - cryptPadText() - exception invalid padding size');

        $I->expectThrowable(
            new Exception("Padding size cannot be less than 0 or greater than 256"),
            function () {
                $crypt       = new CryptFixture();
                $input       = str_repeat("A", 4096);
                $mode        = "cbc";
                $blockSize   = 1024;
                $paddingType = Crypt::PADDING_PKCS7;

                $result = $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
            }
        );

        $I->expectThrowable(
            new Exception("Padding size cannot be less than 0 or greater than 256"),
            function () {
                $crypt       = new CryptFixture();
                $input       = str_repeat("A", 4096);
                $mode        = "cbc";
                $blockSize   = -1024;
                $paddingType = Crypt::PADDING_PKCS7;

                $result = $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
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
    public function cryptEncryptCryptPadZeroPaddingReturnsInput(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - cryptPadText() - zero padding returns input');

        $crypt       = new CryptFixture();
        $input       = str_repeat("A", 32);
        $mode        = "ccb";
        $blockSize   = 16;
        $paddingType = Crypt::PADDING_PKCS7;

        $expected = $input;
        $actual   = $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: encrypt() - cannot calculate Random Pseudo Bytes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptEncryptCannotCalculateRandomPseudoBytes(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt() - cannot calculate Random Pseudo Bytes');

        $I->expectThrowable(
            new Exception("Cannot calculate Random Pseudo Bytes"),
            function () {
                $crypt = Stub::construct(
                    Crypt::class,
                    [],
                    [
                        'phpOpensslRandomPseudoBytes' => false,
                    ]
                );

                $result = $crypt->encrypt('test', '1234');
            }
        );
    }
}
