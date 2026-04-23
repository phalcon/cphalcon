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

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Mvc\Router\Exception;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class CompilePatternTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-05
     */
    public function testMvcRouterRouteCompilePattern(): void
    {
        $route       = '/my-simple-route';
        $simpleRoute = new Route($route);

        $expected = $route;
        $actual   = $simpleRoute->getCompiledPattern();
        $this->assertSame($expected, $actual);

        /**
         * Placeholder
         */
        $route            = '/:module/:namespace/:controller/:action/:params/:int';
        $placeholderRoute = new Route($route);

        $expected = '#^/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)$#u';
        $actual   = $placeholderRoute->getCompiledPattern();
        $this->assertSame($expected, $actual);

        /**
         * Custom regex
         */
        $route      = '/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)';
        $regexRoute = new Route($route);

        $expected = '#^/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)$#u';
        $actual   = $regexRoute->getCompiledPattern();
        $this->assertSame($expected, $actual);
    }
}
