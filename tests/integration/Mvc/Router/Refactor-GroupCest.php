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
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GroupCest
{
    use DiTrait;

    public function testGroups(IntegrationTester $I)
    {
        Route::reset();
        $router = new Router(false);
        $blog   = new Group(
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
            "/blog/save"   => [
                "module"     => "blog",
                "controller" => "index",
                "action"     => "save",
            ],
            "/blog/edit/1" => [
                "module"     => "blog",
                "controller" => "index",
                "action"     => "edit",
            ],
            "/blog/about"  => [
                "module"     => "blog",
                "controller" => "about",
                "action"     => "index",
            ],
        ];

        foreach ($routes as $route => $paths) {
            $router->handle($route);

            $actual = $router->wasMatched();
            $I->assertTrue($actual);

            $expected = $paths["module"];
            $actual   = $router->getModuleName();
            $I->assertEquals($expected, $actual);
            $expected = $paths["controller"];
            $actual   = $router->getControllerName();
            $I->assertEquals($expected, $actual);
            $expected = $paths["action"];
            $actual   = $router->getActionName();
            $I->assertEquals($expected, $actual);

            $expected = $blog;
            $actual   = $router->getMatchedRoute()->getGroup();
            $I->assertEquals($expected, $actual);
        }
    }

    public function testHostnameRouteGroup(IntegrationTester $I)
    {
        $routes = $this->getHostnameRoutes();
        foreach ($routes as $route) {
            $actualHost   = $route[0];
            $expectedHost = $route[1];
            $controller   = $route[2];

            Route::reset();
            $this->newDi();
            $this->setDiRequest();
            $container = $this->getDi();

            $router = new Router(false);
            $router->setDI($container);

            $router->add(
                "/edit",
                [
                    "controller" => "posts3",
                    "action"     => "edit3",
                ]
            );

            $group = new Group();
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

            $expected = $controller;
            $actual   = $router->getControllerName();
            $I->assertEquals($expected, $actual);
            $expected = $expectedHost;
            $actual   = $router->getMatchedRoute()->getHostname();
            $I->assertEquals($expected, $actual);
        }
    }

    private function getHostnameRoutes(): array
    {
        return [
            ["localhost", null, "posts3"],
            ["my.phalconphp.com", "my.phalconphp.com", "posts"],
            [null, null, "posts3"],
        ];
    }

    public function testHostnameRegexRouteGroup(IntegrationTester $I)
    {
        $routes = $this->getHostnameRoutesRegex();
        foreach ($routes as $route) {
            $actualHost   = $route[0];
            $expectedHost = $route[1];
            $controller   = $route[2];

            Route::reset();
            $this->newDi();
            $this->setDiRequest();
            $container = $this->getDi();

            $router = new Router(false);
            $router->setDI($container);
            $router->add(
                "/edit",
                [
                    "controller" => "posts3",
                    "action"     => "edit3",
                ]
            );

            $group = new Group();
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

            $expected = $controller;
            $actual   = $router->getControllerName();
            $I->assertEquals($expected, $actual);
            $expected = $expectedHost;
            $actual   = $router->getMatchedRoute()->getHostname();
            $I->assertEquals($expected, $actual);
        }
    }

    private function getHostnameRoutesRegex(): array
    {
        return [
            ["localhost", null, "posts3"],
            ["my.phalconphp.com", "([a-z]+).phalconphp.com", "posts"],
            [null, null, "posts3"],
        ];
    }
}
