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
use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-29
     */
    public function testCliRouterGetSetDI(): void
    {
        $router = new Router();

        $container = new Di();

        $router->setDI($container);
        $actual = $router->getDI();

        $class = Di::class;
        $this->assertInstanceOf($class, $actual);

        $this->assertSame($container, $actual);
    }
}
