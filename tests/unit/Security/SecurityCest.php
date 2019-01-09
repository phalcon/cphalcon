<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class SecurityCest
{
    use DiTrait;

    private $shouldStopSession = false;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('openssl');

        $this->setNewFactoryDefault();
//        $this->setDiEscaper();
//        $this->setDiUrl();
        $this->setDiSessionFiles();

        $_SESSION = [];
        global $_SESSION;
    }

    public function _after(UnitTester $I)
    {
        if (true === $this->shouldStopSession) {
            @\session_destroy();
        }
    }

    /**
     * Tests the Security constants
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2015-12-19
     */
    public function testSecurityConstants(UnitTester $I)
    {
        $I->assertEquals(0, Security::CRYPT_DEFAULT);
        $I->assertEquals(1, Security::CRYPT_STD_DES);
        $I->assertEquals(2, Security::CRYPT_EXT_DES);
        $I->assertEquals(3, Security::CRYPT_MD5);
        $I->assertEquals(4, Security::CRYPT_BLOWFISH);
        $I->assertEquals(5, Security::CRYPT_BLOWFISH_A);
        $I->assertEquals(6, Security::CRYPT_BLOWFISH_X);
        $I->assertEquals(7, Security::CRYPT_BLOWFISH_Y);
        $I->assertEquals(8, Security::CRYPT_SHA256);
        $I->assertEquals(9, Security::CRYPT_SHA512);
    }

    /**
     * Tests the HMAC computation
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testSecurityComputeHMAC(UnitTester $I)
    {
        $security = new Security();

        $data = [];
        for ($i = 1; $i < 256; ++$i) {
            $data[] = str_repeat('a', $i);
        }
        $keys = [
            substr(md5('test', true), 0, strlen(md5('test', true)) / 2),
            md5('test', true),
            md5('test', true) . md5('test', true),
        ];

        foreach ($data as $index => $text) {
            $expected = hash_hmac('md5', $text, $keys[0]);
            $actual   = $security->computeHmac($text, $keys[0], 'md5');
            $I->assertEquals($expected, $actual);
            $expected = hash_hmac('md5', $text, $keys[1]);
            $actual   = $security->computeHmac($text, $keys[1], 'md5');
            $I->assertEquals($expected, $actual);
            $expected = hash_hmac('md5', $text, $keys[2]);
            $actual   = $security->computeHmac($text, $keys[2], 'md5');
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the security defaults
     */
    public function testSecurityDefaults(UnitTester $I)
    {
        $security = new Security();

        $expected = null;
        $actual   = $security->getDefaultHash();
        $I->assertEquals($expected, $actual);

        $expected = 16;
        $actual   = $security->getRandomBytes();
        $I->assertEquals($expected, $actual);

        $security->setDefaultHash(1);
        $expected = 1;
        $actual   = $security->getDefaultHash();
        $I->assertEquals($expected, $actual);

        $security->setRandomBytes(22);
        $expected = 22;
        $actual   = $security->getRandomBytes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Security::getToken and Security::getTokenKey for generating only
     * one token per request
     */
    public function testOneTokenPerRequest(UnitTester $I)
    {
        $this->startSession();

        $container = $this->getDi();
        $security  = new Security();
        $security->setDI($container);

        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $expected = $tokenKey;
        $actual   = $security->getTokenKey();
        $I->assertEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getToken();
        $I->assertEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getSessionToken();
        $I->assertEquals($expected, $actual);

        $security->destroyToken();

        $expected = $tokenKey;
        $actual   = $security->getTokenKey();
        $I->assertNotEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getToken();
        $I->assertNotEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getSessionToken();
        $I->assertNotEquals($expected, $actual);

        $security->destroyToken();
    }

    private function startSession(): void
    {
        if (PHP_SESSION_ACTIVE !== \session_status()) {
            @\session_start();
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }

        $this->shouldStopSession = true;
    }

    /**
     * Tests Security::checkToken
     */
    public function testCheckToken(UnitTester $I)
    {
        $this->startSession();

        $container = $this->getDi();
        $security  = new Security();
        $security->setDI($container);

        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();
        $_POST    = [$tokenKey => $token];
        $I->assertTrue($security->checkToken(null, null, false));
        $I->assertTrue($security->checkToken());
        $I->assertFalse($security->checkToken());

        // Destroy token check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();
        $security->destroyToken();

        $_POST = [$tokenKey => $token];
        $I->assertFalse($security->checkToken());

        // Custom token key check
        $token = $security->getToken();
        $_POST = ['custom_key' => $token];
        $I->assertFalse($security->checkToken(null, null, false));
        $I->assertFalse($security->checkToken('other_custom_key', null, false));
        $I->assertTrue($security->checkToken('custom_key'));

        // Custom token value check
        $token = $security->getToken();
        $_POST = [];
        $I->assertFalse($security->checkToken(null, null, false));
        $I->assertFalse($security->checkToken('some_random_key', 'some_random_value', false));
        $I->assertTrue($security->checkToken('custom_key', $token));
    }

    /**
     * Tests Security::getSaltBytes
     */
    public function testGetSaltBytes(UnitTester $I)
    {
        $security = new Security();

        $I->assertGreaterOrEquals(16, strlen($security->getSaltBytes()));
        $I->assertGreaterOrEquals(22, strlen($security->getSaltBytes(22)));
    }

    /**
     * Tests Security::hash
     */
    public function testHash(UnitTester $I)
    {
        $security = new Security();
        $password = 'SomePasswordValue';

        $security->setDefaultHash(Security::CRYPT_DEFAULT);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_STD_DES);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_EXT_DES);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_A);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_X);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_Y);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_SHA256);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_SHA512);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));
    }

    public function testRequestToken(UnitTester $I)
    {
        $this->startSession();
        $container = $this->getDI();

        // Initialize session.
        $security = new Security();
        $security->setDI($container);

        $tokenKey = $security->getTokenKey();
        $security->getToken();

        // Reinitialize object like if it's a new request.
        $security = new Security();
        $security->setDI($container);
        $requestToken = $security->getRequestToken();
        $sessionToken = $security->getSessionToken();
        $tokenKey     = $security->getTokenKey();
        $token        = $security->getToken();

        $I->assertEquals($sessionToken, $requestToken);
        $I->assertNotEquals($token, $sessionToken);
        $I->assertEquals($security->getRequestToken(), $requestToken);
        $I->assertNotEquals($token, $security->getRequestToken());

        $_POST = [$tokenKey => $requestToken];
        $I->assertTrue($security->checkToken(null, null, false));

        $_POST = [$tokenKey => $token];
        $I->assertFalse($security->checkToken(null, null, false));

        $I->assertFalse($security->checkToken());

        $security->destroyToken();
        $I->assertNotEquals($security->getRequestToken(), $requestToken);
    }
}
