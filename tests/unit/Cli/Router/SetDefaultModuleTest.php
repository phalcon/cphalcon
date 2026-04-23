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

final class SetDefaultModuleTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterSetDefaultModule(): void
    {
        $router = new Router(false);

        $expected = "";
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $router->handle("");

        $expected = "";
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $router->setDefaultModule("test");
        $router->handle("");

        $expected = "test";
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);
    }
}
