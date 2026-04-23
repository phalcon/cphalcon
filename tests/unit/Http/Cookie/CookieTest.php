<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Http\Cookie;

use Exception;
use Phalcon\Http\Cookie;
use Phalcon\Tests\Unit\Http\Fake\CookieTrait;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function explode;
use function uniqid;

final class CookieTest extends AbstractHttpBase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-05-06
     */
    public function testHttpCookieDecryptValueByUsingMessageAuthenticationCode(): void
    {
        $this->checkExtensionIsLoaded('xdebug');

        $this->setDiService('crypt');

        $name  = uniqid('nam-');
        $value = uniqid('val-');
        $time  = time() + 3600;

        $cookie = new Cookie($name, $value, $time);

        $cookie->setDI($this->container);
        $cookie->useEncryption(true);
        $cookie->setSignKey('12345678901234567890123456789012');

        $cookie->send();

        $this->setProtectedProperty($cookie, 'isRead', false);

        $rawCookie = $this->getCookie($name);
        $rawValue  = explode(';', $rawCookie)[0];

        $_COOKIE[$name] = $rawValue;

        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-05-06
     */
    public function testHttpCookieThrowExceptionIfMessageAuthenticationCodeIsMismatch(): void
    {
        /**
         * TODO: Check the exception
         */
        $this->markTestSkipped('TODO: Check the exception');

        $this->checkExtensionIsLoaded('xdebug');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Hash does not match.');

        $this->setDiService('crypt');

        $container = $this->getDi();

        $cookieName  = 'test-signed-name1';
        $cookieValue = 'test-signed-value';

        $cookie = new Cookie(
            $cookieName,
            $cookieValue,
            time() + 3600
        );

        $cookie->setDI($container);
        $cookie->useEncryption(true);
        $cookie->setSignKey('12345678901234567890123456789012');

        $cookie->send();

        $this->setProtectedProperty($cookie, 'isRead', false);

        $rawCookie = $this->getCookie($cookieName);
        $rawValue  = explode(';', $rawCookie)[0];

        $originalValue = mb_substr($rawValue, 64);

        $_COOKIE[$cookieName] = str_repeat('X', 64) . $originalValue;

        $cookie->getValue();
    }
}
