<?php

namespace Phalcon\Test\Unit;

use Phalcon\Crypt;
use Phalcon\Test\Module\UnitTest;
use UnitTester;

class CryptCest
{
    public function _before(UnitTester $I, $scenario)
    {
        if (!extension_loaded('openssl')) {
            $scenario->skip('Warning: openssl extension is not loaded');
        }
    }

    /**
     * Tests decrypt using HMAC
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     *
     * @expectedException        \Phalcon\Crypt\Mismatch
     * @expectedExceptionMessage Hash does not match.
     */
    public function shouldThrowExceptionIfHashMismatch()
    {
//        $this->specify(
//            'Crypt does not check message digest on decrypt',
//            function () {
//                $crypt = new Crypt();
//                $crypt->useSigning(true);
//
//                $crypt->decrypt(
//                    $crypt->encrypt('le text', 'encrypt key'),
//                    'wrong key'
//                );
//            }
//        );
    }

    /**
     * Tests decrypt using HMAC
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     */
    public function shouldDecryptSignedString(UnitTester $I)
    {
        $crypt = new Crypt();
        $crypt->useSigning(true);

        $key = 'secret';
        $crypt->setKey($key);

        $expected  = 'le text';
        $encrypted = $crypt->encrypt($expected);
        $actual    = $crypt->decrypt($encrypted);

        expect($expected)->equals($actual);
    }

    /**
     * Tests decrypt without using HMAC
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     */
    public function shouldNotThrowExceptionIfKeyMismatch(UnitTester $I)
    {
        $crypt = new Crypt();

        $actual = $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );

        $I->assertNotEmpty($actual);
    }

    /**
     * Tests the Crypt::setCipher
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     *
     * @expectedException        \Phalcon\Crypt\Exception
     * @expectedExceptionMessage The cipher algorithm "xxx-yyy-zzz" is not supported on this system.
     */
    public function shouldThrowExceptionIfCipherIsUnknown(UnitTester $I)
    {
//        $this->specify(
//            'Crypt does not validate cipher algorithm as expected',
//            function () {
//                $crypt = new Crypt();
//                $crypt->setCipher('xxx-yyy-zzz');
//            }
//        );
    }

    /**
     * Tests the Crypt constants
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-12-20
     */
    public function testCryptConstants(UnitTester $I)
    {
        $I->assertEquals(0, Crypt::PADDING_DEFAULT);
        $I->assertEquals(1, Crypt::PADDING_ANSI_X_923);
        $I->assertEquals(2, Crypt::PADDING_PKCS7);
        $I->assertEquals(3, Crypt::PADDING_ISO_10126);
        $I->assertEquals(4, Crypt::PADDING_ISO_IEC_7816_4);
        $I->assertEquals(5, Crypt::PADDING_ZERO);
        $I->assertEquals(6, Crypt::PADDING_SPACE);
    }

    /**
     * Tests the encryption
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-17
     */
    public function testCryptEncryption(UnitTester $I)
    {
        $this->specify(
            "encryption does not return correct results",
            function () {
                $tests = [
                    md5(uniqid())            => str_repeat('x', mt_rand(1, 255)),
                    time().time()            => str_shuffle('abcdefeghijklmnopqrst'),
                    'le$ki12432543543543543' => null,
                ];
                $ciphers = [
                    'AES-128-ECB',
                    'AES-128-CBC',
                    'AES-128-CFB',
                    'AES-128-OFB',
                    'AES128',
                ];

                $crypt = new Crypt();

                foreach ($ciphers as $cipher) {
                    $crypt->setCipher($cipher);

                    foreach ($tests as $key => $test) {
                        $crypt->setKey(substr($key, 0, 16));
                        $encryption = $crypt->encrypt($test);
                        $actual     = rtrim($crypt->decrypt($encryption), "\0");

                        expect($actual)->equals($test);
                    }

                    foreach ($tests as $key => $test) {
                        $encryption = $crypt->encrypt($test, substr($key, 0, 16));

                        $actual = rtrim($crypt->decrypt($encryption, substr($key, 0, 16)), "\0");

                        expect($actual)->equals($test);
                    }
                }
            }
        );
    }

    /**
     * Tests the padding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-17
     */
    public function testCryptPadding()
    {
        $this->specify(
            "padding not return correct results",
            function () {
                $texts = [''];
                $key   = '0123456789ABCDEF0123456789ABCDEF';
                $ciphers = [
                    'AES-256-ECB',
                    'AES-256-CBC',
                    'AES-256-CFB',
                ];
                $pads  = [
                    Crypt::PADDING_ANSI_X_923,
                    Crypt::PADDING_PKCS7,
                    Crypt::PADDING_ISO_10126,
                    Crypt::PADDING_ISO_IEC_7816_4,
                    Crypt::PADDING_ZERO,
                    Crypt::PADDING_SPACE
                ];

                for ($i = 1; $i < 128; ++$i) {
                    $texts[] = str_repeat('A', $i);
                }

                $crypt = new Crypt();
                $crypt->setKey(substr($key, 0, 32));

                foreach ($pads as $padding) {
                    $crypt->setPadding($padding);

                    foreach ($ciphers as $cipher) {
                        $crypt->setCipher($cipher);

                        foreach ($texts as $text) {
                            $encrypted = $crypt->encrypt($text);
                            $actual    = $crypt->decrypt($encrypted);

                            expect($actual)->equals($text);
                        }
                    }
                }
            }
        );
    }

    /**
     * Tests the encryption base 64
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-17
     */
    public function testCryptEncryptBase64()
    {
        $this->specify(
            "encryption base 64does not return correct results",
            function () {
                $crypt = new Crypt();
                $crypt->setPadding(Crypt::PADDING_ANSI_X_923);

                $key      = substr('phalcon notice 13123123', 0, 16);
                $expected = 'https://github.com/phalcon/cphalcon/issues?state=open';

                $encrypted = $crypt->encryptBase64($expected, substr($key, 0, 16));
                $actual    = $crypt->decryptBase64($encrypted, $key);

                expect($actual)->equals($expected);

                $encrypted = $crypt->encryptBase64($expected, $key, true);
                $actual    = $crypt->decryptBase64($encrypted, $key, true);

                expect($actual)->equals($expected);
            }
        );
    }
}
