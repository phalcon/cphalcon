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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetParametersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterGetParams(): void
    {
        $router = new Router();

        $expected = [];
        $actual   = $router->getParameters();
        $this->assertSame($expected, $actual);

        $expected = [];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);

        $router->handle("task action param1 param2");

        $expected = ["param1", "param2"];
        $actual   = $router->getParameters();
        $this->assertSame($expected, $actual);

        $expected = ["param1", "param2"];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }
}
