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

namespace Phalcon\Tests\Unit\Http\Response\Cookies;

use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\Unit\Http\Fake\CookieTrait;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function time;
use function uniqid;

final class GetSetTest extends AbstractHttpBase
{
    use CookieTrait;

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        parent::setUp();
        $this->setDiService('sessionStream');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13464
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-01-20
     */
    public function testHttpCookieSetHttpOnly(): void
    {
        $this->checkExtensionIsLoaded('xdebug');

        $this->setDiService('crypt');

        $cookie = new Cookies();
        $cookie->setDI($this->container);
        $cookie->useEncryption(false);

        $nameOne   = uniqid('nam-');
        $nameTwo   = uniqid('nam-');
        $nameThree = uniqid('nam-');
        $value     = uniqid('val-');
        $time      = time() + 86400;
        $path      = '/';
        $domain    = 'localhost';

        $cookie->set($nameOne, $value, $time, $path, false, $domain, true);
        $cookie->set($nameTwo, $value, $time, $path, false, $domain, false);
        $cookie->set($nameThree, $value, $time, $path, false, $domain);
        $cookie->send();

        $cookieOne   = $this->getCookie($nameOne);
        $cookieTwo   = $this->getCookie($nameTwo);
        $cookieThree = $this->getCookie($nameThree);

        $expected = 'HttpOnly';
        $this->assertStringContainsString($expected, $cookieOne);

        $expected = 'HttpOnly';
        $this->assertStringNotContainsString($expected, $cookieTwo);

        $expected = 'HttpOnly';
        $this->assertStringNotContainsString($expected, $cookieThree);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/15129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-10
     */
    public function testHttpCookieSetOptions(): void
    {
        $this->checkExtensionIsLoaded('xdebug');

        $this->setDiService('crypt');

        $cookies = new Cookies();
        $cookies->setDI($this->container);
        $cookies->useEncryption(false);

        $nameOne   = uniqid('nam-');
        $nameTwo   = uniqid('nam-');
        $nameThree = uniqid('nam-');
        $nameFour  = uniqid('nam-');
        $value     = uniqid('val-');
        $time      = time() + 86400;
        $path      = '/';
        $domain    = 'localhost';

        $cookies->set(
            $nameOne,
            $value,
            $time,
            $path,
            false,
            $domain,
            false,
            [
                'samesite' => 'None',
            ]
        );
        $cookies->set(
            $nameTwo,
            $value,
            $time,
            $path,
            false,
            $domain,
            false,
            [
                'samesite' => 'Lax',
            ]
        );
        $cookies->set(
            $nameThree,
            $value,
            $time,
            $path,
            false,
            $domain,
            false,
            [
                'samesite' => 'Strict',
            ]
        );
        $cookies->set(
            $nameFour,
            $value,
            $time,
            $path,
            false,
            $domain,
            false
        );
        $cookies->send();

        $cookieOne   = $this->getCookie($nameOne);
        $cookieTwo   = $this->getCookie($nameTwo);
        $cookieThree = $this->getCookie($nameThree);
        $cookieFour  = $this->getCookie($nameFour);

        $expected = 'SameSite=None';
        $this->assertStringContainsString($expected, $cookieOne);

        $expected = 'SameSite=Lax';
        $this->assertStringContainsString($expected, $cookieTwo);

        $expected = 'SameSite=Strict';
        $this->assertStringContainsString($expected, $cookieThree);

        $expected = 'SameSite';
        $this->assertStringNotContainsString($expected, $cookieFour);
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function testHttpResponseCookiesGetSet(): void
    {
        $name  = uniqid('nam-');
        $value = uniqid('val-');

        $this->setDiService('crypt');

        $cookies = new Cookies();
        $cookies->setDI($this->container);
        $cookies->set($name, $value);

        $expected = $value;
        $actual   = (string)$cookies->get($name);
        $this->assertSame($expected, $actual);
    }
}
