<?php

namespace Phalcon\Test\Unit;

use Phalcon\Crypt;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\CryptTest
 * Tests the \Phalcon\Crypt component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CryptTest extends UnitTest
{
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('openssl')) {
            $this->markTestSkipped('Warning: openssl extension is not loaded');
        }
    }

    /**
     * Tests the Crypt constants
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-12-20
     */
    public function testCryptConstants()
    {
        $this->specify(
            "Crypt constants are not correct",
            function () {
                expect(Crypt::PADDING_DEFAULT)->equals(0);
                expect(Crypt::PADDING_ANSI_X_923)->equals(1);
                expect(Crypt::PADDING_PKCS7)->equals(2);
                expect(Crypt::PADDING_ISO_10126)->equals(3);
                expect(Crypt::PADDING_ISO_IEC_7816_4)->equals(4);
                expect(Crypt::PADDING_ZERO)->equals(5);
                expect(Crypt::PADDING_SPACE)->equals(6);
            }
        );
    }

    /**
     * Tests the encryption
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-17
     */
    public function testCryptEncryption()
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
