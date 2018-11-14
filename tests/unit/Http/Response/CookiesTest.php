<?php

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Di;
use Phalcon\Http\Cookie;
use Phalcon\Http\CookieInterface;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use Phalcon\Session\Adapter\Files as SessionAdapter;

/**
 * Phalcon\Test\Unit\Http\Response\Http\CookiesTest
 * Tests the Phalcon\Http\Response\Cookies component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Response
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CookiesTest extends HttpBase
{
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
    }

    /**
     * Tests getCookies is work.
     * @author limx <715557344@qq.com>
     */
    public function testGetCookies()
    {
        $cookies = new Cookies();

        Di::reset();
        $di = new Di();
        $di->set('response', function () {
            return new Response();
        });
        $di->set('session', function () {
            return new SessionAdapter();
        });

        $cookies->setDI($di);

        $cookies->set('x-token', '1bf0bc92ed7dcc80d337a5755f879878');
        $cookies->set('x-user-id', 1);

        $this->specify(
            "The cookies is not a array.",
            function () use ($cookies) {
                expect(is_array($cookies->getCookies()))->true();
            }
        );

        $this->specify(
            "The cookie is not instance of CookieInterface",
            function () use ($cookies) {
                $cookieArray = $cookies->getCookies();
                expect($cookieArray['x-token'] instanceof CookieInterface)->true();
                expect($cookieArray['x-user-id'] instanceof CookieInterface)->true();
            }
        );

        $this->specify(
            "The cookie is not correct.",
            function () use ($cookies) {
                /** @var Cookie[] $cookieArray */
                $cookieArray = $cookies->getCookies();
                expect($cookieArray['x-token']->getValue())->equals('1bf0bc92ed7dcc80d337a5755f879878');
                expect($cookieArray['x-user-id']->getValue())->equals(1);
            }
        );
    }
}
