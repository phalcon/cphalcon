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

namespace Phalcon\Tests\Unit\Mvc\Router\Refactor;

use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GroupTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @dataProvider groupsProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGroupGroups(
        string $route,
        string $module,
        string $controller,
        string $action
    ): void {
        Route::reset();

        $router = new Router(false);
        $router->setDI(new FactoryDefault());

        $blog = new Group(
            [
                'module'     => 'blog',
                'controller' => 'index',
            ]
        );

        $blog->setPrefix('/blog');

        $blog->add(
            '/save',
            [
                'action' => 'save',
            ]
        );

        $blog->add(
            '/edit/{id}',
            [
                'action' => 'edit',
            ]
        );

        $blog->add(
            '/about',
            [
                'controller' => 'about',
                'action'     => 'index',
            ]
        );

        $router->mount($blog);

        $router->handle($route);

        $this->assertTrue($router->wasMatched());

        $expected = $module;
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = $controller;
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = $action;
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $this->assertSame($blog, $router->getMatchedRoute()->getGroup());
    }

    /**
     * @dataProvider hostnameRoutesProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGroupHostnameRouteGroup(
        ?string $actualHost,
        ?string $expectedHost,
        string $controller
    ): void {
        Route::reset();

        $this->newDi();
        $this->setDiService('request');

        $container = $this->getDi();

        $router = new Router(false);
        $router->setDI($container);

        $router->add(
            '/edit',
            [
                'controller' => 'posts3',
                'action'     => 'edit3',
            ]
        );

        $group = new Group();
        $group->setHostname('my.phalcon.io');
        $group->add(
            '/edit',
            [
                'controller' => 'posts',
                'action'     => 'edit',
            ]
        );

        $router->mount($group);

        $_SERVER['HTTP_HOST'] = $actualHost;

        $router->handle('/edit');

        $expected = $controller;
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = $expectedHost;
        $actual   = $router->getMatchedRoute()->getHostname();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider hostnameRoutesRegexProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGroupHostnameRegexRouteGroup(
        ?string $actualHost,
        ?string $expectedHost,
        string $controller
    ): void {
        Route::reset();

        $this->newDi();
        $this->setDiService('request');

        $container = $this->getDi();

        $router = new Router(false);
        $router->setDI($container);

        $router->add(
            '/edit',
            [
                'controller' => 'posts3',
                'action'     => 'edit3',
            ]
        );

        $group = new Group();
        $group->setHostname('([a-z]+).phalcon.io');
        $group->add(
            '/edit',
            [
                'controller' => 'posts',
                'action'     => 'edit',
            ]
        );

        $router->mount($group);

        $_SERVER['HTTP_HOST'] = $actualHost;

        $router->handle('/edit');

        $expected = $controller;
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = $expectedHost;
        $actual   = $router->getMatchedRoute()->getHostname();
        $this->assertSame($expected, $actual);
    }

    /**
     * @return array<array{string, string, string, string}>
     */
    public static function groupsProvider(): array
    {
        return [
            ['/blog/save', 'blog', 'index', 'save'],
            ['/blog/edit/1', 'blog', 'index', 'edit'],
            ['/blog/about', 'blog', 'about', 'index'],
        ];
    }

    /**
     * @return array<array{string|null, string|null, string}>
     */
    public static function hostnameRoutesProvider(): array
    {
        return [
            ['localhost', null, 'posts3'],
            ['my.phalcon.io', 'my.phalcon.io', 'posts'],
            [null, null, 'posts3'],
        ];
    }

    /**
     * @return array<array{string|null, string|null, string}>
     */
    public static function hostnameRoutesRegexProvider(): array
    {
        return [
            ['localhost', null, 'posts3'],
            ['my.phalcon.io', '([a-z]+).phalcon.io', 'posts'],
            [null, null, 'posts3'],
        ];
    }
}
