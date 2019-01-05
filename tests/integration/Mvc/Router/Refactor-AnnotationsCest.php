<?php

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
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Controllers\NamespacedAnnotationController;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function is_object;

class AnnotationsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiRequest();
        $this->setDiAnnotations();
    }

    public function testRouterFullResources(IntegrationTester $I)
    {
        require_once dataFolder('fixtures/controllers/NamespacedAnnotationController.php');

        $routes = $this->getRoutes();
        foreach ($routes as $route) {
            $uri        = $route['uri'];
            $method     = $route['method'];
            $controller = $route['controller'];
            $action     = $route['action'];
            $params     = $route['params'];

            $container = $this->getDi();
            $router    = new Annotations(false);

            $router->setDI($container);

            $router->addResource("Phalcon\Test\Controllers\Robots", "/");
            $router->addResource("Phalcon\Test\Controllers\Products", "/products");
            $router->addResource("Phalcon\Test\Controllers\About", "/about");

            $router->handle("/products");

            $expected = 6;
            $actual   = $router->getRoutes();
            $I->assertCount($expected, $actual);

            $router = new Annotations(false);

            $router->setDI($container);
            $router->addResource("Phalcon\Test\Controllers\Robots", "/");
            $router->addResource("Phalcon\Test\Controllers\Products", "/products");
            $router->addResource("Phalcon\Test\Controllers\About", "/about");
            $router->handle("/about");

            $expected = 5;
            $actual   = $router->getRoutes();
            $I->assertCount($expected, $actual);

            $router = new Annotations(false);
            $router->setDI($container);
            $router->setDefaultNamespace("MyNamespace\\Controllers");
            $router->addResource("NamespacedAnnotation", "/namespaced");
            $router->handle("/namespaced");

            $expected = 1;
            $actual   = $router->getRoutes();
            $I->assertCount($expected, $actual);

            $router = new Annotations(false);
            $router->setDI($container);
            $router->addResource("MyNamespace\\Controllers\\NamespacedAnnotation", "/namespaced");
            $router->handle("/namespaced/");


            $router = new Annotations(false);

            $router->setDI($container);
            $router->addResource("Phalcon\Test\Controllers\Robots");
            $router->addResource("Phalcon\Test\Controllers\Products");
            $router->addResource("Phalcon\Test\Controllers\About");
            $router->addResource("Phalcon\Test\Controllers\Main");
            $router->handle("/");

            $expected = 9;
            $actual   = $router->getRoutes();
            $I->assertCount($expected, $actual);

            $route = $router->getRouteByName("save-robot");
            $I->assertTrue(is_object($route));

            $class = Route::class;
            $I->assertInstanceOf($class, $route);

            $route = $router->getRouteByName("save-product");
            $I->assertTrue(is_object($route));

            $class = Route::class;
            $I->assertInstanceOf($class, $route);

            $_SERVER["REQUEST_METHOD"] = $method;
            $router->handle($uri);

            $expected = $controller;
            $actual   = $router->getControllerName();
            $I->assertEquals($expected, $actual);
            $expected = $action;
            $actual   = $router->getActionName();
            $I->assertEquals($expected, $actual);
            $expected = $params;
            $actual   = $router->getParams();
            $I->assertEquals($expected, $actual);
            $I->assertTrue($router->isExactControllerName());
        }
    }

    private function getRoutes(): array
    {
        return [
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
        ];
    }
}
