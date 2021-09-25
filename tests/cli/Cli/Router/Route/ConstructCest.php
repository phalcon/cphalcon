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

namespace Phalcon\Tests\Cli\Cli\Router\Route;

use CliTester;
use Phalcon\Cli\Router\Route;
use Phalcon\Cli\Router\RouteInterface;

class ConstructCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function cliRouterRouteConstruct(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - __construct()');

        $route = new Route('test');
        $I->assertInstanceOf(RouteInterface::class, $route);
        $I->assertInstanceOf(Route::class, $route);
    }
}
