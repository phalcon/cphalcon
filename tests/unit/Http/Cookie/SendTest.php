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

use Phalcon\Http\Cookie;
use Phalcon\Http\Cookie\CookieInterface;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class SendTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpCookieSend(): void
    {
        $this->setDiService('sessionStream');

        $cookie = $this->getCookieObject();

        $result = $cookie->send();
        $this->assertInstanceOf(CookieInterface::class, $result);
    }

    /**
     * A cookie with a non-empty definition and no DI container must not
     * fatal when storing the definition in session is impossible
     *
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testHttpCookieSendNoContainer(): void
    {
        $cookie = new Cookie(
            'test',
            'phalcon',
            time() - 100
        );

        $result = $cookie->send();
        $this->assertInstanceOf(CookieInterface::class, $result);
    }
}
