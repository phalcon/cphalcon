<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

/**
 * Class GetRouteByNameCest
 */
class GetRouteByNameCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: getRouteByName()
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-28
     */
    public function testGetRouteByName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - getRouteByName()');

        $router = $this->getRouter(false);

        $router->add('/test', ['controller' => 'test', 'action' => 'test'])->setName('test');
        $router->add('/test2', ['controller' => 'test', 'action' => 'test'])->setName('test2');
        $router->add('/test3', ['controller' => 'test', 'action' => 'test'])->setName('test3');

        /**
         * We reverse routes so we first check last added route
         */
        foreach (array_reverse($router->getRoutes()) as $route) {
            $expected = $router->getRouteByName($route->getName());
            $actual   = $route;

            $I->assertEquals($expected, $actual);
        }
    }
}
