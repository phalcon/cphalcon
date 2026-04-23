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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class GetRouteByIdTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-28
     */
    public function testGetRouteById(): void
    {
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
                $route->getRouteId()
            );

            $this->assertSame($route, $actual);
        }
    }

    /**
     * @author Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since  2012-08-27
     */
    public function testGettingNamedRoutes(): void
    {
        Route::reset();

        $router = $this->getRouter(false);

        $usersFind = $router
            ->add('/api/users/find')
            ->setHttpMethods('GET')
            ->setName('usersFind')
        ;
        $usersAdd  = $router
            ->add('/api/users/add')
            ->setHttpMethods('POST')
            ->setName('usersAdd')
        ;

        $actual = $router->getRouteById(99);
        $this->assertFalse($actual);

        $expected = $usersFind;
        $actual   = $router->getRouteById(0);
        $this->assertSame($expected, $actual);

        $expected = $usersAdd;
        $actual   = $router->getRouteById(1);
        $this->assertSame($expected, $actual);
    }
}
