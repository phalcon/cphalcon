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

namespace Phalcon\Tests\Integration\Mvc\Router\Route;

use IntegrationTester;
use Phalcon\Mvc\Router\Route;

/**
 * Class CompilePatternCest
 */
class CompilePatternCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: compilePattern()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-05
     */
    public function mvcRouterRouteCompilePattern(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - compilePattern()');

        /**
         * Simple
         */
        $simpleRoute = new Route(
            '/my-simple-route'
        );

        $I->assertEquals(
            '/my-simple-route',
            $simpleRoute->getCompiledPattern()
        );

        /**
         * Placeholder
         */
        $placeholderRoute = new Route(
            '/:module/:namespace/:controller/:action/:params/:int'
        );

        $I->assertEquals(
            '#^/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)$#u',
            $placeholderRoute->getCompiledPattern()
        );

        /**
         * Custom regex
         */
        $regexRoute = new Route(
            '/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)'
        );

        $I->assertEquals(
            '#^/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)/([\\w0-9\\_\\-]+)(/.*)*/([0-9]+)$#u',
            $regexRoute->getCompiledPattern()
        );
    }
}
