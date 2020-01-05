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

class ExtractNamedParamsCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: extractNamedParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterRouteExtractNamedParams(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - extractNamedParams()');

        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');

        $pattern  = '{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country';
        $expected = [
            '([a-z\-]+) ([a-z\-]+) this-is-a-country',
            [
                'task'   => 1,
                'action' => 2,
            ],
        ];
        $I->assertEquals(
            $expected,
            $route->extractNamedParams($pattern)
        );
    }
}
