<?php
/**
 * CryptTest.php
 * \Phalcon\Crypt
 *
 * Tests the \Phalcon\Crypt component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Crypt;

use \Phalcon\Crypt as PhTCrypt;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class CryptTest extends TBase
{
    public function _before()
    {
        if (!extension_loaded('mcrypt')) {
            $this->markTestSkipped('Warning: mcrypt extension is not loaded');
            return;
        }
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
                $modes = [
                    MCRYPT_MODE_ECB,
                    MCRYPT_MODE_CBC,
                    MCRYPT_MODE_CFB,
                    MCRYPT_MODE_CFB,
                    MCRYPT_MODE_NOFB
                ];

                $crypt = new PhTCrypt();

                foreach ($modes as $mode) {

                    $crypt->setMode($mode);

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
                $modes = ['ecb', 'cbc', 'cfb'];
                $pads  = [
                    PhTCrypt::PADDING_ANSI_X_923,
                    PhTCrypt::PADDING_PKCS7,
                    PhTCrypt::PADDING_ISO_10126,
                    PhTCrypt::PADDING_ISO_IEC_7816_4,
                    PhTCrypt::PADDING_ZERO,
                    PhTCrypt::PADDING_SPACE
                ];

                for ($i = 1; $i < 128; ++$i) {
                    $texts[] = str_repeat('A', $i);
                }

                $crypt = new PhTCrypt();
                $crypt->setCipher(MCRYPT_RIJNDAEL_256)
                    ->setKey(substr($key, 0, 16));

                foreach ($pads as $padding) {

                    $crypt->setPadding($padding);

                    foreach ($modes as $mode) {

                        $crypt->setMode($mode);

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

                $crypt = new PhTCrypt();
                $crypt->setPadding(PhTCrypt::PADDING_ANSI_X_923);

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
