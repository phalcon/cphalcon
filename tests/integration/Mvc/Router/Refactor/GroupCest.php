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

namespace Phalcon\Tests\Integration\Mvc\Router\Refactor;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class GroupCest
 *
 * @package Phalcon\Tests\Integration\Mvc\Router
 * @todo: refactor
 */
class GroupCest
{
    use DiTrait;

    /**
     * @dataProvider groupsProvider
     */
    public function testGroups(IntegrationTester $I, Example $example)
    {
        Route::reset();

        $router = new Router(false);

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


        $router->handle(
            $example['route']
        );

        $I->assertTrue(
            $router->wasMatched()
        );

        $I->assertEquals(
            $example['module'],
            $router->getModuleName()
        );

        $I->assertEquals(
            $example['controller'],
            $router->getControllerName()
        );

        $I->assertEquals(
            $example['action'],
            $router->getActionName()
        );

        $I->assertEquals(
            $blog,
            $router->getMatchedRoute()->getGroup()
        );
    }

    private function groupsProvider(): array
    {
        return [
            [
                'route'      => '/blog/save',
                'module'     => 'blog',
                'controller' => 'index',
                'action'     => 'save',
            ],
            [
                'route'      => '/blog/edit/1',
                'module'     => 'blog',
                'controller' => 'index',
                'action'     => 'edit',
            ],
            [
                'route'      => '/blog/about',
                'module'     => 'blog',
                'controller' => 'about',
                'action'     => 'index',
            ],
        ];
    }

    /**
     * @dataProvider getHostnameRoutes
     */
    public function testHostnameRouteGroup(IntegrationTester $I, Example $example)
    {
        $actualHost   = $example[0];
        $expectedHost = $example[1];
        $controller   = $example[2];

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

        $I->assertEquals(
            $controller,
            $router->getControllerName()
        );

        $I->assertEquals(
            $expectedHost,
            $router->getMatchedRoute()->getHostname()
        );
    }

    private function getHostnameRoutes(): array
    {
        return [
            [
                'localhost',
                null,
                'posts3',
            ],
            [
                'my.phalcon.io',
                'my.phalcon.io',
                'posts',
            ],
            [
                null,
                null,
                'posts3',
            ],
        ];
    }

    /**
     * @dataProvider getHostnameRoutesRegex
     */
    public function testHostnameRegexRouteGroup(IntegrationTester $I, Example $example)
    {
        $actualHost   = $example[0];
        $expectedHost = $example[1];
        $controller   = $example[2];

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

        $I->assertEquals(
            $controller,
            $router->getControllerName()
        );

        $I->assertEquals(
            $expectedHost,
            $router->getMatchedRoute()->getHostname()
        );
    }

    private function getHostnameRoutesRegex(): array
    {
        return [
            [
                'localhost',
                null,
                'posts3',
            ],
            [
                'my.phalcon.io',
                '([a-z]+).phalcon.io',
                'posts',
            ],
            [
                null,
                null,
                'posts3',
            ],
        ];
    }
}
