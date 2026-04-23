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

final class GetSetPathTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpCookieGetSetPath(): void
    {
        $this->setDiService('sessionStream');

        $path   = "/";
        $cookie = $this->getCookieObject();

        $expected = $path;
        $actual   = $cookie->getPath();
        $this->assertSame($expected, $actual);

        $path = '/accounting';
        $cookie->setPath($path);

        $expected = $path;
        $actual   = $cookie->getPath();
        $this->assertSame($expected, $actual);
    }
}
