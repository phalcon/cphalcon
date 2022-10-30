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

class GetParametersCest
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

        $expected = [];
        $actual   = $router->getParameters();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $router->getParams();
        $I->assertSame($expected, $actual);

        $router->handle("task action param1 param2");

        $expected = ["param1", "param2"];
        $actual   = $router->getParameters();
        $I->assertSame($expected, $actual);

        $expected = ["param1", "param2"];
        $actual   = $router->getParams();
        $I->assertSame($expected, $actual);
    }
}
