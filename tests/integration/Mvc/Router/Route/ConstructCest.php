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

use function uniqid;

class ConstructCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function mvcRouterRouteConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - __construct()');

        $pattern = uniqid();
        $route   = new Route($pattern);

        $expected = $pattern;
        $actual   = $route->getPattern();
        $I->assertSame($expected, $actual);
    }
}
