<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http;

use Helper\CookieAwareTrait;
use Phalcon\Crypt;
use Phalcon\DI\FactoryDefault;
use Phalcon\Http\Cookie;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class CookieTest extends HttpBase
{
    use CookieAwareTrait;

    /**
     * Tests Cookie::setSignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     *
     * @expectedException        \Phalcon\Http\Cookie\Exception
     * @expectedExceptionMessage The cookie's key should be at least 32 characters long. Current length is 10.
     */
    public function shouldThrowExceptionIfSignKeyIsUnenoughLong()
    {
        $this->specify(
            'Cookie does not validate sign key cipher length as expected',
            function () {
                $cookie = new Cookie('test-cookie', 'test', time() + 3600);
                $cookie->setSignKey('1234567890');
            }
        );
    }

    /**
     * Tests Cookie::getValue using message authentication code and request forgery
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-05-06
     *
     * @expectedException        \Phalcon\Crypt\Mismatch
     * @expectedExceptionMessage Hash does not match.
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
            }
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
    /**
     * Tests the internal cookies property.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12978
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-09-02
     */
    public function shouldWorkWithoutInitializeInternalCookiesProperty()
    {
        $this->specify(
            "The internal cookies property is not initialized or iterable",
            function () {
                expect((new Cookies())->send())->true();
            }
        );
    }}
