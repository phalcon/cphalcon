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
 * Class GetRouteByIdCest
 */
class GetRouteByIdCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: getRouteById()
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-28
     */
    public function testGetRouteById(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - getRouteById()');

        $router = $this->getRouter(false);

        $router->add(
            '/test',
            [
                'controller' => 'test',
                'action'     => 'test',
            ]
        );

        $router->add(
            '/test2',
            [
                'controller' => 'test',
                'action'     => 'test',
            ]
        );

        $router->add(
            '/test3',
            [
                'controller' => 'test',
                'action'     => 'test',
            ]
        );


        /**
         * We reverse routes so we first check last added route
         */
        foreach (array_reverse($router->getRoutes()) as $route) {
            $expected = $router->getRoutebyId($route->getId());
            $actual   = $route;

            $I->assertEquals($expected, $actual);
        }
    }
}
