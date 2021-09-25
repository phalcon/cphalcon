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

namespace Phalcon\Tests\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\Fixtures\Traits\RouterTrait;

class GetRouteByIdCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: getRouteById()
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
            $actual = $router->getRoutebyId(
                $route->getId()
            );

            $I->assertEquals($route, $actual);
        }
    }

    /**
     * Tests getting named route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since  2012-08-27
     */
    public function testGettingNamedRoutes(IntegrationTester $I)
    {
        Route::reset();

        $router = $this->getRouter(false);

        $usersFind = $router->add('/api/users/find')->setHttpMethods('GET')->setName('usersFind');
        $usersAdd  = $router->add('/api/users/add')->setHttpMethods('POST')->setName('usersAdd');

        $I->assertEquals(
            $usersFind,
            $router->getRouteById(0)
        );

        $I->assertEquals(
            $usersAdd,
            $router->getRouteById(1)
        );
    }
}
