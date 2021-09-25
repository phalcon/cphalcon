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

class GetMatchedRouteCest
{
    /**
     * Tests Phalcon\Cli\Router :: getMatchedRoute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterGetMatchedRoute(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getMatchedRoute()');

        $router = new Router();

        $router->add(
            'route1',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

        $router->add(
            'route2',
            [
                'module' => 'devtools2',
                'task'   => 'main2',
                'action' => 'hello2',
            ]
        );
        $router->handle('route2');
        $I->assertEquals("route2", $router->getMatchedRoute()->getPattern());
    }
}
