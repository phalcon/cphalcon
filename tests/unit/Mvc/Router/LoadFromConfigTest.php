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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class LoadFromConfigTest extends AbstractUnitTestCase
{
    use RouterTrait;

    public function testLoadFromConfigAddsRouteWithoutMethod(): void
    {
        $router = new Router(false);

        $result = $router->loadFromConfig([
            'routes' => [
                [
                    'pattern' => '/about',
                    'paths'   => 'About::index',
                ],
            ],
        ]);

        $this->assertInstanceOf(RouterInterface::class, $result);

        $routes = $router->getRoutes();
        $this->assertCount(1, $routes);
        $this->assertSame('/about', $routes[0]->getPattern());
        $this->assertNull($routes[0]->getHttpMethods());
    }

    /**
     * @dataProvider providerHttpMethods
     */
    public function testLoadFromConfigDispatchesHttpMethod(string $method, string $expected): void
    {
        $router = new Router(false);

        $router->loadFromConfig([
            'routes' => [
                ['method' => $method, 'pattern' => '/x', 'paths' => 'X::y'],
            ],
        ]);

        $routes = $router->getRoutes();
        $this->assertCount(1, $routes);
        $this->assertSame($expected, $routes[0]->getHttpMethods());
    }

    public static function providerHttpMethods(): array
    {
        return [
            ['connect', 'CONNECT'],
            ['delete',  'DELETE'],
            ['get',     'GET'],
            ['head',    'HEAD'],
            ['options', 'OPTIONS'],
            ['patch',   'PATCH'],
            ['post',    'POST'],
            ['purge',   'PURGE'],
            ['put',     'PUT'],
            ['trace',   'TRACE'],
            ['GET',     'GET'],
        ];
    }

    public function testLoadFromConfigRejectsUnknownMethod(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessage("Unknown HTTP method 'banana'");

        $router = new Router(false);
        $router->loadFromConfig([
            'routes' => [
                ['method' => 'banana', 'pattern' => '/x', 'paths' => 'X::y'],
            ],
        ]);
    }

    public function testLoadFromConfigAppliesNameAndHostname(): void
    {
        $router = new Router(false);

        $router->loadFromConfig([
            'routes' => [
                [
                    'method'   => 'get',
                    'pattern'  => '/users/{id}',
                    'paths'    => 'Users::show',
                    'name'     => 'user-show',
                    'hostname' => 'api.example.com',
                ],
            ],
        ]);

        $route = $router->getRouteByName('user-show');
        $this->assertNotFalse($route);
        $this->assertSame('user-show', $route->getName());
        $this->assertSame('api.example.com', $route->getHostname());
    }

    public function testLoadFromConfigAppliesDefaults(): void
    {
        $router = new Router(false);
        $router->loadFromConfig([
            'defaults' => [
                'module'     => 'frontend',
                'controller' => 'index',
            ],
        ]);

        $this->assertSame(
            [
                'namespace'  => '',
                'module'     => 'frontend',
                'controller' => 'index',
                'action'     => '',
                'params'     => [],
            ],
            $router->getDefaults()
        );
    }

    public function testLoadFromConfigRejectsNonArrayDefaults(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessage("'defaults' must be an array");

        (new Router(false))->loadFromConfig(['defaults' => 'nope']);
    }

    public function testLoadFromConfigAppliesNotFound(): void
    {
        $router = $this->getRouter(false);
        $router->loadFromConfig([
            'notFound' => [
                'controller' => 'errors',
                'action'     => 'show404',
            ],
        ]);

        $router->handle('/no/such/route');
        $this->assertSame('errors',  $router->getControllerName());
        $this->assertSame('show404', $router->getActionName());
    }

    public function testLoadFromConfigAppliesRemoveExtraSlashes(): void
    {
        $router = $this->getRouter(false);
        $router->loadFromConfig([
            'removeExtraSlashes' => true,
            'routes' => [
                ['method' => 'get', 'pattern' => '/about', 'paths' => 'About::index'],
            ],
        ]);

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/about/');

        $this->assertSame('About',  $router->getControllerName());
        $this->assertSame('index',  $router->getActionName());
    }

    public function testLoadFromConfigMountsGroups(): void
    {
        $router = new Router(false);

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix'   => '/api/v1',
                    'hostname' => 'api.example.com',
                    'paths'    => ['namespace' => 'App\\Api\\V1\\Controllers'],
                    'routes'   => [
                        ['method' => 'get',  'pattern' => '/users', 'paths' => ['controller' => 'users', 'action' => 'index']],
                        ['method' => 'post', 'pattern' => '/users', 'paths' => ['controller' => 'users', 'action' => 'create']],
                    ],
                ],
            ],
        ]);

        $routes = $router->getRoutes();
        $this->assertCount(2, $routes);
        $this->assertSame('/api/v1/users',     $routes[0]->getPattern());
        $this->assertSame('api.example.com',   $routes[0]->getHostname());
        $this->assertSame('GET',  $routes[0]->getHttpMethods());
        $this->assertSame('POST', $routes[1]->getHttpMethods());
    }

    public function testLoadFromConfigRejectsNonArrayGroups(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessage("'groups' must be an array");

        (new Router(false))->loadFromConfig(['groups' => 'nope']);
    }

    public function testLoadFromConfigAcceptsConfigObject(): void
    {
        $config = new \Phalcon\Config\Config([
            'routes' => [
                ['method' => 'get', 'pattern' => '/about', 'paths' => 'About::index'],
            ],
        ]);

        $router = new Router(false);
        $router->loadFromConfig($config);

        $this->assertCount(1, $router->getRoutes());
        $this->assertSame('/about', $router->getRoutes()[0]->getPattern());
    }

    public function testLoadFromConfigRejectsNonArrayNonConfig(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessageMatches('/requires an array or Phalcon/');

        (new Router(false))->loadFromConfig('a string');
    }

    public function testLoadFromConfigRequiresPattern(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessage("Route config entry is missing 'pattern'");

        (new Router(false))->loadFromConfig([
            'routes' => [['paths' => 'X::y']],
        ]);
    }

    public function testLoadFromConfigRequiresPaths(): void
    {
        $this->expectException(\Phalcon\Mvc\Router\Exception::class);
        $this->expectExceptionMessage("Route config entry is missing 'paths'");

        (new Router(false))->loadFromConfig([
            'routes' => [['pattern' => '/x']],
        ]);
    }
}
