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

namespace Phalcon\Tests\Unit\Mvc\Router\Annotations;

use Phalcon\Mvc\Router\Annotations;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;

#[BackupGlobals(true)]
final class HandleTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        parent::setUp();

        $this->newDi();
        $this->setDiService('request');
        $this->setDiService('annotations');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsHandle(): void
    {
        $router = new Annotations(false);
        $router->setDI($this->container);
        $router->setDefaultNamespace('Phalcon\Tests\Support\Controllers');
        $router->addResource('Robots');
        $router->addResource('Products');
        $router->addResource('About');
        $router->addResource('Main');

        $routes = [
            [
                'uri'        => '/products/save',
                'method'     => 'PUT',
                'controller' => 'products',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/products/save',
                'method'     => 'POST',
                'controller' => 'products',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/products/edit/100',
                'method'     => 'GET',
                'controller' => 'products',
                'action'     => 'edit',
                'params'     => ['id' => '100'],
            ],
            [
                'uri'        => '/products',
                'method'     => 'GET',
                'controller' => 'products',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/robots/edit/100',
                'method'     => 'GET',
                'controller' => 'robots',
                'action'     => 'edit',
                'params'     => ['id' => '100'],
            ],
            [
                'uri'        => '/robots',
                'method'     => 'GET',
                'controller' => 'robots',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/robots/save',
                'method'     => 'PUT',
                'controller' => 'robots',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/about/team',
                'method'     => 'GET',
                'controller' => 'about',
                'action'     => 'team',
                'params'     => [],
            ],
            [
                'uri'        => '/about/team',
                'method'     => 'POST',
                'controller' => 'about',
                'action'     => 'teampost',
                'params'     => [],
            ],
            [
                'uri'        => '/',
                'method'     => 'GET',
                'controller' => 'main',
                'action'     => 'index',
                'params'     => [],
            ],
        ];

        foreach ($routes as $route) {
            $_SERVER['REQUEST_METHOD'] = $route['method'];
            $router->handle($route['uri']);

            $this->assertSame($route['controller'], $router->getControllerName());
            $this->assertSame($route['action'], $router->getActionName());
            $this->assertSame($route['params'], $router->getParams());
            $this->assertTrue($router->isExactControllerName());
        }
    }
}
