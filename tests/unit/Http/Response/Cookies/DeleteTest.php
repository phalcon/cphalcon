<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Response\Cookies;

use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\Unit\Http\Fake\CookieTrait;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function header_remove;
use function uniqid;
use function xdebug_get_headers;

final class DeleteTest extends AbstractHttpBase
{
    use CookieTrait;

    /**
     * Executed before each test
     *
     * @return void
     *
     * @return void
     */
    public function setUp(): void
    {
        parent::setUp();

        $this->setDiService('sessionStream');
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function testHttpResponseCookiesDelete(): void
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

        $cookies->delete($name);

        $expected = '';
        $actual   = (string)$cookies->get($name);
        $this->assertSame($expected, $actual);
    }

    /**
     * Cookies that arrived with the request are not in the internal bag. They
     * have to be deleted just the same.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17395
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testHttpResponseCookiesDeleteFromSuperglobal(): void
    {
        $name  = uniqid('nam-');
        $value = uniqid('val-');

        $_COOKIE[$name] = $value;

        $cookies = new Cookies();
        $cookies->setDI($this->container);

        $actual = $cookies->delete($name);
        $this->assertTrue($actual);

        $headers = xdebug_get_headers();
        $this->assertCount(1, $headers);
        $this->assertStringStartsWith(
            'Set-Cookie: ' . $name . '=deleted;',
            $headers[0]
        );
        $this->assertStringContainsString('Max-Age=0', $headers[0]);
    }

    /**
     * A cookie sent with a custom path must be expired with that same path,
     * otherwise the browser keeps it. The attributes come from the definition
     * the cookie stored in the session when it was sent.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17395
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testHttpResponseCookiesDeleteFromSuperglobalRestoresPath(): void
    {
        $name = uniqid('nam-');

        $this->setDiService('crypt');

        $session = $this->container->get('session');
        $session->start();

        /**
         * Emulate a previous request: the cookie was sent with a custom path
         * and domain, and is now arriving back with the request.
         */
        $cookies = new Cookies();
        $cookies->setDI($this->container);
        $cookies->set($name, uniqid('val-'), 0, '/admin', false, 'phalcon.ld');
        $cookies->send();

        header_remove();
        $_COOKIE[$name] = uniqid('val-');

        /**
         * A fresh bag, as a new request would have.
         */
        $cookies = new Cookies();
        $cookies->setDI($this->container);

        $actual = $cookies->delete($name);
        $this->assertTrue($actual);

        $headers = xdebug_get_headers();
        $this->assertCount(1, $headers);
        $this->assertStringContainsString('path=/admin', $headers[0]);
        $this->assertStringContainsString('domain=phalcon.ld', $headers[0]);
    }

    /**
     * Deleting a cookie must not require a container.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17395
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testHttpResponseCookiesDeleteFromSuperglobalWithoutDi(): void
    {
        $name  = uniqid('nam-');
        $value = uniqid('val-');

        $_COOKIE[$name] = $value;

        $cookies = new Cookies();

        $actual = $cookies->delete($name);
        $this->assertTrue($actual);

        $headers = xdebug_get_headers();
        $this->assertCount(1, $headers);
        $this->assertStringStartsWith(
            'Set-Cookie: ' . $name . '=deleted;',
            $headers[0]
        );
    }

    /**
     * An unknown cookie is still a no-op, and must not need a container to
     * find that out.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17395
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testHttpResponseCookiesDeleteUnknown(): void
    {
        $unknown = uniqid('unk-');

        $cookies = new Cookies();

        $actual = $cookies->delete($unknown);
        $this->assertFalse($actual);

        $actual = xdebug_get_headers();
        $this->assertEmpty($actual);
    }
}
