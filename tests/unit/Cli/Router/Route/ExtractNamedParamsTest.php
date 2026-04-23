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

final class ExtractNamedParamsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterRouteExtractNamedParams(): void
    {
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

        $actual = $route->extractNamedParams($pattern);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliRouterRouteExtractNamedParamsEmpty(): void
    {
        Route::reset();
        $route = new Route('test');

        $actual = $route->extractNamedParams('');
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliRouterRouteExtractNamedParamsInvalidFirstChar(): void
    {
        Route::reset();
        $route = new Route('test');

        // {1abc} — first char '1' is not alpha → notValid branch
        $result = $route->extractNamedParams('{1abc}');
        $this->assertIsArray($result);
        // Route accumulated as-is when notValid: "{1abc}"
        $this->assertSame('{1abc}', $result[0]);
        $this->assertSame([], $result[1]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliRouterRouteExtractNamedParamsInvalidChar(): void
    {
        Route::reset();
        $route = new Route('test');

        // {a@b} — '@' is an invalid character → notValid branch
        $result = $route->extractNamedParams('{a@b}');
        $this->assertIsArray($result);
        $this->assertSame('{a@b}', $result[0]);
        $this->assertSame([], $result[1]);
    }
}
