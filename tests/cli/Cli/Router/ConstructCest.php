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

        Router\Route::reset();
        $router = new Router(false);

        $class  = Router::class;
        $actual = $router;
        $I->assertInstanceOf($class, $actual);

        $expected = [];
        $actual   = $router->getRoutes();
        $I->assertSame($expected, $actual);

        //Should contain 2 default routes.
        $router = new Router();

        $class  = Router::class;
        $actual = $router;
        $I->assertInstanceOf($class, $actual);

        $routes   = $router->getRoutes();
        $expected = 2;
        $actual   = count($router->getRoutes());
        $I->assertSame($expected, $actual);

        $expected = "#^(?: )?([a-zA-Z0-9\\_\\-]+)[ ]{0,1}$#";
        $actual   = $routes[0]->getPattern();
        $I->assertSame($expected, $actual);

        $expected = "#^(?: )?([a-zA-Z0-9\\_\\-]+) ([a-zA-Z0-9\\.\\_]+)( .*)*$#";
        $actual   = $routes[1]->getPattern();
        $I->assertSame($expected, $actual);
    }
}
