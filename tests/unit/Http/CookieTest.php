<?php

namespace Phalcon\Test\Unit\Http;

use Phalcon\Crypt;
use Phalcon\Http\Cookie;
use Phalcon\Http\Cookie\Exception;
use Phalcon\DI\FactoryDefault;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use Helper\CookieAwareTrait;
use Phalcon\Crypt\Mismatch;

/**
 * Phalcon\Test\Unit\Http\CookieTest
 * Tests the Phalcon\Http\Cookie component
 *
 * @copyright (c) 2011-2018 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CookieTest extends HttpBase
{
    use CookieAwareTrait;

    /**
     * Tests Cookie::setSignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     */
    public function shouldThrowExceptionIfSignKeyIsUnenoughLong()
    {
        $this->specify(
            'Cookie does not validate sign key cipher length as expected',
            function () {
                $cookie = new Cookie('test-cookie', 'test', time() + 3600);
                $cookie->setSignKey('1234567890');
            },
            [
                'throws' => [
                    Exception::class,
                    "The cookie's key should be at least 32 characters long. Current length is 10."
                ]
            ]
        );
    }

    /**
     * Tests Cookie::getValue using message authentication code and request forgery
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     */
    public function shouldThrowExceptionIfMessageAuthenticationCodeIsMismatch()
    {
        if (!extension_loaded('xdebug')) {
            $this->markTestSkipped('Warning: xdebug extension is not loaded');
        }

        $this->specify(
            'Cookie object unable to detected that message authentication code is mismatch',
            function () {
                $di = new FactoryDefault();

                $di->setShared('crypt', function () {
                    $crypt = new Crypt();
                    $crypt->setKey('cryptkeycryptkey');
                    $crypt->useSigning(true);

                    return $crypt;
                });

                $cookieName  = 'test-signed-name1';
                $cookieValue = 'test-signed-value';

                $cookie = new Cookie($cookieName, $cookieValue, time() + 3600);

                $cookie->setDI($di);
                $cookie->useEncryption(true);
                $cookie->setSignKey('12345678901234567890123456789012');

                $cookie->send();

                $this->tester->setProtectedProperty($cookie, '_readed', false);

                $rawCookie = $this->getCookie($cookieName);
                $rawValue  = explode(';', $rawCookie)[0];

                $originalValue = mb_substr($rawValue, 64);

                $_COOKIE[$cookieName] = str_repeat('X', 64) . $originalValue;
                $cookie->getValue();
            },
            ['throws' => new Mismatch()]
        );
    }

    /**
     * Tests Cookie::getValue using message authentication code
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     */
    public function shouldDecryptValueByUsingMessageAuthenticationCode()
    {
        if (!extension_loaded('xdebug')) {
            $this->markTestSkipped('Warning: xdebug extension is not loaded');
        }

        $this->specify(
            'Cookie object does not work with message authentication code as expected',
            function () {
                $di = new FactoryDefault();

                $di->setShared('crypt', function () {
                    $crypt = new Crypt();
                    $crypt->setKey('cryptkeycryptkey');

                    return $crypt;
                });

                $cookieName  = 'test-signed-name2';
                $cookieValue = 'test-signed-value';

                $cookie = new Cookie($cookieName, $cookieValue, time() + 3600);

                $cookie->setDI($di);
                $cookie->useEncryption(true);
                $cookie->setSignKey('12345678901234567890123456789012');

                $cookie->send();

                $this->tester->setProtectedProperty($cookie, '_readed', false);

                $rawCookie = $this->getCookie($cookieName);
                $rawValue  = explode(';', $rawCookie)[0];

                $_COOKIE[$cookieName] = $rawValue;
                expect($cookie->getValue())->equals($cookieValue);
            }
        );
    }

    /**
     * Tests Cookie::getValue with using encryption and default crypt algo.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/11259
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-10-04
     */
    public function shouldDecryptValueByUsingDefaultEncryptionAlgo()
    {
        $this->specify(
            "The cookie value decrypted incorrectly.",
            function () {
                $di = new FactoryDefault();

                $di->set('crypt', function () {
                    $crypt = new Crypt();
                    $crypt->setKey('cryptkeycryptkey');

                    return $crypt;
                });

                $cookie = new Cookie('test-cookie', 'test', time() + 3600);
                $cookie->setDI($di);
                $cookie->useEncryption(true);

                expect($cookie->getValue())->equals('test');
            }
        );
    }
}
