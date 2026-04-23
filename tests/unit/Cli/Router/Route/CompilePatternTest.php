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

namespace Phalcon\Tests\Unit\Cli\Router\Route;

use Phalcon\Cli\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class CompilePatternTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '/:module',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                '/:task',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                '/:namespace',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                '/:action',
                '#^/([a-zA-Z0-9\_\-]+)$#',
            ],
            [
                '/:params',
                '#^(/.*)*$#',
            ],
            [
                ':delimiter',
                '/',
            ],
            [
                '/:module/:namespace/:task/:action/:params/:delimiter',
                '#^/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)/([a-zA-Z0-9\_\-]+)(/.*)*//$#',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function testCliRouterRouteCompilePattern(
        string $pattern,
        string $expected
    ): void {
        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');

        $actual = $route->compilePattern($pattern);
        $this->assertSame($expected, $actual);
    }
}
