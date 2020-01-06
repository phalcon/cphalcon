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

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;
use Phalcon\Cli\Router\Route;

class ResetCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: reset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterRouteReset(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - reset()');

        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');
        $I->assertEquals(0, $route->getRouteId());

        $route = new Route('test');
        $route = new Route('test');
        $route = new Route('test');
        $I->assertEquals(3, $route->getRouteId());

        Route::reset();
        $route = new Route('test');
        $I->assertEquals(0, $route->getRouteId());
    }
}
