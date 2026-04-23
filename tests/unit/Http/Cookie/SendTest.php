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
}
