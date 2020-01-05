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

class GetSetNameCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: getName()/setName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function cliRouterRouteGetSetName(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - getName()/setName()');

        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');

        $I->assertEquals('', $route->getName());

        $route->setName('otherRoute');
        $I->assertEquals('otherRoute', $route->getName());
    }
}
