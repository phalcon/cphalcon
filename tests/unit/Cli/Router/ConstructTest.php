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

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterConstruct(): void
    {
        Router\Route::reset();
        $router = new Router(false);

        $class  = Router::class;
        $actual = $router;
        $this->assertInstanceOf($class, $actual);

        $expected = [];
        $actual   = $router->getRoutes();
        $this->assertSame($expected, $actual);

        //Should contain 2 default routes.
        $router = new Router();

        $class  = Router::class;
        $actual = $router;
        $this->assertInstanceOf($class, $actual);

        $routes   = $router->getRoutes();
        $expected = 2;
        $actual   = count($router->getRoutes());
        $this->assertSame($expected, $actual);

        $expected = "#^(?: )?([a-zA-Z0-9\\_\\-]+)[ ]{0,1}$#";
        $actual   = $routes[0]->getPattern();
        $this->assertSame($expected, $actual);

        $expected = "#^(?: )?([a-zA-Z0-9\\_\\-]+) ([a-zA-Z0-9\\.\\_]+)( .*)*$#";
        $actual   = $routes[1]->getPattern();
        $this->assertSame($expected, $actual);
    }
}
