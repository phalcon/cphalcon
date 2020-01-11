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

class GetCompiledPatternCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: getCompiledPattern()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function cliRouterRouteGetCompiledPattern(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - getCompiledPattern()');

        Route::reset();
        Route::delimiter('/');
        $route = new Route(
            '/:module/:namespace/:task/:action/:params/:delimiter'
        );

        $expected = '#^/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)/'
            . '([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)(/.*)*//$#';
        $I->assertEquals(
            $expected,
            $route->getCompiledPattern()
        );
    }
}
