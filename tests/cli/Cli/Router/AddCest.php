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

namespace Phalcon\Tests\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;

class AddCest
{
    /**
     * Tests Phalcon\Cli\Router :: add()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterAdd(CliTester $I)
    {
        $I->wantToTest('Cli\Router - add()');

        Router\Route::reset();
        $router = new Router(false);
        $I->assertSame([], $router->getRoutes());

        $router->add(
            'route',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );
        $router->handle('route');

        $routes = $router->getRoutes();
        $class  = Router\Route::class;
        $actual = $routes[0];
        $I->assertInstanceOf($class, $actual);
    }
}
