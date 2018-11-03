<?php

/**
 * Trait for Router test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Helper\Mvc;

use Phalcon\Di;
use Phalcon\Mvc\Router;
use Phalcon\Http\Request;

/**
 * Helper\Mvc\RouterTrait
 *
 * Routing trait
 *
 * @package Helper\Mvc
 */
trait RouterTrait
{
    /**
     * Add method and return route
     *
     * @param Router $router
     * @param array $data
     * @return \Phalcon\Mvc\Router\Route
     */
    protected function getRouteAndSetRouteMethod($router, array $data)
    {
        $methodName = $data['methodName'];

        if (isset($data[1])) {
            return $router->$methodName($data[0], $data[1]);
        }

        return $router->$methodName($data[0]);
    }

    /**
     * get router and set methods
     *
     * @param array $settings
     * @param bool $defaultRoutes
     * @return Router
     */
    protected function getRouterAndSetRoutes(array $settings, $defaultRoutes = true)
    {
        $router = $this->getRouter($defaultRoutes);

        foreach ($settings as $data) {
            $this->getRouteAndSetRouteMethod($router, $data);
        }

        return $router;
    }

    /**
     * get router and set methods and set host name
     *
     * @param array $settings
     * @param bool $defaultRoutes
     * @return Router
     */
    protected function getRouterAndSetRoutesAndHostNames(array $settings, $defaultRoutes = true)
    {
        $router = $this->getRouter($defaultRoutes);

        foreach ($settings as $data) {
            $route = $this->getRouteAndSetRouteMethod($router, $data);

            if (isset($data['hostname'])) {
                $route->setHostname($data['hostname']);
            }
        }

        return $router;
    }

    /**
     * get router and set params for Phalcon\Test\Unit\Mvc\RouterTest::testUsingRouteConverters() test
     *
     * @return Router
     */
    protected function getRouterAndSetData()
    {
        $router= $this->getRouter();

        $router->add('/{controller:[a-z\-]+}/{action:[a-z\-]+}/this-is-a-country')
            ->convert('controller', function ($controller) {
                return str_replace('-', '', $controller);
            })
            ->convert('action', function ($action) {
                return str_replace('-', '', $action);
            });

        $router->add('/([A-Z]+)/([0-9]+)', [
            'controller' => 1,
            'action' => 'default',
            'id' => 2,
        ])->convert('controller', function ($controller) {
            return strtolower($controller);
        })->convert('action', function ($action) {
            return $action == 'default' ? 'index' : $action;
        })->convert('id', function ($id) {
            return strrev($id);
        });

        return $router;
    }

    /**
     * set new router, params and get it
     *
     * @param bool $defaultRoutes
     * @return Router
     */
    protected function getRouter($defaultRoutes = true)
    {
        $router = new Router($defaultRoutes);

        $di = new Di;
        $di->setShared('request', function () {
            return new Request;
        });

        $router->setDI($di);

        return $router;
    }
}
