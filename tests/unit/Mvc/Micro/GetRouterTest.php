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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

class GetRouterTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: callable(): Micro}>
     */
    public static function getDefaultRouterApplications(): array
    {
        return [
            'FactoryDefault' => [
                static fn (): Micro => new Micro(new FactoryDefault()),
            ],
            'no container'   => [
                static fn (): Micro => new Micro(),
            ],
            'not shared'     => [
                static function (): Micro {
                    $container = new Di();
                    $container->set('router', Router::class);

                    return new Micro($container);
                },
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroGetRouter(): void
    {
        $micro = new Micro();
        $this->assertInstanceOf(RouterInterface::class, $micro->getRouter());
    }

    /**
     * A router that is resolved before getRouter() keeps its object, and
     * Micro clears its routes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcMicroGetRouterClearsResolvedRouter(): void
    {
        $container = new FactoryDefault();
        $router    = $container->getShared('router');
        $router->add('/before');

        $micro = new Micro($container);

        $this->assertSame($router, $micro->getRouter());
        $this->assertCount(0, $router->getRoutes());
    }

    /**
     * A router service with a closure definition gets no arguments, and
     * Micro clears its routes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcMicroGetRouterCustomDefinition(): void
    {
        $arguments = null;
        $container = new FactoryDefault();
        $container->setShared(
            'router',
            function (...$args) use (&$arguments): Router {
                $arguments = $args;

                return new Router();
            }
        );

        $micro  = new Micro($container);
        $router = $micro->getRouter();

        $this->assertSame([], $arguments);
        $this->assertCount(0, $router->getRoutes());
    }

    /**
     * The default router service is created without the two default
     * routes, so the first Micro route gets the first route ID.
     *
     * @param callable(): Micro $factory
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    #[DataProvider('getDefaultRouterApplications')]
    public function testMvcMicroGetRouterDefaultServiceWithoutDefaultRoutes(callable $factory): void
    {
        Route::reset();

        $micro = $factory();
        $route = $micro->get(
            '/hello',
            function () {
                return 'hello';
            }
        );

        $this->assertSame('0', $route->getRouteId());
        $this->assertCount(1, $micro->getRouter()->getRoutes());
    }

    /**
     * A container with no router service stops getRouter().
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcMicroGetRouterNoRouterService(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'router' is not registered in the container"
        );

        $micro = new Micro(new Di());
        $micro->getRouter();
    }
}
