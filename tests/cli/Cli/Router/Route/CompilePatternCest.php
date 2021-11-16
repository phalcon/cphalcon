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
use Codeception\Example;
use Phalcon\Cli\Router\Route;

class CompilePatternCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: compilePattern()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-05
     * @dataProvider getExamples
     */
    public function cliRouterRouteCompilePattern(CliTester $I, Example $example)
    {
        $I->wantToTest('Cli\Router\Route - compilePattern() ' . $example[0]);

        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');
        $I->assertEquals(
            $example[2],
            $route->compilePattern($example[1])
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'module',
                '/:module',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                'task',
                '/:task',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                'namespace',
                '/:namespace',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                'action',
                '/:action',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                'params',
                '/:params',
                '#^(/.*)*$#',
            ],
            [
                'delimiter',
                ':delimiter',
                '/',
            ],
            [
                'all',
                '/:module/:namespace/:task/:action/:params/:delimiter',
                '#^/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)(/.*)*//$#',
            ],
        ];
    }
}
