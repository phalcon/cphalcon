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

final class GetPatternTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function testCliRouterRouteGetPattern(): void
    {
        Route::reset();
        Route::delimiter('/');
        $pattern = '/:module/:namespace/:task/:action/:params/:delimiter';
        $route   = new Route($pattern);

        $expected = $pattern;
        $actual   = $route->getPattern();
        $this->assertSame($expected, $actual);
    }
}
