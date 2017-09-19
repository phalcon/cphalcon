<?php

namespace Phalcon\Test\Unit\Mvc\Router;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Router\GroupTest
 * Tests the Phalcon\Mvc\Router\Group component
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
class GroupTest extends UnitTest
{
    public function testGroups()
    {
        $this->specify(
            "Router Groups don't work properly",
            function () {
                \Phalcon\Mvc\Router\Route::reset();

                $router = new \Phalcon\Mvc\Router(false);

                $blog = new \Phalcon\Mvc\Router\Group(
                    [
                        "module"     => "blog",
                        "controller" => "index",
                    ]
                );

                $blog->setPrefix("/blog");

                $blog->add(
                    "/save",
                    [
                        "action" => "save",
                    ]
                );

                $blog->add(
                    "/edit/{id}",
                    [
                        "action" => "edit",
                    ]
                );

                $blog->add(
                    "/about",
                    [
                        "controller" => "about",
                        "action"     => "index",
                    ]
                );

                $router->mount($blog);

                $routes = [
                    "/blog/save" => [
                        "module"     => "blog",
                        "controller" => "index",
                        "action"     => "save",
                    ],
                    "/blog/edit/1" => [
                        "module"     => "blog",
                        "controller" => "index",
                        "action"     => "edit"
                    ],
                    "/blog/about" => [
                        "module"     => "blog",
                        "controller" => "about",
                        "action"     => "index",
                    ],
                ];

                foreach ($routes as $route => $paths) {
                    $router->handle($route);

                    expect($router->wasMatched())->true();

                    expect($paths["module"])->equals($router->getModuleName());
                    expect($paths["controller"])->equals($router->getControllerName());
                    expect($paths["action"])->equals($router->getActionName());

                    expect($blog)->equals($router->getMatchedRoute()->getGroup());
                }
            }
        );
    }

    public function testHostnameRouteGroup()
    {
        $this->specify(
            "Router Groups with hostname don't work properly",
            function ($actualHost, $expectedHost, $controller) {
                \Phalcon\Mvc\Router\Route::reset();

                $di = new \Phalcon\DI();

                $di->set(
                    "request",
                    function () {
                        return new \Phalcon\Http\Request();
                    }
                );

                $router = new \Phalcon\Mvc\Router(false);

                $router->setDI($di);

                $router->add(
                    "/edit",
                    [
                        "controller" => "posts3",
                        "action"     => "edit3",
                    ]
                );

                $group = new \Phalcon\Mvc\Router\Group();

                $group->setHostname("my.phalconphp.com");

                $group->add(
                    "/edit",
                    [
                        "controller" => "posts",
                        "action"     => "edit",
                    ]
                );

                $router->mount($group);

                $_SERVER["HTTP_HOST"] = $actualHost;

                $router->handle("/edit");

                expect($router->getControllerName())->equals($controller);
                expect($router->getMatchedRoute()->getHostname())->equals($expectedHost);
            },
            [
                "examples" => $this->hostnamedRoutesProvider(),
            ]
        );
    }

    protected function hostnamedRoutesProvider()
    {
        return [
            ["localhost", null, "posts3"],
            ["my.phalconphp.com", "my.phalconphp.com", "posts"],
            [null, null, "posts3"],
        ];
    }

    public function testHostnameRegexRouteGroup()
    {
        $this->specify(
            "Router Groups with regular expressions don't work properly",
            function ($actualHost, $expectedHost, $controller) {
                \Phalcon\Mvc\Router\Route::reset();

                $di = new \Phalcon\DI();

                $di->set(
                    "request",
                    function () {
                        return new \Phalcon\Http\Request();
                    }
                );

                $router = new \Phalcon\Mvc\Router(false);

                $router->setDI($di);

                $router->add(
                    "/edit",
                    [
                        "controller" => "posts3",
                        "action"     => "edit3",
                    ]
                );

                $group = new \Phalcon\Mvc\Router\Group();

                $group->setHostname("([a-z]+).phalconphp.com");

                $group->add(
                    "/edit",
                    [
                        "controller" => "posts",
                        "action"     => "edit",
                    ]
                );

                $router->mount($group);

                $_SERVER["HTTP_HOST"] = $actualHost;

                $router->handle("/edit");

                expect($router->getControllerName())->equals($controller);
                expect($router->getMatchedRoute()->getHostname())->equals($expectedHost);
            },
            [
                "examples" => $this->hostnamedRegexRoutesProvider(),
            ]
        );
    }

    protected function hostnamedRegexRoutesProvider()
    {
        return [
            ["localhost", null, "posts3"],
            ["my.phalconphp.com", "([a-z]+).phalconphp.com", "posts"],
            [null, null, "posts3"],
        ];
    }
}
