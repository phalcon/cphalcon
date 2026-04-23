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

namespace Phalcon\Tests\Unit\Http\Cookie;

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class RestoreTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpCookieRestore(): void
    {
        $this->setDiService('sessionStream');

        $name     = 'test';
        $value    = "phalcon";
        $expire   = time() - 100;
        $path     = "/";
        $secure   = true;
        $domain   = "phalcon.ld";
        $httpOnly = true;

        $cookie = $this->getCookieObject();

        $expected = $name;
        $actual   = $cookie->getName();
        $this->assertSame($expected, $actual);
        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);
        $expected = $expire;
        $actual   = $cookie->getExpiration();
        $this->assertSame($expected, $actual);
        $expected = $path;
        $actual   = $cookie->getPath();
        $this->assertSame($expected, $actual);
        $expected = $secure;
        $actual   = $cookie->getSecure();
        $this->assertSame($expected, $actual);
        $expected = $domain;
        $actual   = $cookie->getDomain();
        $this->assertSame($expected, $actual);
        $expected = $httpOnly;
        $actual   = $cookie->getHttpOnly();
        $this->assertSame($expected, $actual);

        $cookie->restore();

        $expected = $name;
        $actual   = $cookie->getName();
        $this->assertSame($expected, $actual);
        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);
        $expected = $expire;
        $actual   = $cookie->getExpiration();
        $this->assertSame($expected, $actual);
        $expected = $path;
        $actual   = $cookie->getPath();
        $this->assertSame($expected, $actual);
        $expected = $secure;
        $actual   = $cookie->getSecure();
        $this->assertSame($expected, $actual);
        $expected = $domain;
        $actual   = $cookie->getDomain();
        $this->assertSame($expected, $actual);
        $expected = $httpOnly;
        $actual   = $cookie->getHttpOnly();
        $this->assertSame($expected, $actual);
    }
}
