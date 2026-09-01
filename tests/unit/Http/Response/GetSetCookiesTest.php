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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function uniqid;

final class GetSetCookiesTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseGetSetCookies(): void
    {
        $name  = uniqid('nam-');
        $value = uniqid('val-');

        $cookies = new Cookies();
        $cookies->setDI($this->container);
        $cookies->set($name, $value);

        $response = new Response();
        $response->setCookies($cookies);

        $expected = $cookies;
        $actual   = $response->getCookies();
        $this->assertSame($expected, $actual);
    }
}
