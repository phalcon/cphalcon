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

namespace Phalcon\Test\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;

class ConstructCest
{
    /**
     * Tests Phalcon\Cli\Router :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterConstruct(CliTester $I)
    {
        $I->wantToTest('Cli\Router - __construct()');
        $router = new Router(false);

        $I->assertInstanceOf('Phalcon\Cli\Router', $router);

        $I->assertEquals([], $router->getRoutes());

        //Should contain 2 default routes.
        $router = new Router();

        $I->assertInstanceOf('Phalcon\Cli\Router', $router);
        $routes = $router->getRoutes();
        $I->assertCount(2, $routes);

        $I->assertEquals("#^(?: )?([a-zA-Z0-9\\_\\-]+)[ ]{0,1}$#", $routes[0]->getPattern());
        $I->assertEquals("#^(?: )?([a-zA-Z0-9\\_\\-]+) ([a-zA-Z0-9\\.\\_]+)( .*)*$#", $routes[1]->getPattern());
    }
}
