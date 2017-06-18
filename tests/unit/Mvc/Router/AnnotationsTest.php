<?php

namespace Phalcon\Test\Unit\Mvc\Router;

use Phalcon\Di;
use Phalcon\Http\Request;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Annotations\Adapter\Memory;

require_once PATH_DATA . '/controllers/NamespacedAnnotationController.php';

/**
 * \Phalcon\Test\Unit\Mvc\Router\AnnotationsTest
 * Tests the Phalcon\Mvc\Router\Annotations component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Router
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AnnotationsTest extends UnitTest
{
    public function _getDI()
    {
        $di = new Di();

        $di["request"] = new Request();
        $di["annotations"] = new Memory();

        return $di;
    }

    public function testRouterFullResources()
    {
        $this->specify(
            "The Annotations Router doesn't work properly",
            function ($uri, $method, $controller, $action, $params) {
                $router = new Annotations(false);

                $router->setDI($this->_getDI());

                $router->addResource("Robots", "/");
                $router->addResource("Products", "/products");
                $router->addResource("About", "/about");

                $router->handle("/products");

                expect($router->getRoutes())->count(6);

                $router = new Annotations(false);

                $router->setDI($this->_getDI());

                $router->addResource("Robots", "/");
                $router->addResource("Products", "/products");
                $router->addResource("About", "/about");

                $router->handle("/about");

                expect($router->getRoutes())->count(5);

                $router = new Annotations(false);

                $router->setDI($this->_getDI());

                $router->setDefaultNamespace("MyNamespace\\Controllers");

                $router->addResource("NamespacedAnnotation", "/namespaced");

                $router->handle("/namespaced");

                expect($router->getRoutes())->count(1);

                $router = new Annotations(false);

                $router->setDI($this->_getDI());

                $router->addResource("MyNamespace\\Controllers\\NamespacedAnnotation", "/namespaced");

                $router->handle("/namespaced/");

                $router = new Annotations(false);

                $router->setDI($this->_getDI());

                $router->addResource("Robots");
                $router->addResource("Products");
                $router->addResource("About");
                $router->addResource("Main");

                $router->handle();

                expect($router->getRoutes())->count(9);

                $route = $router->getRouteByName("save-robot");
                expect(is_object($route))->true();
                expect($route)->isInstanceOf(Route::class);

                $route = $router->getRouteByName("save-product");
                expect(is_object($route))->true();
                expect($route)->isInstanceOf(Route::class);

                $_SERVER["REQUEST_METHOD"] = $method;
                $router->handle($uri);

                expect($router->getControllerName())->equals($controller);
                expect($router->getActionName())->equals($action);
                expect($router->getParams())->equals($params);
                expect($router->isExactControllerName())->true();
            },
            [
                'examples' => [
                    [
                        "uri"        => "/products/save",
                        "method"     => "PUT",
                        "controller" => "products",
                        "action"     => "save",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/products/save",
                        "method"     => "POST",
                        "controller" => "products",
                        "action"     => "save",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/products/edit/100",
                        "method"     => "GET",
                        "controller" => "products",
                        "action"     => "edit",
                        "params"     => ["id" => "100"],
                    ],
                    [
                        "uri"        => "/products",
                        "method"     => "GET",
                        "controller" => "products",
                        "action"     => "index",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/robots/edit/100",
                        "method"     => "GET",
                        "controller" => "robots",
                        "action"     => "edit",
                        "params"     => ["id" => "100"],
                    ],
                    [
                        "uri"        => "/robots",
                        "method"     => "GET",
                        "controller" => "robots",
                        "action"     => "index",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/robots/save",
                        "method"     => "PUT",
                        "controller" => "robots",
                        "action"     => "save",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/about/team",
                        "method"     => "GET",
                        "controller" => "about",
                        "action"     => "team",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/about/team",
                        "method"     => "POST",
                        "controller" => "about",
                        "action"     => "teampost",
                        "params"     => [],
                    ],
                    [
                        "uri"        => "/",
                        "method"     => "GET",
                        "controller" => "main",
                        "action"     => "index",
                        "params"     => [],
                    ],
                ]
            ]
        );
    }
}
