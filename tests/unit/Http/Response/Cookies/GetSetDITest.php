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

use Phalcon\Di\Di;
use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function testHttpResponseCookiesGetSetDI(): void
    {
        $container = new Di();

        $cookies = new Cookies();
        $cookies->setDI($container);

        $expected = $container;
        $actual   = $cookies->getDI();
        $this->assertSame($expected, $actual);

        $class  = Di::class;
        $actual = $cookies->getDI();
        $this->assertInstanceOf($class, $actual);
    }
}
