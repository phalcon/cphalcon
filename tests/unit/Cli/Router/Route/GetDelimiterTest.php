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

final class GetDelimiterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function testCliRouterRouteGetDelimiter(): void
    {
        $store = Route::getDelimiter();

        Route::delimiter(Route::DEFAULT_DELIMITER);
        $route = new Route("test");

        // Default delimiter
        $expected = " ";
        $actual   = Route::DEFAULT_DELIMITER;
        $this->assertSame($expected, $actual);

        $expected = " ";
        $actual   = $route->getDelimiter();
        $this->assertSame($expected, $actual);

        $route = new Route("test");
        $route::delimiter("-");

        $expected = " ";
        $actual   = Route::DEFAULT_DELIMITER;
        $this->assertSame($expected, $actual);

        $expected = "-";
        $actual   = $route->getDelimiter();
        $this->assertSame($expected, $actual);

        $route = new Route("test");
        $route::delimiter("-");

        Route::delimiter($store);
    }
}
