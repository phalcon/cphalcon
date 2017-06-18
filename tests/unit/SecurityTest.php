<?php

namespace Phalcon\Test\Unit;

use Phalcon\Di;
use Phalcon\Security;
use Phalcon\Http\Request;
use Phalcon\Test\Module\UnitTest;
use Codeception\Lib\Connector\Phalcon\MemorySession;

/**
 * \Phalcon\Test\Unit\SecurityTest
 * Tests the \Phalcon\Security component
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
            'Security constants are not correct',
            function () {
                expect(Security::CRYPT_DEFAULT)->equals(0);
                expect(Security::CRYPT_STD_DES)->equals(1);
                expect(Security::CRYPT_EXT_DES)->equals(2);
                expect(Security::CRYPT_MD5)->equals(3);
                expect(Security::CRYPT_BLOWFISH)->equals(4);
                expect(Security::CRYPT_BLOWFISH_A)->equals(5);
                expect(Security::CRYPT_BLOWFISH_X)->equals(6);
                expect(Security::CRYPT_BLOWFISH_Y)->equals(7);
                expect(Security::CRYPT_SHA256)->equals(8);
                expect(Security::CRYPT_SHA512)->equals(9);
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
            'The HMAC computation values are not identical',
            function ($key) {
                $security = new Security();

                $data = [];
                for ($i = 1; $i < 256; ++$i) {
                    $data[] = str_repeat('a', $i);
                }

                foreach ($data as $text) {
                    expect($security->computeHmac($text, $key, 'md5'))->equals(hash_hmac('md5', $text, $key));
                }
            },
            [
                'examples' => [
                    [
                        substr(md5('test', true), 0, strlen(md5('test', true)) / 2)
                    ],
                    [
                        md5('test', true)
                    ],
                    [
                        md5('test', true) . md5('test', true)
                    ],
                ]
            ]
        );
    }

    /**
     * Tests the security defaults
     */
    public function testSecurityDefaults()
    {
        $this->specify(
            'Security defaults are not correct',
            function () {
                $s = new Security();
                expect($s->getDefaultHash())->equals(null);
                expect($s->getRandomBytes())->equals(16);

                $s->setDefaultHash(1);
                expect($s->getDefaultHash())->equals(1);

                $s->setRandomBytes(22);
                expect($s->getRandomBytes())->equals(22);
            }
        );
    }

    /**
     * Tests Security::getToken and Security::getTokenKey for generating only one token per request
     */
    public function testOneTokenPerRequest()
    {
        $this->specify(
            "The Security::getToken and Security::getTokenKey must return only one token per request",
            function () {
                $di = $this->setupDI();

                $s = new Security();
                $s->setDI($di);

                $tokenKey = $s->getTokenKey();
                $token = $s->getToken();

                expect($tokenKey)->equals($s->getTokenKey());
                expect($token)->equals($s->getToken());
                expect($token)->equals($s->getSessionToken());

                $s->destroyToken();

                expect($tokenKey)->notEquals($s->getTokenKey());
                expect($token)->notEquals($s->getToken());
                expect($token)->notEquals($s->getSessionToken());

                $s->destroyToken();
            }
        );
    }

    /**
     * Tests Security::checkToken
     */
    public function testCheckToken()
    {
        $this->specify(
            'The Security::checkToken works incorrectly',
            function () {
                $di = $this->setupDI();

                $s = new Security();
                $s->setDI($di);

                // Random token and token key check
                $tokenKey = $s->getTokenKey();
                $token = $s->getToken();

                $_POST = [$tokenKey => $token];

                expect($s->checkToken(null, null, false))->true();
                expect($s->checkToken())->true();
                expect($s->checkToken())->false();

                // Destroy token check
                $tokenKey = $s->getTokenKey();
                $token = $s->getToken();

                $s->destroyToken();

                $_POST = [$tokenKey => $token];

                expect($s->checkToken())->false();

                // Custom token key check
                $token = $s->getToken();

                $_POST = ['custom_key' => $token];

                expect($s->checkToken(null, null, false))->false();
                expect($s->checkToken('other_custom_key', null, false))->false();
                expect($s->checkToken('custom_key'))->true();

                // Custom token value check
                $token = $s->getToken();

                $_POST = [];

                expect($s->checkToken(null, null, false))->false();
                expect($s->checkToken('some_random_key', 'some_random_value', false))->false();
                expect($s->checkToken('custom_key', $token))->true();
            }
        );
    }

    /**
     * Tests Security::getSaltBytes
     */
    public function testGetSaltBytes()
    {
        $this->specify(
            'The Security::getSaltBytes works incorrectly',
            function () {
                $s = new Security();

                expect(strlen($s->getSaltBytes()))->greaterOrEquals(16);
                expect(strlen($s->getSaltBytes(22)))->greaterOrEquals(22);
            }
        );
    }

    /**
     * Tests Security::hash
     */
    public function testHash()
    {
        $this->specify(
            'The Security::hash works incorrectly',
            function () {
                $s = new Security();

                $password = 'SomePasswordValue';

                $s->setDefaultHash(Security::CRYPT_DEFAULT);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_STD_DES);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_EXT_DES);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_BLOWFISH);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_BLOWFISH_A);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_BLOWFISH_X);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_BLOWFISH_Y);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_SHA256);
                expect($s->checkHash($password, $s->hash($password)))->true();

                $s->setDefaultHash(Security::CRYPT_SHA512);
                expect($s->checkHash($password, $s->hash($password)))->true();
            }
        );
    }

    /**
     * Set up the environment.
     *
     * @return Di
     */
    private function setupDI()
    {
        Di::reset();

        $di = new Di();

        $di->setShared('session', function () {
            return new MemorySession();
        });

        $di->setShared('request', function () {
            return new Request();
        });

        return $di;
    }
}
