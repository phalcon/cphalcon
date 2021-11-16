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

class SetDefaultsCest
{
    /**
     * Tests Phalcon\Cli\Router :: setDefaults()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterSetDefaults(CliTester $I)
    {
        $I->wantToTest('Cli\Router - setDefaults()');

        $router = new Router(false);
        $router->handle(
            []
        );
        $I->assertNull(
            $router->getModuleName()
        );
        $I->assertNull(
            $router->getTaskName()
        );
        $I->assertNull(
            $router->getActionName()
        );
        $defaults = [
            'module' => "testModule",
            'task'   => "testTask",
            'action' => "testAction",
        ];
        $router->setDefaults($defaults);
        $router->handle(
            []
        );
        $I->assertEquals(
            $defaults['module'],
            $router->getModuleName()
        );
        $I->assertEquals(
            $defaults['task'],
            $router->getTaskName()
        );
        $I->assertEquals(
            $defaults['action'],
            $router->getActionName()
        );
    }
}
