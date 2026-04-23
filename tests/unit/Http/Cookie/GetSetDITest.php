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

use Phalcon\Di\Di;
use Phalcon\Http\Cookie;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function testHttpCookieGetSetDI(): void
    {
        $name      = uniqid('nam-');
        $container = new Di();
        $cookie    = new Cookie($name);
        $cookie->setDI($container);

        $expected = $container;
        $actual   = $cookie->getDI();
        $this->assertSame($expected, $actual);

        $class  = Di::class;
        $actual = $cookie->getDI();
        $this->assertInstanceOf($class, $actual);
    }
}
