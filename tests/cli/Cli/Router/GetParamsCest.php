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

class GetParamsCest
{
    /**
     * Tests Phalcon\Cli\Router :: getParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterGetParams(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getParams()');

        $router = new Router();
        $I->assertEquals(
            [],
            $router->getParams()
        );
        $router->handle("task action param1 param2");

        $I->assertEquals(["param1", "param2"], $router->getParams());
    }
}
