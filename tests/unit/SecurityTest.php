<?php

namespace Phalcon\Test\Unit;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Security;

/**
 * \Phalcon\Test\Unit\SecurityTest
 * Tests the \Phalcon\Security component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SecurityTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        if (!extension_loaded('openssl')) {
            $this->markTestSkipped('Warning: openssl extension is not loaded');
        }
    }

    /**
     * Tests the Security constants
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-12-19
     */
    public function testSecurityConstants()
    {
        $this->specify(
            "Security constants are not correct",
            function () {
                expect(Security::CRYPT_DEFAULT)->equals(0);
                expect(Security::CRYPT_STD_DES)->equals(1);
                expect(Security::CRYPT_EXT_DES)->equals(2);
                expect(Security::CRYPT_MD5)->equals(3);
                expect(Security::CRYPT_BLOWFISH)->equals(4);
                expect(Security::CRYPT_BLOWFISH_X)->equals(5);
                expect(Security::CRYPT_BLOWFISH_Y)->equals(6);
                expect(Security::CRYPT_SHA256)->equals(7);
                expect(Security::CRYPT_SHA512)->equals(8);
            }
        );
    }

    /**
     * Tests the HMAC computation
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testSecurityComputeHMAC()
    {
        $this->specify(
            "The HMAC computation values are not identical",
            function () {
                $security = new Security();
                $key      = md5('test', true);
                $keys     = [
                    substr($key, 0, strlen($key) / 2),
                    $key,
                    $key . $key
                ];

                $data = [];
                for ($i = 1; $i < 256; ++$i) {
                    $data[] = str_repeat('a', $i);
                }

                foreach ($keys as $key) {
                    foreach ($data as $text) {
                        $actual   = $security->computeHmac($text, $key, 'md5');
                        $expected = hash_hmac('md5', $text, $key);

                        $this->assertSame($expected, $actual, "The HMAC computation values are not identical");
                    }
                }
            }
        );
    }
}
