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

class WasMatchedCest
{
    /**
     * Tests Phalcon\Cli\Router :: wasMatched()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterWasMatched(CliTester $I)
    {
        $I->wantToTest('Cli\Router - wasMatched()');

        $router = new Router();
        $I->assertFalse($router->wasMatched());
        $router->add(
            'route1',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );
        $router->handle('route1');
        $I->assertTrue($router->wasMatched());
    }
}
