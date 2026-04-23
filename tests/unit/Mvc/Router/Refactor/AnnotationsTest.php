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

use Phalcon\Mvc\Router\Annotations;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function is_object;

final class AnnotationsTest extends AbstractUnitTestCase
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
    public function testMvcRouterAnnotationsRouterFullResources1(): void
    {
        $container = $this->getDi();
        $router    = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Support\Controllers\Robots", '/');
        $router->addResource("Phalcon\Tests\Support\Controllers\Products", '/products');
        $router->addResource("Phalcon\Tests\Support\Controllers\About", '/about');

        $router->handle('/products');

        $this->assertCount(6, $router->getRoutes());

        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Support\Controllers\Robots", '/');
        $router->addResource("Phalcon\Tests\Support\Controllers\Products", '/products');
        $router->addResource("Phalcon\Tests\Support\Controllers\About", '/about');

        $router->handle('/about');

        $this->assertCount(5, $router->getRoutes());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsRouterFullResourcesNamespaced(): void
    {
        require_once supportDir('Controllers/NamespacedAnnotationController.php');

        $container = $this->getDi();

        $router = new Annotations(false);

        $router->setDI($container);

        $router->setDefaultNamespace('MyNamespace\\Controllers');

        $router->addResource('NamespacedAnnotation', '/namespaced');

        $router->handle('/namespaced');

        $this->assertCount(1, $router->getRoutes());

        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource(
            'MyNamespace\\Controllers\\NamespacedAnnotation',
            '/namespaced'
        );

        $router->handle('/namespaced/');
    }

    /**
     * @dataProvider getRoutesProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsRouterFullResources2(
        string $uri,
        string $method,
        string $controller,
        string $action,
        array $params
    ): void {
        $container = $this->getDi();

        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Support\Controllers\Robots");
        $router->addResource("Phalcon\Tests\Support\Controllers\Products");
        $router->addResource("Phalcon\Tests\Support\Controllers\About");
        $router->addResource("Phalcon\Tests\Support\Controllers\Main");

        $router->handle('/');

        $this->assertCount(9, $router->getRoutes());

        $route = $router->getRouteByName('save-robot');
        $this->assertTrue(is_object($route));
        $this->assertInstanceOf(Route::class, $route);

        $route = $router->getRouteByName('save-product');
        $this->assertTrue(is_object($route));
        $this->assertInstanceOf(Route::class, $route);

        $_SERVER['REQUEST_METHOD'] = $method;
        $router->handle($uri);

        $expected = $controller;
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = $action;
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }

    /**
     * @return array<array{string, string, string, string, array}>
     */
    public static function getRoutesProvider(): array
    {
        return [
            ['/products/save', 'PUT', 'products', 'save', []],
            ['/products/save', 'POST', 'products', 'save', []],
            ['/products/edit/100', 'GET', 'products', 'edit', ['id' => '100']],
            ['/products', 'GET', 'products', 'index', []],
            ['/robots/edit/100', 'GET', 'robots', 'edit', ['id' => '100']],
            ['/robots', 'GET', 'robots', 'index', []],
            ['/robots/save', 'PUT', 'robots', 'save', []],
            ['/about/team', 'GET', 'about', 'team', []],
            ['/about/team', 'POST', 'about', 'teampost', []],
            ['/', 'GET', 'main', 'index', []],
        ];
    }
}
