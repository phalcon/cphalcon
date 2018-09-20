<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc;

use Helper\Mvc\RouterTrait;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\RouterTest
 *
 * Routing tests
 *
 * @package Phalcon\Test\Unit\Mvc
 */
class RouterTest extends UnitTest
{
    use RouterTrait;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        Route::reset();
    }

    /**
     * Tests routing by use Route::convert
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-12-25
     */
    public function testUsingRouteConverters()
    {
        $this->specify(
            'The Route::convert doest not work as expected',
            function ($route, $paths) {
                $router = $this->getRouterAndSetData();

                $router->handle($route);

                expect($router->wasMatched())->true();
                expect($router->getControllerName())->equals($paths['controller']);
                expect($router->getActionName())->equals($paths['action']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_converted.php'
            ]
        );
    }

    /**
     * Tests using callbacks before match route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-01-08
     */
    public function testUsingCallbacksBeforeMatchRoute()
    {
        $this->specify(
            'The Route::beforeMatch does not use callback as expected',
            function () {
                $router= $this->getRouter(false);
                $trace = 0;

                $router
                    ->add('/static/route')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return false;
                    });

                $router
                    ->add('/static/route2')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return true;
                    });

                $router->handle();
                expect($router->wasMatched())->false();

                $router->handle('/static/route');
                expect($router->wasMatched())->false();

                $router->handle('/static/route2');
                expect($router->wasMatched())->true();

                expect($trace)->equals(2);
            }
        );
    }

    /**
     * Tests getting named route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-27
     */
    public function testGettingNamedRoutes()
    {
        $this->specify(
            'Getting named route does not return expect result',
            function () {
                $router= $this->getRouter(false);

                $usersFind = $router->add('/api/users/find')->setHttpMethods('GET')->setName('usersFind');
                $usersAdd = $router->add('/api/users/add')->setHttpMethods('POST')->setName('usersAdd');

                expect($router->getRouteByName('usersAdd'), $usersAdd);
                // second check when the same route goes from name lookup
                expect($router->getRouteByName('usersAdd'), $usersAdd);
                expect($router->getRouteById(0), $usersFind);
            }
        );
    }

    /**
     * Tests removing extra slashes
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-12-16
     */
    public function testRemovingExtraSlashes()
    {
        $this->specify(
            'Removing extra slashes does not work as expected',
            function ($route, $paths) {
                $router= $this->getRouter();
                $router->removeExtraSlashes(true);

                $router->handle($route);

                expect($router->wasMatched())->true();
                expect($router->getControllerName())->equals($paths['controller']);
                expect($router->getActionName())->equals($paths['action']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_extra_slashes.php'
            ]
        );
    }

    /**
     * Tests router
     *
     * @test
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-01-17
     */
    public function shouldMatchWithRouter()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_router.php';
        $this->specify(
            'Router does not matched correctly',
            function ($params) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutes($pathToRouterData);
                $router->handle($params['uri']);

                expect($router->getControllerName())->equals($params['controller']);
                expect($router->getActionName())->equals($params['action']);
                expect($router->getParams())->equals($params['params']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_router.php'
            ]
        );
    }

    /**
     * Tests router by using rote params
     *
     * @test
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-22
     */
    public function shouldMatchWithTheRouterByUsingHttpMethods()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_router_http.php';
        $this->specify(
            'Router does not matched correctly by using http method',
            function ($params) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutes($pathToRouterData);

                $_SERVER['REQUEST_METHOD'] = $params['method'];
                $router->handle($params['uri']);

                expect($router->getControllerName())->equals($params['controller']);
                expect($router->getActionName())->equals($params['action']);
                expect($router->getParams())->equals($params['params']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_router_http.php'
            ]
        );
    }

    /**
     * Tests router by using http method
     *
     * @test
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-22
     */
    public function shouldMatchWithGotRouterParam()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_router_param.php';
        $this->specify(
            'Router does not matched correctly by using rote params',
            function ($params) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutes($pathToRouterData);

                $router->handle($params['uri']);

                expect($router->getControllerName())->equals($params['controller']);
                expect($router->getActionName())->equals($params['action']);
                expect($router->getParams())->equals($params['params']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_got_router.php'
            ]
        );
    }

    /**
     * Tests adding a route to the router by using short path
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-01-16
     */
    public function testAddingRouteByUsingShortPaths()
    {
        $this->specify(
            'Adding a route to the router by using short path does not produce expected paths',
            function ($route, $path, $expected) {
                $router = $this->getRouter(false);
                $route = $router->add($route, $path);

                expect($route->getPaths())->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_path_provider.php'
            ]
        );
    }

    /**
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13326
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-03-24
     */
    public function shouldAttachRoute()
    {
        $this->specify(
            'Err',
            function () {
                $router = $this->getRouter(false);
                expect($router->getRoutes())->count(0);

                $router->attach(
                    new Route("/about", "About::index", ["GET", "HEAD"]),
                    Router::POSITION_FIRST
                );

                expect($router->getRoutes())->count(1);
            }
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-23
     */
    public function shouldMathWithHostnameRegex()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_router_with_hostname.php';
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($expected, $handle, $hostname) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutesAndHostNames($pathToRouterData, false);
                $_SERVER['HTTP_HOST'] = $hostname;
                $router->handle($handle);

                expect($router->getControllerName())->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_hostname_regex.php'
            ]
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2573
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function shouldMathWithHostnameRegexWithHostPort111()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_regex_router_host_port.php';
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($param, $expected) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutesAndHostNames($pathToRouterData, false);
                $_SERVER['HTTP_HOST'] = $param['hostname'] . ($param['port'] ? ':' . $param['port'] : '');
                $router->handle($param['handle']);

                expect($router->getControllerName())->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_regex_router_host_port.php'
            ]
        );
    }

    /**
     * Tests setting host name
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-04-15
     */
    public function shouldReturnCorrectController()
    {
        $pathToRouterData = include_once PATH_FIXTURES . 'mvc/router_test/data_to_router_host_name.php';
        $this->specify(
            'The Router::getControllerName does not return correct controller by using host name',
            function ($param, $expected) use ($pathToRouterData) {
                $router = $this->getRouterAndSetRoutesAndHostNames($pathToRouterData, false);
                $_SERVER['HTTP_HOST'] = $param['hostname'];
                $router->handle($param['handle']);

                expect($router->getControllerName())->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/router_test/matching_with_host_name.php'
            ]
        );
    }

    /**
     * Tests setting notFound handler
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-03-01
     */
    public function testSettingNotFoundPaths()
    {
        $this->specify(
            'Setting a group of paths to be returned when none of the defined routes are matched does not work as expected',
            function () {
                $router = $this->getRouter(false);

                $router->notFound(
                    [
                        'module'     => 'module',
                        'namespace'  => 'namespace',
                        'controller' => 'controller',
                        'action'     => 'action'
                    ]
                );

                $router->handle();

                expect($router->getControllerName())->equals('controller');
                expect($router->getActionName())->equals('action');
                expect($router->getModuleName())->equals('module');
                expect($router->getNamespaceName())->equals('namespace');
            }
        );
    }

    /**
     * Tests setting different URI source
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-04-07
     */
    public function testMatchingByUsingDifferentUriSource()
    {
        $this->specify(
            'Matching uri when setting different uri source does not work as expected',
            function () {
                $router = $this->getRouter(false);

                $_GET['_url'] = '/some/route';
                expect($router->getRewriteUri())->equals('/some/route');

                $router->setUriSource(Router::URI_SOURCE_GET_URL);
                expect($router->getRewriteUri())->equals('/some/route');

                $_SERVER['REQUEST_URI'] = '/some/route';
                $router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);

                expect($router->getRewriteUri())->equals('/some/route');

                $_SERVER['REQUEST_URI'] = '/some/route?x=1';
                expect($router->getRewriteUri())->equals('/some/route');
            }
        );
    }

    /**
     * Tests get route by name method
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-28
     */
    public function testGetRouteByName()
    {
        $this->specify(
            "Router::getRouteByName is not working properly.",
            function () {
                $router = $this->getRouter(false);
                $router->add('/test', ['controller' => 'test', 'action' => 'test'])->setName('test');
                $router->add('/test2', ['controller' => 'test', 'action' => 'test'])->setName('test2');
                $router->add('/test3', ['controller' => 'test', 'action' => 'test'])->setName('test3');
                /**
                 * We reverse routes so we first check last added route
                 */
                foreach (array_reverse($router->getRoutes()) as $route) {
                    expect($route->getName())->equals($router->getRouteByName($route->getName())->getName());
                    expect($route)->equals($router->getRouteByName($route->getName()));
                }
            }
        );
    }

    /**
     * Tests ge route by id method
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2018-06-28
     */
    public function testGetRouteById()
    {
        $this->specify(
            "Router::getRouteById is not working properly",
            function () {
                $router = $this->getRouter(false);
                $router->add('/test', ['controller' => 'test', 'action' => 'test']);
                $router->add('/test2', ['controller' => 'test', 'action' => 'test']);
                $router->add('/test3', ['controller' => 'test', 'action' => 'test']);
                /**
                 * We reverse routes so we first check last added route
                 */
                foreach (array_reverse($router->getRoutes()) as $route) {
                    expect($route->getId())->equals($router->getRoutebyId($route->getId())->getId());
                    expect($route)->equals($router->getRoutebyId($route->getId()));
                }
            }
        );
    }
}
